package org.gdgu.swghosh.cse2016;

/**
 * Domestic Animal inherits Animal,
 * mimics inherited properties viz.
 * age, weight and in additional
 * domesticPurpose property
 *
 * @author Swarup Ghosh
 * @since 2018-08-23
 * @version 1.0
 */
public class DomesticAnimal extends Animal {
    /*
     * Properties of domestic animal
     */
    private String domesticPurpose;

    /**
     * Initialise a Domestic Animal object
     */
    public DomesticAnimal() {
        System.out.println("Creation of new domestic animal...");
    }

    /**
     * Domestic Purpose Getter Method
     * @return domestic purpose of the animal
     */
    public String getDomesticPurpose() {
        return this.domesticPurpose;
    }
    /**
     * Domestic Purpose Setter Method
     * @param domesticPurpose
     */
    public void setDomesticPurpose(String domesticPurpose) {
        this.domesticPurpose = domesticPurpose;
    }

    /**
     * Prints a sample message about the
     * domestic purpose of the animal
     */
    public void serveDomesticPurpose() {
        System.out.println("This domestic animal serves with " + this.domesticPurpose + ".");
    }
}
