package org.gdgu.swghosh.cse2016;

/**
 * Animal class
 * to mimic age and weight
 *
 * @author Swarup Ghosh
 * @since 2018-08-23
 * @version 1.0
 */

public class Animal {

    /* Properties of animal
     */
    private int age;
    private float weight;

    /**
     * Initialise an Animal object with
     * age 0 and weight 0
     */
    public Animal() {
        this.age = 0;
        this.weight = 0.0f;
        System.out.println("Creation of new animal...");
    }

    /**
     * Age Getter Method
     * @return age of animal
     */
    public int getAge() {
        return this.age;
    }

    /**
     * Age Setter Method
     * @param age animal age
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     * Weight Getter Method
     * @return weight of animal
     */
    public float getWeight() {
        return this.weight;
    }
    /**
     * Weight Setter Method
     * @param weight animal weight
     */
    public void setWeight(float weight) {
        this.weight = weight;
    }
}
