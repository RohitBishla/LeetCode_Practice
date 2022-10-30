class Solution {
    void convert(string& s){
        int carry = 1;
        int i = s.size() - 1;
         while(i >= 0){
            if(s[i] != '0'){
                s[i--] = '0';
                break;
            }
            i--;
        }
        while(i >= 0 && carry == 1){
            if(s[i] == '9'){
                s[i] = '0';
            }
            else{
                s[i]++;
                carry = 0;
            }
            i--;
        }
        if(carry == 1){
            s = '1' + s;
        }
    }
    
    long long helper(string& s, int target){
        long long summ = 0;
        int i = s.size() - 1;
        while(i >= 0){
            if(summ + (s[i] - '0') > target){
                convert(s);
                i = s.size();
                summ = 0;
            }
            else summ += s[i] - '0';
            i--;
        }
        long long ans = 0;
        long long ten = 1;
        // cout << s << endl;
        for(int i = s.size() - 1; i >= 0; i--){
            ans += ten*(s[i] - '0');
            ten *= 10;
        }
        return ans;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        string s = to_string(n);
        long long a = helper(s, target);
        // cout << a << endl;
        return a - n;
    }
};