#define MOD 1000000007
typedef long long ll;

ll pow(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return pow(a, b - 1) * a % MOD;
	ll half = pow(a, b / 2);
	return half * half % MOD;
}

ll facto(ll n)
{
	ll ret = 1;
	for (ll i = 2; i <= n; i++)
		ret = (ret * i) % MOD;
	return ret;
}

ll solve(ll n, ll k)
{
	ll ret;
	ret = facto(n) * pow(facto(k) * facto(n - k) % MOD, (ll)MOD - 2) % MOD;
	return ret;
}
