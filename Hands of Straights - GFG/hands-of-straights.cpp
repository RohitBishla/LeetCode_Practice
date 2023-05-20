//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        map<int, int> map1;
        if(groupSize == 1) return true;
        for(int i = 0; i < N; i++){
            map1[hand[i]]++;
        }
        int hold = 0;
        unordered_map<int, int> visited;
        for(auto it: map1){
            int neww = it.second - hold;
            if(neww < 0) return false;
            hold += neww;
            hold -= visited[it.first];
            visited[it.first] = 0;
            if(hold < 0) return false;
            visited[it.first + groupSize - 1] = neww;
        }
        if(hold > 0) return false;
        for(auto it: visited) if(it.second > 0) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends