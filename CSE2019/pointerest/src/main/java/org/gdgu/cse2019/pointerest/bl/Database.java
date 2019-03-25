package org.gdgu.cse2019.pointerest.bl;

import com.google.gson.Gson;
import com.mongodb.ConnectionString;
import org.bson.Document;
import com.mongodb.client.*;
import org.bson.types.ObjectId;
import org.gdgu.cse2019.pointerest.models.Image;
import org.gdgu.cse2019.pointerest.models.Place;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.regex.Pattern;

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

    public static ArrayList<Place> searchPlaces(String query) {
        HashSet<String> words = new HashSet();
        for(String word : query.split(" ")) {
            System.out.println(word);
            words.add(word);
        }
        String search[] = new String[words.size()];
        int iterIndex = 0;
        for(String word : words) {
            search[iterIndex] = Pattern.quote(word);
            iterIndex++;
        }
        String searchRegex = String.join("|", search);
        System.out.println(searchRegex);

        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        Document searchQuery = new Document();
        Document regexQuery = new Document();
        regexQuery.append("$regex", searchRegex);
        searchQuery.append("name", regexQuery);

        Gson gBuilder = new Gson();
        ArrayList<Place> places = new ArrayList();
        for(Document placeDoc : placesCol.find(searchQuery)) {
            Place place = gBuilder.fromJson(
                    placeDoc.toJson(), Place.class
            );
            places.add(place);
        }
        return places;
    }
}
