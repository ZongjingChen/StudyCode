package easy;


/**
 * leet #88
 * 
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * The number of elements initialized in nums1 and nums2 are m and n respectively. 
 * You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
 * 
 * @author zongjing
 *
 */
public class MergeSortedArray_88 {
	public static void main(String[] args) {
		int[] nums1 = new int[] {1,2,3};
		int[] nums2 = new int[] {};
		int m = 3;
		int n = nums2.length;
		merge(nums1, m, nums2, n);
		for(int i = 0; i< nums1.length; i++) {
			System.out.println(nums1[i]);
		}
	}
	
	public static void merge(int[] nums1, int m, int[] nums2, int n) {
		int[] result = new int[m + n];
    	int i = 0;
    	int j = 0;
    	while(i < m || j < n) {
    		if(i == m) {
    			result[i + j] = nums2[j];
    			j++;
    		}
    		else if(j == n) {
    			result[i + j] = nums1[i];
    			i++;
    		}
    		else {
        		int n1 = nums1[i];
        		int n2 = nums2[j];
        		if(n1 < n2) {
        			result[i + j] = n1;        			
        			i++;
        		}
        		else {
        			result[i + j] = n2;
        			j++;
        		}
    		}
    	}        	
        
        for(int k = 0; k < m + n; k++) {
        	nums1[k]= result[k]; 
        }
    }
}	
