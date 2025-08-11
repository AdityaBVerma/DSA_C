#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selection(int arr[], int n){
    int min ;
    for(int i = 0; i<n-1 ; i++){
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void bubble(int arr[], int n){
    for (int i = 0; i<n ; i++){
        bool swapped = false;
        for(int j = 1 ; j< n-i-1 ; j++){
            if(arr[j]> arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void insetion(int arr[], int n){
    for (int i = 0 ; i <n ; i++){
        int j = i;
        while(j > 0 && arr[j]< arr[j-1]){
            swap(arr[j] , arr[j-1]);
            j--;
        }
    }
}

void insertionShift(int arr[], int n){
    for(int i = 1 ; i<n ;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key< arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void mergeArr(int arr[], int low, int mid, int high){
    int n1 = mid - low +1;
    int n2 = high - mid;
    int arr1[n1],arr2[n2];
    for(int i = 0; i<n1;i++){
        arr1[i] = arr[low+i];
    }
    for(int i = 0; i<n2 ;i++){
        arr2[i] = arr[mid +i+1];
    }
    int k=low;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeArr(arr, low, mid, high);
    }
}

int partition(vector<int> &arr, int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void qs(vector<int> &arr, int low, int high){
    if(low<high){
        int p = partition(arr, low, high);
        qs(arr, low, p -1);
        qs(arr, p +1 , high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    qs(arr, 0, arr.size()-1);
    return arr;
}

void countSort(int arr[], int n){
    int k = 0;
    for(int i = 0 ; i< n ;i++){
        k=max(k,arr[i]);
    }
    int count[10] = {0};
    for(int i = 0 ; i<n ;  i++){
        count[arr[i]]++;
    } 
    for(int i = 1; i<=k;i++){
        count[i]+=count[i-1];
    }
    int ans[n]={0};
    for(int i = 0 ;i <n ;i ++){
        ans[--count[arr[i]]] = arr[i];
    }
    for(int i = 0 ;i <n ; i++){
        arr[i] = ans[i];
    }
}

void dnf(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

void wave(int arr[], int n){
        for(int i = 1 ; i<n-1; i+=2){
            if(arr[i]>arr[i-1]) swap(arr[i], arr[i-1]);
            if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
        }
    }

void wiggleSort(vector<int>& nums) {
       vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
       int mid = (nums.size()+1)/2;
       int j = mid - 1;
       int k = nums.size()-1;
       for(int i = 0 ; i < nums.size(); i++){
            if(i%2==0){
                nums[i] = sorted[j--];
            }
            else {
                nums[i] = sorted[k--];
            }

       } 
    }

int main(){
    // vector<int> arr = {99,23,3,121,2,8};
    // vector<int> arr1 = quickSort(arr);
    // for(int i = 0; i<6 ;i++){
    //     cout<< arr1[i]<<" ";
    // }
    // return 0;

    // vector<int> nums = {2,0,2,1,1,0};
    // sortColors(nums);
    vector<int> arr = {1,3,2,2,3,1} ;
    wiggleSort(arr);
    for(int i = 0 ; i<6 ;i ++){
        cout<<arr[i]<< " ";
    }


    return 0;

}

/*
    2 0 1
    lm   h
    1  0  2
    ml h
    1  0  2
    l  mh


*/