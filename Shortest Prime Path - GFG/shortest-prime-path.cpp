//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    bool prime(string& s){
        int a = (s[3] - '0') + 10*(s[2] - '0') + 100*(s[1] - '0') + 1000*(s[0] - '0');
        int x = pow(a, 0.5) + 1;
        for(int i = 2; i < x; i++){
            if(a%i == 0) return false;
        }
        return true;
    }
    
    
    void helper(string& s, queue<string>& qu, unordered_map<string, int>& map){
        string temp = s;
        for(int j = 0; j < 4; j++){
            for(char i = '0'; i <= '9'; i++){
                if(j == 0 && i == '0') continue;
                if(i == s[j]) continue;
                temp[j] = i;
                if(map.count(temp) == false){
                    if(prime(temp)){
                        map[temp] = 1;
                        qu.push(temp);
                    }
                }
                temp[j] = s[j];
            }
        }
    }
  public:
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        string final = to_string(Num2);
        string s = to_string(Num1);
        unordered_map<string, int> map;
        queue<string> qu;
        qu.push(s);
        qu.push("");
        int ans = 0;
        while(!qu.empty()){
            string a = qu.front();
            qu.pop();
            map[a] = 1;
            if(a == final) return ans;
            if(a.size() == 0){
                ans++;
                if(qu.size() != 0){
                    qu.push("");
                }
            }
            else{
                helper(a, qu, map);
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends