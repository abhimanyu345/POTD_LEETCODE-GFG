int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<long long int, int>mpp;
        long long int sum = 0;
        int longest = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum==k){
                longest = max(longest, i+1);
            }
            if(mpp.find(sum-k)!=mpp.end()){
                longest = max(longest, i-mpp[sum-k]);
            }
            if(mpp[sum]){
                mpp[sum] = min(mpp[sum],i);
            }
            else{
                mpp[sum] = i;
            }
        }
        return longest;
    }