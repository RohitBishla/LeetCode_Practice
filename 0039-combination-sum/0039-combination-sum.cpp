class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target, int count, vector<int> temp, int ii){
        if(count == target){
            ans.push_back(temp);
            return;
        }
        else if(count > target){
            return;
        }
        for(int i = ii; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            helper(candidates, target, count + candidates[i], temp, i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int count = 0;
        int i = 0;
        helper(candidates, target, count, temp, i);
        return ans;
    }
};