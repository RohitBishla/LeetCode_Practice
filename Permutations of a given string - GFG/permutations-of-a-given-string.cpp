//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    unordered_map<string, int> map;
    vector<string> helper(int i, string& S){
        if(i == S.size()) return {""};
        vector<string> temp = helper(i + 1, S);
        vector<string> ans;
        int t = temp[0].size() + 1;
        for(int ii = 0; ii < t; ii++){
            for(int j = 0; j < temp.size(); j++){
                string m = temp[j].substr(0, ii) + S[i] + temp[j].substr(ii);
                if(!map.count(m))
                    ans.push_back(m);
                map[m] = 1;
            }
        }
        return ans;
        
    }
	public:
		vector<string>find_permutation(string S){
		  //  sort(S.begin(), S.end());
		    
		    vector<string> ans = helper(0, S);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends