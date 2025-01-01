class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;
        for(int i=0; i<s.length()-1; i++){
            string s1 = s.substr(0,i+1);
            string s2 = s.substr(i+1, s.length()-i-1);
            int temp = 0;
            for(int j=0; j<s1.length(); j++){
                if(s1[j]=='0'){
                    temp++;
                }
            }
            for(int j=0; j<s2.length(); j++){
                if(s2[j]=='1'){
                    temp++;
                }
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};