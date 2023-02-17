
#include <algorithm>
#include <iostream>
using namespace std;

int r, c, ans = 0;

char board[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool al[26] = {
    0,
};

void backtracking(int, int, int);
bool promising(int, int);

int main() {
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> board[i][j];
    }
  }
  al[board[1][1] - 'A'] = true;
  backtracking(1, 1, 1);
  cout << ans << endl;
}

void backtracking(int x, int y, int cnt) {
  bool can = false;
  for (int i = 0; i < 4; i++) {
    int fx = x + dx[i];
    int fy = y + dy[i];
    if (fx > 0 && fy > 0 && fx <= r && fy <= c) {
      if (promising(fx, fy)) {
        can = true;
        backtracking(fx, fy, cnt + 1);
        al[board[fx][fy] - 'A'] = false;
      }
    }
  }
  if (!can) {
        ans = max(ans, cnt);
        return;
      }
}

bool promising(int x, int y) {
  int check = board[x][y];
  if (al[check - 'A'])
    return false;
  else {
    al[check - 'A'] = true;
    return true;
  }
}