#include <iostream>
#include <queue>
using namespace std;

//이동을 위한 배열임 (상하좌우)
int Dx[4] = {0, 0, 1, -1};
int Dy[4] = {-1, 1, 0, 0};

//입력 받는 배열
int map[1001][1001] = {0, };

//방문했는지 안했는지 알아보는 것
//마지막 [2]는 벽을 깬건지 아닌지
bool visit[1001][1001][2];

//결과
int r[1001][1001];

//가로 세로 배열 길이
int n, m;

//구조체로 벽을 깼는지 아닌지 여부와 
//x,y좌표를 저장해줌-> 이걸 큐에 그대로 저장
typedef struct {
  int x;
  int y;
  int b;
} s;

//bfs에 사용할 큐
queue<s> q;


int main() {
  cin >>n>> m;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%1d", &map[i][j]);
      //입력 배열이 공백이 없으므로 scamf로 받아줌
    }
  }
  //초기 값 넣어주기
  q.push({1, 1, 0});
  visit[0][0][0] = true;//벽을 부수고 x,y 방문
  visit[0][0][1] = true;//벽을 부수지 않고 x,y 방문
  r[1][1] = 1;
  
  while (!q.empty()) {
    //큐의 fromt 값에서 원하는 변수 설정해줌
    int x = q.front().x;
    int y = q.front().y;
    int b = q.front().b; //벽을 깼는지 안깼는지 여부
    q.pop(); //맨 앞 데이터 삭제

    //상하좌우 이동하기
    for (int i = 0; i < 4; i++) {
      int dx = x + Dx[i];
      int dy = y + Dy[i];
      //없는 좌표를 탐색하지 않게 하기 위해서 
      if (dx > 0 && dy > 0 && dx <= n && dy <= m) {

        //벽이고, 벽을 부순적이 없고, 방문을 하지 않은 경우
        if (map[dx][dy] == 1 && b == 0 && !visit[dx][dy][b + 1]) {
          visit[dx][dy][b+1] = true;
          r[dx][dy] = r[x][y] + 1;
          q.push({dx, dy, b + 1});
        }
        //벽이 아니고, 방문한 적이 없는 경우
        if (map[dx][dy] != 1 && !visit[dx][dy][b]) {
          visit[dx][dy][b] = true;
          r[dx][dy] = r[x][y] + 1;
          q.push({dx, dy, b});
        }
        //마지막에 도착한 경우
        if (dx == n && dy == m) {
          cout<<r[dx][dy]<<endl;
          return 0;
        }
      }
    }
  }
  //목표에 도착하지 못한 경우
  if (n == 1 && m== 1) cout<<"1\n";
  else cout<<"-1\n";
  }