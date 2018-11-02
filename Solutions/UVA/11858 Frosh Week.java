import java.util.*;
public class Main{
	static ArrayList<Integer> A = new ArrayList<Integer>();
	static ArrayList<Integer>tmp = new ArrayList<Integer>();
	static long InversionIndex;
	public static void sort(int l, int r){
		if (l == r) return;
		int m = (l + r) >> 1;
		sort(l, m); sort(m + 1, r);
		int i = l, j = m + 1;
		while(i <= m && j <= r)
			if (A.get(i) <= A.get(j))
				tmp.add(A.get(i++));
			else {tmp.add(A.get(j++)); InversionIndex += (m + 1 - i);}
		while(i <= m)
			tmp.add(A.get(i++));
		while(j <= r)
			tmp.add(A.get(j++));
		for (int k = 0; k < tmp.size(); ++k)
			A.set(k + l, tmp.get(k));
		tmp.clear();
	}
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			A.clear(); InversionIndex = 0L;
			for (int i = 0; i < n; ++i)
				A.add(sc.nextInt());
			sort(0, n - 1);
			System.out.println(InversionIndex);
		}
		sc.close();
	}
}

