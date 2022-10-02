class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        long long ans=0;
        int sum=0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                arr[i]=-1;
            }
            sum+=arr[i];
            if(sum==0)
            {
                ans++;
            }
            if(mp.find(sum)!=mp.end())
            {
                ans+=mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};
