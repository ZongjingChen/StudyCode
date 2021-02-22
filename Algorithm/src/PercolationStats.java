import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
	private final int trials;
	private final double[] thresholds;
	private static final double CONFIDENCE_95 = 1.96;
    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
    	if (n <= 0 || trials <= 0) {
    		throw new IllegalArgumentException();
    	}
    	this.trials = trials;
    	thresholds = new double[trials];
    	for (int i = 0; i< trials; i++) { 
    		Percolation p = new Percolation(n);
    		while(!p.percolates()) {
    			int row = StdRandom.uniform(n) + 1;
	        	int col = StdRandom.uniform(n) + 1;	        	
	    		p.open(row, col);
    		}
			thresholds[i] = p.numberOfOpenSites() / (n * n *1.0);	
			
    	}
    }

    // sample mean of percolation threshold
    public double mean() {
    	return StdStats.mean(thresholds);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
    	return StdStats.stddev(thresholds);
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
    	return this.mean() - CONFIDENCE_95 * (this.stddev() / Math.sqrt(trials));
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
    	return this.mean() + CONFIDENCE_95 * (this.stddev() / Math.sqrt(trials));
    }

   // test client (see below)
   public static void main(String[] args) {
	   PercolationStats p = new PercolationStats(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
	   System.out.println("mean = " + p.mean());
	   System.out.println("stddev = " + p.stddev());
	   System.out.println("95% confidence interval = [" + p.confidenceLo() + ", " + p.confidenceHi() + "]");
   }

}