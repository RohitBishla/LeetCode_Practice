class Solution {
    string reverse1(string s){
        reverse(s.begin(), s.end());
        return s;
    }
    bool pali(string& temp){
        int i = 0;
        int j = temp.size() - 1;
        while(i < j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map1;
        map<string, int> pal;
        int count = 0;
        int countPal = 0;
        vector<string> arr;
        for(int i = 0; i < words.size(); i++){
            string temp = reverse1(words[i]);
            if(pali(temp)){
                arr.push_back(temp);
                pal[temp]++;
            }
            else if(map1.count(temp) && map1[temp] > 0){
                map1[temp]--;
                count += 2*temp.size();
            }
            else{
                map1[words[i]]++;
            }
        }
        for(auto it: pal){
            if(pal[it.first] > 1){
                int temp = pal[it.first]/2;
                count += 2*(it.first).size()*temp;
            }
            if((it.second)%2 != 0){
                if(countPal < (it.first).size()){
                    countPal = (it.first).size();
                }
                // countPal = max(countPal, (it.first).size());
            }
        }
        count += countPal;
        return count;
    }
};