class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string temp = countAndSay(n - 1);
        string ans = "";
        int i = 0;
        while(i < temp.size()){
            int count = 1;
            char c = temp[i];
            while(i + 1 < temp.size() && temp[i] == temp[i + 1]){
                i++;
                count++;
            }
            ans = ans + to_string(count) + c;
            i++;
        }
        return ans;
    }
};