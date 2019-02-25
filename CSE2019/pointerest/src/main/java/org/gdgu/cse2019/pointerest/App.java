package org.gdgu.cse2019.pointerest;

import com.mongodb.ConnectionString;
import org.bson.Document;
import com.mongodb.client.*;


public class App {
    static final String CONNECTION_STRING = "mongodb://localhost:27017/",
            DATABASE_NAME = "cse2019";

    public static void main(String[] args) {
        ConnectionString connUrl = new ConnectionString(CONNECTION_STRING);
        MongoClient client = MongoClients.create(connUrl);
        MongoDatabase db = client.getDatabase(DATABASE_NAME);

        System.out.println("Listing all collections in the database.");
        for(String collectionName : db.listCollectionNames()) {
            System.out.println(collectionName);
        }

        MongoCollection<Document> msgCol = db.getCollection("messages");
        System.out.println(msgCol.countDocuments() + " documents are present in the messages collection.");

        System.out.println("List all documents in the messages collection.");
        for(Document doc : msgCol.find()) {
            System.out.println(doc.toJson());
        }

        client.close();
    }
}
