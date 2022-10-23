class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = nums[0], minn = nums[0];
        int temp = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int a = max(nums[i], max(nums[i] * maxx, nums[i] * minn));
            minn = min(nums[i], min(nums[i] * maxx, nums[i] * minn));
            maxx = a;
            if(temp < maxx){
                temp = maxx;
            }
        }
        return temp;
    }
};