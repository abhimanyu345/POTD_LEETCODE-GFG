class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i=0; i<boxes.length(); i++){
            int cnt = 0;
            for(int j=0; j<boxes.length(); j++){
                if(boxes[j]=='1'){
                    cnt += abs(i-j);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};