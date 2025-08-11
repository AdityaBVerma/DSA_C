#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

void setZeroesBrute(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n,0);
    vector<int> col(m,0);
    for(int i= 0; i<n ;i++){
        for(int j = 0 ; j< m ; j ++){
            if(matrix[i][j] ==0){
                row[i] =1 ;
                col[j] =1 ;
            }
        }
    }
    for(int i = 0; i< n ;i++){
        for(int j = 0; j <m ;j ++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroes(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int first = 1;
    int second =1;
    for(int i = 0; i<n ; i++){
        for (int j = 0; j<m ; j ++){
            if(matrix[i][j] == 0){
                if( i==0 ) {
                    first = 0;
                    continue;
                }
                if( j==0 ) {
                    second = 0;
                    continue;
                }
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = n-1 ;i >=0  ;i --){
        for(int j = m-1 ;j >=0 ;j --){
            if(matrix[i][0] == 0 || matrix[0][j] ==0){
                matrix[i][j] = 0;
            }
        }
    }
    if (first ==0 ){
        for(int i = 0; i<m ; i++){
        matrix[0][i]=0;
        }
    }
    if (second==0 ){
        for(int i = 0; i<n ; i++){
        matrix[i][0]=0;
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i =0 ;i < n ; i++){
        for(int j = i+1; j< n ;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0;i <n;i++){
        for(int j = 0; j<n/2;j++){
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for(int i =0;i<4;i++){
        rotate(mat);
        if(mat == target){
            return true;
        }
    }
    return false;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n =  matrix[0].size();
    vector<int> answer;
    for(int i= 0; i<(min(m, n) + 1) / 2 ;i++){
        for(int j = i; j<n-i;j++){
            answer.push_back(matrix[i][j]);
        }
        for(int k = i+1; k<m-i;k++){
            answer.push_back(matrix[k][n-i-1]);
        }
        if(m-i-1!=i){
            for(int j = n-2-i; j>=i;j--){
            answer.push_back(matrix[m-i-1][j]);
            }
        }
        if(n-i-1!=i){
            for(int k=m-i-2; k>i; k--){
                answer.push_back(matrix[k][i]);
            }
        }
    }
    return answer;
}

vector<int> spiralOrderCleaner(vector<vector<int>>& matrix) {
    vector<int> ans;
    int top =0; int right = matrix[0].size() -1;
    int left = 0; int bottom = matrix.size() -1;
    while(top<=bottom && left<=right){
        for(int j= left; j<=right;j++){
            ans.push_back(matrix[top][j]);
        }
        top++;
        for(int j = top;j<=bottom; j++){
            ans.push_back(matrix[j][right]);
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer(numRows);
    for(int i = 0; i<numRows ;i++){
        answer[i].resize(i+1);
    }
    for(int i =0 ;i<numRows;i++){
        answer[i][0] = 1;
        for(int j = 1; j<=i-1;j++){
            answer[i][j] = answer[i-1][j-1] + answer[i-1][j];
        }
        answer[i][i] = 1;
    }
    return answer;
}

vector<int> majorityElement(vector<int> nums) {
    int count1 = 0; int count2 = 0;
    int candidate1= -1; int candidate2 = -1;
    for(int num : nums){
        if(num == candidate1) count1 ++;
        else if(num == candidate2) count2 ++;
        else if(count1 ==0 ){
            candidate1 = num;
            count1++;
        } else if( count2 ==0){
            candidate2 = num;
            count2++;
        } else {
            count1--;
            count2--;
        }
    }
    count1=count2=0;
    for(int num: nums ){
        if(candidate1 == num) count1++;
        else if(candidate2 == num) count2++;
    }
    vector<int> answer;
    if(count1>nums.size()/3) answer.push_back(candidate1);
    if(count2>nums.size()/3) answer.push_back(candidate2);

    return answer;
}

vector<int> majorityElementHash(vector<int> nums) {
    unordered_map<int,int> freq;
    vector<int> answer;
    for(int num : nums){
        freq[num]++;
    }
    for(auto i: freq){
        if(i.second> nums.size()/3 ) answer.push_back(i.first);
    }
    return answer;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();

    vector<int> ans = majorityElementHash({2,1,1,2,1,2,2,6});
    for(int i : ans){
        cout<< i<<" ";
    }
    // int n = matrix.size();
    // int m = matrix[0].size();

    // findRotation(matrix);
    
    // for (int i = 0; i < n; i++){
    //     for(int j = 0; j < m ; j++){
    //         cout<< matrix[i][j]<<" ";
    //     }
    //     cout<< endl;
    // }
    // for( auto i : matrix){
    //     for(int nums : i){
    //         cout<<nums<<" ";
    //     }
    //     cout<<endl;
    // }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout <<endl<< "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}