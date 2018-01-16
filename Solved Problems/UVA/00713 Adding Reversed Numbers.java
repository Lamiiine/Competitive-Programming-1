import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    static BigInteger reverse(BigInteger a){
        BigInteger r = BigInteger.ZERO;
        while(!a.equals(BigInteger.ZERO))
        {
            r = r.multiply(BigInteger.valueOf(10));
            r = r.add(a.mod(BigInteger.valueOf(10)));
            a = a.divide(BigInteger.valueOf(10));
        }
        return r;
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for (int tc = 0; tc < TC; ++tc){
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            BigInteger Sum = reverse(a).add(reverse(b));
            System.out.println(reverse(Sum));
        }
    }    
}

