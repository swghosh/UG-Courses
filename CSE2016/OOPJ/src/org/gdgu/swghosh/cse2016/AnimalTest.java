package org.gdgu.swghosh.cse2016;

/**
 * Test the use of inheritance across
 * Animal, DomesticAnimal classes
 * by creating objects of both.
 *
 * When DomesticAnimal's object is to
 * be created the Animal constructor
 * is called first, then the DomesticAnimal
 * constructor.
 *
 * @author Swarup Ghosh
 * @since 2018-08-23
 * @version 1.0
 */

public class AnimalTest {
    public static void main(String[] args) {
        /**
         * Create an object of Animal,
         * set its properties and access its methods
         */
        Animal fox = new Animal();
        fox.setAge(10);
        fox.setWeight(55);
        System.out.println("Fox with age " + fox.getAge() + "yrs and weight " + fox.getWeight() + "kgs.");

        System.out.println();

        /**
         * Create an object of DomesticAnimal,
         * set its properties and access its methods
         */
        DomesticAnimal cow = new DomesticAnimal();
        cow.setAge(5);
        cow.setWeight(200);
        System.out.println("Cow with age " + cow.getAge() + "yrs and weight " + cow.getWeight() + "kgs.");
        cow.setDomesticPurpose("DAIRY MILK");
        cow.serveDomesticPurpose();
    }
}
