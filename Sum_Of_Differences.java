/*--------------------------------------------------------------------------------------------------------------------------------------
Problem Statement:
Given an array of all positive elements, pick sequence of pairs in order to maximize the sum of differences of each pair.

Rules:
•	Difference of pair = value at higher index – value at lower index
•	You cannot pick element previous to the one picked last. That means you can only move forward in the array to make suitable pairs, 
but no looking back!

Input: 
[10,4,5,20,30,20,15,10,80,79]
Output: 
96
--------------------------------------------------------------------------------------------------------------------------------------*/

public class Sum_Of_Differences {
	public int Max_Sum_Of_Differences(int arr[]){
		int length = arr.length;
		int i =0;
		int sum = 0;
		while(i<length){
			int k = i+1;
			if(k<length && arr[i]<arr[k] ){
				int j = i+1;
				while(j<length && j+1<length  && arr[j]>=arr[j-1] && arr[j]<=arr[j+1])
					j++;
				sum += arr[j]-arr[i];
				i = j+1;
			}
			else
				i++;
		}
		return sum;
	}
	public static void main(String args[]){
		Sum_Of_Differences obj = new Sum_Of_Differences();
		int arr[] = {10,4,5,20,30,20,15,10,79,80};
        System.out.println(obj.Max_Sum_Of_Differences(arr));
    }
}
