// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

void print(int arr[],int n)
{
    cout<<"\nprinting array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void reversearray(int arr[],int s,int e)
{
    cout<<"\nreversing array:";
    int i=s,j=e-1;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    }
    print(arr,e);
    cout<<endl;
}

void minmaxsmax(int arr[],int n)
{
    cout<<"\nfinding min,max,smax element : "<<endl;
    int min=INT_MAX,max=INT_MIN,smax=INT_MIN;
      for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            smax=max;
            max=arr[i];
        }
        else if(arr[i]>smax && arr[i]<max)
        {
            smax=arr[i];
        }
        else if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    cout<<"\nmax element is: "<<max;
    cout<<"\nsmax element is: "<<smax;
    cout<<"\nmin element is: "<<min<<endl;
}

void freqofelement(int arr[],int n)
{
      cout<<"\nfinding freq of elements : "<<endl;
      cout<<"\nalso finding least n most freq of elements : "<<endl;
      
      vector<bool> visited(n,false);
      int mostfreq=-1,leastfreq=-1;
      int maxfreq=INT_MIN,minfreq=INT_MAX;
      
      for(int i=0;i<n-1;i++)
    {
        if(visited[i]==true) continue;
        
        int cnt=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
            {
                visited[j]=true;
                cnt++;
            }
        }
        cout<<arr[i]<<" occurs "<<cnt<<" times "<<endl;
        if(maxfreq<cnt) 
        {
            maxfreq=cnt;
            mostfreq=arr[i];
        }
        else if(cnt<minfreq)
        {
             minfreq=cnt;
            leastfreq=arr[i]; 
        }
    }
     cout<<"\nleast freq element : "<<leastfreq;
     cout<<"\nmost freq  element : "<<mostfreq<<endl<<endl;
    
 
 //method 2
 /*
 unordered_map<int,int> mp;
 for(int i=0;i<n;i++) mp[arr[i]]++;
 for(auto it:mp)
 {
     cout<<it.first<<" occurs "<<it.second<<" times "<<endl;
 }
 int mostfreq=-1,leastfreq=-1;
 int maxfreq=INT_MIN,minfreq=INT_MAX;
 for(auto it:mp)
 {
        if(maxfreq<it.second) 
        {
            maxfreq=it.second;
            mostfreq=it.first;
        }
        else if(it.second<minfreq)
        {
             minfreq=it.second;
            leastfreq=it.first; 
        }
     }
     cout<<"\n least freq element : "<<leastfreq;
     cout<<"\n most freq  element : "<<mostfreq<<endl;
     */
 }
     
void findKthSmalllarge(int arr[], int n, int k) {
//method 1    
cout<<"\nfinding kth  largest/samllest elemnent : "<<endl;
    
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
        
 for (int i = 0; i < n; i++) {
      maxHeap.push(arr[i]);
      minHeap.push(arr[i]);
      if (maxHeap.size() > k) {
             maxHeap.pop();  // Remove the largest of the k+1 elements
        }
      if (minHeap.size()>k)
        {
          minHeap.pop();   
        }
    }

   cout<<k<<" th samllest elemnent is: "<<maxHeap.top()<<endl;
   cout<<k<<" th largest elemnent is: "<<minHeap.top()<<endl;
   
//m2 sort and return k index
}

 void movenegetiveelementtoleft(int brr[],int m)
 {
     //m1
     cout<<"\nmoving all negetive elements to oneside maintaining order: "<<endl;
     int j=0;
     for (int i = 0; i < m; i++)
     {
         if(brr[i]<0)
         {
             swap(brr[i],brr[j]);
             j++;
         }
     }
     print(brr,m);
     
     //m2 sorting but order not maintain
 }
 
  void maxconsectiveones(int crr[],int p)
 {
     //m1
     cout<<"\nfinding max consective ones in binary array "<<endl;
     int maxcnt=0;
     int cnt=0;
     for (int i = 0; i < p; i++)
     {
         if(crr[i]==1)
         {
             cnt++;
             maxcnt=max(maxcnt,cnt);
         }
         else cnt=0;
     }
     
      cout<<"\nmax consective ones :"<<maxcnt<<endl;
     
 }
   void duplicateelement(int drr[],int q)
 {
     cout<<"\nfinding duplicate in size of n+1 "<<endl;
     //m1 
     int duplicate=0,freq[q]={0};
     for (int i = 0; i < q; i++)
     {
         int val=drr[i]-1;
         if(!freq[val])
         {
            freq[val]++;
         }
         else {
             duplicate=drr[i];
             break;
         }
     }
     cout<<"\nduplicate element is: "<<duplicate<<endl;
     
     //m2 cycle sort and check consecutive elements
 }
    void uniqueintwice(int err[],int r)
 {
     cout<<"\nfinding unique element where every other appears twice"<<endl;
     //m1 
     int unique=0;
     for (int i = 0; i < r; i++)
     {
           unique^=err[i];
     }
     cout<<"\nunique element is: "<<unique<<endl;
     
     //m2 map n return it.second==1;
 }
 
     void rotatearray(int brr[],int m,bool dir,int k)
 {
     cout<<"\nrotating array 1=left/0=right by k which is "<<k<<endl;
     k=k%m;
     cout<<"\noriginal array : "<<endl;
     print(brr,m);
     if(dir)
     {
           cout<<"\nrotating array left by "<<k<<endl;
           reversearray(brr,0,m);
           reversearray(brr,0,m-k);
           reversearray(brr,m-k,m);
           print(brr,m);
     }
     else
     {
           cout<<"\nrotating array right by "<<k<<endl;
           reversearray(brr,0,m-k);
           reversearray(brr,0,m);
           reversearray(brr,0,k);
           print(brr,m);
     }
     
 }

int main() {
    int arr[]={12,4,65,3,87,55,23,45,65,65,4,55};
    int brr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int crr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
    int drr[]= {1,3,3,2,4};
    int err[] = {4,1,2,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(brr)/sizeof(brr[0]);
    int p=sizeof(crr)/sizeof(crr[0]);
    int q=sizeof(drr)/sizeof(drr[0]);
    int r=sizeof(err)/sizeof(err[0]);
    print(arr,n);
    reversearray(arr,0,n);
    minmaxsmax(arr,n);
    freqofelement(arr,n);
    findKthSmalllarge(arr,n,3);
    movenegetiveelementtoleft(brr,m);
    maxconsectiveones(crr,p);
    duplicateelement(drr,q);
    uniqueintwice(err,r);
    rotatearray(brr,m,0,3); //array,size,0=right/1=left,move by k;
    return 0;
}

