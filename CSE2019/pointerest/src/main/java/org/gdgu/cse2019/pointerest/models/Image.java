package org.gdgu.cse2019.pointerest.models;

public class Image {
    private Place place;
    private byte[] image;

    public Image(Place place, byte[] image) {
        this.place = place;
        this.image = image;
    }

    public Place getPlace() {
        return this.place;
    }
    public void setPlace() {
        this.place = place;
    }
}
