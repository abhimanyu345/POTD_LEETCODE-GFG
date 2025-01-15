class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int>mpp1;
        unordered_map<int, int>mpp2;
        vector<int>C;
        int cnt = 0;
        for(int i=0; i<A.size(); i++){
            mpp1[A[i]]++;
            mpp2[B[i]]++;
            for(auto it:mpp1){
                if(mpp2.find(it.first)!=mpp2.end()){
                    cnt += min(it.second, mpp2[it.first]);
                }
            }
            C.push_back(cnt);
            cnt = 0;
        }
        return C;
    }
};