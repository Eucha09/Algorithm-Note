int dp[1003][1003];

int solve(int n, int k)
{
	int & ret = dp[n][k];

	if (ret != -1)
		return ret;
	if (k == 0 || n == k)
		return 1;

	ret = (solve(n - 1, k - 1) + solve(n - 1, k)) % MOD;
	return ret;
}
