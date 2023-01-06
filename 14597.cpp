#include <cmath>
#include <iostream>
#include <algorithm>
#define inf 987654321
using namespace std;
int b1[103][103];
int b2[103][103];
int dp[103][103];

int main() {
  int h, w;
  // height, weight
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++)
      cin >> b1[i][j];
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++){
      cin >> b2[i][j];
      b2[i][j] = pow(abs(b1[i][j] - b2[i][j]),2);
    }
  }

  for(int i = 0; i<=h+1; i++){
    dp[i][0] = -1;
    dp[i][w+1]= -1;
  }
  for(int i = 0; i<=w+1; i++){
    dp[0][i] = -1;
    dp[h+1][i] = -1;
  }
  for(int i = 1; i<=w; i++){
    dp[1][i] = b2[1][i];
  }
  int a, b, c;

  for(int i = 2; i<=h; i++){
    for(int j = 1; j<=w; j++){
      if(dp[i-1][j-1]<0){ a = inf;}
      else a = dp[i-1][j-1]+b2[i][j];

      if(dp[i-1][j]<0){ b = inf;}
      else b = dp[i-1][j]+b2[i][j];
      
      if(dp[i-1][j+1]<0){ c = inf;}
      else c = dp[i-1][j+1]+b2[i][j];
      
      dp[i][j] = min({a,b,c});
    }
  }
  int min = inf;
  for (int i = 1; i <= w; i++) {
    if(dp[h][i]<min) min = dp[h][i];
  }
  cout<<min<<endl;
  
}