import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
	private boolean[] cells;
	private int numOpen;
	private final int n;
	private final WeightedQuickUnionUF union;
	
	public Percolation(int n) {
		if (n < 1) {
			throw new IllegalArgumentException();
		}
		this.n = n;
		cells = new boolean[n*n];
		numOpen = 0;
		union = new WeightedQuickUnionUF(n * n);
	}
	
	public void open(int row, int col) {
		if (row < 1 || col < 1 || row > n || col > n) {
			throw new IllegalArgumentException();
		}
		if(!this.isOpen(row, col)) {
			int i = (row - 1) * n + (col - 1);
			cells[i] = true;	
			numOpen++;
			if (col != n && isOpen(row, col + 1)) {
				union.union(i, i + 1);
			}
			if (col != 1 && isOpen(row, col - 1)) {
				union.union(i, i - 1);
			}
			if (row != n && isOpen(row + 1, col)) {
				union.union(i, i + n);
			}
			if (row != 1 && isOpen(row - 1, col)) {
				union.union(i, i - n);
			}
		}
	}
	
	public boolean isOpen(int row, int col) {
		if (row < 1 || col < 1 || row > n || col > n) {
			throw new IllegalArgumentException();
		}
		int i = (row - 1) * n + (col - 1);
		return cells[i];
	}
	
	public boolean isFull(int row, int col) {
		if (row < 1 || col < 1 || row > n || col > n) {
			throw new IllegalArgumentException();
		}
		int i = (row - 1) * n + (col - 1);
		if (this.isOpen(row, col)) {
			int fCol = 1;			
			for (; fCol <= n; fCol++) {
				if(this.isOpen(1, fCol)){
					if(union.find(i) == union.find(fCol - 1)) {
						return true;
					}
					while(fCol <= n - 1 && this.isOpen(1, fCol + 1)) {
						fCol++;
					}
				}				
			}			
		}
		return false;
	}
	
	public int numberOfOpenSites() {
		return numOpen;
	}
	
	public boolean percolates() {
		int col = 1;
		for (; col <= n; col++) {
			if(this.isOpen(n, col)) {
				if (this.isFull(n, col)) {
					return true;
				}
				else {
					if (col <= n - 1 && this.isOpen(n, col + 1)) {
						col++;
					}
				}
			}
		}
		return false;
	}
	

}
