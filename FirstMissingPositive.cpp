Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2


o(n) time and o(1) complexity.
use array as hash also. set index to negative so that you can know the presence of element.
if any element is greater that array size that means answer will less that element
so all negative and bigger than size are useless. 
if elemtns are in order [1,2,3,4] then ans will be 5 to do that insert two extra positive number greater
than size of array si they don't affect array. INT_MAX will be better.


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(INT_MAX);
        nums.push_back(INT_MAX);
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] <= 0)
            {
                nums[i] = INT_MAX;
            }
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
             int index = abs(nums[i]);
             if(index < nums.size() && nums[index] > 0)
             {
                 nums[index] = -nums[index];
             }
        }
        for(int i = 1 ; i < nums.size() ; i++)
        {
             if(nums[i]  > 0)
                 return i;
        }
        return -1;
    }
};