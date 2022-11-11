class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int j = 1;
        int last = nums[0];
        while(j < nums.size()){
            if(nums[j] == last){
                j++;
            }
            else{
                last = nums[j];
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};