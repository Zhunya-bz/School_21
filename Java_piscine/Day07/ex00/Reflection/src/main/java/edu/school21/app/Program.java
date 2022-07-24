package edu.school21.app;

import edu.school21.model.Car;
import edu.school21.model.User;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.TypeVariable;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Class<User> userClass = User.class;
        Class<Car> carClass = Car.class;

        System.out.println("Classes:\n" + userClass.getSimpleName() + "\n" + carClass.getSimpleName());
        System.out.println("------------------");
        System.out.print("Enter class name:\n-> ");
        String name = sc.next();
        Class whichCLass;
        if (name.equals(userClass.getSimpleName()))
            whichCLass = userClass;
        else if (name.equals(carClass.getSimpleName()))
            whichCLass = carClass;
        else
            throw new RuntimeException("Not valid name class!");
        Field [] fields = whichCLass.getDeclaredFields();
        System.out.println("fields:");
        for (int i = 0; i < fields.length; i++) {
            System.out.println("    " + fields[i].getType() + " " + fields[i].getName());
        }
        Method [] methods = whichCLass.getDeclaredMethods();
        System.out.println("methods:");
        for (int i = 0; i < methods.length; i++) {
            TypeVariable<Method> [] typeParam = methods[i].getTypeParameters();

            System.out.print("    " + methods[i].getReturnType() + " " + methods[i].getName() + " (");
            for (int j = 0; j < typeParam.length - 1; j++) {
                System.out.print(typeParam[j] + ", ");
            }
            System.out.println(typeParam[typeParam.length - 1] + ")");
        }
        System.out.println("------------------");

    }
}
