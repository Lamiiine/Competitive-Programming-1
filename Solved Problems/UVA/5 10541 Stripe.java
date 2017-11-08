import java.math.*;
import java.util.*;
import java.lang.*;
public class Main {
    static final int MAX = 205;
    static BigInteger memo[][];
    static BigInteger f(int n, int m){
	/* number of ways of assigning n identical elements to m people */
        if (!memo[n][m].equals(BigInteger.valueOf(-1)))
            return memo[n][m];
        if (m == 1) return memo[n][m] = BigInteger.ONE;
        BigInteger ans = BigInteger.ZERO;
        for (int i = 0; i <= n; ++i)
            ans = ans.add(f(n-i, m-1));
        return memo[n][m] = ans;
    }
    public static void init(){
        memo = new BigInteger[MAX][MAX];
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                memo[i][j] = BigInteger.valueOf(-1);
    }
    public static void main(String[] args) {
        init();
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        while(TC-- > 0){
            int N = sc.nextInt();
            int K = sc.nextInt();
            int L = 0;
            for (int x, i = 0; i < K; ++i)
            {x = sc.nextInt(); L += x;}
            int F = N - L;  // free squares
            int dist = F - (K - 1);
            if (dist < 0) System.out.println(0);
            else System.out.println(f(dist, K + 1));
        }
    }
}
