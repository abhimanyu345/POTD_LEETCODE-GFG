class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sorted_nums = nums;  
        vector<int> result(n);
        iota(result.begin(), result.end(), 0);  // Store original indices
        
        // Sort based on values
        sort(result.begin(), result.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // Process segments
        for (int i = 0; i < n; ) {
            int j = i;
            while (j + 1 < n && nums[result[j + 1]] - nums[result[j]] <= limit) {
                j++;
            }
            // Sort the indices within this segment
            vector<int> segment_indices(result.begin() + i, result.begin() + j + 1);
            sort(segment_indices.begin(), segment_indices.end());

            // Assign sorted values back
            vector<int> segment_values;
            for (int idx : segment_indices) {
                segment_values.push_back(nums[idx]);
            }
            sort(segment_values.begin(), segment_values.end());

            for (int k = 0; k < segment_indices.size(); k++) {
                nums[segment_indices[k]] = segment_values[k];
            }
            i = j + 1;  // Move to the next segment
        }
        return nums;
    }
};
