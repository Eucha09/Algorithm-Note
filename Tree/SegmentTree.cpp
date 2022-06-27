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