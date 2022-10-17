class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> arr(26, false);
        for(int i = 0; i < sentence.size(); i++){
            arr[sentence[i] - 'a'] = true;
        }
        for(int i = 0; i < 26; i++){
            if(arr[i] == false) return false;
        }
        return true;
    }
};