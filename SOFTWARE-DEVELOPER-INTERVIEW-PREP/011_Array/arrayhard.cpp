// Online C++ compiler to run C++ program online
/*
2Sum
3Sum
3Sum closest
4Sum
bruteforces : 2 /3 foorloops
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

 void print(vector<int> nums)
 {
     cout<<"\nvector is: \n";
     for(auto it:nums)
     {
         cout<<it<<" ";
     }
     cout<<endl;
 }

void twoSum(vector<int>& nums, int target) {
    cout<<"\ntwo sum problem: for target: "<<target;
    print(nums);
    unordered_map<int,int> st;
     for(int i=0;i<nums.size();i++)
     {
         int second=target-nums[i];
         if(st.find(second)!=st.end())
         {   
             cout<<"first element is at index: "<<st[second]<<endl;
             cout<<"second element is at index: "<<i<<endl;
             return;
         }
         else st[nums[i]]=i;
     }
     cout<<"no pair found:\n ";
 }
 
 void threeSum(vector<int>& nums) {
  cout<<"\n three sum problem: \n";
  print(nums);
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());  // Step 1: sort the array
  int n = nums.size();

  for (int i = 0; i < n - 2; i++) {
      // Step 2: skip duplicate elements for i
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
          int sum = nums[i] + nums[left] + nums[right];
          if (sum == 0) {
              ans.push_back({nums[i], nums[left], nums[right]});
              // Move left and right to the next unique values
              while (left < right && nums[left] == nums[left + 1]) left++;
              while (left < right && nums[right] == nums[right - 1]) right--;
              left++;
              right--;
          }
          else if (sum < 0) {
              left++;  // we need a bigger sum
          }
          else {
              right--; // we need a smaller sum
          }
      }
    }
     int i=1;
    for(auto it:ans)
    {
        cout<<i<<" th pair is: "<<endl;
        for(auto x:it)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        i++;
    }
}

  void threeSumClosest(vector<int>& nums, int target) {
        cout<<"\nthree sum closest problem: for target: "<<target;
        print(nums);
        int n = nums.size();
        int diff = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int st = i + 1, end = n - 1;
            while (st < end) {
                int sum = nums[i] + nums[st] + nums[end];
                int currentDiff = abs(sum - target);
                if (currentDiff == 0)
                    cout<<"3sum closet sum is: "<<target<<endl;;
                if (currentDiff < diff) {
                    diff = currentDiff;
                    ans = sum;
                }
                if (sum < target)
                    st++;
                else
                    end--;
            }
        }

        cout<<"3sum closet sum is: "<<ans<<endl;;
    }
    
 void fourSum(vector<int>& nums, int target) {
      cout<<"\nfoursum problem: for target: "<<target;
      print(nums);
     int n=nums.size();
     vector<vector<int>> ans;
     sort(nums.begin(),nums.end());
     for(int i=0;i<n-3;i++)
     {
   if(i>0 && nums[i]==nums[i-1]) continue; // to avoid duplicates 
   for(int j=i+1;j<n-2;j++)
   {
     if(j>i+1 && nums[j]==nums[j-1]) continue;
     int st=j+1;
     int end=n-1;
     while(st<end)
     {
          long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[st]+(long long)nums[end];
          if(sum==target)
          {
              vector<int> temp={nums[i],nums[j],nums[st],nums[end]};
              ans.push_back(temp);
              while(st<end && nums[st]==nums[st+1]) st++;
              while(st<end && nums[end]==nums[end-1]) end--;

              st++;end--;
          }
          else if(sum<target) st++;
          else end--;
     }
         }
     }
    int i=1;
    for(auto it:ans)
    {
        cout<<i<<" th pair is: "<<endl;
        for(auto x:it)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        i++;
    }
 }
 

int main() {
  cout<<"Array hard:\n";
  vector<int> nums = {-1,0,1,2,-1,-4};
  vector<int> nums3 = {-1,2,1,-4};
  vector<int> nums4 = {1,0,-1,0,-2,2};
  int target4 = 0;
  int target = 1;
  twoSum(nums,3);
  threeSum(nums);
  threeSumClosest(nums3,target);
  fourSum(nums4,target4);
  return 0;
}
