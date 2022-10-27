class Solution {
    int check(vector<vector<int>>& img1, vector<vector<int>>& img2, int I, int J){
        int n = img2.size();
        int count = 0;
        for(int i = I; i < n; i++){
            for(int j = J; j < n; j++){
                if(img1[i - I][j - J] == img2[i][j] && img2[i][j] == 1){
                    // return 0;
                    count++;
                }
                // count += img1[i - I][j - J];
            }
        }
        return count;
    }
    // (I, J) = (n, n)
    int check2(vector<vector<int>>& img1, vector<vector<int>>& img2, int I, int J){
        int n = img1.size();
        int count = 0;
        for(int i = 0; i <= I; i++){
            for(int j = 0; j <= J; j++){
                if(img1[i + n - I - 1][j + n - J - 1] == img2[i][j] && img2[i][j] == 1){
                    // return 0;
                    count++;
                }
                // count += img2[i][j];
            }
        }
        return count;
    }
//     (I, J + n - 1) = (n, n)      (0, n), ()
    int check3(vector<vector<int>>& img1, vector<vector<int>>& img2, int I, int J){
        int n = img1.size();
        int count = 0;
        for(int i = I; i < n; i++){
            for(int j = 0; j <= J; j++){
                if(img1[i - I][j + n - 1 - J] == img2[i][j] && img2[i][j] == 1){
                    count++;
                }
                
            }
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, max(check(img1, img2, i, j), check2(img1, img2, i, j)));
                ans = max(ans, max(check3(img1, img2, i, j), check3(img2, img1, i, j)));
            }
        }
        return ans;
    }
};
// [[0,0,0,0,1],
//  [0,0,0,0,0],
//  [0,0,0,0,0],
//  [0,0,0,0,0],
//  [0,0,0,0,0]]
 

// [[0,0,0,0,0],
//  [0,0,0,0,0],
//  [0,0,0,0,0],
//  [0,0,0,0,0],
//  [1,0,0,0,0]]
