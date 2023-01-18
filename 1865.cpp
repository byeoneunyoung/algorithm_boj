#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,m,w;

typedef struct{
int s,e,t;
}edge;

bool tt(int, vector<edge>);

int main(){
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
  int tc;
  cin>>tc;
  for(int i = 1; i<=tc; i++){
    cin>>n>>m>>w;
    vector<edge> edges;
    for(int j = 0; j< m;j++){
      int s,e,t;
      cin>>s>>e>>t;
      edges.push_back({s, e, t});
      edges.push_back({e, s, t});
    }
    for(int j = 0; j<w; j++){
      int s, e, t;
      cin>>s>> e>> t;
      edges.push_back({s, e, -t});
    }
    if(tt(n, edges)) cout<<"YES\n";
    else cout<<"NO\n";
  }
}

bool tt(int n, vector<edge>edges){
  vector<int> dist(n+1, 501);
  dist[1] = 0;
  int s,e,t;
  for(int i = 1; i<n; i++){
    for(int j = 0; j<edges.size(); j++){
      s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
      if(dist[e] > dist[s]+t){
        dist[e] = dist[s] +t;
      }
    }
  }
  for( int j = 0; j < edges.size(); j++){
    s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
    if(dist[e] > dist[s]+t){
      return true;
    }
  }
  return false;
}