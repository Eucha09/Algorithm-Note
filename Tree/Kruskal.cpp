struct edge
{
	ll a, b, cost;
	bool operator<(const edge& b)const
	{
		return cost < b.cost;
	}
};

vector<edge> edges;

// 유니온파인드
int parent[1000006]; // parent[i] = i로 초기화

int find_parent(int x)
{
	if (parent[x] != x)
		parent[x] = find_parent(parent[x]);
	return parent[x];
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

// 크루스칼
int kruskal(int n)
{
	int ret = 0;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		edge e = edges[i];
		if (find_parent(e.a) != find_parent(e.b))
		{
			union_parent(e.a, e.b);
			ret += e.cost;
		}
	}

	return ret;
}
