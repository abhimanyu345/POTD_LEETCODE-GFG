int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == target) {
                // Count duplicates for `left` and `right`
                if (arr[left] == arr[right]) {
                    // If all elements between `left` and `right` are the same
                    int count = right - left + 1;
                    ans += (count * (count - 1)) / 2; // Combination formula: C(n, 2)
                    break;
                } else {
                    // Count duplicates for `arr[left]`
                    int leftCount = 1;
                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        left++;
                        leftCount++;
                    }

                    // Count duplicates for `arr[right]`
                    int rightCount = 1;
                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        right--;
                        rightCount++;
                    }

                    // Add the number of combinations
                    ans += leftCount * rightCount;

                    // Move both pointers
                    left++;
                    right--;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return ans;