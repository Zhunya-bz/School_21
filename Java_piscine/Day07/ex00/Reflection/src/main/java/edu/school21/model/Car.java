package edu.school21.model;

import java.util.StringJoiner;

public class Car {
    private String model;
    private Long price;

    public Car() {
        this.model = "Default model";
        this.price = 0L;
    }

    public Car(String model, Long price) {
        this.model = model;
        this.price = price;
    }

    public Long priceWithDiscount(Long discount) {
        return (this.price * discount + this.price);
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", User.class.getSimpleName() + "[", "]")
                .add("model='" + model + "'")
                .add("price='" + price + "'")
                .toString();
    }
}
