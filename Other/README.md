## 6. Other

### Contens

1. [LIS (nlogn)](https://github.com/Eucha09/Algorithm-Note/tree/main/Other#6-1-lis-nlogn)
1. [Euler Tour Technique](https://github.com/Eucha09/Algorithm-Note/tree/main/Other#6-2-euler-tour-technique)

### 6-1. LIS (nlogn)

```cpp
int arr[1000006];
vector<int> v;

int main() 
{
	int n;

	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %d", arr + i);

	v.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > v.back())
			v.push_back(arr[i]);
		else
		{
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx] = arr[i];
		}
	}

	printf("%d\n", v.size());
	return 0;
}
```

### 6-2. Euler Tour Technique

```cpp
int s[100005];
int e[100005];
int cnt;
vector<int> graph[100005];

void dfs(int cur)
{
    s[cur] = ++cnt;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        dfs(next);
    }
    e[cur] = cnt;
}
```