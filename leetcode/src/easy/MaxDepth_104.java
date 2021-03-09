package easy;

/**
 * leet #104
 * 
 * @author zongjing
 *
 */
public class MaxDepth_104 {
	public static void main(String[] args) {
		
	}
	
	//recursion
	public int maxDepth(TreeNode root) {
        if(root == null) {
        	return 0;
        }
        else {
        	return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
        }
    }
}
