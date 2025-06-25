 // Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void print(vector<int> nums)
{
    cout<<"\nprinting vector\n";
       for(auto it:nums)
    {
        cout<<it<<" ";
    }
    
}
/////////////////////////////////////////////////////////////////////////////////////////////
void subarraysum(vector<int> nums,int k)
{
    cout<<"\nsubarray sum of size k: "<<k;
    print(nums);
    vector<int> ans;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=nums[i];
    }
    ans.push_back(sum);
    for(int i=k;i<nums.size();i++)
    {
        int temp=sum+nums[i]-nums[i-k];
        ans.push_back(temp);
        sum=temp;
    }
    cout<<"\nsubarray sum is:\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////
    void numOfSubarrays(vector<int> arr, int k, int threshold) {
    cout<<"\nfinding subarrays count whose average >= threashold : "<<threshold<<" in window size :"<<k;
    print(arr);
    vector<int> ans;
    int cnt=0;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    if((sum/k)>=threshold) cnt++;
    for(int i=k;i<arr.size();i++)
    {
        int temp=sum+arr[i]-arr[i-k];
        if((temp/k)>=threshold) cnt++;
        sum=temp;
    }
    cout<<"overall subarrays count whose average >= threashold : "<<cnt<<endl;
    }
//////////////////////////////////////////////////////////////////////////////////////
void maximinisubarraysum(vector<int> nums,int k)
{
    cout<<"\nfinding maximum/minimum subarray sum of size k: "<<k;
    print(nums);
    vector<int> ans;
    int sum=0;
    int maxi=INT_MIN,mini=INT_MAX;
    for(int i=0;i<k;i++)
    {
        sum+=nums[i];
    }
    ans.push_back(sum);
    mini=maxi=sum;
    for(int i=k;i<nums.size();i++)
    {
        int temp=sum+nums[i]-nums[i-k];
        ans.push_back(temp);
        sum=temp;
        if(temp>maxi) maxi=temp;
        if(mini>temp) mini=temp;
    }
    cout<<"\nsubarray sum is:\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\nmaximum subarray sum in size k: "<<k<<" = "<<maxi;
    cout<<"\nminimum subarray sum in size k: "<<k<<" = "<<mini<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////
void maxSlidingWindow(vector<int>& nums, int k) {
  cout<<"\nsliding window maximum very hard :";
  print(nums);
  vector<int>  ans;
  deque<int> dq;
  for(int i=0;i<k;i++)
  {
    while(dq.size()>0 && nums[dq.back()]<=nums[i]) dq.pop_back();
    dq.push_back(i);
  }
  for(int i=k;i<nums.size();i++)
  {
      //storing prev window max elemnt
      ans.push_back(nums[dq.front()]);

      //popping dq ka front if not part of curr index 
      if(dq.size()>0 && dq.front()<=i-k) dq.pop_front();

      //if curr elemnt > dq ka back then popping
      while(dq.size()>0 && nums[dq.back()]<=nums[i]) dq.pop_back();
      dq.push_back(i);
  }
    ans.push_back(nums[dq.front()]);
    cout<<"\nMAX VALUE IN WINDOW IS :\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
       cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////
void minSlidingWindow(vector<int>& nums, int k) {
  cout<<"\nsliding window minimum very hard :";
  print(nums);
  vector<int>  ans;
  deque<int> dq;
  for(int i=0;i<k;i++)
  {
    while(dq.size()>0 && nums[dq.back()]>nums[i]) dq.pop_back();
    dq.push_back(i);
  }
  for(int i=k;i<nums.size();i++)
  {
      //storing prev window max elemnt
      ans.push_back(nums[dq.front()]);

      //popping dq ka front if not part of curr index 
      if(dq.size()>0 && dq.front()<=i-k) dq.pop_front();

      //if curr elemnt > dq ka back then popping
      while(dq.size()>0 && nums[dq.back()]>nums[i]) dq.pop_back();
      dq.push_back(i);
  }
    ans.push_back(nums[dq.front()]);
    cout<<"\nmin VALUE IN WINDOW IS :\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
       cout<<endl;
}
///////////////////////////////////////////////////////////////////////////////

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    vector<int> nums={2,3,4,1,5,2,2,5,6};
    subarraysum(nums,4);
    numOfSubarrays(nums,3,4);
    maximinisubarraysum(nums,4);
    maxSlidingWindow(nums,3);
    minSlidingWindow(nums,3);
    return 0;
}

