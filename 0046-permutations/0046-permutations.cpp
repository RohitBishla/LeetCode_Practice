class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&nums,int index){
        //base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(ans,nums,index+1);
            //make the chanes back to normal 
            swap(nums[index],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index=0;
        vector<vector<int>>ans;
        solve(ans,nums,index);
        return ans;
    }
};