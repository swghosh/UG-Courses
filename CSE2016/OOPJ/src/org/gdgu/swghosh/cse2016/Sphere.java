package org.gdgu.swghosh.cse2016;

/**
 * Class Sphere inherits abstract
 * class Shape
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */
public class Sphere extends Shape {
    float radius;
    Sphere(float radius) {
        this.radius = radius;
    }
    /**
     * @return the volume of the sphere
     */
    float volume() {
        return (4.0f / 3.0f) * super.PI * (radius * radius * radius);
    }
}
