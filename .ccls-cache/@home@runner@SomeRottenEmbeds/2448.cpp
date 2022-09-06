#include <iostream>
#define MAX 2 * (3072 + 1)
using namespace std;

int n;
char star[MAX / 2][MAX];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      star[i][j] = ' ';
    }
  }
}
void print(int h, int y, int x) {
  if (h == 3) {
    star[y][x] = '*';
    star[y+1][x-1] = '*';
    star[y+1][x+1] = '*';
    for (int i = x - 2; i < x + 3; i++) {
      star[y + 2][i] = '*';
    }
    return;
  }
  else{
    int nh = h/2;
    print(nh, y, x);
    print(nh, nh + y, nh + x);
    print(nh, nh + y, x - nh);
  }
}
void solve(){
  for(int i = 0; i<n; i++){
    for(int j = 0; j<2*n-1; j++){
      cout<<star[i][j];
    }
    cout<<endl;
  }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    print(n, 0, n-1);
    solve();
    return 0;
  }