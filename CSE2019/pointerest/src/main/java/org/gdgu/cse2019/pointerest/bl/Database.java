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
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;

public class Database {

    private static final String DATABASE_URL = System.getenv("POINTEREST_MONGO_URL");
    private static final String DATABASE_NAME = "pointerest";

    private static final String PLACES_COLLECTION = "places";
    private static final String IMAGES_COLLECTION = "images";

    private static MongoDatabase db;
    private static Gson gson;

    static {
        connectToDatabase();
        gson = new Gson();
    }

    private static void connectToDatabase() {
        Logger mongoLogger = Logger.getLogger( "org.mongodb.driver" );
        mongoLogger.setLevel(Level.SEVERE);

        ConnectionString connUrl = new ConnectionString(DATABASE_URL);
        MongoClient client = MongoClients.create(connUrl);
        db = client.getDatabase(DATABASE_NAME);
    }

    public static ArrayList<Place> getAllPlaces() {
        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        ArrayList<Place> places = new ArrayList<Place>();
        for(Document placeDoc : placesCol.find()) {
            Place place = gson.fromJson(
                    placeDoc.toJson(), Place.class
            );
            places.add(place);
        }
        return places;
    }

    public static ArrayList<Image> getImagesByPlace(Place place) {
        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        Document searchQuery = Document.parse(gson.toJson(place));
        ObjectId placeId = null;
        for(Document found : placesCol.find(searchQuery).limit(1)) {
            placeId = (ObjectId) found.get("_id");
        }

        ArrayList<Image> images = new ArrayList<Image>();

        if(placeId == null) return images;

        MongoCollection<Document> imagesCol = db.getCollection(IMAGES_COLLECTION);
        searchQuery = new Document();
        searchQuery.append("place", placeId);
        for(Document imageDoc : imagesCol.find(searchQuery)) {
            imageDoc.remove("place");
            Image image = gson.fromJson(
                    imageDoc.toJson(), Image.class
            );
            image.setPlace(place);
            images.add(image);
        }
        return images;
    }

    public static ArrayList<Place> searchPlaces(String query) {
        query = query.toLowerCase();

        HashSet<String> words = new HashSet<String>();
        for(String word : query.split(" ")) {
            words.add(word);
        }
        String search[] = new String[words.size()];
        int iterIndex = 0;
        for(String word : words) {
            search[iterIndex] = Pattern.quote(word);
            iterIndex++;
        }
        String searchRegex = String.join("|", search);

        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);

        Document searchQuery1 = new Document();
        Document regexQuery = new Document();
        regexQuery.append("$regex", searchRegex);
        regexQuery.append("$options", "i");
        searchQuery1.append("name", regexQuery);

        Document searchQuery2 = new Document();
        Document inQuery = new Document();
        inQuery.append("$in", words);
        searchQuery2.append("tags", inQuery);

        ArrayList<Document> queries = new ArrayList<Document>();
        queries.add(searchQuery1);
        queries.add(searchQuery2);
        Document searchQuery = new Document();
        searchQuery.append("$or", queries);

        Gson gson = new Gson();
        ArrayList<Place> places = new ArrayList();
        for(Document placeDoc : placesCol.find(searchQuery)) {
            Place place = gson.fromJson(
                    placeDoc.toJson(), Place.class
            );
            places.add(place);
        }
        return places;
    }

    public static void addNewPlace(Place place) {
        Document placeDoc = Document.parse(
                gson.toJson(place)
        );
        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        placesCol.insertOne(placeDoc);
    }

    public static void addNewImage(Image image) {
        Place place = image.getPlace();
        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        Document searchQuery = Document.parse(gson.toJson(place));
        ObjectId placeId = null;
        for(Document found : placesCol.find(searchQuery).limit(1)) {
            placeId = (ObjectId) found.get("_id");
        }

        if(placeId == null) return;

        Document imageDoc = Document.parse(
                gson.toJson(image)
        );
        imageDoc.remove("place");
        imageDoc.append("place", placeId);

        MongoCollection<Document> imagesCol = db.getCollection(IMAGES_COLLECTION);
        imagesCol.insertOne(imageDoc);
    }
}
