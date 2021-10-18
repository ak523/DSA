#include<iostream>
using namespace std;
int main()
{
    int A[5][5]={0};
    int S[5][5]={0};
    int p[]={5,4,6,2,7};
    int n=5;
    int j,mini,q;

    for(int d=1;d<n-1;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            j=i+d;
            mini=32767;
            //K's value will be j-1
            for(int k=i;k<=j-1;k++)
            {
                q = A[i][k] + A[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<mini)
                {
                    mini=q;
                    S[i][j]=k;
                }
            }
            A[i][j]=mini;
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"The maximum numbers of multiplication required is: "<<A[1][n-1];
    return 0;
}
