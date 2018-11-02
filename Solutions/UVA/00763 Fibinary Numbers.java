import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    static final int MAX = 150;
    static BigInteger memo[] = new BigInteger[MAX];
    static boolean taken[] = new boolean[MAX];
    static void init()
    {
        for (int i = 0; i < MAX; ++i)
            taken[i] = false;
        memo[0] = BigInteger.ONE;
        memo[1] = BigInteger.valueOf(2);
        for (int i = 2; i < MAX; ++i)
            memo[i] = memo[i-1].add(memo[i-2]);
    }
    static BigInteger parse(BigInteger a){
        BigInteger ans = BigInteger.ZERO;
        int counter = 0;
        while(!a.equals(BigInteger.ZERO)){
            // if it is not a zero
            if (!a.mod(BigInteger.TEN).equals(BigInteger.ZERO))
                ans = ans.add(memo[counter]);
            ++counter;
            a = a.divide(BigInteger.TEN);
        }
        return ans;
    }
    static void solve(BigInteger a){
        for (int i = MAX - 1; i >= 0; --i){
            if (a.compareTo(memo[i]) >= 0) {
                taken[i] = true;
                a = a.subtract(memo[i]);
            }
        }
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        boolean first = true;
        while(sc.hasNext()){
            init();
            if (!first) System.out.println("");
            first = false;
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            BigInteger sum = parse(a).add(parse(b));
            solve(sum);
            int i = MAX - 1;
            // DON'T ASSUME THAT THE INPUT WILL ALWAYS BE POSITIVE!
            while(i >= 0 && !taken[i])--i;
            if (i < 0) System.out.print("0");
            else
            for (; i >= 0; --i)
                if (taken[i])System.out.print("1");
                else System.out.print("0");
            System.out.println("");
        }
    }    
}

