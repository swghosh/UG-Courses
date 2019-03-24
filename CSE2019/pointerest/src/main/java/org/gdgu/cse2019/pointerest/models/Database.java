package org.gdgu.cse2019.pointerest.models;

import com.google.gson.Gson;
import com.mongodb.ConnectionString;
import org.bson.Document;
import com.mongodb.client.*;
import org.bson.types.ObjectId;

import javax.print.Doc;
import java.util.ArrayList;

public class Database {
    private static final String DATABASE_URL = System.getenv("POINTEREST_MONGO_URL");
    private static final String DATABASE_NAME = "pointerest";

    private static final String PLACES_COLLECTION = "places";
    private static final String IMAGES_COLLECTION = "images";

    private static MongoDatabase db;
    static {
        db = new Database().connectToDatabase();
    }

    private MongoDatabase connectToDatabase() {
        ConnectionString connUrl = new ConnectionString(DATABASE_URL);
        MongoClient client = MongoClients.create(connUrl);
        MongoDatabase db = client.getDatabase(DATABASE_NAME);
        return db;
    }

    public static ArrayList<Place> getAllPlaces() {
        Gson gBuilder = new Gson();
        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        ArrayList<Place> places = new ArrayList();
        for(Document placeDoc : placesCol.find()) {
            Place place = gBuilder.fromJson(
                placeDoc.toJson(), Place.class
            );
            places.add(place);
        }
        return places;
    }

    public static ArrayList<Image> getImagesByPlace(Place place) {
        Gson gBuilder = new Gson();
        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        Document searchQuery = Document.parse(gBuilder.toJson(place));
        ObjectId placeId = null;
        for(Document found : placesCol.find(searchQuery).limit(1)) {
            placeId = (ObjectId) found.get("_id");
        }

        ArrayList<Image> images = new ArrayList();

        if(placeId == null) return images;

        MongoCollection<Document> imagesCol = db.getCollection(IMAGES_COLLECTION);
        searchQuery = new Document();
        searchQuery.append("place", placeId);
        for(Document imageDoc : imagesCol.find(searchQuery)) {
            imageDoc.remove("place");
            Image image = gBuilder.fromJson(
                imageDoc.toJson(), Image.class
            );
            image.setPlace(place);
            images.add(image);
        }
        return images;
    }
}
