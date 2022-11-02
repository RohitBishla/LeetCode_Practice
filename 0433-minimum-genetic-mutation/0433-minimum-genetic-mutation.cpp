class Solution {
    vector<char> c = {'A', 'C', 'G', 'T'};
    // int helper(string start, string& end, unordered_map<string, int>& map){
    //     // if(i == 0){
    //     //     for(int i = 0; i < 8; i++){
    //     //         if(start[i] != end[i]){
    //     //            return 8; 
    //     //         }
    //     //     }
    //     //     return 0;
    //     // }
    //     int count = 0;
    //     for(int i = 0; i < 8; i++){
    //         if(start[i] != end[i]) count++;
    //     }
    //     if(count == 0) return 0;
    //     // int a = helper(start, end, map);
    //     int ans = 9;
    //     for(int i = 0; i < 8; i++){
    //         char last = start[i];
    //         // if(start[i] != end[i]){
    //             for(int j = 0; j < 4; j++){
    //                 if(c[j] == last) continue;
    //                 start[i] = c[j];
    //                 if(map[start] == 1){
    //                     map[start] = 0;
    //                     ans = min(ans, 1 + helper(start, end, map));
    //                     map[start] = 1;
    //                 }
    //                 start[i] = last;
    //             }
    //         // }
    //     }
    //     return ans;
    // }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> map;
        for(int i = 0; i < bank.size(); i++){
            map[bank[i]] = 1;
        }
        queue<string> qu;
        qu.push(start);
        qu.push("");
        int count = 0;
        while(!qu.empty()){
            string s = qu.front();
            qu.pop();
            int a = 0;
            if(s == ""){
                count++;
                if(!qu.empty())
                    qu.push("");
            }
            for(int i = 0; i < 8; i++){
                if(s[i] != end[i]) a++;
            }
            if(a == 0) return count;
            for(int i = 0; i < 8; i++){
                int last = s[i];
                for(int j = 0; j < 4; j++){
                    if(last == c[j]) continue;
                    s[i] = c[j];
                    if(map[s] == 1){
                        qu.push(s);
                        map[s] = 0;
                    }
                    s[i] = last;
                }
            }
        }
        return -1;
        // int ans = helper(start, end, map);
        // if(ans == 9) return -1;
        // return ans;
    }
};