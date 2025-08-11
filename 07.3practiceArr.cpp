/* 
    output is fucked up same for anything
*/

#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

int minSubArrayLen(int target, vector<int>& nums) {
    int minimum = INT_MAX;
    int sum = 0;
    int j = 0;
    for(int i = 0 ; i< nums.size() ; i++){
        sum+=nums[i];
        while(sum >target && j<=i && sum-nums[j]>=target){
            sum-=nums[j];
            j++;
        }
        if(sum >= target){
            minimum = min(minimum, i-j+1);
        }
    }
    return minimum==INT_MAX? 0 : minimum;
}

int minSubArrayLenBetter(int target, vector<int>& nums){
    int minimum = INT_MAX;
    int sum = 0;
    int j =0;
    for(int i = 0 ; i< nums.size() ; i++){
        sum +=nums[i];
        while (sum>= target && j<=i)
        {
            minimum = min(minimum, i-j+1);
            sum-=nums[j];
            j++;
        }
    }
    return minimum>nums.size()? 0 : minimum ;
}

double findMaxAverage(vector<int>& nums, int k) {
    double maximum  = INT_MIN;
    double sum = 0;
    for(int i = 0; i< nums.size(); i++){
        sum += nums[i];
        if(i>=k-1){
            maximum = max(maximum, sum);
            sum-=nums[i-k+1];
        }
    }
    return maximum/k;
}

int pivotIndex(vector<int>& nums) {
    int sumLeft = 0;
    int sumRight = 0;
    int n = nums.size();
    for(int i = 0; i< n; i++){
        sumRight+= nums[i];
    }
    for(int i = 0 ; i < n ; i++){
        sumRight-= nums[i];
        if(i > 0) sumLeft+=nums[i-1];
        if( sumLeft == sumRight) return i;
    }
    return -1;
}

vector<int> productExceptSelf(vector<int>& nums) {
    map<int, int> forwardProd;
    map<int, int> BackwardProd;
    vector<int> ans;
    int n = nums.size();
    int prod = 1;
    int bprod = 1;
    for(int i = 0; i<n; i++){
        forwardProd.insert({i, prod});
        prod*=nums[i];
        BackwardProd.insert({n-i-1, bprod});
        bprod*= nums[n-i-1];
        ans.push_back(prod * bprod); 
    }
    for (int i = 0; i < n; i++)
    {
        ans.push_back(forwardProd[i] * BackwardProd[i]);
    }
    return ans;
}

vector<int> productExceptSelfOptimized(vector<int>& nums) {
    vector<int> ans;
    int prod = 1;
    int bprod = 1;
    int n = nums.size();
    for(int i = 0; i< n ; i++){
        ans.push_back(prod);
        prod *= nums[i];
    }
    for(int i = n-1 ; i>= 0 ; i--){
        ans[i] *= bprod;
        bprod *= nums[i];
    }
    return ans;
}

// int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
//     int n = nums.size();
//     int j = 0;
//     int count = 0;
//     for(int i = 0 ;i < n ;i ++){
//         int maximum = max(nums[i], maximum);
//         if(maximum<=right && maximum>=left){
//             count++;
//         }
//         else {
//             while (j!=i+1 && j<n)
//             {
//                 if(j!=i && nums[j]<=right && nums[j]>=left) count+=2;
//                 else count++;
//                 j++;
//             }
            
//         }
//     }
//     return count;
// }


int numSubarrayBoundedMaxBrute(vector<int>& nums, int left, int right){
    int maximum = INT_MIN;
    int n = nums.size();
    int count = 0;
    for(int i = 0; i<n ;i ++){
        maximum = INT_MIN;
        for(int j = i;j<n;j++){
            maximum= max(maximum,nums[j]);
            
            if(maximum>right) break;

            if(maximum >=left && maximum<=right){
                count++;
            }
        }
    }
    return count;
}

int upperBoundSubArr(vector<int>&nums, int bound){
    int count = 0;
    int n = nums.size();
    int j = -1;
    for(int i = 0; i<n ; i++){
        if(nums[i]<=bound){
            count+= i-j;
        } else {
            j = i;
        }
    }
    return count;
}

int numSubarrayBoundedMax(vector<int>& nums, int left, int right){
    return upperBoundSubArr(nums, right) - upperBoundSubArr(nums, left-1);
}

int numberOfSubarraysMap(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    int count = 0;
    for(int i = 0 ; i< n ; i++){
        nums[i] = nums[i]%2;
    }
    //sum and numof times
    map<int, int> reverseMap;
    for(int num: nums){
        sum+=num;
        count += reverseMap[sum-k];
        reverseMap[sum]++;
    }
    return count;
}

int numberOfSubarraysGreedy(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    int count = 0;
    for(int i = 0 ; i< n ; i++){
        nums[i] = nums[i]%2;
    }
    int j = 0;
    for(int i = 0 ; i<n ;i++){
        sum+=nums[i];
        while(sum>k && j<=i){
            sum-=nums[j];
            j++;
        }
        if(sum == k){
            count ++;
        }
    }
    return count;
}

int upperBound(vector<int>& nums , int k){
    int j = 0;
    int sum = 0;
    int count = 0;
    for(int i = 0; i<nums.size() ; i++){
        sum += nums[i];
        while(sum > k){
            sum -= nums[j];
            j++;
        }
        count += (i - j + 1);
    }
    return count;
}

int numberOfSubarraysTwoPointer(vector<int>& nums, int k){
    int n = nums.size();
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i< n ; i++){
            nums[i] = nums[i]%2;
        }
    
    return upperBound(nums , k) - upperBound(nums, k-1);
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return upperBound(nums, goal) - upperBound(nums, goal-1);
}

int main(){
    auto start = high_resolution_clock::now();

    vector<int> nums = {0,0,0,1,0,0,1,0,0,0};
    //cout << minSubArrayLen(11, nums)<< endl;
    //cout << findMaxAverage(nums, 2)<< endl;
    //cout << pivotIndex(nums)<< endl;
    // vector<int> ans =  productExceptSelfOptimized(nums);
    // for(auto it : ans){
    //     cout<< it << " ";
    // }
    //cout << numSubarrayBoundedMax(nums,2,3)<< endl;
    
    cout<<numSubarraysWithSum(nums, 2);



    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout <<endl<< "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}