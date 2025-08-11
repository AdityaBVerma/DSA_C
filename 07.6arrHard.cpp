#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answer;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0 ;i<nums.size();i++){
        if (i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if ( sum ==0){
                answer.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (j < k && nums[j] == nums[j - 1]) j++;
                k--;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if (sum<0){
                j++;
            } 
            else k--;
        }
    }
    return answer;
}

vector<vector<int>> threeSumHash(vector<int>& nums){
    vector<vector<int>> result;
    unordered_set<string> seen;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        unordered_map<int, int> mp;
        for(int j = i+1; j<n;j++){
            int complement = -nums[i]-nums[j];
            if(mp.find(complement) != mp.end()){
                vector<int> ans = {nums[i], nums[j], complement};
                sort(ans.begin(), ans.end());
                string key = to_string(ans[0])+","+to_string(ans[1])+","+to_string(ans[2]);
                if(!seen.count(key)){
                    result.push_back(ans);
                    seen.insert(key);
                }
            }
            mp[nums[j]]++;
        }
    }
    return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answer;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i<n-3; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j = i+1 ; j<n-2; j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            long sum = (long)nums[i] + nums[j];
            int k = j+1;
            int l = n-1;
            while( k < l){
                long total = (long)nums[i] + nums[j] + nums[k] + nums[l];
                if( total == target){
                    answer.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                } else if(total < target) k++;
                else l--;
            }
        }
    }
    return answer;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> rest;
    int count =0;
    int n = nums1.size();
    for(int i = 0; i < n ; i ++) {
        for(int j = 0 ; j < n ; j ++){
            rest[nums3[i] + nums4[j]]++;
        }
    }
    for(int i = 0 ;i < n ; i ++){
        for(int j = 0; j < n ;j++){
            int sum = nums1[i]+nums2[j];
            if(rest.find(-sum)!=rest.end()){
                count +=rest[-sum];
            }
        }
    }
    return count;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
        return a[0]<b[0];
    });// lambda not needed
    vector<vector<int>> answer;
    vector<int> temp;
    for(int i =0 ; i < intervals.size(); i++){
        temp = intervals[i];
        while(i+1<intervals.size() && temp[1]>= intervals[i+1][0]){
            temp[1] = max(temp[1],intervals[i+1][1]); 
            i++;
        }
        answer.push_back(temp);
    }
    return answer;
}

vector<vector<int>> mergeopt(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());// lambda not needed
    vector<vector<int>> answer;
    int index = 0;
    for(int i =1 ; i < intervals.size(); i++){ 
        if(intervals[index][1]>=intervals[i][0]){
            intervals[index][1] = max(intervals[index][1], intervals[i][1]);
        } else {
            index++;
            intervals[index]= intervals[i];
        }
    }
    intervals.resize(index+1);
    return intervals;
}

void mergeBetter(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0; int j = 0;
    while (i<m)
    {
        if(nums1[i]<= nums2[0]) i++;
        else {
            swap(nums1[i], nums2[0]);
            i++;
            while (nums2[j]>nums2[j+1])
            {
                swap(nums2[j],nums2[j+1]);
                j++;
            }
            j=0;
        }
    }
    while (j<n)
    {
        nums1[i] = nums2[j];
        j++;
        i++;
    }    
}

void mergeopt(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m+n-1;
    int i = m-1;
    int j = n-1;
    while (i>=0 && j>=0){
        if(nums1[i]<nums2[j]) {
            nums1[k--] = nums2[j--];
        } else {
            nums1[k--] = nums1[i--];
        }
    }
    while(j>=0){
        nums1[k--] = nums2[j--];
    }
}

void mergeWithoutExtraSpace(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int left = 0;
    int right = m-1;
    while(left<n && right>=0){
        if(nums1[right]>nums2[left]){
            swap(nums1[right--],nums2[left++]);
        }else { break;}
    }
    sort(nums1.begin(), nums1.begin()+m);
    sort(nums2.begin(), nums2.end());
}

void swapGreater(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2){
    if(nums1[idx1]> nums2[idx2]){
        swap(nums1[idx1], nums2[idx2]);
    }
}

void mergeWithGap(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int len = m + n ;
    int gap = (len/2) + (len%2);
    while(gap> 0){
        int left = 0 ;
        int right = left+gap;
        while(right < len){
            if( left< m && right >=m){
                swapGreater(nums1 ,nums2 , left, right-m);
            }
            else if( left >=m){
                swapGreater(nums2, nums2, left-m, right-m);
            } else {
                swapGreater(nums1, nums1, left, right);
            }
            left++; right++;
        }
        if (gap == 1) break;
        gap = (gap/2) + (gap%2);
    }
}

void printVector(const vector<int>& v) {
    for (int num : v) cout << num << " ";
    cout << endl;
}

vector<int> findRepeatingAndMissing(vector<int>& nums){
    int n = nums.size();
    long long S = n * (n+1)/2;
    long long Sq = n * (n+1) * (2*n+1) / 6;
    long long Sn = 0;
    long long Sqn = 0;
    for(int i = 0; i< n ;i ++){
        Sn +=nums[i]; 
        Sqn += (nums[i]*nums[i]);
    }
    long long val1 = S - Sn; 
    long long val2 = Sq - Sqn; //(x^2 -Y^2)
    val2 = val2/val1; // (x^2 -Y^2)/(x-Y)
    long long x = (val1 + val2)/2;
    long long y = val1 - x;
    return {(int)x, (int)y};
}

vector<int> findRepeatingAndMissingHash(vector<int>& nums){
    unordered_map<int, int> hash;
    int n = nums.size();
    for (int num : nums) {
        hash[num]++;
    }
    int x=-1; int y=-1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            y = i;
        } else if (hash[i] == 2) {
            x = i;
        }
    }
    return {x,y};
}

vector<int> findRepeatingAndMissingXOR(vector<int>& nums){
    int n = nums.size();
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= nums[i];
        xr ^= (i+1);
    }
    int one=0;
    int two=0;
    int number = (xr & ~(xr -1));
    for (int i = 0; i < n; i++)
    {
        if((nums[i]&number) !=0){
            one^=nums[i];
        }else{
            two^=nums[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if((i&number) !=0){
            one^=i;
        }else{
            two^=i;
        }
    }
    int count= 0;
    for(int i= 0;i <n;i++){
        if (nums[i]==one)
        {
            count++;
        }
        
    }
    if (count==2){
        return {one, two};
    }
    return {two,one};
}

int merge(vector<int> &nums, int low, int mid, int high){
    int count = 0;
    vector<int> temp;
    int left = low;
    int right = mid +1;
    while( left<= mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            count +=mid- left +1;
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i= low; i<=high; i++){
        nums[i] = temp[i- low];
    }
    return count;
}
int meregeSort(vector<int> &nums, int low, int high){
    int count = 0;
    if(low < high){  
    int mid = low+(high- low)/2;
    count += meregeSort(nums, low, mid);
    count += meregeSort(nums, mid+1, high);
    count += merge(nums, low, mid, high);
    }
    return count;    
}
int countInversion(vector<int>&a, int n){
    return meregeSort(a, 0, n-1);
}

int mer(vector<int>& nums,int left,int mid, int right){
    int n1 = left;
    int count =0;
    int j = mid+1;
    for(int i = left; i<=mid; i++){
        while (j <= right && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }
    int n2 = mid+1;
    vector<int> temp;
    while(n1<= mid && n2<=right){
        if(nums[n1]<nums[n2]){
            temp.push_back(nums[n1++]);
        }else {
            temp.push_back(nums[n2++]);
        }
    }
    while (n1<=mid)
    {
        temp.push_back(nums[n1++]);
    }
    while (n2<=right)
    {
        temp.push_back(nums[n2++]);
    }
    for(int i = left; i<=right; i++ ){
        nums[i] = temp[i-left];
    }
    return count;
}
int merSort(vector<int> &nums, int low, int high){
    int count = 0;
    if(low < high){  
    int mid = low+(high- low)/2;
    count += merSort(nums, low, mid);
    count += merSort(nums, mid+1, high);
    count += mer(nums, low, mid, high);
    }
    return count;    
}

int reverseInteger(vector<int>&a, int n){
    return merSort(a, 0, n-1);
}

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1; int suf =1;
    int ans = INT_MIN;
    for(int i = 0 ;i < n ;i++){
        if(pre == 0) pre = 1;
        if(suf == 0) suf = 1;
        pre*=nums[i];
        suf *= nums[n-1-i];
        ans = max(ans, max(pre, suf));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();

    vector<int> a = {2,4,3,5,1};
    int n = 5;
    int cnt = reverseInteger(a, n);
    cout << "The number of inversions are: "<< cnt << endl;
    return 0;

    // vector<vector<int>> testCases = {
    //     {1, 2, 2, 4},        // missing: 3, repeating: 2
    //     {3, 1, 3},           // missing: 2, repeating: 3
    //     {4, 3, 6, 2, 1, 1},  // missing: 5, repeating: 1
    //     {1, 5, 3, 2, 2, 6, 7, 8}, // missing: 4, repeating: 2
    //     {2, 2},              // missing: 1, repeating: 2
    // };

    // for (int i = 0; i < testCases.size(); i++) {
    //     vector<int> result = findRepeatingAndMissingXOR(testCases[i]);
    //     cout << "Test Case " << i+1 << ": ";
    //     cout << "Repeating = " << result[0] << ", Missing = " << result[1] << endl;
    // }


    // vector<int> nums1 = {1, 3, 5};
    // vector<int> nums2 = {2, 4, 6};
    // int m = 3, n = 3;
    // mergeWithGap(nums1, m, nums2, n);
    // cout << "Test Case 1: ";
    // printVector(nums1);
    // printVector(nums2);

    // // Test Case 2
    // nums1 = {2, 5, 7};
    // nums2 = {1, 3, 6};
    // m = 3, n = 3;
    // mergeWithGap(nums1, m, nums2, n);
    // cout << "Test Case 2: ";
    // printVector(nums1);
    // printVector(nums2);
    // // Test Case 3
    // nums1 = {1, 2, 3};
    // nums2 = {4, 5, 6};
    // m = 3, n = 3;
    // mergeWithGap(nums1, m, nums2, n);
    // cout << "Test Case 3: ";
    // printVector(nums1);
    // printVector(nums2);
    // // Test Case 4
    // nums1 = {4, 5, 6};
    // nums2 = {1, 2, 3};
    // m = 3, n = 3;
    // mergeWithGap(nums1, m, nums2, n);
    // cout << "Test Case 4: ";
    // printVector(nums1);
    // printVector(nums2);


    //vector<int> nums = {1000000000, 1000000000, -1000000000, -1000000000};
    // vector<int> a = {0};
    // vector<int> b = {0};
    // vector<int> c = {0};
    // vector<int> d = {0};

    // cout<<fourSumCount(a,b,c,d);

    // vector<vector<int>> intervals = {{1,10}, {2,3}, {6,8}, {5,7}, {8,9}};
    // vector<vector<int>> result = mergeopt(intervals);
    // for (auto& interval : result) {
    //     cout << "[" << interval[0] << ", " << interval[1] << "] ";
    // }
    
    // for( auto num : answer){
    //     cout << "[ ";
    //     for( int ele: num ){
    //         cout<<ele<<", ";
    //     }
    //     cout<< "]";
    // }


    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout <<endl<< "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}