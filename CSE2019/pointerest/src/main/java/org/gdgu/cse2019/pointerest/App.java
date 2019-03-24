package org.gdgu.cse2019.pointerest;

import org.gdgu.cse2019.pointerest.models.Database;
import org.gdgu.cse2019.pointerest.models.Place;

public class App {

    public static void main(String[] args) {
        for(Place place : Database.getAllPlaces()) {
            float[] latLng = place.getPointCoordinates();
            String tags = String.join(", ", place.getTags());
            System.out.printf("(Name: %s, Latitude: %f, Longitude: %f, Tags: [%s])\n",
                    place.getName(), latLng[0], latLng[1], tags
            );
        }
    }
}
