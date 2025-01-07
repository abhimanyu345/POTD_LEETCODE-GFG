int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int cnt = 0;
        unordered_map<long long int, int>mpp;
        for(int i=0; i<arr.size(); i++){
            long long int rem = (long long int)target-(long long int)arr[i];
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[arr[i]]++;
        }
        return cnt;
    }