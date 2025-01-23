class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>>temp;
        for(int i=0; i<grid.size(); i++){
            int cnt = 0;
            vector<int>temp2;
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1)
                cnt++;
                temp2.push_back(0);
            }
            temp.push_back(temp2);
            if(cnt>1){
                for(int j=0; j<grid[0].size(); j++){
                    if(grid[i][j]==1)
                    temp[i][j] = 1;
                }
                ans+=cnt;
            }
        }
        for(int i=0; i<grid[0].size(); i++){
            int cnt = 0;
            for(int j=0; j<grid.size(); j++){
                if(grid[j][i]==1)
                cnt++;
            }
            if(cnt>1){
                for(int j=0; j<grid.size(); j++){
                    if(grid[j][i]==1 && temp[j][i]!=1)
                    ans++;
                }
            }
        }
        return ans;
    }
};