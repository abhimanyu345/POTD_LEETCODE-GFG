class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        unordered_map<char, int>mpp;
        for(int i=0; i<words2.size(); i++){
            unordered_map<char, int> temp;
            for(int j=0; j<words2[i].length(); j++){
                temp[words2[i][j]]++;
                if(mpp[words2[i][j]]<temp[words2[i][j]]){
                    mpp[words2[i][j]] = temp[words2[i][j]];
                }
            }
        }

        for(int i=0; i<words1.size(); i++){
            unordered_map<char, int> temp;
            for(int j=0; j<words1[i].length(); j++){
                temp[words1[i][j]]++;
            }
            int flag = 1;
            for(auto it:mpp){
                if(it.second>temp[it.first]){
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
            ans.push_back(words1[i]);
        }
        return ans;
    }
};