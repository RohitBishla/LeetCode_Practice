class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i = 0; i < arr1.size(); i++){
            map[arr1[i]]++;
        }
        for(int i = 0; i < arr2.size(); i++){
            ans.push_back(arr2[i]);
            if(map.count(arr2[i])){
                for(int j = 0; j < map[arr2[i]] - 1; j++){
                    ans.push_back(arr2[i]);
                }
                map[arr2[i]] = 0;
            }
        }
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto it: map){
            for(int i = 0; i < it.second; i++){
                pq.push(it.first);
            }
        }
        while(pq.size()){
            int temp = pq.top();
            pq.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};