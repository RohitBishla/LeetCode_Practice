class Solution {
    void largestHelper(vector<int>& nums, vector<int>& largest){
        stack<int> st;
        int n = nums.size();
        st.push(n - 1);
        largest[n - 1] = -1;
        for(int i = n - 2; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if(st.empty()) largest[i] = -1;
            else largest[i] = st.top();
            st.push(i);
        }
    }
//     vector<int> helper(vector<int>& nums){
        
//         int n = nums.size();
//         vector<int> ans(n);
//         stack<int> st;
//         ans[n - 1] = -1;
//         st.push(nums[n - 1]);
//         for(int i = n - 2; i >= 0; i--){
//             while(!st.empty() && nums[i] >= st.top()){
//                 st.pop();
//             }
//             cout << nums[i] << ", " << st.size() << endl;
//             if(st.empty()){
//                 ans[i] = -1;
//             }
//             else{
//                 stack<int> temp;
//                 temp.push(st.top());
//                 st.pop();
//                 while(!st.empty() && nums[i] >= st.top()){
//                     cout << st.top() << " ";
//                     temp.push(st.top());
//                     st.pop();
//                 }
//                 cout << " ,;" << nums[i]  << " " << st.size()<< endl;
//                 if(st.empty()) ans[i] = -1;
//                 else{
//                     ans[i] = st.top();
//                 }
//                 while(!temp.empty()){
//                     st.push(temp.top());
//                     temp.pop();
//                 }
//             }
//             st.push(nums[i]);
//         }
//         return ans;
//     }
    int helper(int val, int i, vector<int>& nums, vector<int>& largest){
        if(i == -1 || i >= nums.size() - 1) return -1;
        i++;
        if(nums[i] > val) return nums[i];
        int index = largest[i];
        if(index == -1) return -1;
        if(nums[index] > val) return nums[index];
        return helper(val, index, nums, largest);
    }
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> largest(n);
        largestHelper(nums, largest);
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            ans[i] = helper(nums[i], largest[i], nums, largest);
        }
        return ans;
    }
};