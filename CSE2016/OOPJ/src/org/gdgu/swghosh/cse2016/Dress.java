package org.gdgu.swghosh.cse2016;

/**
 * Interface Wearable
 * directs method wear to
 * be implemented
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */
interface Wearable {
    void wear();
}

/**
 * Interface Cloth
 * directs methods setMaterial,
 * getMaterial to
 * be implemented
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */
interface Cloth {
    String getMaterial();
    void setMaterial(String material);
}

/**
 * Class Dress implements both
 * Wearable and cloth
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */
public class Dress implements Wearable, Cloth {
    private String material;
    Dress(String material) {
        this.material = material;
    }

    public void wear() {
        System.out.println("Sample implementation of implemented function wear().");
    }

    public void setMaterial(String material) {
        this.material = material;
    }
    public String getMaterial() {
        return this.material;
    }

    public static void main(String[] args) {
        Dress dress = new Dress("Cotton");
        dress.wear();
        dress.setMaterial("Velvet");
        System.out.println(dress.getMaterial());
    }
}
