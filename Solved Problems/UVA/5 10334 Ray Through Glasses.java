import java.math.*;
import java.util.*;
import java.lang.*;
public class Main {
    static final int MAX = 1005;
    static BigInteger memo[];
    public static void init(){
        memo = new BigInteger[MAX];
        memo[0] = BigInteger.ONE;
        memo[1] = BigInteger.valueOf(2);
        for (int i = 2; i < MAX; ++i)
            memo[i] = memo[i-1].add(memo[i-2]);
    }
    public static void main(String[] args) {
        init();
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext())
            System.out.println(memo[sc.nextInt()]);
    }
}
