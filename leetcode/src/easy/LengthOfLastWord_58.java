package easy;

/**
 * leet code problem#58
 * 
 * Given a string s consists of some words separated by spaces, return the length of the last word in the string.
 * If the last word does not exist, return 0.
 * A word is a maximal substring consisting of non-space characters only.
 * 
 * @author zongjing
 *
 */
public class LengthOfLastWord_58 {
	public static void main(String[] args) {
		String s1 = "Hello World";
		String s2 = "";
		System.out.println(solution1(s1));
		System.out.println(solution1(s2));
	}
	
	/*
	 * First answer: uses the strip() and split() method
	 */
	public static int solution1(String s) {
		s = s.strip();	// in case the string contains only spaces
		if(s.length() == 0) {
			return 0;
		}
		else {
			String[]list = s.split(" ");
			return list[list.length - 1].length();
		}
	}
	
	/*
	 * Use the charAt() method only.
	 */
	public static int solution2(String s) {
		if(s == null){
            return 0;
        }
        int count = 0;
        int i = s.length() - 1;
        while(i >= 0 && s.charAt(i) == ' '){
            i--;
        }
        while(i >= 0 && s.charAt(i) != ' '){
            i--;
            count++;
        }
        return count;
	}
}
