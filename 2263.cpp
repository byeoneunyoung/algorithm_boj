/*인오더: 중위순회-> 왼쪽으로 탐색을 이어가다가 더이상 탐색할 노드가 없으면 
    루트 노드 방문하고, 오른쪽을 탐색하는 방법을 재귀적으로 반복

    포스트 오더: 왼쪽 자식 노드를 다 탐색하고 더이상 탐색할 노드가 없으면 다시 
    오른쪽 자식 노드를 탐색함, 그 이후 루트를 방문함

    프리 오더: 루트를 먼저 탐색하고 이후에 왼쪽 노드 방문, 이후 오른쪽 노드 방문*/

#include<iostream>
using namespace std;


//숫자 입력을 저장 받을 배열
int in[100001];
//inorder 숫자에 따른 인덱스 저장
int index[100001];
int post[100001];

/*

이분 탐색으로 루트를 출력함

방법: 후위순회의 가장 마지막 값은 루트 값이므로
그 루트 값이 중위순회에서 어디에 위치해 있는지 찾은 뒤
그 루트 값을 중심으로 이분탐색을 재귀적으로 반복함

*/
void BinarySearch(int inf, int inl, int postf, int postl){
    if(inf > inl || postf>postl) return;
    int root_index = index[post[postl]];
    int left = root_index - inf;
    int right = inl - root_index;
    cout<< in[root_index] << " ";

    BinarySearch(inf, root_index-1, postf, postf+left-1);
    BinarySearch(root_index + 1, inl, postf + left, postl -1);
}

int main(){

    //노드 개수
    int n;
    cin>>n;

    for(int i = 1; i<=n; i++){
        cin>>in[i];
        index[in[i]] = i;
    }
    for(int i = 1; i<=n; i++){
        cin>>post[i];
    }
    BinarySearch(1,n,1,n);

}
