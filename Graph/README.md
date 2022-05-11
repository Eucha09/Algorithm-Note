## 2. Graph

### Contens

1. [DFS](https://github.com/Eucha09/Algorithm-Note/tree/main/Graph#2-1-dfs)
1. [BFS](https://github.com/Eucha09/Algorithm-Note/tree/main/Graph#2-2-bfs)
1. [Dijkstra](https://github.com/Eucha09/Algorithm-Note/tree/main/Graph#2-3-dijkstra)
1. [BellmanFord](https://github.com/Eucha09/Algorithm-Note/tree/main/Graph#2-4-bellman-ford)
1. [Floyd Warshall](https://github.com/Eucha09/Algorithm-Note/tree/main/Graph#2-5-floyd-warshall)

### 2-1. DFS

```cpp
#include <vector>
using namespace std;

vector<int> graph[1003];
int visited[1003];

void dfs(int cur)
{
	visited[cur] = 1;
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (visited[next] == 0)
			dfs(next);
	}
}
```

### 2-2. BFS

```cpp
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1003];
queue<int> q;
int visited[1003];

void bfs(int start)
{
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (visited[next] == 0)
			{
				q.push(next);
				visited[next] = 1;
			}
		}
	}
}
```

### 2-3. Dijkstra

```cpp
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[20004];
priority_queue<pair<int, int>> pq;
int dist[20004]; // INF로 초기화

void dijkstra(int start)
{
	pq.push(pair<int, int>(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curdist = -pq.top().first;
		pq.pop();

		if (curdist > dist[cur])
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextdist = dist[cur] + graph[cur][i].second;
			if (dist[next] > nextdist)
			{
				dist[next] = nextdist;
				pq.push(pair<int, int>(-dist[next], next));
			}
		}
	}
}
```

### 2-4 Bellman Ford

```cpp
#include <vector>
using namespace std;

struct edge {
	int to, cost;
};

vector<edge> graph[1003];
int dist[1003];

int bellmanFord(int s, int v)
{
	for (int i = 1; i <= v; i++) // dist 초기화
		dist[i] = INF;
	dist[s] = 0;
	int updated;

	for (int i = 0; i < v; i++) // v번 반복
	{
		updated = 0;
		for (int cur = 1; cur <= v; cur++) // 모든 간선을 확인해보면서 dist 갱신
		{
			if (dist[cur] == INF)
				continue;
			for (int j = 0; j < graph[cur].size(); j++)
			{
				int next = graph[cur][j].to;
				int nextdist = dist[cur] + graph[cur][j].cost;
				if (dist[next] > nextdist)
				{
					dist[next] = nextdist;
					updated = 1;
				}
			}
		}
		if (!updated) // 더 이상 갱신되지 않았다면 break
			break;
	}

	if (updated) // v번 반복했음에도 갱신되었다면 음수 사이클이 있음
		return -1;
	return 0;
}
```

### 2-5. Floyd Warshall

```cpp
int dist[102][102]; // INF로 초기화

void floyd(int n)
{
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```
