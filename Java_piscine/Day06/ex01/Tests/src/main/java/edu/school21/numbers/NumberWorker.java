package edu.school21.numbers;

public class NumberWorker {

    public int digitsSum(int number) {
        int sum = 0;
        while (number != 0)
        {
            sum += number % 10;
            number = number / 10;
        }
        return (sum);
    }

    public boolean isPrime(int number) {
        int i = 2;
        for (i = 2; i * i <= number ; i++)
        {
            if (number % i == 0)
                break;
        }
        if (number <= 1) {
            throw new  IllegalNumberException("IllegalArgument");
        }
        if (i * i > number || number == 2 || number == 3)
            return (true);
        return (false);
    }

}


