class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>count;
        int cnt=0;
        for(int i=0; i<words.size(); i++){
            int size = words[i].length()-1;
            if((words[i][0]=='a'||words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u') &&(words[i][size]=='a'||words[i][size]=='e'||words[i][size]=='i'||words[i][size]=='o'||words[i][size]=='u')){
                cnt++;
            }
            count.push_back(cnt);
        }

        vector<int>ans;
        for(auto it:queries){
            int size = words[it[0]].length()-1;
            if((words[it[0]][0]=='a'||words[it[0]][0]=='e'||words[it[0]][0]=='i'||words[it[0]][0]=='o'||words[it[0]][0]=='u') &&(words[it[0]][size]=='a'||words[it[0]][size]=='e'||words[it[0]][size]=='i'||words[it[0]][size]=='o'||words[it[0]][size]=='u')){
                ans.push_back(count[it[1]]-count[it[0]]+1);
            }
            else{
                ans.push_back(count[it[1]]-count[it[0]]);
            }
        }
        return ans;
    }
};