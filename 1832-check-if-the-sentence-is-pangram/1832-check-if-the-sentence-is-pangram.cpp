class Solution {
public:
    bool checkIfPangram(string &sentence) {
        vector<bool> arr(26, false);
        int count = 0;
        for(int i = 0; i < sentence.size(); i++){
            if(!arr[sentence[i] - 'a']){
                count++;
                arr[sentence[i] - 'a'] = true;
            }
        }
        if(count == 26) return true;
        return false;
    }
};