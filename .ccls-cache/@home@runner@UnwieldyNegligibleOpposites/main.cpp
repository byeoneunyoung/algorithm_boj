#include <algorithm>
#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;
int arr[105][105];
int P[105][105];
vector<int> v;

int a, b, c;

void floyd(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (arr[i][j] > arr[i][k] + arr[k][j]) {
          P[i][j] = k;
          arr[i][j] = arr[i][k] + arr[k][j];
        }
      }
    }
  }
}


void Path(int i, int j) {

  if (P[i][j] != 0) {
    Path(i, P[i][j]);
    v.push_back(P[i][j]);
    Path(P[i][j], j);
  }
}

int main() {

  int n = 0, m = 0;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      P[i][j] = 0;
      if (arr[i][j] < 1 && i != j)
        arr[i][j] = INF;
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    arr[a][b] = min(arr[a][b], c);
  }

  floyd(n);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (arr[i][j] == INF)
        arr[i][j] = 0;
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      Path(i, j);
      if (i == j)
        cout << 0;
      else {
        cout << 2 + v.size() << " " << i << " ";
        for (int k = 0; k < v.size(); k++) {
          cout << v[k] << " ";
        }
        cout << j;
        v.clear();
      }
      cout << endl;
    }
  }
}
