#include <iostream>
using namespace std;

class Node {
  char data;
  Node *left;
  Node *right;
public:
  Node() :data(0), left(NULL), right(NULL){}
  void setData(char c){data = c;}
  void setLeft(Node *l){left = l;}
  void setRight(Node *r){right = r;}

  void preorder(Node *cur){
    if(cur){
      cout<<cur->data;
      preorder(cur->left);
      preorder(cur->right);
    }
  }
  void inorder(Node *cur){
    if(cur){
      inorder(cur->left);
      cout<<cur->data;
      inorder(cur -> right);
    }
  }
  void postorder(Node *cur){
    if(cur){
      postorder(cur->left);
      postorder(cur->right);
      cout<<cur->data;
    }
  }
};

int main() {
  int n;
  cin >> n;
  Node *node = new Node[n];
  for (int i = 0; i < n; i++) {
    char d, l, r;
    cin>>d>>l>>r;
    if(d != '.')
      node[(int)(d-'A')].setData(d);
    if(l != '.')
      node[(int)(d-'A')].setLeft(&node[(int)(l-'A')]);
    else node[(int)(d-'A')].setLeft(NULL);
    if(r != '.')
      node[(int)(d-'A')].setRight(&node[(int)(r-'A')]);
    else node[(int)(d-'A')].setRight(NULL);
  }
  node[0].preorder(&node[0]);
  cout<<endl;
  node[0].inorder(&node[0]);
  cout<<endl;
  node[0].postorder(&node[0]);
  cout<<endl;
}