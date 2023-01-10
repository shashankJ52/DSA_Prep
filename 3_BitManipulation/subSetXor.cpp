/***********
 * Topic : Bit Manipulation
 * 
 * Question : Given an integer array of size n. print the XOR of all the possible subsets
 *  
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int getSubset(int arr[], int n){
    int ans = 0;
    int i = 0;
    while(n > 0){
        if(n &1){
            ans ^= arr[i];
        }
        i++;
        n = n >> 1;
    }
    return ans;
}

int xorSum(int arr[], int n){
    int range = (1 << n) - 1;
    int sum = 0;
    for (int i = 0; i <= range; i++){
        sum ^= getSubset(arr, i);
    }
    return sum;
}

int main(int argc, char **argv) {
    // Take input
    int n;
    cout << "Enter size of Array : "; cin >> n;
    cout << "Enter the elements "<<endl;

    int arr[n];
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int ans = xorSum(arr, n);
    cout << "XOR-SUBSET SUM : " << ans << endl;
    return 0;
}


/**************
 * ANSWER : The XOR-SUBSET-SUM will always be ZERO....
*/

