#include <iostream>
#include <vector>

using namespace std;
vector <int> visited(15, -1); //visited[i][j]를 visited[i] = j로 표현함
//어차피 한 행에 하나씩 들어가야하니까.
int n;
int answer = 0;
//qcolumn은 queen이 위치한 행
bool check(int qcolumn){
  for(int i = 0; i<qcolumn; i++)
    if(visited[qcolumn] == visited[i] || qcolumn - i == abs(visited[qcolumn]-visited[i]))
      //abs는 절댓값 함수, 같은 행에 퀸이 있거나, 퀸이 위치한 행이 이전에 퀸을 배치했던 행과 같은지
      return 0;//놓지 못하는 위치이면 return 0;
  return 1;//가능하면 return 1;
}
void queen(int qcolumn){
  if(qcolumn == n){
    answer++;
    return;
  }

  for(int i = 0; i<n; i++){//i는 앞에서 설명한 j의 역할을 함
    visited[qcolumn] = i;//[qcolumn][i] 에 배치해보고 가능하면
    if(check(qcolumn)) queen(qcolumn + 1); //행을 + 1해서 배치해봄.
  }
  
}

int main() {
  cin>>n;
  queen(0);
  cout<<answer<<endl;
}