ll fibo(ll n)
{
	matrix a(2, vector<ll>(2));
	matrix b(2, vector<ll>(1));
	matrix ret;

	a[0][0] = a[0][1] = a[1][0] = b[0][0] = 1;
	a[1][1] = b[1][0] = 0;

	ret = pow(a, n) * b;

	return ret[1][0];
}
