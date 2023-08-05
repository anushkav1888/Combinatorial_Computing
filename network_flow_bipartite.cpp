
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
                                                             
bool bfs(int V, int rGraph[100][100], int s, int t, int parent[])
{
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				if (v == t) {
					parent[v] = u;
					return true;          
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return false;
}
void fordFulkerson(int V, int graph[100][100], int s, int t, int ans[100][2], int n)
{
	int u, v;

	
	int rGraph[100][100];
			
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; 

	int max_flow = 0; 

	
	while (bfs(V, rGraph, s, t, parent)) {
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		max_flow += path_flow;
	}

for(int p = 1; p < n+1; p++){
	ans[p][0] = p;
	for( int y = n + 1; y < V; y++){
		if(rGraph[p][y] == 0){
			ans[p][1] =  y-n;
			break;
		}
	}
	
}}

int main()
{
 
	int n, m;
	cin>>n>>m;
	int V = n + m + 2;
	vector<vector<int>> matrix;
    for (int i = 0; i < n+1; i++){
       string line;
       vector<int> row;
       getline(cin, line);
       if(i >= 1){
       for( char c: line){
       if(c != ' '){ 
        int r = c - '0';
        row.push_back(r); 
        }
       }
       matrix.push_back(row);
       }
    }
	int ans[100][2];
	for(int o = 1; o < n+1; o++){
		ans[o][1] = -1;
	}
	int graph[100][100];
	for(int h = 0; h < 100; h++){
		for(int f = 0; f < 100; f++){
			graph[h][f] = -1;
		}
	}
	int i = 0;
		for(int j = 1; j < n + 1; j++){
			graph[i][j] = 1;
		}
		for( int k = 1; k < m + 1; k++){
			graph[k + n][n + m +1] = 1;
		}
	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < matrix[i].size(); j++){
			graph[i+1][n + matrix[i][j]] = 1;
		}
	}


		 fordFulkerson(V ,graph, 0, n + m +1, ans, n);
	bool flag = true;
		 for(int a = 1; a < n+1; a++){
			if(ans[a][1] == -1){
				flag = false;
			}
		 }
		if(flag == true){
		 for(int a = 1; a < n+1; a++){
			cout<<ans[a][0]<<" "<<ans[a][1]<<endl;
		 }
		}
		if(flag == false){
			cout<<"-1"<<endl;}
	return 0;
}
