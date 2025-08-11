#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums){
    int i = 0;
    int j = 0;
    while(j<nums.size()){
        if(nums[i] == nums[j]){
            j++;
        }else
        {
            nums[++i] = nums[j];
        }
    }
    return i+1;
}

void rotate(vector<int>& nums, int k) {
    int temp[k] = {0};
    int n = nums.size();
    for(int i = 0; i<k ;i ++){
        temp[i] = nums[i];
    }
    for(int i = 0; i<n;i++){
        nums[i] = nums[i+k];
    }
    for(int i = n-k; i<n ;i ++){
        nums[i] = temp[i-(n-k)];
    }
}

void rotate1(vector<int>& nums, int k) {
    int n = nums.size();
    k= k%n;
    vector<int> temp(k);
    for(int i = 0; i<k ;i ++){
        temp[i] = nums[n-k+i];
    }
    for(int i = n-1; i>=k;i--){
        nums[i] = nums[i-k];
    }
    for(int i =0; i<k ;i ++){
        nums[i] = temp[i];
    }
}

void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[j]==0 && nums[j]!=nums[i]  ){
                swap(nums[j],nums[i]);
                j++;
            }
            if(nums[j]!=0 && j<i){
                j++;
            }
        }
    }

void moveZeroRightCode(vector<int>& nums){
    int j  = 0;
    for(int i = 0;i<nums.size();i++){
        if (nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
}

vector<int> unionOfTwoSortedArrays(vector<int> arr1, vector<int> arr2){
    int n1= arr1.size();
    int n2 = arr2.size();
    vector<int> unionArr;
    int i,j=0;
    while (i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j]){
            if(arr1[i]!=unionArr.back()){
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else
        {
            if(arr2[j]!= unionArr.back()){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
        
    }
    while (i<n1)
    {
        if(arr1[i]!=unionArr.back()){
            unionArr.push_back(arr1[i]);
            i++;
        }
    }
    while (j<n2)
    {
        if (arr2[j] != unionArr.back())
        {
            unionArr.push_back(arr2[j]);
            j++;
        }
        
    }
    
return unionArr;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
vector<int> intersection;
sort(nums1.begin(), nums1.end());
sort(nums2.begin(), nums2.end());
int n1 = nums1.size();
int n2 = nums2.size();
int i = 0;
int j = 0;
while (i<n1 && j<n2)
{
    if(nums1[i]<nums2[j])i++;
    else if ( nums1[i]> nums2[j]) j++;
    else{
        if(intersection.empty() || nums1[i] != intersection.back()){
            intersection.push_back(nums1[i]);
            i++;
            j++;
        }
    }
}  

return intersection;   
}

int main(){

    vector<int> nums = {1,0,2,0,4,0,0,1};
    int n=nums.size();
    // int n = removeDuplicates(nums);
    // for(int i = 0 ; i < n ; i++){
    //     cout<< nums[i]<< " ";
    // }

    moveZeroRightCode(nums);
    for(int i = 0 ; i < n ; i++){
        cout<< nums[i]<< " ";
    }
    return 0;
}