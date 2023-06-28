#include <bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node* leftptr;
    node* rightptr;

    node(char val){
        data = val;
        leftptr = NULL;
        rightptr = NULL;
    }
};
node* createBinaryTree(int row, int col, vector<vector<char>> matrix) {
    node* newNode = new node(matrix[row][col]);
    while(matrix[row].size() != NULL){
        if( stoi(matrix[row].begin()) % 2 == 0){
              matrix[row].erase(matrix[row].begin() + col);
    newNode->leftptr = createBinaryTree(row, col + 1, matrix);
    }
    else {
         matrix[row].erase(matrix[row].begin() + col);
    newNode->rightptr = createBinaryTree(row, col + 1, matrix);
    }
    }

    return newNode;
}
int main(){
    int n;
    cin>>n;
    
    vector<vector<char>> matrix;
    for (int i = 0; i < n+1; i++){
       string line;
       vector<char> row;
       getline(cin, line);
       if(i >= 1){
       for( char c: line){
       if(c != ' '){ 
       row.push_back(c); 
       cout<<c<<endl;
       }
       }
       cout<<row[0]<<"row"<<endl;
       matrix.push_back(row);
       }
    }
    struct node* root = new node('start');
    root->leftptr = createBinaryTree(0, 0, matrix);


}

