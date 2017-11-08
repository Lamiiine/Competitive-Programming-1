package main;
import java.util.Scanner;
import java.math.BigInteger;
import java.math.*;
import java.lang.Integer;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a;
        while(true){
            a = sc.nextBigInteger();
            if (a.compareTo(BigInteger.ZERO) == 0) break;
            if (a.mod(BigInteger.valueOf(17)) == BigInteger.ZERO) System.out.println(1);
            else System.out.println(0);
        }
    }
}

