import java.math.*;
import java.util.*;
import java.lang.*;

public class Main
{
    /* matching against a regular expression,
     * notice that making all spaces optional
     * would cause a sentence like "MynameisAhmed" to be valid!
     */
    public static final String space = "\\s+";
    public static final String verb = "((hate|love|know|like)s*)";
    public static final String noun = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
    public static final String article = "(a|the)";
    public static final String actor = "((" + article + space + ")?" + noun + ")";
    public static final String active_list = "(" + actor + "(" + space + "and" + space + actor + ")*)";
    public static final String action = "(" + active_list + space + verb + space + active_list + ")";
    public static final String statement = action + "(" + space + "," + space + action + ")*";
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext())
        {
            String s = sc.nextLine();
            System.out.println(s.matches(statement) ? "YES I WILL" : "NO I WON'T");
        }
    }
}

