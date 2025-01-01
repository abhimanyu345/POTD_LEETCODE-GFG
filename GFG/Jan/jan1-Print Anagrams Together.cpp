class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<string>newarr = arr;
        for(auto &it:newarr){
            sort(it.begin(), it.end());
        }
        unordered_map<string, int>mpp;
        vector<vector<string>>ans;
        for(int i=0; i<newarr.size(); i++)
        {
            vector<string>temp;
            if(mpp.find(newarr[i])==mpp.end()){
                mpp[newarr[i]]++;
                for(int j=0; j<arr.size(); j++){
                    if(newarr[j]==newarr[i]){
                        temp.push_back(arr[j]);
                    }
                }
                ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};