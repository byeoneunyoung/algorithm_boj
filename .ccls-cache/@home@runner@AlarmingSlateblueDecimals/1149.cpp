#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin>>n;
  int cost[3][1001] = {{0, }, {0, }, {0, }};
  int rgb[3];
  for(int i = 1; i<=n; i++){
    cin>>rgb[0]>>rgb[1]>>rgb[2]; 
    cost[0][i] = min(cost[1][i-1], cost[2][i-1]) + rgb[0];
    cost[1][i] = min(cost[0][i-1], cost[2][i-1]) + rgb[1];
    cost[2][i] = min(cost[1][i-1], cost[0][i-1]) + rgb[2];
  }
  cout<<min(cost[2][n], min(cost[0][n], cost[1][n]))<<"\n";
  
}