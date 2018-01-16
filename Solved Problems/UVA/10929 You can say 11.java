import java.math.*;
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			String s = sc.nextLine().trim();
			BigInteger x = new BigInteger(s);
			if (x.equals(BigInteger.ZERO))
			{
				break;
			}
			
			System.out.println(s + " is " + (x.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO) ? "" : "not ") + "a multiple of 11.");
		}
	}
}

