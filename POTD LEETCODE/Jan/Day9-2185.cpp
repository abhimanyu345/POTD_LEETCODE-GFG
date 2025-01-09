class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            int cnt = 0;
            for(int j=0; j<pref.length(); j++){
                if(words[i][j]==pref[j]){
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            if(cnt==pref.length())
            ans++;
        }
        return ans;
    }
};