class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        int i = 0;
        while(i < s.size()){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};