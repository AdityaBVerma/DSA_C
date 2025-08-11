#include <bits/stdc++.h>
#include <chrono>
#include <windows.h>
#include <psapi.h>
using namespace std;
using namespace std::chrono;

// ====================== Memory Usage ======================
void printMemoryUsageMB() {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        SIZE_T memUsed = pmc.WorkingSetSize; // Bytes
        cout << fixed << setprecision(2);
        cout << "Memory used: " << (memUsed / (1024.0 * 1024.0)) << " MB" << endl;
    } else {
        cerr << "Failed to get process memory info.\n";
    }
}

// ====================== Functions ======================
int binaryIteration(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;
    else if (target < nums[mid])
        return binaryIteration(nums, low, mid - 1, target);
    else
        return binaryIteration(nums, mid + 1, high, target);
}

int lowerbound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = high + 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperbound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = high + 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int searchRotated(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

bool searchRotatedII(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;
        while (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        }
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int findMin(vector<int>& nums) {
    int n = nums.size(), low = 0, high = n-1;
    int least = INT_MAX; 
    while(low <= high){
        if(nums[low] < nums[high]) {
            least = min(least, nums[low]);
            break;
        }
        int mid = low + (high - low) /2;
        if( nums[low] <=nums[mid]){
            least = min(least, nums[low]);
            low = mid + 1;
        } else if ( nums[mid] <= nums[high]){
            least = min (nums[mid], least);
            high = mid - 1;
        }
    }
    return least;
}

//well not quite confident about this
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size(), low = 0, high = n-1;
    if(n==1) return nums[0];
    if(nums[0]!= nums[1]) return nums[0];
    if(nums[n-1]!= nums[n-2]) return nums[n-1];
    while(low <= high){
        int mid = low + (high-low)/2;
        if(mid > 0 && mid < n-1 && nums[mid]!=nums[mid+1] && nums[mid]!= nums[mid-1]) return nums[mid];
        if((mid%2 == 0 && nums[mid+1]==nums[mid]) || (mid%2==1 && nums[mid-1] == nums[mid])){
            low = mid + ((mid % 2 == 0) ? 2 : 1);
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int singleNonDuplicateI(vector<int>& nums){
    int n = nums.size(), low = 0, high=n-1;
    while( low < high){
        int mid = low + ( high - low)/2;
        if(mid %2 ==1) mid--;
        if(nums[mid] == nums[mid+1]) low = mid+2;
        else high = mid;
    }
    return nums[low];
}
// ====================== Test Runner ======================
void runTestCase() {
    vector<int> nums = {3,3,7,7,9,9,11,11};
    int target = 0;
    cout << singleNonDuplicateI(nums) << "\n";

    // cout << "Lower bound (custom): " << lowerbound(nums, target)<< " | STL: " << (lower_bound(nums.begin(), nums.end(), target) - nums.begin()) << "\n";
    // cout << "Upper bound (custom): " << upperbound(nums, target)<< " | STL: " << (upper_bound(nums.begin(), nums.end(), target) - nums.begin()) << "\n";
    // cout << "Binary Iteration (on sorted copy): ";
    // sort(nums.begin(), nums.end());
    // cout << binaryIteration(nums, 0, nums.size() - 1, target) << "\n";
    // cout << "Search Rotated: " << searchRotated(nums, target) << "\n";
}

// ====================== Main Function ======================
int main() {
    auto start = high_resolution_clock::now();

    runTestCase();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time taken: " << duration.count() << " microseconds\n";
    printMemoryUsageMB();

    return 0;
}
