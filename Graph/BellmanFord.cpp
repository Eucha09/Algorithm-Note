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
