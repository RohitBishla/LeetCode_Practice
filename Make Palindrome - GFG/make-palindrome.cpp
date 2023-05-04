//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        unordered_map<string, vector<int>> map;
        for(int i = 0; i < n; i++){
            map[arr[i]].push_back(i);
        }
        bool flag = false;
        int x = 0;
        for(int i = 0; i < n; i++){
            reverse(arr[i].begin(), arr[i].end());
            if(map.count(arr[i])){
                if(map[arr[i]].size() == 1){
                    if(map[arr[i]][0] == i){
                        if(flag) return false;
                        flag = true;
                        map[arr[i]].pop_back();
                    }
                    else{
                        map[arr[i]].pop_back();
                    }
                }
                else if(map[arr[i]].size() > 1){
                    for(int j = 0; j < map[arr[i]].size(); j++){
                        if(map[arr[i]][j] != i){
                            swap(map[arr[i]][j], map[arr[i]][map[arr[i]].size() - 1]);
                            // cout << i << " " << map[arr[i]][j] << endl;
                            map[arr[i]].pop_back();
                            break;
                        }
                    }
                }
                else return false;
                // cout << arr[i] << endl;
            }
            else return false;
        }
        return true;
        // if(x == n || (x == n - 1 && flag)) return true;
        // return false;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends