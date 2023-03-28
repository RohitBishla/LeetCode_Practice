//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    Shop shop;
    unordered_map<int, int> map;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        if(!map.count(0)){
            map[0] = shop.get(0);
            if(k < map[0]) return 0;
        }
        else if(k < map[0]) return 0;
        
        if(!map.count(n - 1)){
            map[n - 1] = shop.get(n - 1);
            if(k >= map[n - 1]){
                long long ans1 = find(n, k - map[n - 1]);
                return ans1 + 1;
            }
        }
        else if(k >= map[n - 1]){
            long long ans1 = find(n, k - map[n - 1]);
            return ans1 + 1;
        }
        if(k <= 0) return 0;
        long long ans = -1;
        int left = 0;
        int right = n - 1;
        // if(k < shop.get(0)) return 0;
        while(left <= right){
            int mid = (left + right)/2;
            long long x;
            if(!map.count(mid)){
                x = shop.get(mid);
                map[mid] = x;
            }
            else{
                x = map[mid];
            }
            
            if(x == -1) return 0;
            if(x <= k){
                ans = x;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(ans == -1) return 0;
        // cout << ans << endl;
        k = k - ans;
        if(k == 0) return 1;
        long long ans1 = find(n, k);
        return 1 + ans1;
        // return 1 + shop.find(n, k);
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends