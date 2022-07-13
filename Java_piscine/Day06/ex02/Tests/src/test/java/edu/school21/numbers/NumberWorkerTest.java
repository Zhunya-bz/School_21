package edu.school21.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvFileSource;
import org.junit.jupiter.params.provider.ValueSource;

public class NumberWorkerTest {
    private NumberWorker nw;

    @BeforeEach
    void beforeEachFunction() {
        nw = new NumberWorker();
    }

    @Test
    void check() {
        Assertions.assertTrue(true);
    }

    @ParameterizedTest
    @ValueSource(ints = { 2, 3, 11 })
    void isPrimeForPrimes(int num) {
        Assertions.assertTrue(nw.isPrime(num));
    }

    @ParameterizedTest
    @ValueSource(ints = { 6, 100, 4545 })
    void isPrimeForNotPrimes(int num) {
        Assertions.assertFalse(nw.isPrime(num));
    }

    @ParameterizedTest
    @ValueSource(ints = { 1, 0, -1, -7 })
    void isPrimeForIncorrectNumbers(int num) {
        Assertions.assertThrows(IllegalNumberException.class, () -> nw.isPrime(num));
    }

    @ParameterizedTest
    @CsvFileSource(resources = "/data.csv")
    void checkDigitSum(int number, int sum) {
        Assertions.assertEquals(sum, nw.digitsSum(number));
    }

}
