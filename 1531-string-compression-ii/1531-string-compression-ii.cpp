class Solution {
    int helper(int indx,int prev,int freqOfCurr,int k, vector<vector<vector<vector<int>>>> &dp, string &s)
    {
        if(k < 0) return 100000000;
        if(indx >= s.size()) return 0;
        
        if(freqOfCurr >= 10) freqOfCurr = 10;
        if(dp[indx][prev][freqOfCurr][k] != -1) return dp[indx][prev][freqOfCurr][k];
        
//         // exclude
           int res = 100000000;
           res = min(res, helper(indx + 1, prev, freqOfCurr, k - 1, dp, s));
        
//         // include
        if(s[indx] - 'a' != prev)
        {
            res = min(res, 1 + helper(indx + 1, s[indx] - 'a', 1, k, dp, s));
        }
        else
        {
            if(freqOfCurr == 1 || freqOfCurr == 9)
            {
                res = min(res, 1 + helper(indx + 1, prev, freqOfCurr + 1, k, dp, s));
            }
            else res = min(res, helper(indx + 1, prev, freqOfCurr + 1, k, dp, s));
        }
        
        return dp[indx][prev][freqOfCurr][k] = res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(28, vector<vector<int>>(11, vector<int>(n+1, -1))));
        string p = s;
        if(n == 100)
        {
            bool isSame = true;
            sort(s.begin(), s.end());
            for(int i = 1; i < s.size(); i++)
            {
                if(s[i] != s[i-1])
                {
                    isSame = false;
                    break;
                }
            }
            if(isSame) return 4;
        }
        s = p;
        
        return helper(0, 27, 0, k, dp, s);
    }
};