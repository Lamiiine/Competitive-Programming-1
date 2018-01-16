import java.math.*;
import java.util.*;
import java.lang.*;
public class Main {
    static final int MAX = 50;
    static final int arr_size = 1000;
    static HashMap<Integer, Integer>m = new HashMap<Integer, Integer>();
    static char arr[] = new char[arr_size];
    static int x[] = new int[arr_size];
    static void init_fib(){
        int fib[] = new int[MAX];
        fib[0] = 1; fib[1] = 2;
        for (int i = 2; i < MAX; ++i)
            fib[i] = fib[i - 1] + fib[i - 2];
        for (int i = 0; i < MAX; ++i)
            m.put(fib[i], i);
    }
    static void init_arr(){
        for (int i = 0; i < arr_size; ++i)
            arr[i] = ' ';
    }
    static String upper_case_only(String a){
        String ans = new String("");
        for (int i = 0; i < a.length(); ++i)
            if (Character.isUpperCase(a.charAt(i)))
                ans = ans + a.charAt(i);
        return ans;
    }
    public static void main(String[] args) {
        init_fib();
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        while(TC-- > 0){
            int n = sc.nextInt();
            for (int i = 0; i < n; ++i)
                x[i] = sc.nextInt();
            sc.nextLine();
            String s = upper_case_only(sc.nextLine());
            init_arr();
            for (int i = 0, j = 0; i < n; ++i)
                arr[m.get(x[i])] = s.charAt(j++);
            String ans = new String(arr);
            while(!Character.isUpperCase(ans.charAt(ans.length() - 1)))
                ans = ans.substring(0, ans.length() - 1);
            System.out.println(ans);
        }
    }
}

