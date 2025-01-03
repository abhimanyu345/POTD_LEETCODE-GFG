class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=(long long int)nums[i];
        }
        long long int sum1 = 0;
        long long int cnt = 0;
        for(int i=0; i<=nums.size()-2; i++){
            sum1+=nums[i];
            sum-=nums[i];
            if(sum1>=sum){
                cnt++;
            }
        }
        return cnt;
    }
};