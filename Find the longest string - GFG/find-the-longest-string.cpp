//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
bool check(string& s, unordered_map<string, int>& map){
    string temp = "";
    temp += s[0];
    int i = 0;
    // cout << temp << ",  " << s << endl;
    while(i < s.size() && map.count(temp) > 0){
        i++;
        temp += s[i];
        // cout << s << " index = " << i << ",  " << temp << endl;
    }
    if(i == s.size()) return true;
    return false;
}


class Solution
{
public:
    string longestString(vector<string> &words){
        string ans = "";
        int n = words.size();
        unordered_map<string, int> map;
        for(int i = 0; i < n; i++){
            map[words[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(ans.size() <= words[i].size()){
                if(ans.size() == words[i].size()){
                    if(ans > words[i]){
                        if(check(words[i], map)) ans = words[i];
                    }
                }
                else{
                    // cout << words[i] << endl;
                    if(check(words[i], map)) ans = words[i];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends