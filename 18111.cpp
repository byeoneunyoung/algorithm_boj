#include<iostream>
using namespace std;
int land[501][501];
int n, m, b;
int main(){
    cin>>n>>m>>b;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m; j++){
            cin>>land[i][j];
        }
    }

    int min_t = 0x7fffffff, max=-1;
    for(int i = 0; i<=256; i++){
        int sub = 0;//제거하는 횟수(시간은 2초)
        int add = 0;//인벤토리의 블록을 더하는 횟수(시간은 1초)
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=m; k++){
                int height = land[j][k] - i; // 기준 높이와 현재 블럭 높이 비교
                if(height<0) add-=height; //현재 블럭 높이가 더 크면 add횟수는 (-둘의 차이)
                else sub += height;//아니면 그냥 둘의 차이 더해주기
            }
        }
        if(sub + b >= add){
            int cur_t= 2* sub + add; // 현재 시간
            if(min_t >= cur_t)//최소인지 비교
            {
                min_t = cur_t;
                max = i;
            }
        }
    }
    cout<<min_t<<" "<<max<<"\n";
}

