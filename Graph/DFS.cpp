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
