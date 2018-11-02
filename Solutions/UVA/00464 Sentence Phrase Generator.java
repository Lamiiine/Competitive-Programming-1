import java.util.*;

public class Main
{
	public static int counter = 1;
	public static String gen_sentence()
	{
		if (counter++ % 2 == 0)
		return gen_trans_sentence();
		else return gen_intrans_sentence();
	}
	public static String gen_trans_sentence(){
		String ans =gen_subject() + " ";
		ans += gen_verb_phrase() + " ";
		ans += gen_object() + " ";
		ans += gen_prep_phrase();
		return ans;
	}
	public static String gen_intrans_sentence(){
		String ans = gen_subject() + " ";
		ans += gen_intrans_verb_phrase() + " ";
		ans += gen_prep_phrase();
		return ans;
	}
	public static String gen_subject() {
		return gen_noun_phrase();
	}
	public static String gen_object() {
		return gen_noun_phrase();
	}
	public static String gen_noun_phrase(){
		String ans = gen_article() + " ";
		return ans + gen_modified_noun();
	}
	public static String gen_modified_noun(){
		if (counter++ % 2 == 0)
		return gen_noun();
		else return gen_modifier() + " " + gen_noun();
	}
	public static String gen_modifier(){
		if (counter++ % 2 == 0)
		return gen_adjective();
		else return gen_adverb() + " " + gen_adjective();
	}
	public static String gen_verb_phrase(){
		if (counter++ % 2 == 0)
		return gen_trans_verb();
		else
		return gen_adverb() + " " + gen_trans_verb();
	}
	public static String gen_intrans_verb_phrase(){
		if (counter++ % 2 == 0)
		return gen_intrans_verb();
		else return gen_adverb() + " " + gen_intrans_verb();
	}
	public static String gen_prep_phrase(){
		if (counter++ % 2 == 0)
			return gen_preposition() + " " + gen_noun_phrase();
		else
		return gen_empty();
	}
	public static String[] noun = {"man",  "dog",  "fish", "computer", "waves"};
	public static String[] trans_verb = {"struck", "saw", "bit", "took"};
	public static String[] intrans_verb = { "slept", "jumped", "walked", "swam"};
	public static String[] article = {"the", "a"};
	public static String[] adjective = { "green", "small", "rabid", "quick"};
	public static String[] adverb = {"nearly", "suddenly", "restlessly"};
	public static String[] preposition = {"on", "over", "through"};
	public static String gen_noun(){
		return noun[counter++ % noun.length];
	}
	public static String gen_trans_verb(){
		return trans_verb[counter++ % trans_verb.length];
	}
	public static String gen_intrans_verb(){
		return intrans_verb[counter++ % intrans_verb.length];
	}
	public static String gen_article(){
		return article[counter++ % article.length];
	}
	public static String gen_adjective(){
		return adjective[counter++ % adjective.length];
	}
	public static String gen_adverb(){
		return adverb[counter++ % adverb.length];
	}
	public static String gen_preposition(){
		return preposition[counter++ % preposition.length];
	}
	public static String gen_empty()
	{
		return "";
	}
	public static String normalize(String line)
	{
		StringBuilder ans = new StringBuilder();
		for (int i = 0; i < line.length();)
			if (line.charAt(i) == ' ')
			{
				ans.append(' ');
				++i;
				while(i < line.length() && line.charAt(i) == ' ') ++i;
			}
			else ans.append(line.charAt(i++));
		if (ans.length() > 0 && ans.charAt(ans.length() - 1) == ' ') return ans.substring(0, ans.length() - 1);
		else return ans.toString();
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			String line = sc.nextLine();
			switch(line)
			{
			case "sentence" : line = gen_sentence(); break;
			case "trans-sentence" : line = gen_trans_sentence(); break;
			case "intrans-sentence" : line = gen_intrans_sentence(); break;
			case "subject" : line = gen_subject(); break;
			case "object" : line = gen_object(); break;
			case "noun-phrase" : line = gen_noun_phrase(); break;
			case "modified-noun" : line = gen_modified_noun(); break;
			case "modifier" : line = gen_modifier(); break;
			case "verb-phrase" : line = gen_verb_phrase(); break;
			case "intrans-verb-phrase" : line = gen_intrans_verb_phrase(); break;
			case "prep-phrase" : line = gen_prep_phrase(); break;
			case "noun" : line = gen_noun(); break;
			case "trans-verb" : line = gen_trans_verb(); break;
			case "intrans-verb" : line = gen_intrans_verb(); break;
			case "article" : line = gen_article(); break;
			case "adjective" : line = gen_adjective(); break;
			case "adverb" : line = gen_adverb(); break;
			case "preposition" : line = gen_preposition(); break;
			case "empty" : line = gen_empty(); break;
			}
			
			System.out.println(normalize(line));
		}
	}
}
/*
sentence
noun
sentence
*/
