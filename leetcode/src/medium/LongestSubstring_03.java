package medium;

import java.util.ArrayList;

/**
 * leet #3
 * Given a string s, find the length of the longest substring without repeating characters.
 * @author zongjing
 *
 */
public class LongestSubstring_03 {
	public static void main(String[] args) {
		String s1 = "bbbbbb";
		String s2 = "";
		String s3 = "a";
		String s4 = "asdfghjkl";
		String s5 = "abcabcbb";
		
		System.out.println(lengthOfLongestSubstring(s5));
	}
	
	// Too slow
	public static int lengthOfLongestSubstring(String s) {
		if(s == null || s.isEmpty()) {
			return 0;
		}
        int head = 0;
        int tail = 0;
        int maxLen = 1;
        ArrayList<Character> dic = new ArrayList<Character>();
        while(head < s.length()) {
        	if(dic.contains(s.charAt(head))) {
        		tail = tail + s.substring(tail, head).indexOf(s.charAt(head)) + 1;
        		dic.clear();
        		for(int i = tail; i <= head; i++) {
        			dic.add(s.charAt(i));
        		}
        		
        	}
        	else {
        		if((head - tail + 1) > maxLen){
        			maxLen = head - tail + 1;
        		}
        		
        		dic.add(s.charAt(head));       		       		
        	}
        	head++; 
        }
        
        return maxLen;        
    }
	
	//author: EdickCoding
	public int solution2(String s) {
        int result = 0;
        int[] cache = new int[256];
        for (int i = 0, j = 0; i < s.length(); i++) {
            j = (cache[s.charAt(i)] > 0) ? Math.max(j, cache[s.charAt(i)]) : j;
//            if(cache[s.charAt(i)] > 0) {
//            	j = Math.max(j, cache[s.charAt(i)]);	// move j to the index of duplicated char (+1). If it existed previous than j, ignore it.            	
//            }            
            
            
            cache[s.charAt(i)] = i + 1;
            result = Math.max(result, i - j + 1);
        }
        return result;
    }
	
}
