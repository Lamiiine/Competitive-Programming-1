import java.util.*;

public class Main
{
	public static boolean valid(char a)
	{
		return Character.isAlphabetic(a) || (a == '-');
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String ans = "";
		boolean flag = true;
		while(sc.hasNext() && flag)
		{
			String line = sc.nextLine();
			ArrayList<String> A = new ArrayList<String>();
			for (int i = 0; i < line.length();)
			{
				char c = line.charAt(i);
				if (!valid(c)) {++i; continue;}
				int j = i + 1;
				while(j < line.length() && valid(line.charAt(j))) ++j;
				A.add(line.substring(i, j));
				i = j;
			}
			for (String a : A)
			{
				if (a.equals("E-N-D"))
				{
					flag = false;
					break;
				}
				
				if (a.length() > ans.length())
					ans = a;
			}
		}
		System.out.println(ans.toLowerCase());
		sc.close();
	}
}

