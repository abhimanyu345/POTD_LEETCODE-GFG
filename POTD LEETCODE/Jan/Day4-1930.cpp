int countPalindromicSubsequence(string s) {
        int res = 0;
        unordered_set<char>st;
        for(int i=0; i<s.length(); i++){
            st.insert(s[i]);
        }
        for(auto it: st){
            int left_idx = -1;
            int right_idx = -1;
            for(int i=0; i<s.length(); i++){
                if(s[i]==it){
                    if(left_idx==-1){
                        left_idx = i;
                    }
                    else{
                        right_idx = i;
                    }
                }
            }
                unordered_set<char>st1;
                for(int j=left_idx+1; j<=right_idx-1; j++){
                    st1.insert(s[j]);
                }
                res+=st1.size();
            
        }
        return res;
    }