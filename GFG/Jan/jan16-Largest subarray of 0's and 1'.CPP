int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int, int> mp;  // Map to store first occurrence of `cnt1 - cnt0`
    int cnt0 = 0, cnt1 = 0, ans = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) cnt0++;
        else cnt1++;

        int diff = cnt1 - cnt0;  // Key insight: Difference of 1s and 0s

        if (diff == 0) {
            ans = max(ans, i + 1);  // If difference is 0, subarray from 0 to i is balanced
        }

        if (mp.find(diff) != mp.end()) {
            ans = max(ans, i - mp[diff]);  // Found earlier occurrence of same diff
        } else {
            mp[diff] = i;  // Store first occurrence
        }
    }
    return ans;
    }