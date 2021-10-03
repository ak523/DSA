#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> max_heap; //Max heap (complexity will be nlogk)
                                //where sorting will give you nlogn

int ksmall(int a[],int n,int k)
{
    for(int i = 0; i<n; i++)
    {
        max_heap.push(a[i]);

        if(max_heap.size()>k)
            max_heap.pop();
    }
    return max_heap.top();
}

int main()
{
    int k,n;
    cin>>k>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=ksmall(a,n,k);
    cout<<"\nk ="<<k;
    cout<<"\nkth smallest element is: "<<ans;
    return 0;
}
