#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> graph[100001];
int parent[100001];

void dfs(int node) {
	
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (parent[next] == 0) {
			parent[next] = node;
			dfs(next);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		//양방향그래프
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs(1);
	
	for (int i = 2; i <= n; i++) {
		cout <<parent[i]<< '\n';
	}
}