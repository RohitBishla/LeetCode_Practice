class Solution {
    vector<string> five = {"V", "L", "D"};
    vector<string> ten = {"I", "X", "C", "M"};
    string helper(int temp, int count){
        if(temp == 5){
            return five[count];
        }
        if(temp == 4){
            return ten[count] + five[count];
        }
        if(temp == 9){
            return ten[count] + ten[count + 1];
        }
        if(temp < 4){
            string s = "";
            for(int i = 0; i < temp; i++){
                s += ten[count];
            }
            return s;
        }
        string s = five[count];
        for(int i = 0; i < temp - 5; i++){
            s += ten[count];
        }
        return s;
    }
public:
    string intToRoman(int num) {
        string ans = "";
        int count = 0;
        while(num != 0){
            int temp = num%10;
            num = num/10;
            if(temp != 0)
                ans = helper(temp, count) + ans;
            count++;
        }
        return ans;
    }
};