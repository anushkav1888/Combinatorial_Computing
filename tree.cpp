#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* leftptr;
    node* rightptr;

    node(int val){
        data = val;
        leftptr = NULL;
        rightptr = NULL;
    }
};


void printLabeledBinaryTree(struct node* root, int level = 0) {
    if (root == nullptr) {
        return;
    }

    printLabeledBinaryTree(root->rightptr, level + 1);

    for (int i = 0; i < level; ++i) {
        cout << "   ";
    }

     cout << "|--" << root->data << std::endl;

    printLabeledBinaryTree(root->leftptr, level + 1);
}

void assign(struct node* root, vector <int> row , char a){
 if(row.size() > 0){    
    if(a == 'l'){
        root->leftptr = new node(row[0]);
        row.erase(row.begin());
        assign(root->leftptr, row, 'l');        
    }
    else if(a == 'r' && row.size() > 0){
        root->rightptr = new node(row[0]);
        row.erase(row.begin());
        assign(root->rightptr, row, 'r');  
    }
 } 
}
void central_unit(struct node* root, int index, char a, vector<vector<int>> matrix){
    if(index == matrix.size()){
        return;
    }
   
    if(a == 'r'){
     assign(root->leftptr, matrix[index], 'r');
      if(index == (matrix.size()-1) ) {
        return;}
     if(matrix[index+1][0] % 2 == 0){
     central_unit(root->leftptr, index+1,'l',matrix);
     }
    if(matrix[index+1][0] % 2 != 0){
     central_unit(root->leftptr, index+1,'r',matrix);
     } 
    }
    
    else if (a == 'l')
    {
      assign(root->rightptr, matrix[index], 'l');
      if(index == (matrix.size()-1) ) {
        return;
      }
      if(matrix[index+1][0] % 2 == 0){
     central_unit(root->rightptr, index+1,'l',matrix);
     }
    if(matrix[index+1][0] % 2 != 0){
     central_unit(root->rightptr, index+1,'r',matrix);
     } 
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> matrix;
    for (int i = 0; i < n+1; i++){
       string line;
       vector<int> row;
       getline(cin, line);
       if(i >= 1){
       for( char c: line){
       if(c != ' '){ 
        int r = c - '0';
        row.push_back(r); 
        }
       }
       matrix.push_back(row);
       }
    }
    struct node* start = new node(00);
    assign(start, matrix[0], 'l');
    if(matrix.size() >=2 ){
    assign(start, matrix[1], 'r'); 
    }
    char a;
     if(matrix.size() <= 2){
     printLabeledBinaryTree(start);}
    if(matrix.size() > 2){
    if(matrix[2][0] % 2 == 0){
        a = 'l';
    }
    else if(matrix[2][0] % 2 != 0){
        a = 'r';
    }
    central_unit(start, 2, a, matrix);
    printLabeledBinaryTree(start);
    }

}
