import java.math.*;
import java.util.*;
import java.lang.*;
public class Main
{
    public static final String SignedInteger = "(\\+|-)?\\d+";
    public static final String Fraction = SignedInteger + "\\.\\d+";
    public static final String Exponential = "((" + SignedInteger + ")|(" + Fraction + "))(e|E)" + SignedInteger;
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            String s = sc.nextLine();
            if (s.equals("*"))
            {
                break;
            }
            s = s.trim();
            
            System.out.println(s + (s.matches(Fraction) || s.matches(Exponential) ? " is legal." : " is illegal."));
        }
    }
}

