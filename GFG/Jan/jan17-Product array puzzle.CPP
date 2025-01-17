vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int cnt0 = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                cnt0++;
            }
        }
        if(cnt0>1){
            return vector<int>(arr.size(), 0);
        }
        long long int prod = 1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=0){
                prod *= arr[i];
            }
        }
        vector<int>res;
        if(cnt0==1){
            for(int i=0; i<arr.size(); i++){
                if(arr[i]!=0){
                    res.push_back(0);
                }
                else{
                    res.push_back(prod);
                }
            }
        }
        else{
            for(int i=0; i<arr.size(); i++){
                res.push_back(prod/arr[i]);
            }
        }
        return res;
    }