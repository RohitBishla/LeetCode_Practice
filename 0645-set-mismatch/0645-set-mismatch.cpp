class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;
        int temp = 1;
        for(int i = 0; i < nums.size(); i++){
            if(map.count(nums[i])){
                temp = nums[i];
                break;
            }
            map[nums[i]] = 1;
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans^(i + 1)^nums[i];
        }
        ans = ans^temp;
        return {temp, ans};
    }
};