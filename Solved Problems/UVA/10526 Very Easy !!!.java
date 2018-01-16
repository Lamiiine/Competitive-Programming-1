import java.util.Scanner;
import java.math.BigInteger;
import java.math.*;
import java.lang.Integer;
public class Main {
    static public BigInteger compute(BigInteger a, int n){
        BigInteger ans = BigInteger.ZERO;
        BigInteger power = a;
        for (int i = 1; i <= n; ++i){
            ans = ans.add(BigInteger.valueOf(i).multiply(power));
            power = power.multiply(a);
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt(), a = sc.nextInt();
            System.out.println(compute(BigInteger.valueOf(a), n));
        }
    }
}

