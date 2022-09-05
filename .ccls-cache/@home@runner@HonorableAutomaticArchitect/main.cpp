#include <iostream>
#define MAX 1005

using namespace std;

int n;
char arr[MAX][MAX] ={0, };
int ans[MAX][MAX];
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {0,-1,1,-1,1,0,-1,1};

void find(int y, int x){
  //arr[y][x]가 숫자면 *넣고 다음
  if(arr[y][x] != '.'){
    ans[y][x] = -1;
    return;
  }
  else{
    for(int i = 0; i<8; i++){
      if((y+dy[i])>0 && (x+dx[i])>0 && (y+dy[i])<=n && (x+dx[i])<=n){
        if(arr[y+dy[i]][x+dx[i]] != '.'){
          ans[y][x] += arr[y+dy[i]][x+dx[i]] - '0';
          }
        }
      }
    }
  }

int main() {
  cin>>n;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cin>>arr[i][j];
      ans[i][j] = 0;
      }
  }
    
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      find(i, j);
    }
  }


  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      if(ans[i][j] > 9)
           cout<<'M';
      else if(ans[i][j] == -1)
          cout<<'*';
      else{
        cout<<ans[i][j];
      }
    }
    cout<<endl;
  }
}
