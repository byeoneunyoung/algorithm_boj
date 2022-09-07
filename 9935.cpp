#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  string boom;
  bool check = 0;
  string answer;
  //폭발 문자열 입력 받기
  cin >> str >> boom;

  //문자열 입력 받아서 스택에 쌓기
  for (int i = 0; i < str.length(); i++) {
    cout << i << ": " << answer << endl;
    answer += str[i];

    if (str[i] == boom[boom.length() - 1]) {
      for (int j = 0; j < boom.length(); j++) {

        if (boom[j] == answer[answer.length() - boom.length() +j])
          check = 1;

        else {
          check = 0;
          break;
        }
      }
    }
    if (check) {
      for (int j = 0; j < boom.length(); j++) {
        answer.pop_back();
      }
      check = 0;
    }
  }

  if (answer.empty()) {
    cout << "FRULA";
    return 0;
  }

  else {
    cout << answer;
  }
}
