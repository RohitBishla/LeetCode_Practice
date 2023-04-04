//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int a = 0;
    int b = 0;
    int i = 0;
    while(i < str.size()){
        char temp = str[i];
        if(temp == 'a'){
            a++;
        }
        else b++;
        while(str[i] == temp) i++;
    }
    return min(a, b) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends