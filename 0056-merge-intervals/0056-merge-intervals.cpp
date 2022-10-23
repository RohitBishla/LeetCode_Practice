class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(ans[ans.size() - 1][1] >= intervals[i][0]){
                ans[ans.size() - 1][1] = max(intervals[i][1], ans[ans.size() - 1][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

// 1 2 8 15
// 3 6 10 18