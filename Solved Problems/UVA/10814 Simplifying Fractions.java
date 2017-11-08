import java.util.Scanner;
import java.math.BigInteger;
import java.math.*;
import java.lang.Integer;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        while(TC-- > 0){
            BigInteger a = sc.nextBigInteger();
            sc.skip(" / ");
            BigInteger b = sc.nextBigInteger();
            BigInteger c = a.gcd(b);
            a = a.divide(c);
            b = b.divide(c);
            System.out.println(a.toString() + " / " + b.toString());
        }
    }
}

