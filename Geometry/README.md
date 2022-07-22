## 4. Geometry

### Contens

1. [CCW]()
1. [선분 교차]()

### 4-1. CCW

- CCW 알고리즘은 세 점이 시계 방향인지 직선인지 반시계 방향인지를 구하는 알고리즘이다.
- 두 벡터의 외적을 통해 구하며 음수면 시계방향, 0이면 직선, 양수면 반시계 방향이다.
- 두 벡터의 외적은 두 벡터가 만들어내는 평행사변형의 넓이이다.
```c++
typedef long long ll;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) 
{
	ll a = x1 * y2 + x2 * y3 + x3 * y1;
	ll b = y1 * x2 + y2 * x3 + y3 * x1;
	return a - b;
}
```

### 4-2. 선분 교차

#### 선분 교차 판정

- 교차하면 1 출력 아니면 0 출력

```c++
typedef long long ll;

struct point {
	ll x, y;
	bool operator<(const point& o) {
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
	bool operator<=(const point& o) {
		if (x != o.x)
			return x <= o.x;
		return y <= o.y;
	}
};

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll a = x1 * y2 + x2 * y3 + x3 * y1;
	ll b = y1 * x2 + y2 * x3 + y3 * x1;
	if (a - b < 0)
		return -1;
	else if (a - b > 0)
		return 1;
	return 0;
}

int isIntersection(point a, point b, point c, point d)
{
	ll abc = ccw(a.x, a.y, b.x, b.y, c.x, c.y);
	ll abd = ccw(a.x, a.y, b.x, b.y, d.x, d.y);
	ll cda = ccw(c.x, c.y, d.x, d.y, a.x, a.y);
	ll cdb = ccw(c.x, c.y, d.x, d.y, b.x, b.y);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (b < a)
			swap(a, b);
		if (d < c)
			swap(c, d);
		if (a <= d && c <= b)
			return 1;
		else
			return 0;
	}
	else if (abc * abd <= 0 && cda * cdb <= 0)
		return 1;
	else
		return 0;
}
```

#### 교차점 출력하기

```cpp
void print_intersection(point a, point b, point c, point d)
{
	ll px = (a.x*b.y - a.y*b.x)*(c.x - d.x) - (a.x - b.x)*(c.x*d.y - c.y*d.x);
	ll py = (a.x*b.y - a.y*b.x)*(c.y - d.y) - (a.y - b.y)*(c.x*d.y - c.y*d.x);
	ll p = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);

	if (p == 0)
	{
		if (a < d && c == b)
			printf("%lld %lld\n", b.x, b.y);
		else if (c < b && a == d)
			printf("%lld %lld\n", a.x, a.y);
	}
	else
		printf("%.12f %.12f\n", (double)px / p, (double)py / p);
}
```