package org.gdgu.cse2019.pointerest;

import com.google.gson.Gson;
import org.gdgu.cse2019.pointerest.models.Database;
import org.gdgu.cse2019.pointerest.models.Image;
import org.gdgu.cse2019.pointerest.models.Place;

import java.util.ArrayList;

public class App {

    public static void main(String[] args) {
        Gson gson = new Gson();
        for(Place place : Database.getAllPlaces()) {
            float[] latLng = place.getPointCoordinates();
            String tags = String.join(", ", place.getTags());
            System.out.printf("(Name: %s, Latitude: %f, Longitude: %f, Tags: [%s])\n",
                    place.getName(), latLng[0], latLng[1], tags
            );

            ArrayList<Image> images = Database.getImagesByPlace(place);
            for(Image image : images) {
                System.out.println(gson.toJson(image.getImageURL()));
            }
        }
    }
}
