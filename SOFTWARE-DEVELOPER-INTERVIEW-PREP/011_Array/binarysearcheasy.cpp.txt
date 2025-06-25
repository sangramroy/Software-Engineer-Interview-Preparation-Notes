/*
Search in rotated sorted array 1
Search in rotated sorted array 2
Peak index in mountain array
search insert posn in sorted array (floor/ceil based)
Single element in sorted array (every appers twice except 1 in sorted manner)
Repeat & missing number
lower bound and upper bound
floor and ceil
first n last posn of element in sorted array (floor/ceil based)
| Term            | Meaning                        | Example (target = 6) in \[1,3,5,7,9] |
| --------------- | ------------------------------ | ------------------------------------ |
| **Floor**       | Greatest number ≤ target       | 5                                    |
| **Ceil**        | Smallest number ≥ target       | 7                                    |
| **Lower Bound** | First index of number ≥ target | 3 (value: 7)                         |
| **Upper Bound** | First index of number > target | 3 (value: 7)                         |
lower bound returns ceil index;
upper bound returns floor index;
*/

#include <iostream>
#include <vector>
using namespace std;

void peakIndexInMountainArray(vector<int>& nums) 
  {
    cout<<"finding peak element in mountain array:"<<endl;
    int n = nums.size();
    if (n == 1) 
    {
     cout<<"single element present so peak index is :"<<0<<endl<<endl;
     return;
    }
    if (nums[0] > nums[1]) 
    {
        cout<<"two element present so for peak greatest one is :"<<0<<endl<<endl;
         return;
    }
    if (nums[n - 1] > nums[n - 2])  
    {
        cout<<"for last two element present so for peak greatest one is :"<<n-1<<endl<<endl;
        return;
    }
    int st = 1, end = n - 2; // first n last element cannot be peak if mountain exists
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
             {
              cout<<"peak element present so peak index is :"<<mid<<endl<<endl;
              return;
             }
        else if (nums[mid] < nums[mid + 1])
            st = mid + 1;
        else
            end = mid - 1;
    }
    cout<<"peak element not found so index is :"<<-1<<endl<<endl;
}

 void searchinrotatedarrayone(vector<int>& nums, int target) {
    cout<<"searching element in rotated sorted array (distinct elements) :"<<endl;
    int st=0,end=nums.size()-1;
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(nums[mid]==target) 
        {
            cout<<"target: "<<target<<" element found at iindex :"<<mid<<endl<<endl;;
            return;
        }
        // detecting sorted array direction as left is sorted
        if(nums[st]<=nums[mid])
        {
            if(nums[st]<=target && target<=nums[mid]){
              end=mid-1;
            }
            else
            {
               st=mid+1;
            }
        }
        // // detecting sorted array direction as right is sorted
        else
        {
              if(nums[mid]<=target && target<=nums[end]){
              st=mid+1;
            }
            else
            {
               end=mid-1;
            }
        }
    }
    cout<<"peak element not found so index is :"<<-1<<endl<<endl;;
}

 void searchinrotatedarraytwo(vector<int>& nums, int target) {
     cout<<"searching element in rotated sorted array (duplicates present) :"<<endl;
    int st=0,end=nums.size()-1;
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(nums[mid]==target) 
        {
            cout<<"target: "<<target<<" element found at iindex :"<<mid<<endl<<endl;;
            return;
        }
         if((nums[st]==nums[mid]) && (nums[end]==nums[mid]))
            {
                st++;end--;
            }
             // // detecting sorted array direction as left is sorted
        else if(nums[st]<=nums[mid])
        {
            if(nums[st]<=target && target<=nums[mid]){
              end=mid-1;
            }
            else
            {
               st=mid+1;
            }
        }
         // // detecting sorted array direction as right is sorted
        else
        {
              if(nums[mid]<=target && target<=nums[end]){
              st=mid+1;
            }
            else
            {
               end=mid-1;
            }
        }
    }
    cout<<"peak element not found so index is :"<<-1<<endl<<endl;;
}

 void firstlastoccurence(vector<int>& nums, int target) {
     
       cout<<"finding first n last occ of element:"<<target<<endl;
       int first=-1,last=-1;
       int s=0,e=nums.size()-1;
       vector<int> v(2);
       while(s<=e)
       {
        int mid=s+(e-s)/2;
        // after finding element mode left for first occ
        if(nums[mid]==target)
        {
            first=mid;
            e=mid-1;
        }
        else if(nums[mid]<target) s=mid+1;
        else e=mid-1;
       } 
       s=0,e=nums.size()-1;
       while(s<=e)
       {
        int mid=s+(e-s)/2;
         // after finding element mode right for last occ
        if(nums[mid]==target)
        {
            last=mid;
            s=mid+1;
        }
        else if(nums[mid]<target) s=mid+1;
        else e=mid-1;
       } 
       cout<<"first  occ of element: "<<first<<endl;
       cout<<"last occ of element: "<<last<<endl<<endl;
}

void findFloorCeil(const vector<int>& nums, int target) {
    
    cout<<"finding first n last occ of element:"<<target<<endl;
    int n = nums.size();
    int floor = -1, ceil = -1;

    // Find floor (last element <= target)
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            floor = nums[mid];  // Exact match is both floor and ceil
            break;
        } else if (nums[mid] < target) {
            floor = nums[mid];  // Potential floor found, move right to find greater
            s = mid + 1;
        } else {
            e = mid - 1;  // Too big, move left
        }
    }

    // Find ceil (first element >= target)
    s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            ceil = nums[mid];  // Exact match
            break;
        } else if (nums[mid] < target) {
            s = mid + 1;  // Too small, move right
        } else {
            ceil = nums[mid];  // Potential ceil found, move left to find smaller
            e = mid - 1;
        }
    }

    cout<<"ceil  occ of element: "<<ceil<<endl;
    cout<<"floor occ of element: "<<floor<<endl<<endl;
}

void searchinsertpos(const vector<int>& nums, int target) {
    
    cout<<"in sorted array finding insert pos of element: "<<target<<endl;
    int n = nums.size();
    int ceil = -1;
    
    // Find ceil (first element >= target)
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            ceil = mid;  // Exact match
            break;
        } else if (nums[mid] < target) {
            s = mid + 1;  // Too small, move right
        } else {
            ceil = mid;  // Potential ceil found, move left to find smaller
            e = mid - 1;
        }
    }

    cout<<"insert pos of element: "<<ceil<<endl<<endl;
}



int main() 
 {
    vector<int> arr = {0,2,1,0};
    vector<int> nums = {4,5,6,7,0,1,2};
    vector<int> nums1 = {2,5,6,0,0,1,2};
    vector<int> nums2 = {5,7,7,8,8,10};
    vector<int> nums3 = {1, 2, 4, 6, 8, 10};
    vector<int> nums4 = {1, 4, 6, 8, 10,14 ,16};
    peakIndexInMountainArray(arr);
    searchinrotatedarrayone(nums,0);
    searchinrotatedarraytwo(nums1,0);
    firstlastoccurence(nums2,8);
    findFloorCeil(nums3,6);
    searchinsertpos(nums4,5);
    return 0;
}

