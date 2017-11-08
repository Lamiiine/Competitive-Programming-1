import java.math.*;
import java.util.*;
import java.lang.*;
public class Main {
    final static int MAX = 42;
    static long memo[] = new long[MAX];
    public static void init(){
        memo[0] = 1L;
        memo[1] = 1L;
        memo[2] = 5L;
        for (int i = 3; i < MAX; ++i)
            memo[i] = memo[i-1] + (memo[i-2] << 2) + (memo[i-3] << 1);
    }
    public static void main(String[] args) {
        init();
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        while(TC-- > 0)
            System.out.println(memo[sc.nextInt()]);
   }
}
