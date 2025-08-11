#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isSelfDividing(int n){
        bool flag = true;
        int orignal = n;
        int digit=0;
        while (n!=0){
            digit = n%10;
            if(digit==0 || (orignal%digit) != 0) return false;
            n/=10;
        }
        return true;
    }

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> nums;
    for(int i = left; i<=right; i++){
        if(isSelfDividing(i)) nums.push_back(i);
    }
    return nums;
}

int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){ 
                factors.push_back(i);
                if(i!=n/i){ factors.push_back(n/i);}
            }
        }
        try {
            sort(factors.begin(), factors.end());
            for(auto fac : factors){
                cout<<fac<<" ";
            }
            return factors.at(k-1);
        } catch(out_of_range& e) {
            return -1;
        }
        
    }

bool isPrime(int n){
    if(n ==1) return false;
    if(n==2 || n==3) return true;
    if(n%2 ==0 || n%3 == 0) return false;
    for(int i = 5 ; i*i <=n; i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}

int countPrime(int n) {
    int count = 0;
    for (int i = 1; i<n; i++){
        if(isPrime(i)) count++;
    }
    return count;
}

int countPrimes(int n){
    if(n<=2)return 0;
    vector<bool> Prime(n, true);
    Prime[0]=Prime[1]=false;
    for(int i =2 ; i*i <n; i++){
        if (Prime[i])
        {
            for (int j = i*i; j < n; j+=i)
            {
                Prime[j] = false;
            }
            
        }
        
    }
    return count(Prime.begin(),Prime.end(),true);
}

bool isUgly(int n){
        if(n<=0) return false;

        while(n%2 == 0) n/=2;
        while(n%3 == 0) n/=3;
        while(n%5 == 0) n/=5;
        
        return n == 1;
    }

int nthUglyNumber(int n) {
    int count = 0;
    for(int i = 1;  ; i++){
        if(isUgly(i)){
            count++;
            if(count == n) return i;
        }
    }
}

bool checkPerfectNumber(int num) {
        vector<int> divisors;
        if(num<=1) return false;
        for(int i = 1; i*i <=num; i++){
            if(num%i == 0){
                divisors.push_back(i);
                if(i!=num/i && i!=1) divisors.push_back(num/i);
            }
        }
        for(auto divisor : divisors){
            num-=divisor;
        }
        return num==0;
    }

int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int temp;
        int a = nums.front();
        int b = nums.back();
        while(b != 0){
            temp = b;
            b= a%b;
            a= temp;
        }
        if(b==0) return a;
}

int trailingZeroes(int n) {
        int count = 0;
        int zeros = 0;
        int k = 1;
        int num = 0;
        do{
            zeros += n/pow(5,k);
            num=n/pow(5,k);
            k++;
        }while(num!=0);
        return zeros;
}


int main(){
    //cout<<isSelfDividing(21);
    // vector<int> selfDividing =  selfDividingNumbers(10, 20);
    // for(auto num : selfDividing){
    //     cout<<num<<" ";
    // }
    // return 0;

    //cout<<kthFactor(7,2);

    //cout<<countPrimes(956150);

    //cout<< nthUglyNumber(1407);

    //cout<<checkPerfectNumber(28);

    // vector<int> v = {3,3};
    // cout<<findGCD(v);

    cout<<trailingZeroes(30);

    return 0;
}