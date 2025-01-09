vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            long long int sum = 0;
            int start = i+1;
            int end = -1;
            for(int j=i; j<arr.size(); j++){
                sum += arr[j];
                if(sum>target)
                break;
                if(sum==target){
                    end = j+1;
                    break;
                }
            }
            if(end!=-1){
                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
        }
        
        ans.push_back(-1);
        return ans;
    }