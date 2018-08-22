package org.gdgu.swghosh.cse2016;

public class AnimalTest {
    public static void main(String[] args) {
        Animal fox = new Animal();
        fox.setAge(10);
        fox.setWeight(55);
        System.out.println("Fox with age " + fox.getAge() + "yrs and weight " + fox.getWeight() + "kgs.");

        System.out.println();

        DomesticAnimal cow = new DomesticAnimal();
        cow.setAge(5);
        cow.setWeight(200);
        System.out.println("Cow with age " + cow.getAge() + "yrs and weight " + cow.getWeight() + "kgs.");
        cow.setDomesticPurpose("DAIRY MILK");
        cow.serveDomesticPurpose();
    }
}
