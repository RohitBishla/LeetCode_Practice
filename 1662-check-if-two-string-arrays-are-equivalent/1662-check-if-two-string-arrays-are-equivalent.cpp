class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0;
        int ii = 0;
        int j = 0;
        int jj = 0;
        while(i < word1.size() && j < word2.size()){
            if(word1[i][ii] != word2[j][jj]){
                return false;
            }
            ii++;
            jj++;
            if(ii == word1[i].size()){
                i++;
                ii = 0;
            }
            if(jj == word2[j].size()){
                j++;
                jj = 0;
            }
        }
        if(i != word1.size() || j != word2.size()){
            return false;
        }
        return true;
    }
};