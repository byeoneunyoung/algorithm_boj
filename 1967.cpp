#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<pair<int,int>> node[10002];
bool visited[10002] = {false,};
int r=0;
int e=0;



void dfs(int, int);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    for(int i = 1; i<=n; i++){
        int p, c, v;
        cin>>p>>c>>v;
        node[p].push_back({c, v});
        node[c].push_back({p, v});
    }

    dfs(1, 0);
    r = 0;
    memset(visited, false, sizeof(visited));

    dfs(e, 0);
    cout<<r<<endl;

}

void dfs(int p, int v){
    if(visited[p]) return;

    visited[p] = true;

    if(r < v){
        r = v;
        e = p;
    }

    for(int i = 0; i<node[p].size(); i++){
        dfs(node[p][i].first, v + node[p][i].second);
    }
}

