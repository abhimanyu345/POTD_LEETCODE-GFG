 vector<string> findPermutation(string &s) {
        // Code here there
        unordered_set<string>st;
        string temp = s;
        st.insert(s);
        while(next_permutation(s.begin(), s.end())){
            st.insert(s);
        }
        while(prev_permutation(temp.begin(), temp.end())){
            st.insert(temp);
        }
        return vector<string>(st.begin(), st.end());
    }