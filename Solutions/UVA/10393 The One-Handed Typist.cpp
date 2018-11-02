package Main;

import java.math.*;
import java.util.*;

import javax.xml.crypto.AlgorithmMethod;

import java.io.*;
public class Main {
	static String [] word = new String[1005];
	static String [] finger = new String[11];
	static boolean use [] = new boolean[128];	// is this character usable?
	static void init_finger(){
		finger[1] = "qaz";
		finger[2] = "wsx";
		finger[3] = "edc";
		finger[4] = "rfvtgb";
		finger[5] = " ";
		finger[6] = " ";
		finger[7] = "yhnujm";
		finger[8] = "ik,";
		finger[9] = "ol.";
		finger[10] = "p;/";
	}
	static boolean can(String s){
		for (int i = 0; i < s.length(); ++i)
			if (!use[s.charAt(i)]) return false;
		return true;
	}
	static void init_use(){
		for (int i = 0; i < 128; ++i)
			use[i] = true;
	}
	public static void main(String [] args){
		init_finger();
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int f = sc.nextInt();
			int w = sc.nextInt();
			init_use();
			while(f--> 0) {
				int F = sc.nextInt();
				for (int i = 0; i < finger[F].length(); ++i)
					use[finger[F].charAt(i)] = false;
			}
			sc.nextLine();
			int ans = 0;
			for (int i = 0; i < w; ++i)
				if (can(word[i] = sc.nextLine()))
					ans = Math.max(ans, word[i].length());
			ArrayList<String> v = new ArrayList<String>();
			for (int i = 0; i < w; ++i)
				if (word[i].length() == ans && can(word[i]))
					v.add(word[i]);
			int counter = v.isEmpty() ? 0 : 1;
			Collections.sort(v);
			for (int i = 1; i < v.size(); ++i)
				if (!v.get(i).equals(v.get(i-1))) ++counter;
			System.out.println(counter);
			if (counter != 0) System.out.println(v.get(0));
			for (int i = 1; i < v.size(); ++i)
				if (!v.get(i).equals(v.get(i-1)))
					System.out.println(v.get(i));
		}
	}
}

