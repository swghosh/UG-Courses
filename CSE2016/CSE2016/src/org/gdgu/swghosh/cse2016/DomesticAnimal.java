package org.gdgu.swghosh.cse2016;

public class DomesticAnimal extends Animal {
    private String domesticPurpose;

    public DomesticAnimal() {
        System.out.println("Creation of new domestic animal...");
    }

    public String getDomesticPurpose() {
        return this.domesticPurpose;
    }
    public void setDomesticPurpose(String domesticPurpose) {
        this.domesticPurpose = domesticPurpose;
    }

    public void serveDomesticPurpose() {
        System.out.println("This domestic animal serves with " + this.domesticPurpose + ".");
    }
}
