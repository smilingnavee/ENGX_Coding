/*
Genome Chain

Given an array of size <=1,00,000 and a positive integer N, generate N-sized continuous sub-arrays from the input array. 
Genome Chain is a group of numbers, so that each one of them (distinct) is present as the least number from the continuous sub-arrays till it disappears in the subsequent sub-arrays.
Your output should be the minimum sum of these group of numbers.

Example
                Input Array:
                                inputArray: [3,6,1,8,9,3,9,5,7,1,4]
                                N:                  5

All Possible Sub Arrays of length N:
                                [3,6,1,8,9], [6,1,8,9,3], [1,8,9,3,9], [8,9,3,9,5], [9,3,9,5,7],[3,9,5,7,1], [9,5,7,1,4]

Output: Genome Chain = [1,3,1]  sum = 5
The same 1 is available in first 3 sub-arrays and the same 3 is available in next 3 sub-arrays. Note that in the second last sub-array in the example, you cannot choose 1 because 3 was already chosen from the previous sub-arrays. But in the last sub-array, it disappears and now you can choose the next least number, that is, 1.
Minimum Sum here is 1+3+1 = 5.

*/
public class Genome_Chain {
	private int find_sum(){
		int input[]= {3,6,1,8,9,3,9,5,7,1,4};
		int sum = 0;
		int prev_min = -1;
		for(int i = 0; i<input.length-5+1;i++){
						
			if (prev_min != -1 && prev_min == input[i+0] || prev_min ==input[i+1] ||prev_min ==input[i+2] ||prev_min ==input[i+3] ||prev_min ==input[i+4] ) {
				continue;
			}
			
			int this_min = input[i+0];
			if (this_min>input[i+1])
				this_min= input[i+1];
			if (this_min>input[i+2])
				this_min= input[i+2];
			if (this_min>input[i+3])
				this_min= input[i+3];
			if (this_min>input[i+4])
				this_min= input[i+4];
			
			if (prev_min == -1) {
				prev_min = this_min;
				sum = this_min;
			} else {
				prev_min = this_min;
				sum = sum+this_min;
			}		 		
		}
		return sum;
	}
	public static void main(String args[]){
		Genome_Chain cc = new Genome_Chain();
        System.out.println(cc.find_sum());
    }
}
