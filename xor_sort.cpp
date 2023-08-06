#include <iostream>
#include <vector>
using namespace std;
int counter = 0;
vector<vector<int>> inn;
int findMinFromIndex(const vector<int>& vec, int i) {
    if (i < 0 || i >= vec.size()) {
        return 0;
    }

    int minElement = vec[i];
    int index = i;
    for (int j = i + 1; j < vec.size(); ++j) {
        if (vec[j] < minElement) {
            minElement = vec[j];
            index = j; 
        }
    }

    return index;
}


void swapNumbers(std::vector<int>& numbers, int index1, int index2, vector<vector<int>> &in) {
    if (index1 == index2) {
        return;
    }

    int number1 = numbers[index1];
    int number2 = numbers[index2];

    number1 = number1 ^ number2;
    vector<int> row;
    row.push_back(index1+1);
    row.push_back(index2+1);
    in.push_back(row);
    row.clear();
    number2 = number1 ^ number2;
    row.push_back(index2+1);
    row.push_back(index1+1);
    in.push_back(row);
    row.clear();
    number1 = number1 ^ number2;
    row.push_back(index1+1);
    row.push_back(index2+1);
    in.push_back(row);
    row.clear();


    numbers[index1] = number1;
    numbers[index2] = number2;
}

int main() {
    int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
    cin>>arr[i];}
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        numbers.push_back(arr[i]);
    }
    int index = 0;
    for(int  i = 0; i < n; i++){
    int a = findMinFromIndex(numbers, index);    
    int index1 = index; 
    int index2 = a;
    if(index1 != index2){
    swapNumbers(numbers, index1, index2, inn);
    counter++;
    }
    index++;
    }
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout<<counter*3<<endl;

    for(int p = 0; p < counter*3; p++){
        
        cout<<inn[p][0]<<" "<<inn[p][1]<<endl;
        
    }
inn.clear();
counter = 0;    
}
}
