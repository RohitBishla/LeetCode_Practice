class Solution {
    bool check(string& s){
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i])){
                return false;
            }
            map[s[i]] = 1;
        }
        return true;
    }
    
    int helper(vector<string>& arr, int i, string s){
        if(i == arr.size()){
            return s.size();
        }
        string temp = s + arr[i];
        int ans = helper(arr, i + 1, s);
        if(check(temp)){
            ans = max(ans, helper(arr, i + 1, temp));
        }
        return ans;
    }
public:
    int maxLength(vector<string>& arr) {
        return helper(arr, 0, "");
    }
};