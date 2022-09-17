#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[9] = {0, };
int num[9] = {0, };
int visit[9] = {0, };

void dfs(int a){
  if(a == m){
    for(int i = 0; i<m; i++){
      cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return;
  }
  for(int i = 1; i<=n ; i++){
    if(!visit[i]){
      visit[i] = 1;
      arr[a] = num[i];
      dfs(a+1);
      visit[i] = 0;
    }
  }
}
int main() {
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    cin>>num[i];
  }
  sort(num, num+n+1);
  
  dfs(0);
}