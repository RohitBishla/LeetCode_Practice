class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it: map){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        // vector<pair<int, int>> arr;
        // for(auto it: map){
        //     arr.push_back({it.second, it.first});
        // }
        // sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        // vector<int> ans;
        // for(int i = 0; i < k; i++){
        //     ans.push_back(arr[i].second);
        // }
        return ans;
    }
};