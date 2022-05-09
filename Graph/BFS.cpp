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
