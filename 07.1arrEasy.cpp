#include<bits/stdc++.h>
using namespace std;

int missingNumberBrute(vector<int> &nums){
    int n = nums.size();
    for (int i = 0; i < n+1; i++)
    {   int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if(i == nums[j]){
                flag = 1;
                break;
            }
        }
        if(!flag) return i;
    }
}

int missingNumberHash(vector<int> &nums){
    int n = nums.size();
    vector<int> hash(n+1,0);
    for(int i = 0 ; i<n ; i++){
        hash[nums[i]] = 1;
    }
    for(int i = 0 ;i <= n; i++){
        if(hash[i] == 0) return i;
    }
}

int missingNumberXOR(vector<int> &nums){
    int XORall = 0;
    int XORmissing = 0;
    int n = nums.size();
    for(int i = 0 ; i< n; i++){
        XORall^= nums[i];
        XORmissing^= i+1;
    }
    return XORmissing^XORall;
}

int missingNumberSum(vector<int> &nums){
    int n = nums.size();
    int sum = (n * (n+1) / 2);
    for(int i = 0 ;i < n ; i ++){
        sum -= nums[i];
    }
    return sum;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0 ;
        int count = 0;
        int n = nums.size();
        for(int i = 0 ;i < n ; i++){
            if(nums[i]==0){
                if(count>max){
                    max= count;
                }
                count=0;
            }else{
                count++;
            }
        }
        return max>count? max:count;
    }

int singleNumber(vector<int>& nums) {
    /*
        1 <= nums.length <= 3 * 104
        -3 * 104 <= nums[i] <= 3 * 104
        Each element in the array appears twice except for one element which appears only once.
    */
    int n = nums.size();
    map<int, int> hash;
    for(int i = 0 ; i < n ; i++ ){
        hash[nums[i]]++;
    }
    for(int i = 0 ; i<n ; i++){
        if(hash[nums[i]] == 1) return nums[i];
    }
    return -1;
}

int singleNumberXor(vector<int> &nums){
        int XORsum = 0;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            XORsum ^= nums[i];
        }
        return XORsum;
}

int longestSubarraySumKBrute(vector<int> nums, long long k){
    int n = nums.size();
    int length = 0;
    for(int i = 0 ; i<n ;i++){
        long long sum = 0;
        for(int j = i ; j<n ;j++){
            sum += nums[j];
            if(sum == k){
                length = max(length, j-i+1);
            }
        }
    }
    return length;
}

int longestSubarraySumKHash(vector<int> &nums, int k){
    int length = 0;
    int sum = 0;
    map<int, int> reverseMap;
    int n = nums.size();
    int firstPtr = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=nums[i];
        if(sum == k){
            length = i+1;
        }
        auto it = reverseMap.find(sum-k);
        if(it!= reverseMap.end()){
            firstPtr = it->second;
            length  = max(length, i-firstPtr);
        } 
        if(reverseMap.find(sum)==reverseMap.end()){
            reverseMap.insert({sum,i});
        }
    }
    
    return length;
}

int longestSubarraySumKGreedy(vector<int> &nums, int k){
    int length = 0;
    int j = 0;
    int sum = 0;
    for(int i = 0 ; i<nums.size() ; i++){
        sum+=nums[i];
        while(sum > k && j<=i){
            sum-=nums[j];
            j++;
        } 
        if(sum == k){
            length = max(length, i-j+1);
        }
    }
    return length;
}

int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();
    map<int, int> reverseMap;
    int sum = 0;
    reverseMap[0] = 1;
    for(int i = 0 ; i<n; i++){
        sum += nums[i];
        if(reverseMap.find(sum - k) != reverseMap.end()){
            count+=reverseMap[sum - k];
        }
        reverseMap[sum]++;
    }
    return count;
}

int main(){
    vector<int> nums = {0,0,0,0,0,0,0,0,0,0};
    cout<<subarraySum(nums , 0);

    return 0;
}