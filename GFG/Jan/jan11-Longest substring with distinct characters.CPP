int longestUniqueSubstr(string &s) {
        // code here
        unordered_set<char> st;
    int left = 0, maxSize = 0;

    for (int right = 0; right < s.length(); right++) {
        // Slide the window if a duplicate is found
        while (st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        maxSize = max(maxSize, right - left + 1);
    }

    return maxSize;
    }