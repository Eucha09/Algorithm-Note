## 3. Data_Structures

### Contens

1. [Union Find](https://github.com/Eucha09/Algorithm-Note/tree/main/Data_Structures#3-1-union-find)
1. [Segment Tree](https://github.com/Eucha09/Algorithm-Note/tree/main/Data_Structures#3-2-segment-tree)

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

### 3-2. Segment Tree

#### 구간 합 구하기

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

#### x번째 원소 찾기

```cpp
struct segment_tree
{
	int tree[400005];

	void update(int idx, int value, int node, int start, int end)
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

	int findx(int x, int node, int start, int end)
	{
		if (start == end)
			return start;
		int mid = start + end >> 1;
		if (x <= tree[node * 2])
			return findx(x, node * 2, start, mid);
		else
			return findx(x - tree[node * 2], node * 2 + 1, mid + 1, end);
	}
};
```