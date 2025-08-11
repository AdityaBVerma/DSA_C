#include<bits/stdc++.h>
using namespace std;

void countFreeq(int arr[], int n){
    vector<bool> visited(n, false);
    for(int i = 0; i<n; i++){
        int count=1;
        if(visited[i]) continue;
        for(int j = i+1; j <n ;j++){
            if(arr[i] == arr[j]){
                visited[j] = true;
                count++;
            }
        }
        cout<< arr[i]<< "->" << count<<endl;
    }
}

void countFreq(int arr[], int n ){
    int hash[n] = {0};
    for(int i = 0; i<n;i++){
        hash[arr[i]]+=1;
    }
    for(int i = 0; i <n ; i++){
        cout<< i << " -> "<< hash[i]<<endl;
    }
}

void countFreqMap(int arr[], int n){
    unordered_map<int, int> hash; // can use map too just will become ordered
    for(int i = 0 ; i < n ; i++ ){
        hash[arr[i]]++;
    }
    for(auto hashval : hash){
        cout << hashval.first << " -> "<< hashval.second<<endl;
    }
}

int maxFrequency(vector<int>& nums) {
        unordered_map<int,int> hash;
        int maxf= 0;
        for(auto num : nums){
            hash[num]++;
            maxf = max(maxf, hash[num]);
        }
        return maxf;
    }

int main(){
    vector<int> arr = {1,2,1,3,5,2,2,2};
    cout<<maxFrequency(arr);

    return 0;
}