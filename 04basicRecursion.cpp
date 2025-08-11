#include<bits/stdc++.h>
using namespace std;

void nameRecursion(int n){
    if(n==0) return;
    cout<< "adityabverma" <<endl;
    nameRecursion(n-1);
}

void oneToNLinear(int i,int n){
    if(i>n) return;
    cout<<i<<endl;
    oneToNLinear(i+1,n);
}

void NToOneLinear(int i, int n){
    if(i<1) return;
    cout<<i<<endl;
    NToOneLinear(i-1,n);
}

void oneToNBack(int i, int n){
    if(i<1) return;
    oneToNBack(i-1,n);
    cout<< i <<endl;
}

void nToOneBack(int i, int n){
    if(i>n) return;
    oneToNBack(i+1,n);
    cout<<i<<endl;
}

int sum(int n){
    if(n == 1) return 1;
    return n + sum (n-1);
}

int fac(int n){
    if(n == 1) return 1;
    return n * fac(n-1);
}

void reverse(int arr[], int n, int i = 0 ){
    if(i>n-i-1) return;
    swap(arr[i], arr[n-i-1]);
    reverse( arr, n , i+1);
}

bool palindrome( string s,int i = 0){
    if(i>=s.size()/2) return true;
    if(s[i] != s[s.size() -i-1]) return false;
    return palindrome(s, i+1);
}

int fibonacci(int n){
    if(n <=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(left<right){
            while(left < right &&!isalnum(s[left])) left++;
            while(left < right &&!isalnum(s[right])) right--;
            cout<<s[left]<<" "<<s[right]<<endl;
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
}

int main(int argc, char* argv[]){

    // nameRecursion(4);
    // int arr[6] = {1,2,3,4,5,6};
    // reverse(arr, 6);
    // for(int i = 0; i<6;i++){
    //     cout<< arr[i]<< " ";
    // }

    // string s = "MWDWM";
    // cout<<palindrome(s);
    cout<<isPalindrome(".,");
    return 0;
    
}//0 1 1 2 3 5  8