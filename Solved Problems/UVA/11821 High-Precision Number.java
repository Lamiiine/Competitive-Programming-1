import java.math.*;
import java.util.*;
import java.lang.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        while(TC-- > 0){
            BigDecimal sum = BigDecimal.ZERO;
            while(true){
                BigDecimal tmp = sc.nextBigDecimal();
                if (tmp.equals(BigDecimal.ZERO)) break;
                sum = sum.add(tmp);
            }
            /* This representation always has a decimal point
            even if the value is an integer
            Sometimes, there are extra zeros at the tail */
            String ans = sum.toPlainString();
            while(ans.length() > 1 && ans.charAt(ans.length() - 1) == '0')
                ans = ans.substring(0, ans.length() - 1);
            if (ans.length() > 1 && ans.charAt(ans.length() - 1) == '.')
                ans = ans.substring(0, ans.length() - 1);
            System.out.println(ans);
        }
    }
}

