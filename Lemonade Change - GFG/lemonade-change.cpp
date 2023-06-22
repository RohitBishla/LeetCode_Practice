//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        vector<int> arr(3);
        for(int i = 0; i < bills.size(); i++){
            int x = bills[i] - 5;
            int j = 0;
            if(arr[1] && x > 10){
                arr[1]--;
                x-=10;
            }
            while(arr[0] && x > 0){
                x -= 5;
                arr[0]--;
            }
            if(x) return false;
            if(bills[i] == 5) arr[0]++;
            if(bills[i] == 10) arr[1]++;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends