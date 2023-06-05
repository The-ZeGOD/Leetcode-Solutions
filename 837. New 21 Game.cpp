class Solution
{
public:
    double new21Game(int N, int K, int W)
    {
        if (K == 0)
            return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double wsum = 1.0;
        for (int i = 1; i <= N; ++i)
        {
            dp[i] = wsum / W;
            if (i < K)
                wsum += dp[i];
            if (i >= W && i - W < K)
                wsum -= dp[i - W];
        }
        double res = 0.0;
        for (int i = K; i <= N; ++i)
            res += dp[i];
        return res;
    }
};
