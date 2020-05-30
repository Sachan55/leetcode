Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
https://leetcode.com/problems/missing-number/
Example 1:

Input: [3,0,1]
Output: 2


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1 ; i <=n ; i++)
        {
            ans = ans^i;
        }
        for(int j = 0 ; j < nums.size() ; j++)
        {
            ans = ans^nums[j];
        }
        return ans;
    }
};