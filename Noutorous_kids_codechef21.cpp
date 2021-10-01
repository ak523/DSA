#include <bits/stdc++.h>
using namespace std;

bool Find(int mid,int a[],int n,int k)
{
    int pos=a[0];
    int ele=1;

    for(int i=1;i<n;i++)
    {
        if(a[i]-pos >=mid)
        {
            pos=a[i];
            ele++;

            if(ele==k)
                return true;
        }
    }
    return 0;
}

int LargeMinDis(int a[],int n,int k)
{
    sort(a,a+n);
    int result=-1;
    int l=1,r=a[n-1];

    while(l<r)
    {
        int mid=(l+r)/2;

        if(Find(mid,a,n,k))
        {
            result=max(result,mid);
            l=mid+1;
        }
        else
            r=mid;
    }
    return result;
}

int main()
{
    int t,n,kids;
    cin>>t;
    while(t--)
    {
    cin>>n>>kids;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int answer=LargeMinDis(a,n,kids);
    cout<<answer;
    }
    return 0;
}
