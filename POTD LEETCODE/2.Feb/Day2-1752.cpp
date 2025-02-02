class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) { // Check breakpoints including wrap-around
                count++;
            }
            if (count > 1) return false; // More than one breakpoint is invalid
        }
        
        return true;
    }
};
