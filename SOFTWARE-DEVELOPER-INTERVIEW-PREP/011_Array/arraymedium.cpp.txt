//array medium
/*
Sort array of 0s, 1s & 2s
Stock Buy & Sell
Product of array except itself
Merge overlapping intervals
Container with most water
Trapping Rainwater
Kadane's Algorithm
Majority Element
Repeat & missing number
Merge 2 sorted array without xtra space
Single Number
2Sum
3Sum
4Sum
*/

#include <iostream>
#include <climits>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


void print(int arr[],int n)
{
    cout<<"\nprinting array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void sortzeroonetwo(int crr[],int p)
{
    print(crr,p);
    cout<<"\n DNF algo sorting ongoing:";
   int low=0,mid=0,high=p-1;
   while(mid<=high)
   {
       if(crr[mid]==0)
       {
           swap(crr[low++],crr[mid++]);
       }
       else if(crr[mid]==1)
       {
           mid++;
       }
       else swap(crr[mid],crr[high--]);;
   }
   print(crr,p);
   cout<<endl;
}

void stockbuysell(int arr[],int n)
{
   print(arr,n);
   cout<<"\nstock buy and sell best time";
   int bestbuy=arr[0];
   int maxprofit=0;
   int buyidx=-1;
   int sellidx=-1;
   for(int i=0;i<n;i++)
   {
       if(arr[i]<bestbuy)
       {
           bestbuy=min(arr[i],bestbuy);
           buyidx=i;
       }
       if(maxprofit<(arr[i]-bestbuy))
       {
           maxprofit=max(maxprofit,arr[i]-bestbuy);
           sellidx=i;
       }
   }
   cout<<"\nstock buy price: "<<arr[buyidx]<<" at day: "<<buyidx;
   cout<<"\nstock sell price: "<<arr[sellidx]<<" at day: "<<sellidx;
   cout<<"\nmax profit is: "<<maxprofit<<endl;
}

void arrayproductexceptself(int drr[],int q)
{
   print(drr,q);
   cout<<"\nProduct of array except itself";
   int prefix[q]={0}, suffix[q]={0},ans[q]={0};
   prefix[0]=suffix[q-1]=1;
   for(int i=1;i<q;i++)
   {
       prefix[i]=prefix[i-1]*drr[i-1];
       ans[i]=prefix[i-1]*drr[i-1];
   }
     for(int i=q-2;i>=0;i--)
   {
       suffix[i]=suffix[i+1]*drr[i+1];
   }
       for(int i=0;i<q;i++)
   {
       ans[i]=prefix[i]*suffix[i];
   }
    print(ans,q);
}

void trappinrainwater(int drr[],int q)
{
   print(drr,q);
   cout<<"\ntrapping rain water problem";
   int leftmax=drr[0],rightmax=drr[q-1],left=0,right=q-1;
   int ans=0;
   while(left<right)
   {
       leftmax=max(leftmax,drr[left]);
       rightmax=max(rightmax,drr[right]);
       if(drr[left]<drr[right])
       {
           //decision is based on leftmax;
           ans+=leftmax-drr[left];
           left++;
       }
       else
       {
           ans+=rightmax-drr[right];
           right--;
       }
   }
   cout<<"\nmax water trapped is: "<<ans<<endl;
   
   //m2 create two prefix arrays to store leftsidemax and rightside max
   //and in ans=0; while iterating ans+=min(leftsidemax[i],rightside[i])-arr[i];
}

void containerwithmostwater(int drr[],int q)
{
   print(drr,q);
   
   cout<<"\ncontainer with most water: ";
   int left=0,right=q-1,ht,wt;
   int maxwatercoll=0;
   int currwatercoll;
   while(left<right)
   {
       ht=min(drr[left],drr[right]);
       wt=right-left;
       currwatercoll=wt*ht;
       maxwatercoll=max(currwatercoll,maxwatercoll);
       
       drr[left]<drr[right]?left++:right--;
   }
   cout<<"\nmax water collected is: "<<maxwatercoll<<endl;
   
   //m2 use two for loops and calculate area=wt*ht and update maxwatercoll at each iteration
}

void majorityelement(int drr[],int q)
{
   print(drr,q);
   cout<<"\nfinding element occuring greater than n/2 times: ";
   sort(drr,drr+q);
   cout<<"\nelement is: "<<drr[q/2]<<endl;
   
   //m2 use two for loops and calculate area=wt*ht and update maxwatercoll at each iteration
}

void kadanesalgo(int nrr[],int u)
{
   print(nrr,u);
   cout<<"\nfinding max subarray sum with start n end track ";
   int currsum=0,maxsum=0,start=0,end=0,tempstart=0;
   for(int i=0;i<u;i++)
   {
       currsum+=nrr[i];
       if(currsum>maxsum)
       {
           maxsum=currsum;
           start=tempstart;
           end=i;
       }
       else if(currsum<0)
       {
           currsum=0;
           tempstart=i+1;
       }
   }
    cout<<"\nmax subarray sum is: "<<maxsum;
    cout<<"\nstart of subarray is: "<<start;
    cout<<"\nend of subarray is: "<<end<<endl;
}

int main() {
    int arr[]={12,4,65,32,87,55,23,45,65,65,4,55};
    int brr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int crr[] = {1, 1, 0, 0, 1, 0, 1, 0, 2, 1, 2, 1};
    int drr[]= {1,3,3,2,4};
    int err[] = {4,2,0,3,2,5,4,5};
    int frr[] = {1,8,6,2,5,4,8,3,7};
    int mrr[]={2,2,1,1,1,2,2};
    int nrr[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(brr)/sizeof(brr[0]);
    int p=sizeof(crr)/sizeof(crr[0]);
    int q=sizeof(drr)/sizeof(drr[0]);
    int r=sizeof(err)/sizeof(err[0]);
    int s=sizeof(frr)/sizeof(frr[0]);
    int t=sizeof(mrr)/sizeof(mrr[0]);
    int u=sizeof(nrr)/sizeof(nrr[0]);
    sortzeroonetwo(crr,p);
    stockbuysell(arr,n);
    arrayproductexceptself(drr,q);
    trappinrainwater(err,r);
    containerwithmostwater(frr,s);
    majorityelement(mrr,t);
    kadanesalgo(nrr,u);
    return 0;
}



