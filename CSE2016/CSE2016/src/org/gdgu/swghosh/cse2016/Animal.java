package org.gdgu.swghosh.cse2016;

public class Animal {
    private int age;
    private float weight;

    public Animal() {
        this.age = 0;
        this.weight = 0.0f;
        System.out.println("Creation of new animal...");
    }

    public int getAge() {
        return this.age;
    }
    public void setAge(int age) {
        this.age = age;
    }

    public float getWeight() {
        return this.weight;
    }
    public void setWeight(float weight) {
        this.weight = weight;
    }
}
