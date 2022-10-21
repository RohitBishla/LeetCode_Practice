class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i <= k && i < nums.size(); i++){
            if(map.count(nums[i])){
                return true;
            }
            map[nums[i]] = 1;
        }
        for(int i = k + 1; i < nums.size(); i++){
            map.erase(nums[i - k - 1]);
            if(map.count(nums[i])) return true;
            map[nums[i]] = 1;
        }
        return false;
    }
};