class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string>st;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].length(); j++){
            string s="";
                for(int m=j ; m<words[i].length(); m++){
                s+=words[i][m];
                for(int k=0; k<words.size(); k++){
                    if(k!=i && s==words[k]){
                        st.insert(words[k]);
                    }
                }
                }
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};