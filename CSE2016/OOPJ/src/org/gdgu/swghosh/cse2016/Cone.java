package org.gdgu.swghosh.cse2016;

/**
 * Class Cone inherits abstract
 * class Shape
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */

public class Cone extends Shape {
    float radius, height;
    Cone(float radius, float height) {
        this.radius = radius;
        this.height = height;
    }

    /**
     * @return the volume of the conce
     */
    float volume() {
        return super.PI * (radius * radius) * height;
    }
}
