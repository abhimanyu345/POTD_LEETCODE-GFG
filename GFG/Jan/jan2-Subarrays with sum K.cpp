int countSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<long long int, int>mpp;
        long long int sum = 0;
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum==k)
            cnt++;
            
            long long int rem = sum-k;
            if(mpp.find(rem)!=mpp.end())
            cnt+=mpp[rem];
            
            mpp[sum]++;
        }
        return cnt;