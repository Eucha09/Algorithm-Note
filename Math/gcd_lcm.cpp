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
