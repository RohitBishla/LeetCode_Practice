class Solution {
public:
    string minWindow(string s, string t) {
        int index = 0;
        int len = s.size();
        unordered_map<char, int> map;
        for(int i = 0; i < t.size(); i++){
            map[t[i]]++;
        }
        int count = map.size();
        int i = 0;
        int j = 0;
        while(j != s.size()){
            if(count == 0){
                while(i < j){
                    if(map.count(s[i]) && map[s[i]] < 0){
                        map[s[i]]++;
                    }
                    else if(map.count(s[i]) && map[s[i]] == 0) break;
                    i++;
                }
                if(j - i < len){
                    len = j - i;
                    index = i;
                }
            }
            if(map.count(s[j])){
                map[s[j]]--;
                if(map[s[j]] == 0) count--;
            }
            j++;
        }
        while(i < j){
            if(map.count(s[i]) && map[s[i]] < 0){
                map[s[i]]++;
            }
            else if(map.count(s[i]) && map[s[i]] == 0) break;
            i++;
        }
        if(count == 0 && j - i < len){
            len = j - i;
            index = i;
        }
        if(count != 0) return "";
        return s.substr(index, len);
    }
};