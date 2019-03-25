package org.gdgu.cse2019.pointerest;

import org.bson.Document;
import org.gdgu.cse2019.pointerest.models.Image;
import org.gdgu.cse2019.pointerest.models.Place;

import org.gdgu.cse2019.pointerest.bl.Database;

import java.util.ArrayList;

public class App {

    public static void main(String[] args) {
        for(Place place : Database.getAllPlaces()) {
            float[] latLng = place.getPointCoordinates();
            String tags = String.join(", ", place.getTags());
            System.out.printf("(%s, (%f, %f), [%s])\n",
                    place.getName(), latLng[0], latLng[1], tags
            );

            ArrayList<Image> images = Database.getImagesByPlace(place);
            for(Image image : images) {
                System.out.println(image.getImageURL());
            }
        }
        for(Place place : Database.searchPlaces("GD Goenka snacks")) {
            System.out.println(place.getName());
        }
    }
}
