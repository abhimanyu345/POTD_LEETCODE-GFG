unordered_map<long long int, int>mpp;
        long xor1 = 0;
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            xor1^=arr[i];
            if(xor1==k){
                cnt++;
            }
            long long int rem = xor1^k;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[xor1]++;
        }
        return cnt;