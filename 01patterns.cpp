#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j < n ;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for (int i = 0; i<n;i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<=i; j++){
            cout<< j+1 << " ";
        }
        cout<< endl;
    }
}

void pattern4(int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<=i; j++){
            cout<< i+1 <<" "; 
        }
        cout << endl;
    }
}

void pattern5(int n) {
    for (int i = n; i>0; i--){
        for (int j = i; j>0;j--){
            cout<<"* ";
        }
        cout << endl;
    }
}

void pattern6(int n){
    for (int i = 0 ; i <n ; i++){
        for (int j = 0; j < n-i;j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
}

void pattern7(int n){
    for (int i = 0 ; i<n;i++){
        
        for (int j = 0; j <n-i-1;j++){
            cout << " ";
        }
        for (int j = 0; j<=i;j++){
            cout << "*";
        }
        for (int j = 0; j<i;j++){
            cout << "*";
        }
        cout << endl;
        
    }
} 

void pattern8(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0 ; j < n-i; j++){
            cout << "*";
        }
        for (int j = 0 ; j < n-i-1; j++){
            cout << "*";
        }
        cout << endl;
    }
    
}

void pattern9(int n){
    for (int i = 0 ; i<n;i++){
        
        for (int j = 0; j <n-i-1;j++){
            cout << " ";
        }
        for (int j = 0; j<=i;j++){
            cout << "*";
        }
        for (int j = 0; j<i;j++){
            cout << "*";
        }
        cout << endl;
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0 ; j < n-i; j++){
            cout << "*";
        }
        for (int j = 0 ; j < n-i-1; j++){
            cout << "*";
        }
        cout << endl;
    }
} 

void pattern10(int n){
    for (int i = 0; i<n;i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int i = n; i>0; i--){
        for (int j = i-1; j>0;j--){
            cout<<"* ";
        }
        cout << endl;
    }
}

void pattern11(int n){
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j<=i ; j++){
            if (i%2 == 0)
            {
                cout << (j%2 == 0)<< " ";
            }
            else
            {
                cout << (j%2 == 1)<< " ";
            }
            
            
        }
        cout << endl;
    }
}

void pattern12(int n){
    for (int i = 0; i<n; i++){
        for (int j = 0 ; j<=i; j++){
            cout << j +1 << "";
        }
        for (int j = n-i-1; j >0; j--){
            cout << " ";
        }
        
        for (int j = n-i-1; j >0; j--){
            cout << " ";
        }
        for(int j=i;j>=0;j--){
            cout<<j+1;
        }
        cout << endl;
    }
}

void pattern13(int n){
    int num = 1;
    for (int i = 0 ; i <n ; i++){
        for (int j = 0; j<=i; j++){
            cout << num++ << " ";
        }
        cout << endl;
    }
}

void pattern14(int n){
    for (int i = 0 ; i < n ; i++){
        for( char j  = 'A'; j <= ('A'+i) ; j ++){
            cout  << j << " ";
        }
        cout << endl;
    }
}

void pattern15(int n){
    for (int i = 0; i<n; i++){
        for (char j = 'A'; j < ('A'+n-i); j++){
            cout << j<< " ";
        }
        cout << endl;
    }
}

void pattern16(int n){
    for(int i = 0; i<n; i++){
        for (int j=0; j<=i; j++){
            cout<<char('A'+i)<<" ";
        }
        cout << endl;
    }
}

void pattern17(int n){
    for(int i = 0; i<n; i++){
        for (int j = n-i-1; j >=0 ; j--){
            cout << " ";
        }
        for(int j = 0 ; j <=i;j++){
            cout << char('A'+j )<< " ";
        }
        for ( int j = i-1 ; j >= 0 ; j--){
            cout << char('A'+j)<< " ";
        }
        cout <<endl;
    }
}

void pattern18(int n){
    for (int i = 0 ; i< n; i++){
        for(int j = i ; j >=0  ;j-- ){
            cout << char('A'+(n-j));
        }
        cout<< endl;
    }
}

void pattern19(int n){
    for (int i = 0; i < n; i++){
        for (int j = n ; j>i ; j--){
            cout<<"*";
        }
        for(int j = 0; j <2*i; j++){
            cout<<" ";
        }
        for(int j = n ; j >i ; j--){
            cout<<"*";
        }
        cout<<endl;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <=i;j++){
            cout << "*";
        }
        for(int j = 2*n - 2*(i+1); j>i;j--){
            cout << " ";
        }
        for (int j = 0; j <=i;j++){
            cout << "*";
        }
        cout<<endl;
    }
    
}

void pattern20(int n){
    for (int i = 0; i<n; i++){
        for(int j = 0;j<=i;j++){
            cout<<"* ";
        }
        for(int j =2*n - 2*(i+1);j>0;j--){
            cout<<"  ";
        }
        for(int j = 0;j<=i;j++){
            cout<<"* ";
        }
        cout << endl;
    }
    for(int i = 0; i<n;i++){
        for(int j = n-i-1; j>0; j--){
            cout<<"* ";
        }
        for(int j = 0;j<n+2*i;j++){
            cout << "  ";
        }
        for(int j = n-i-1; j>0; j--){
            cout<<"* ";
        }
        cout<< endl;
    }
}

void pattern21(int n){
    for(int i = 0; i <n;i++){
        for( int j = 0 ; j<n; j++){
            if(i == 0 || i == n-1){
                cout<<"* ";
            }else{
                if(j == 0 || j ==n-1){
                    cout<< "* ";
                }
                else{
                    cout<< " ";
                }
            }
        }
        cout<< endl;
    }
}


int main(){
    int n;
    cout<<"enter the number\n";
    cin>>n;
    pattern21(n);

    return 0;
}