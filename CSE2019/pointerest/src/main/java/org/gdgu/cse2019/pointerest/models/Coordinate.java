package org.gdgu.cse2019.pointerest.models;

public class Coordinate {
    private float latitude, longitude;
    public Coordinate(float latitude, float longitude) {
        this.latitude = latitude;
        this.longitude = longitude;
    }
    public float[] getCoordinates() {
        float[] coordinates = {
            latitude, longitude
        };
        return coordinates;
    }
}
