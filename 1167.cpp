#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef struct{
    int index;
    int dist;
}node;

int m_d = 0, m_n = 0;
bool visit[100001];
vector<node> tree[100002];
//tree[a][0].first = b, tree[a][0].second = c면 
//a에서 b로 가는 가중치 c를 가진 간선을 의미함

void dfs(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin>>v;
    int a, b, c;
    for(int i = 0; i<v; i++){
        cin>>a;
        while(true){
            cin>>b;
            if(b == -1) break;
            cin>>c;
            
            tree[a].push_back({b, c});
            tree[b].push_back({a, c});
        }
    }

    dfs(1,0);
    memset(visit, false, sizeof(visit));
    m_d = 0;
    dfs(m_n, 0);
    cout<<m_d<<"\n";

}

void dfs(int a, int c){
    if(visit[a]) return;
    if(m_d<c){
        m_d = c;
        m_n = a;
    }
    visit[a] = true;

    for(int i= 0; i< tree[a].size(); i++){
        int nextIndex = tree[a][i].index;
        int nextDist = tree[a][i].dist;
        dfs(nextIndex, nextDist + c);
    }
}