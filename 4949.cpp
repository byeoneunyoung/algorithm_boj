#include<iostream>
#include<stack>
#include <string>

using namespace std;

stack <char> ss;

int main(){
    string arr;
    while(1){
        getline(cin, arr);
        if(arr == ".") break;
        int state = 0;
        int l = arr.length();
        for(int i = 0; i< l ;i++){

            //열림 괄호가 들어올 경우
            if(arr[i] == '(' || arr[i] =='[') ss.push(arr[i]);

            //소괄호 닫힘의 경우
            else if(arr[i] == ')'){
                if(ss.empty() == 0 && ss.top() == '(') ss.pop();
                else if(ss.empty() == 0 && ss.top() != '('){
                    state = 1;
                    break;
                }
                else if(ss.empty()==1){
                    state = 1;
                    break;
                }
            }
            //대괄호 닫힘의 경우
            else if(arr[i] == ']'){
                if(ss.empty() == 0 && ss.top() == '[') ss.pop();
                else if(ss.empty() == 0 && ss.top() != '['){
                    state = 1;
                    break;
                }
                else if(ss.empty()==1){
                    state = 1;
                    break;
                }
            }  
        }
        //yes,no출력 경우의 수
        if(ss.empty() == 0 || state == 1) cout<<"no\n";
        else if(ss.empty() == 1 && state == 0) cout<<"yes\n";
        //stack다 비우기
        while(!ss.empty()) ss.pop();
    }//이미 for문 돌기 전에 state는 초기화 되므로 따로 할 필요 없음
}
