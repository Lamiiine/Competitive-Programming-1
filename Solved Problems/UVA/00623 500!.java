import java.util.Scanner;
import java.math.BigInteger;
import java.math.*;
import java.lang.Integer;
public class Main {
    static final int max = 1010;
    static BigInteger memo[] = new BigInteger[max];
    static void init(){
        memo[0] = BigInteger.ONE;
        for (int i = 1; i <= 1000; ++i)
            memo[i] = memo[i-1].multiply(BigInteger.valueOf(i));
    }
    static int counter[] = new int[10];
    public static void main(String[] args) {
        init();
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int x = sc.nextInt();
            System.out.print(x + "!\n" + memo[x] + "\n");
        }
    }
}

