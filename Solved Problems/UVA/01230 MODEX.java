import java.util.Scanner;
import java.math.BigInteger;
import java.math.*;
import java.lang.Integer;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        while(TC-- > 0){
            BigInteger x = sc.nextBigInteger();
            BigInteger y = sc.nextBigInteger();
            BigInteger n = sc.nextBigInteger();
            System.out.println(x.modPow(y, n));
        }
    }
}

