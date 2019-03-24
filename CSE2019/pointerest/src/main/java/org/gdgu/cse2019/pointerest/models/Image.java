package org.gdgu.cse2019.pointerest.models;

import java.net.URL;

public class Image {
    private Place place;
    private String imageURL;

    public Image(Place place, String imageUrl) {
        this.place = place;
        this.imageURL = imageUrl;
    }

    public Place getPlace() {
        return this.place;
    }
    public void setPlace(Place place) {
        this.place = place;
    }
    public String getImageURL() {
        return this.imageURL;
    }
}
