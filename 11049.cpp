#include <algorithm>
#include <iostream>
using namespace std;
#define INT_MAX 987654321
int **P;
int minmult(int n, int *d, int **P) {
  int i, j, k, diagonal;
  int **M = new int *[n + 1];
  for (int i = 1; i <= n + 1; i++)
    M[i] = new int[n + 1];
  for (int i = 1; i <= n; i++)
    M[i][i] = 0;
  for (diagonal = 1; diagonal <= n - 1; diagonal++)
    for (i = 1; i <= n - diagonal; i++) {
      j = i + diagonal;
      int minimum = INT_MAX;
      for (int k = i; k <= j - 1; k++) {
        if (minimum > M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j])) {
          minimum = M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]);
          P[i][j] = k;
          M[i][j] = minimum;
        }
      }
    }
  return M[1][n];
}

int main() {
  int n;
  cin >> n;
  int *d = new int[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> d[i - 1]>>d[i];
  }
  P = (int **)malloc(sizeof(int *) * (n + 1));
  for (int i = 1; i <= n; i++)
    P[i] = (int *)malloc(sizeof(int) * n);
  int ans;
  ans = minmult(n, d, P);
  cout <<ans << endl;
}