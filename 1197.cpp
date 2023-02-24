#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Point{
    int u;
    int v;
    int w;
};

vector<Point>list;
int parent[10001];
int n, m, ans, cnt;

bool cmp(Point a, Point b){
    if(a.w < b.w) return true;
    else return false;
}

void init(){
    for(int i = 1; i<=n; i++){
        parent[i] = i;
    }
}

int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int x, int y, int w){
    int a = find(x);
    int b = find(y);

    if(a == b) return;
    parent[b] = a;
    ans += w;
    cnt++;
}
void func(){
    for(int i = 0; i<m; i++){
        int u = list[i].u;
        int v = list[i].v;
        int w = list[i].w;

        Union(u, v, w);
        if(cnt == n-1) break;
    }
    cout<<ans<<"\n";
}

int main(){
    int u, v, w;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        cin>>u>>v>>w;
        list.push_back({u,v,w});
    }
    sort(list.begin(), list.end(), cmp);
    init();
    func();
}