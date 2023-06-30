#include <bits/stdc++.h>

using namespace std;
int count1 = 0;
int count2 = 0;

void give(vector<vector<vector<int>>> matrix, int k){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout<<matrix[k][i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSmallerPartition(const vector<int>& partition1, const vector<int>& partition2) {
    if (partition1.size() < partition2.size()) {
        return true;
    } else if (partition1.size() > partition2.size()) {
        return false;
    }

    for (size_t i = 0; i < partition1.size(); ++i) {
        if (partition1[i] < partition2[i]) {
            return true;
        } else if (partition1[i] > partition2[i]) {
            return false;
        }
    }

    return false; //checks whether two 2d vec k first row compare
}

void generateSubsets(const vector<int>& set, vector<int> set_in_use, vector<int>& subset, int index, vector<vector<vector<int>>>& partition_store) {
    if( index == set_in_use.size() && subset.size() == 0){
        return;
    }
    
    
    if (index == set_in_use.size() && subset.size()>0 )         //subset found
     { 
        partition_store[count1].push_back(subset);
        for(int i = 0; i < subset.size(); i++){
            int valueToRemove = subset[i];
            auto it = find(set_in_use.begin(), set_in_use.end(), valueToRemove);
            if (it != set_in_use.end()) {
            set_in_use.erase(it);
            }
        }    
            index = -1;
            return;
        }
        if(set_in_use.size() != 0 && set_in_use.size() < set.size()){
            generateSubsets(set, set_in_use, subset,index+1, partition_store);
            subset.push_back(set[index]);
            generateSubsets(set,  set_in_use, subset,index + 1, partition_store);
             subset.pop_back();

        }
        if(set_in_use.size() == 0){
            count1++;
            set_in_use = set;
        }

    generateSubsets(set, set_in_use, subset, index + 1, partition_store);
    subset.push_back(set[index]);
    generateSubsets(set,  set_in_use, subset,index + 1, partition_store);
    subset.pop_back();
}



void generateAllsubsets(const vector<int>& set, vector<vector<int>>& all, int k){
    vector<vector<vector<int>>> part(k + 1, vector<vector<int>>());
    vector<int> set_in_use = set;
    vector<int> subset;
    generateSubsets(set,set_in_use, subset, 0, part);
     give(part, k);


}

int main() {
    int N;
    cin >> N;
    vector<int> set;
    for(int i = 0; i < N; i++){
        set.push_back(i+1);
    }
    int k; 
    cin >> k;
    vector<vector<int>> all;
    generateAllsubsets(set ,all, k);

    return 0;
}
