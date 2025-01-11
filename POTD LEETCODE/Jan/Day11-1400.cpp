class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()==k)
        return true;
        unordered_map<char, int>mpp;
        for(int i=0; i<s.length(); i++){
            mpp[s[i]]++;
        }
        int cnt = 0;
        for(auto it:mpp){
            if(it.second %2 ==1)
            cnt++;
        }
        if(cnt>k){
            return false;
        }
        if(s.length()<k)
        return false;
        return true;
    }
};