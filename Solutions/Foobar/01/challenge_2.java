import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			String n = sc.nextLine();
			int b = sc.nextInt(); sc.nextLine();
			System.out.println(answer(n, b));
		}
	}
	
	public static int answer(String n, int b)
	{
		int k = n.length();
		HashMap<String, Integer> seen = new HashMap<String, Integer>();
		int time = 0;
		seen.put(n, time);
		char[] xx = new char[k];
		char[] yy = new char[k];
		char[] zz = new char[k];
		while(true)
		{
			++time;
			for (int i = 0; i < k; ++i)
			{
				xx[i] = n.charAt(i);
			}
			Arrays.sort(xx);
			for (int i = 0; i < k; ++i)
			{
				yy[i] = xx[k - 1 - i];
			}
			
			n = (new BigInteger(xx.toString(), b)).subtract(new BigInteger(yy.toString(), b)).toString(b);
			int l = 0;
			for (;l < k - n.length(); ++l)
			{
				zz[l] = '0';
			}
			for (int i = 0; i < n.length(); ++i)
			{
				zz[l++] = n.charAt(i);
			}
			n = zz.toString();
			if (seen.containsKey(n))
			{
				return time - seen.get(n);
			}
			seen.put(n, time);
		}
	}
}
