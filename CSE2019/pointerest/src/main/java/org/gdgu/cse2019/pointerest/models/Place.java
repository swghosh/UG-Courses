package org.gdgu.cse2019.pointerest.models;

import java.util.ArrayList;

public class Place {
    private Coordinate point;
    private String name;
    private ArrayList<String> tags;

    public Place(Coordinate point, String name, ArrayList<String> tags) {
        this.point = point;
        this.name = name;
        this.tags = tags;
    }

    public float[] getPointCoordinates() {
        return this.point.getCoordinates();
    }
    public String getName() {
        return this.name;
    }
    public ArrayList<String> getTags() {
        return this.tags;
    }
}
