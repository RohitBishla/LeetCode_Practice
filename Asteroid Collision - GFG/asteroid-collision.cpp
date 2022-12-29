//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(asteroids[i] < 0){
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top() < 0) st.push(asteroids[i]);
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int> ans(st.size());
        for(int i = 0; i < ans.size(); i++){
            ans[ans.size() - i - 1] = st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends