// 1. Two Sum
// https://leetcode.com/problems/two-sum/
// Difficulty: Easy | Language: java
// Runtime: 45 ms
// Memory: 44.7 MB
// Solved: 2024-06-30

import java.util.Scanner;

public class Solution {

    // Method to find two indices in the array that add up to the target value
    public static int[] twoSum(int[] nums, int target) {
        // Iterate through each element in the array
        for (int i = 0; i < nums.length; i++) {
            // For each element, iterate through the subsequent elements
            for (int j = i + 1; j < nums.length; j++) {
                // Check if the sum of the current pair equals the target value
                if (nums[i] + nums[j] == target) {
                    // If a pair is found, return their indices
                    return new int[] { i, j };
                }
            }
        }
        // If no pair is found, throw an exception
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);

        // Prompt the user to enter the number of elements in the array
        System.out.print("Enter the number of elements in the array: ");
        int n = sc.nextInt();

        // Initialize the array with the given number of elements
        int[] nums = new int[n];

        // Prompt the user to enter the elements of the array
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Prompt the user to enter the target value
        System.out.print("Enter the target value: ");
        int target = sc.nextInt();

        // Try to find the indices of the two numbers that add up to the target
        try {
            int[] result = twoSum(nums, target);
            // If a pair is found, print their indices
            System.out.println("Indices: " + result[0] + ", " + result[1]);
        } catch (IllegalArgumentException e) {
            // If no pair is found, print the exception message
            System.out.println(e.getMessage());
        }

        // Close the Scanner object
        sc.close();
    }
}
