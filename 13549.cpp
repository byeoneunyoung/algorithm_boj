#include <cstring>
#include <deque>
#include <iostream>
#define MAX_SIZE 100001

using namespace std;

int n, k;
int v[MAX_SIZE];

int bfs() {
  deque<int> dq;
  dq.push_back(n);
  v[n] = 1;
  while (!dq.empty()) {
    int pos_x = dq.front();
    dq.pop_front();
    
    //수빈이의 현재 위치가 동생의 위치랑 같으면 현재 값에서 1을 빼주고 리턴, 왜냐하면 시작할 때 1로 두고 시작했기 떄문에
    if (pos_x == k)
      return v[k] - 1;
    //순간이동은 덱의 앞에 넣어줌
    //이동할 때, 동생이 있을 수 있는 위치보다 커지거나 0보다 작아지면 유망하지 않음, 그리고 이미 방문한 위치에 또 방문하는 일이 없도록 함
    
    if (pos_x * 2 < MAX_SIZE && !v[pos_x * 2]) {
      dq.push_front(pos_x * 2);
      //순간이동은 0초 걸림
      v[pos_x * 2] = v[pos_x];
    }
    if (pos_x + 1 < MAX_SIZE && !v[pos_x + 1]) {
      dq.push_back(pos_x + 1);
      v[pos_x + 1] = v[pos_x] + 1;
    }
    if (pos_x - 1 >= 0 && !v[pos_x - 1]) {
      dq.push_back(pos_x - 1);
      v[pos_x - 1] = v[pos_x] + 1;
    }
  }
}

int main() {
  cin >> n >> k;
  cout << bfs() << endl;
}
