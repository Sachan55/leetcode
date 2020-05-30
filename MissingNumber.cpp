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