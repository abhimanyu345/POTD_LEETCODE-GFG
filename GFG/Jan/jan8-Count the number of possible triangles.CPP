int countTriangles(vector<int>& arr) {
    // Sort the array to simplify the triangle inequality check
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int n = arr.size();

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int sum = arr[i] + arr[j];

            int low = j + 1, high = n - 1, idx = j;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] < sum) {
                    idx = mid; 
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            cnt += (idx - j);
        }
    }
    return cnt;
}