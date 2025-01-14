int findEquilibrium(vector<int> &arr) {
        // code here
        long long int sum0 = accumulate(arr.begin(), arr.end(), (long long int)0);
        long long int sum = 0;
        for(int i=0; i<arr.size(); i++){
            if(sum == sum0-(sum+arr[i])){
                return i;
            }
            sum+=arr[i];
        }
        return -1;
    }