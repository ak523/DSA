// 

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=1,sum=0;
        long ans=0;
        int md=1e9+7;
        for(int n:arr)
        {
            sum+=n;
            if(sum%2==0)
            {
                sum=0;
                ans+=odd;
                even++;
            }
            else
            {
                sum=1;
                ans+=even;
                odd++;
            }
            ans=ans%md;
        }
        return ans;
    
        
    }
};