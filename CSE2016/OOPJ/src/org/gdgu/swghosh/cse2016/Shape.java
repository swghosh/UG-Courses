package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

/**
 * Abstract class Shape will
 * be inherited by cone and sphere
 * for method volume and field PI
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */

public abstract class Shape {
    final float PI = 3.14f;
    abstract float volume();

    public static  void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Specify radius and height of cone... (two floating point numbers expected) -> ");
        Cone cone = new Cone(in.nextFloat(), in.nextFloat());
        System.out.println("The volume of the cone is " + cone.volume());
        System.out.print("Specify radius of sphere... (floating point number expected) -> ");
        Sphere sphere = new Sphere(in.nextFloat());
        System.out.println("The volume of the sphere is " + sphere.volume());
    }
}
