package traingle_sum;

/*
Maximumtriangle path sum
	3		3		 3		  23
       7 4	      7   4	      20   19           20   19
      2 4 6 	=>  10 13 15   =>   10  13   15  =>   10  13   15  => 23 is Answer
     8 5 9 3	   8  5  9  3     8    5   9   3    8    5   9   3
*/

	import java.nio.file.*;
	import static java.util.Arrays.stream;
	 
	public class Traingle_sum {
	 
	    public static void main(String[] args) throws Exception {
	        int[][] data = Files.lines(Paths.get("input.txt"))
	                .map(s -> stream(s.trim().split("\\s+"))
	                        .mapToInt(Integer::parseInt)
	                        .toArray())
	                .toArray(int[][]::new);
	 
	        for (int r = data.length - 1; r > 0; r--) {
	            for (int c = 0; c < data[r].length - 1; c++) 
	                data[r - 1][c] += Math.max(data[r][c], data[r][c + 1]);
	        System.out.println(data[0][0]);
	    }
	}
