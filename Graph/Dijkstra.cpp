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
