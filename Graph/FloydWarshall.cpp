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
