#define MOD 1000
typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator*(const matrix& a, const matrix& b)
{
	int row = a.size();
	int col = b[0].size();
	matrix ret(row, vector<ll>(col));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			for (int k = 0; k < b.size(); k++)
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
	return ret;
}


matrix pow(matrix a, ll b)
{
	int size = a.size();
	matrix ret(size, vector<ll>(size));
	for (int i = 0; i < size; i++)
		ret[i][i] = 1;
	if (b == 0)
		return ret;
	if (b % 2)
		return a * pow(a, b - 1);
	ret = pow(a, b / 2);
	return ret * ret;
}
