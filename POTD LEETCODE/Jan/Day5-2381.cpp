class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> netShift(n + 1, 0);

        // Build the net shift array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            // Increment or decrement shift range
            if (direction == 1) {
                netShift[start] += 1;
                netShift[end + 1] -= 1;
            } else {
                netShift[start] -= 1;
                netShift[end + 1] += 1;
            }
        }

        // Compute prefix sum for net shift
        int currentShift = 0;
        for (int i = 0; i < n; ++i) {
            currentShift += netShift[i];
            // Normalize the shift to the range [0, 25]
            int effectiveShift = (currentShift % 26 + 26) % 26;

            // Apply the shift to the character
            s[i] = 'a' + (s[i] - 'a' + effectiveShift) % 26;
        }

        return s;
    }
};
