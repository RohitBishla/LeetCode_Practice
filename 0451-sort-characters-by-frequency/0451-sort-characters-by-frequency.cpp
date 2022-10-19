class Solution {
public:
    string frequencySort(string &s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: map){
            pq.push({it.second, it.first});
        }
        map.erase(map.begin(), map.end());
        string ans = "";
        while(!pq.empty()){
            pair<int, char> p = pq.top();
            pq.pop();
            for(int i = 0; i < p.first; i++){
                ans += p.second;
            }
        }
        return ans;
    }
};