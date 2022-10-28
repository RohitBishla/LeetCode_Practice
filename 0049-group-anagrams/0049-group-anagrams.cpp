class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto it: map){
            ans.push_back(it.second);
        }
        return ans;
    }
};