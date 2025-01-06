 if (arr.size() < 2) return {};

        // Sort the array
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int left = 0, right = n - 1;
        int closestSum = INT_MAX;
        int maxAbsDiff = INT_MIN;
        vector<int> result;

        // Two-pointer approach
        while (left < right) {
            int sum = arr[left] + arr[right];
            int diff = abs(sum - target);

            // Update the closest sum and result pair
            if (diff < closestSum || 
               (diff == closestSum && (arr[right] - arr[left] > maxAbsDiff))) {
                closestSum = diff;
                maxAbsDiff = arr[right] - arr[left];
                result = {arr[left], arr[right]};
            }

            // Move pointers
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return result;