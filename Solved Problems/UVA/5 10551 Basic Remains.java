import java.util.Scanner;
import java.math.BigInteger;
import java.math.*;
import java.lang.Integer;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int b = sc.nextInt();
            if (b == 0) break;
            BigInteger p = sc.nextBigInteger(b);
            BigInteger m = sc.nextBigInteger(b);
            System.out.println(p.mod(m).toString(b));
        }
    }
}

