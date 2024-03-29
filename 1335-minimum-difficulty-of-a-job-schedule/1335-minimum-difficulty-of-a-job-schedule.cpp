class Solution {
    int helper(int ind, int n, vector<vector<int>> &dp, vector<int> &jobDifficulty, int d)
    {
        if(ind >= n) return 0;
        if(dp[ind][d] != -1) return dp[ind][d];
        
        int ans = 1000000000, maxi = jobDifficulty[ind];
        
        if(d == 1)
        {
            for(int i = ind; i < n; i++)
                maxi = max(maxi, jobDifficulty[i]);
        
            ans = maxi;
        }
        else
        {
            for(int i = ind; i <= n - d; i++)
            {
                maxi = max(maxi, jobDifficulty[i]);
                ans = min(ans, maxi + helper(i+1, n, dp, jobDifficulty, d - 1));
            }
        }
        
        return dp[ind][d] = ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int> (d + 1, -1));
        if(n < d) return -1;
        return helper(0, n, dp, jobDifficulty, d);
    }
};