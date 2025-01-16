class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        int ans = 0;
        if(a%2==0){
            ans = ans^0;
        }
        else{
            for(int i=0; i<nums2.size(); i++){
                ans ^= nums2[i];
            }
        }
        if(b%2==0){
            ans = ans^0;
        }
        else{
            for(int i=0; i<nums1.size(); i++){
                ans^=nums1[i];
            }
        }
        return ans;
    }
};