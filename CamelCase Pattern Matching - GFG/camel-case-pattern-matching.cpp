//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dic, string Pattern) {
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < Dic.size(); i++){
            string s = Dic[i];
            string temp = "";
            for(int i = 0; i < s.size(); i++){
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    temp += s[i];
                    map[temp].push_back(s);
                }
            }
        }
        if(!map.count(Pattern)) return {"-1"};
        return map[Pattern];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends