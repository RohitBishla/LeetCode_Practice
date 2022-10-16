class Solution {
    int helper(int i, vector<int>& jobD, int d, int lastMax, vector<vector<vector<int>>> &dp){
        if(i == jobD.size()){
            if(d == 0) return jobD[lastMax];
            else return -1;
        }
        if(dp[i][d][lastMax] != -1) return dp[i][d][lastMax];
        int a = i;
        if(jobD[lastMax] > jobD[i]) a = lastMax;
        int ans = helper(i + 1, jobD, d, a, dp);

        if(d > 0){
            int temp = helper(i + 1, jobD, d - 1, i, dp);
            if(temp == -1) return dp[i][d][lastMax] = ans;
            if(ans == -1) ans = jobD[lastMax] + temp;
            else ans = min(ans, jobD[lastMax] + temp);
        }
        return dp[i][d][lastMax] = ans;
    }
    
public:
    int minDifficulty(vector<int>& jobD, int d) {
        if(jobD.size() <= 0) return -1;
        int n = jobD.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(d + 1, vector<int>(n, -1)));
        int lastMax = 0;
        return helper(1, jobD, d - 1, lastMax, dp);
    }
};