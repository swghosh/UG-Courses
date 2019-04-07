package org.gdgu.cse2019.pointerest;

import org.gdgu.cse2019.pointerest.bl.Database;
import org.gdgu.cse2019.pointerest.models.Coordinate;
import org.gdgu.cse2019.pointerest.models.Image;
import org.gdgu.cse2019.pointerest.models.Place;

import java.util.ArrayList;
import java.util.Scanner;

public class App {

    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";

    static boolean menuActions() {
        String welcomeMessage = String.join("\n", "",
                "    ____        _       __                      __ ",
                "    / __ \\____  (_)___  / /____  ________  _____/ /_",
                "   / /_/ / __ \\/ / __ \\/ __/ _ \\/ ___/ _ \\/ ___/ __/",
                "  / ____/ /_/ / / / / / /_/  __/ /  /  __(__  ) /_  ",
                " /_/    \\____/_/_/ /_/\\__/\\___/_/   \\___/____/\\__/  ",
                ""
        );

        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println(ANSI_YELLOW + welcomeMessage);
        System.out.println(ANSI_CYAN + " 1 - Search places");
        System.out.println(ANSI_GREEN + " 2 - Add new place");
        System.out.println(ANSI_PURPLE + " 3 - Add new picture");
        System.out.println(ANSI_RESET);

        Scanner in = new Scanner(System.in);
        in.useDelimiter("\n");
        System.out.print(ANSI_BLUE + " Your Choice... ");
        System.out.print(ANSI_RESET);
        int choice = in.nextInt();

        switch (choice) {
            case 1:
                System.out.println(" In order to search for a place we need to know some keywords.");

                System.out.print(ANSI_GREEN + " Specify your search query... " + ANSI_RESET);
                String userQuery = in.next();

                System.out.println(ANSI_GREEN + " Based on your search query " + ANSI_PURPLE + "\"" + userQuery + "\"" + ANSI_GREEN + " results are as follows.");

                searchAction(userQuery);

                System.out.println();
                System.out.println(ANSI_PURPLE + " Thank you! :0 ");

                break;
            case 2:
                System.out.println(" In order to add a new place please give details about the place.");

                System.out.print(ANSI_GREEN + " Specify name... " + ANSI_RESET);
                String name = in.next();

                System.out.print(ANSI_GREEN + " Specify latitude... " + ANSI_RESET);
                float latitude = in.nextFloat();

                System.out.print(ANSI_GREEN + " Specify longitude... " + ANSI_RESET);
                float longitude = in.nextFloat();

                System.out.print(ANSI_GREEN + " Specify tags... " + ANSI_RESET);
                String tags = in.next();

                addPlaceAction(name, latitude, longitude, tags);

                System.out.println();
                System.out.println(ANSI_PURPLE + " Place has been added. Thank you! :0 ");
                break;
            case 3:
                System.out.println(" In order to add a new image for a place please provide details.");

                System.out.print(ANSI_GREEN + " Specify exact name of place... " + ANSI_RESET);
                String exactName = in.next();

                System.out.print(ANSI_GREEN + " Specify URL of image... " + ANSI_RESET);
                String imageURL = in.next();

                addImageAction(exactName, imageURL);

                System.out.println();
                System.out.println(ANSI_PURPLE + " Image has been added to the place. Thank you! :0 ");
                break;
            default:
                System.out.println(" Unfortunately, That was an invalid choice.");
        }

        System.out.println(ANSI_RESET + "Press a to continue. Press q to quit.");
        System.out.print(ANSI_RED + " ... ");
        char ex = in.next().charAt(0);
        return ex != 'q';
    }

    static void searchAction(String query) {
        ArrayList<Place> places = Database.searchPlaces(query);
        System.out.println();
        for(Place place : places) {
            System.out.println(ANSI_RESET);
            System.out.println(ANSI_GREEN + place.getName());
            float[] coord = place.getPointCoordinates();
            System.out.println(ANSI_RESET + "Located at: " + ANSI_CYAN + coord[0] + ", " + coord[1]);
            ArrayList<Image> images = Database.getImagesByPlace(place);
            for(Image image : images) {
                System.out.println(image.getImageURL());
            }
            System.out.println(ANSI_RESET);
        }
    }

    static void addPlaceAction(String name, float latitude, float longitude, String tagString) {
        String[] tagsArray = tagString.split(" ");
        ArrayList<String> tags = new ArrayList<String>();
        for(String tag : tagsArray) tags.add(tag);
        Place newPlace = new Place(
                new Coordinate(latitude, longitude),
                name,
                tags
        );
        Database.addNewPlace(newPlace);
    }

    static void addImageAction(String exactName, String imageURL) {
        ArrayList<Place> searchedPlaces = Database.searchPlaces(exactName);
        Place reqdPlace = searchedPlaces.get(0);
        Image newImage = new Image(reqdPlace, imageURL);
        Database.addNewImage(newImage);
    }

    public static void main(String[] args) {
        while(menuActions()) {
            System.out.print(ANSI_RESET);
            System.out.print("\033[H\033[2J");
            System.out.flush();
        }
        System.out.print(ANSI_RESET);
    }
}
