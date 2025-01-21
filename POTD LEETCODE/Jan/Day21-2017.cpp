class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
       int n = grid[0].size();
       vector<long long>row0(n+1, 0); 
       vector<long long>row1(n+1, 0);
       for(int i=n-1; i>=0; i--){
        row0[i] = row0[i+1]+grid[0][i];
        
       }
       row1[0] = grid[1][0];
       for(int i=1; i<=n-1; i++){
        row1[i] = row1[i-1] + grid[1][i]; 
        
       }
    long long ans = LLONG_MAX;
       for(int i=0; i<n; i++){
        long long temp;
        if(i!=0)
        temp = max(row0[i+1], row1[i-1]);
        else{
            temp = row0[i+1];
        }
        ans = min(ans, temp);
       }
        return ans;
    }
};