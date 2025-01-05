int lowerb(vector<int>&arr, int rem, int i){
        int ans = -1;
        int first = i+1;
        int last = arr.size()-1;
        while(first<=last){
            int mid = (first+last)/2;
            if(arr[mid]<rem){
                ans = mid-(i+1);
                first = mid+1;
            }
            else{
                last = mid-1;
            }
        }
        return ans;
    }
    
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int cnt = 0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            int rem = target-arr[i];
            int x = lowerb(arr, rem, i);
            cnt+=x+1;
        }
        return cnt;
    }