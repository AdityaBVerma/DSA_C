#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> freq;
        int j = 0;
        int maximum = INT_MIN;
        int sum = 0;    
        for(int  i = 0 ; i< nums.size() ; i++){
            while(freq.count(nums[i])){
                freq.erase(nums[j]);
                sum-=nums[j];
                j++;
            }
            freq.insert(nums[i]);
            sum+=nums[i];
            maximum = max(maximum, sum);
        }
        return maximum;
}

int minimumCardPickup(vector<int>& nums) {
    map<int, int> freq;
    int minimum = INT_MAX;
    for(int i =0 ; i< nums.size(); i++){
        auto it = freq.find(nums[i]);
        if(it!=freq.end()){
            minimum = min(minimum,i+1-it->second);
        }
        freq[nums[i]]=i;
    }
    return minimum>nums.size()? -1 : minimum;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int maximum = INT_MIN;
    vector<int> maxArr;
    int j = 0;
    for(int i = 0 ;i < nums.size() ;i ++){
        while(i<k-1){
            maximum = max(nums[i], maximum);
            i++;
        }
        j++;
        maximum = max(maximum , nums[i]);
        maxArr.push_back(maximum);
    }
    return maxArr;
}

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    int n = nums.size();
    for(int i = 0; i< n; i++){
        if( nums[i] > 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }
    nums.clear();
    for(int i = 0; i<n/2; i++){
        nums.push_back(pos[i]);
        nums.push_back(neg[i]);
    }
    return nums;
}

vector<int> rearrangeArraybetter(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int posidx = 0;
    int negidx = 1;
    for(int i = 0; i< n; i++){
        if( nums[i] > 0){ 
            ans[posidx] = nums[i];
            posidx+=2;
        }
        else {
            ans[negidx] = nums[i];
            negidx +=2;
        };
    }
    return ans;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int minimum = INT_MAX;
    int toSwap = 0;
    bool last =1;
    int idx;
    for(int i = n-1 ; i>0 ;i--){
        if(nums[i]>nums[i-1] ){
            toSwap = i-1;
            last=0;
            break;
        }
    }
    if(last){
        sort(nums.begin(), nums.end());
        return;
    }
    for(int i= n-1; i>toSwap; i--){
        if(nums[i]>nums[toSwap]){
            idx = i;
            break;
        }
    }

    swap(nums[idx], nums[toSwap]);
    reverse(nums.begin()+ toSwap+1,nums.end());
}

vector<int> leader(vector<int> nums){
    int maximum = INT_MIN;
    vector<int> ans;
    for(int i = nums.size()-1; i>=0;i--){
        if(nums[i]>= maximum){
            maximum = nums[i];
            ans.push_back(nums[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int longestConsecutive(vector<int>& nums) {
    int maximum = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for( int nums : s){
        if(!s.count(nums-1)){
            int curr = nums;
            int len = 1;
            while(s.count(curr+1)){
                curr++;
                len++;
            }
            maximum = max(maximum, len);
        }
    }
    return maximum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();

    vector<int> nums = {1,0,1,2};
    //cout<<minimumCardPickup(nums);
    // vector<int> ans = leader(nums);
    // for(auto it : ans){
    //     cout<< it<< " ";
    // }

    cout<< longestConsecutive(nums);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout <<endl<< "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}