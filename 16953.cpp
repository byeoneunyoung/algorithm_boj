#include <iostream>
using namespace std;

int main() {
  long a,b;
  int cnt = 0;
  cin >> a >> b;
  while(1){
    if(a>b) {
      cout<<-1<<endl;
      break;
    }
    if(a==b){
      cnt++;
      cout<<cnt<<endl;
      break;
    }
    if(b%2 == 0){
      b /= 2;
    }
    else if(b%10 == 1){
      b /= 10;
    }
    else{
      cout<<-1<<endl;
      break;
    }
    cnt++;
  }
}