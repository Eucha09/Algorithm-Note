## 1. Math

### Contens

1. [에라토스테네스의 체](https://github.com/Eucha09/Algorithm-Note/tree/main/Math#1-1-%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4)
1. [좌표 압축](https://github.com/Eucha09/Algorithm-Note/tree/main/Math#1-2-%EC%A2%8C%ED%91%9C-%EC%95%95%EC%B6%95)
1. [유클리드 호제법(최대공약수 최소공배수)]()
1. [이항 계수(DP)]()
1. [이항 계수(거듭제곱, 페르마의 소정리)]()
1. [행렬 거듭제곱]()
1. [피보나치 수열(행렬 거듭제곱)]()

### 1-1. 에라토스테네스의 체

```cpp
int num[1000006]; // 찾을 소수 범위 (1 ~ 1000006)
vector<int> primeNumver; // 소수

void Eratosthenes()
{
    for (int i = 2; i < 1000006; i++)
    {
        if (num[i])
            continue;
        primeNumver.push_back(i);
        for (int j = i * 2; j < 1000006; j += i)
            num[j] = 1;
    }
}
```

### 1-2. 좌표 압축

```cpp
int arr[1000006];
vector<int> v;

int getidx(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main()
{
    int n;

    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", arr + i);
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // arr[i] : 원래 좌표
    // getidx(arr[i]) : 압축된 좌표
}
```
### 1-3. 유클리드 호제법(최대공약수 최소공배수)

```cpp
int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
```

### 1-4. 이항 계수(DP)

시간복잡도: O(n*k)

```cpp
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
```

### 1-5. 이항 계수(거듭제곱, 페르마의 소정리)

> 페르마의 소정리
> p가 소수고 a가 p의 배수가 아니면 a^(p - 1) = 1 (mod p)이다.
> a^(p - 1) = 1 (mod p)
> a * a^(p - 2) = 1 (mod p)
> a^(p - 2) = a^-1 (mod p)

> 이항계수
> nCk = n! / (k!(n - k)!) = n! * (k!(n - k)!)^-1
> nCk = n! * (k!(n - k)!)^(p - 2) (mod p)

시간복잡도: O(n)

```cpp
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
```

### 1-6. 행렬 거듭제곱

```cpp
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
```

### 1-7. 피보나치 수열(행렬 거듭제곱)

시간복잡도: O(logn)

```cpp
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
```