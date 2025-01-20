class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int>mpp1;
        unordered_map<int, int>mpp2;
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>>pos;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                pos[mat[i][j]].first = i;
                pos[mat[i][j]].second = j;
            }
        }
        for(int i=0; i<arr.size(); i++){
            int ele = arr[i];
            int idx_i = pos[ele].first;
            int idx_j = pos[ele].second;
            mpp1[idx_i]++;
            
            mpp2[idx_j]++;
            
            if(mpp1[idx_i]==n || mpp2[idx_j]==m){
                return i;
            }
        }
        return 0;
    }
};