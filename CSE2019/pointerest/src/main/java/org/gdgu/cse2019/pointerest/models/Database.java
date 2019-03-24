package org.gdgu.cse2019.pointerest.models;

import com.google.gson.Gson;
import com.mongodb.ConnectionString;
import org.bson.Document;
import com.mongodb.client.*;

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
        MongoCollection<Document> placesCol = db.getCollection(PLACES_COLLECTION);
        Gson gBuilder = new Gson();
        ArrayList<Place> places = new ArrayList();
        for(Document a : placesCol.find()) {
            Place place = gBuilder.fromJson(
                a.toJson(), Place.class
            );
            places.add(place);
        }
        return places;
    }
}
