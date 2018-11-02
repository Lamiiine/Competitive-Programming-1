/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger a, p;
		while(true){
			p = sc.nextBigInteger();
			a = sc.nextBigInteger();
			if (a.equals(BigInteger.ZERO) && p.equals(BigInteger.ZERO))
				break;
			if (!p.isProbablePrime(10) && a.modPow(p, p).equals(a))
				System.out.println("yes");
			else
				System.out.println("no");
		}
		// your code goes here
	}
}