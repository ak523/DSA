#include<bits/stdc++.h>
#include <iostream>

using namespace std;

// INPUTS CAN BE LIKE::
// Number of activities(N):9
// (start(si),finish(fi)): (1,2),(2,3),(1,4),(2,5),(3,7),(4,9),(5,6),(6,8),(7,9)


int main()
{
    int n;
    cout << "Enter number of activities:";
    cin >> n;
    int si[n],fi[n];
    int sol[n];
    for(int i=0;i<n;i++){
        cout << "si[" << i << "]:";
        cin >> si[i];
        cout << "fi[" << i << "]:";
        cin >> fi[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(fi[i]>fi[j]){
                swap(fi[i],fi[j]);
                swap(si[i],si[j]);
            }
        }
    }
    
    cout << endl << "Activities are :" << endl;
    int f=0;
    for(int i=0;i<n;i++){
        if(si[i]>=fi[f] || i==0){
            cout << "[" << si[i] << "," << fi[i] << "] \t";
            f=i;
        }
    }    
    
    
    return 0;
}
