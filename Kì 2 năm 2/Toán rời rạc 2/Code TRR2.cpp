//---------DFS----------
int a[100][100], n, u, vs[100];
void DFS(int u)
{
	stack<int> st;
	st.push(u);
	vs[u] = 1;
	cout << u << " ";
	while(!st.empty())
	{
		int s = st.top();
		st.pop();
		for(int i = 1; i <= n; i++)
		{
			if(a[s][i] == 1 && vs[i] == 0)
			{
				cout << i << " ";
				vs[i] = 1;
				st.push(s);
				st.push(i);
				break;
			}
		}
	}
}
//---------BFS----------
int a[100][100], n, u, vs[100];
void BFS(int u)
{
	queue<int> q;
	q.push(u);
	vs[u] = 1;
	cout << u << " ";
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		for(int i = 1; i <= n; i++)
		{
			if(vs[i] == 0 && a[s][i] == 1)
			{
				q.push(i);
				vs[i] = 1;
				cout << i << " ";
			}
		}
	}
}
//--------DIJKSTRA---------
int a[100][100], n, u, vs[100], pre[100], d[100];
void Dijkstra(int u)
{
	d[u] = 0;
	for(int i = 1; i <= n; i++)
	{
		d[i] = a[u][i];
		pre[i] = u;
	}

	while(1)
	{
		int s = 0, min = 1e9;
		for(int i = 1; i <= n; i++)
		{
			if(vs[i] == 0 && d[i] < min)
			{
				s = i;
				min = d[s];
			}
		}
		if(s == 0) return;
		vs[s] = 1;
		for(int i = 1; i <= n; i++)
		{
			if(vs[i] = 0 && d[i] > d[s] + a[s][i])
			{
				d[i] = d[s] + a[s][i];
				pre[i] = s;
			}
		}
	}
}