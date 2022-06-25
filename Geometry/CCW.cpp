typedef long long ll;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) 
{
	ll a = x1 * y2 + x2 * y3 + x3 * y1;
	ll b = y1 * x2 + y2 * x3 + y3 * x1;
	return a - b;
}