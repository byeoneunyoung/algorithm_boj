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
            
            if(arr[i] == '(' || arr[i] =='[') ss.push(arr[i]);
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
        if(ss.empty() == 0 || state == 1) cout<<"no\n";
        else if(ss.empty() == 1 && state == 0) cout<<"yes\n";
        while(!ss.empty()) ss.pop();
    }
}
