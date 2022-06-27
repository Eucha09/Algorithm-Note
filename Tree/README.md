## 3. Tree

### Contens

1. [Union Find](https://github.com/Eucha09/Algorithm-Note/tree/main/Tree#3-1-union-find)
1. [Kruskal](https://github.com/Eucha09/Algorithm-Note/tree/main/Tree#3-2-kruskal)
1. [Segment Tree](https://github.com/Eucha09/Algorithm-Note/tree/main/Tree#3-3-segment-tree)

### 3-1. Union Find

```cpp
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
```

### 3-2. Kruskal

```cpp
struct edge{
  int a, b;
}

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
```

### 3-3. Segment Tree

```cpp
struct segment_tree
{
	ll tree[4000006];

	void update(int idx, ll value, int node, int start, int end)
	{
		if (idx < start || end < idx)
			return;
		if (start == end)
		{
			tree[node] = value;
			return;
		}
		int mid = start + end >> 1;
		update(idx, value, node * 2, start, mid);
		update(idx, value, node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	ll sum(int left, int right, int node, int start, int end)
	{
		if (right < start || end < left)
			return 0;
		if (left <= start && end <= right)
			return tree[node];
		int mid = start + end >> 1;
		return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, end);
	}
};
```

#### 구간에 수를 더하고, 한 칸의 값만 가져오는 경우

```cpp
struct segment_tree
{
	ll tree[4000006];

	void update(int left, int right, ll value, int node, int start, int end)
	{
		if (right < start || end < left)
			return;
		if (left <= start && end <= right)
		{
			tree[node] += value;
			return;
		}
		int mid = start + end >> 1;
		update(left, right, value, node * 2, start, mid);
		update(left, right, value, node * 2 + 1, mid + 1, end);
	}

	ll getx(int idx, int node, int start, int end)
	{
		if (idx < start || end < idx)
			return 0;
		if (start == end)
			return tree[node];
		int mid = start + end >> 1;
		return tree[node] + getx(idx, node * 2, start, mid) 
			+ getx(idx, node * 2 + 1, mid + 1, end);
	}
};
```

