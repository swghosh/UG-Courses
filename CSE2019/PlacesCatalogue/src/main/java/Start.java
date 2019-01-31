import com.mongodb.ConnectionString;
import com.mongodb.client.*;
import org.bson.Document;

public class Start {
    public static void main(String args[]) {
        ConnectionString databaseUrl = new ConnectionString("mongodb://localhost:27017/cse2019");
        MongoClient client = MongoClients.create(databaseUrl);
        MongoDatabase db = client.getDatabase("cse2019");
        MongoCollection<Document> users = db.getCollection("users");
        Document aDocument = users.find().first();
        System.out.println(aDocument.toJson());
        client.close();
    }
}
