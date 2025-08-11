#include<bits/stdc++.h>
using namespace std;


void countDigits(int n){
    int count = 0;
    do
    {
        count+=1;
        n=n/10;
    } while (n>0);
    
    cout<< count ;
}

void countDigitsLog(int n){
    int count = (int)log10(n) + 1;
    
    cout<< count ;
}

int reverseNum(int x){
    int rev = 0;
        while (x!=0)
        {
            if (rev> INT_MAX/10 || (rev== INT_MAX/10 && x%10>7)) return 0;
            if( rev< INT_MIN/10 || (rev == INT_MIN/10 && x%10 <-8)) return 0;
            rev*=10;
            rev += x%10;
            x /=10; 
        }
        return rev;
}

bool palindrome(int n){
    int rev = 0;
    int orig = n;
    while (n!=0)
    {
        rev = (rev*10)+n%10;
        n/=10;
    }
    if ((rev == orig) && rev>0)
    {
        return true;
    }
    return false;
}

int gcdLoop(int n1 ,int n2){
    for (int i = min(n1,n2); i>0 ; i--){
        if ( n1%i==0 && n2%i==0) return i;
    }
    return 1;
}

int gcdSub(int n1 ,int n2){
    while (n1 > 0 && n2>0){
        if(n1>n2){
            n1=n1%n2;
        } else {
            n2=n2%n1;
        }
    }
    cout<<n2;
    if (n1==0) {
        return n2;
    }
    // return n1;
}

bool armstrong(int n){
    int sum = 0;
    int orig = n;
    int k = to_string(n).length();
    int digit = 0;
    while(n!=0){
        digit = n%10;
        sum =sum + round(pow(digit,k));
        n/=10;
    }

    if(sum == orig){
        return true;
    }
    return false;
}

int* printDivisior(int n, int &size ){
    int ans = abs(n);
    int* arr = new int[ans];
    int pointer = 0;
    for(int i =1;i<=sqrt(ans);i++){
        if(n%i==0){ arr[pointer++] = i;
        if(i!=n/i) arr[pointer++] = n/i;}
    }
    size =pointer;
    return arr;
}

vector<int> divisor(int n){
    vector<int> v;
    int ans = abs(n);
    for(int i = 1 ; i <=sqrt(ans); i++){
        if(ans%i==0) {v.push_back(i);
        if(i!=ans/i) v.push_back(ans/i);}
    }
    return v;
}

bool isPrime(int n){
    int flag = 1;
    if(n ==1 ) return 0;
    if(n == 2) return 1;
    for(int i = 2; i*i <=n; i++){
        if(n%i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

bool sieve(int n){
    int flag;
    if(n ==1) return 0;
    if(n%2 == 0 || n%3 ==0 ) return 0;
    for (int i = 5; i <= sqrt(n); i+=6)
    {
        if(n%i == 0 || n%(i+2) == 0) return 0;
    }
    return 1;
}

int main(){
    int size;
    // int* arr = printDivisior(12, size);
    // for(int i=0;i<size;i++){
    //     cout<< arr[i]<<" ";
    // }
    // delete[] arr;
    // cout<<endl;
    // vector<int> v= divisor(-12);
    // for( int i : v){
    //     cout << i << " ";
    // }
    cout << sieve(11);
    return 0;
}