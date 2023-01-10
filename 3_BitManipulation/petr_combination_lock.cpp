/***********
 * Topic : Bit Manipulation
 * 
 * Question : B. Petr and a Combination Lock
 * 
 *  
*/



#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPossible(int arr[], int no, int size){
    int subsetSum = 0;
   
    for (int i = 0; i <size ; i++){
        if((no & (1<<i)) > 0){
            subsetSum += arr[i];
        }else{
            subsetSum -= arr[i];
        }
       
    }
    // cout << "  Subset Sum : " << subsetSum << endl;
    if(subsetSum%360 == 0  ) return true;
    return false;
    
}

int main(int argc, char **argv){
    // Take input
    int n; cin>>n;
    int arr[n];
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int range = (1<<n)-1 ;
    for(int i = 1; i<= range; i++){

        if(isPossible(arr, i,n) == true){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    
    cout<<"NO"<<endl;
    return 0;
}