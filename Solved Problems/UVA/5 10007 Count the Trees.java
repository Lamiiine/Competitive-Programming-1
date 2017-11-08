import java.math.*;
import java.util.*;
import java.lang.*;
public class Main {
    static BigInteger fact(int i){
        return (i == 1) ? BigInteger.ONE
                : BigInteger.valueOf(i).multiply(fact(i-1));
    }
    static BigInteger cat(int i){
        return (i == 0) ? BigInteger.ONE :
                (BigInteger.valueOf(2*i*(2*i - 1)).multiply(cat(i - 1))).divide(BigInteger.valueOf(i*(i + 1)));
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if (n == 0) break;
            System.out.println(cat(n).multiply(fact(n)));
        }
    }
}

