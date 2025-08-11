#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

vector<int> twoSum(vector<int>& nums, int k){
    int n = nums.size();
    map<int ,int> reverseMap;
    for(int i = 0 ; i<n ; i++){
        if(reverseMap.find(k- nums[i]) != reverseMap.end()){
            return {reverseMap[k-nums[i]] , i};
        }
        reverseMap.insert({nums[i], i});
    }
    return {};
}

vector<int> twoSum1(vector<int> nums, int k){
    // as sorting we need to maintain another data structure to maintain the indexes
    int n = nums.size();
    int low = 0;
    int high = n-1;
    sort(nums.begin(), nums.end());
    while (low<high)
    { 
        int sum = nums[low] + nums[high];
        if(sum == k){
            return {nums[low],nums[high]};
        }
        else if(sum<k){
            low++;
        }
        else{
            high--;
        }
    }
    return {};
}

int majorityElement(vector<int> nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for(int i = 0; i<n ; i++){
        freq[nums[i]]++;
    }
    for(auto it : freq){
        if(it.second>n/2) return it.first;
    }
    return -1;
}

int majorityElementMoore(vector<int> nums){
    int n = nums.size();
    int element = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(count == 0){
            element = nums[i];
        }
        if(element == nums[i]){
            count++;
        }else{
            count--;
        }
    }
    return element;
}

int kadanes(vector<int> nums){
    int n = nums.size();
    int sum = 0;
    int maximum = INT_MIN;
    for(int i = 0; i<n; i++){
        if(sum<0){
            sum = 0;
        }
        sum +=nums[i];
        if(sum > maximum){
            maximum = max(maximum, sum);
        }
    }
    return maximum;
}

int maxSubArrSum(vector<int> nums){
    int n = nums.size();
    int sum  = 0;
    int maximum= INT_MIN;
    for(int i = 0; i< n ;i ++){
        for(int j = 0; j<n;j++){
            sum += nums[j];
            maximum = max(maximum ,sum);
        }
    }
    return maximum;
}

vector<int> kadanesAlgo(vector<int> nums){
    int n = nums.size();
    int maximum = INT_MIN;
    int sum = 0;
    int start = 0;
    int arrst = 0;
    int arrend= 0;
    for(int i = 0 ; i < n ; i ++){
        if(sum <0) {
            sum = 0;
            start = i;
        }
        sum+=nums[i];
        if(sum>maximum){
            maximum = max(maximum,sum);
            arrst = start;
            arrend = i;
        }
    }
    return {arrst, arrend};
}

int main (){

    auto start = high_resolution_clock::now();

    //cout<< majorityElementMoore({2,2,1,1,1,2,2,2,3,3,3,3})<<" "; 
    // vector<int> answer = kadanesAlgo({2,-2,-1,-1,1,2,2,2,3,3,3,3});
    // for(auto i : answer){
    //     cout<<i << " -> ";
    // }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout <<endl<< "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}