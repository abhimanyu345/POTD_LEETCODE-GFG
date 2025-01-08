class Solution {
public:

    bool isPrefixAndSuffix(string str1, string str2){
        int n=str1.length();
        int m = str2.length();
        int i=0;
        if(n>m)
        return false;
        while(i<n){
            if(str1[i]==str2[i] && str1[i]==str2[m-n+i]){
                i++;
            }
            else{
                return false;
            }
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};