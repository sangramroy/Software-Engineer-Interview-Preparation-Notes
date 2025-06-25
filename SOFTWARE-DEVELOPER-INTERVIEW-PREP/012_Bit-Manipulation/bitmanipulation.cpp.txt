/*
Check if a number is even or odd using bitwise operators
Find the ith bit of a number
Set the ith bit of a number
Clear the ith bit of a number
Toggle the ith bit of a number
Count the number of set bits in an integer (Hamming Weight)
Check if a number is a power of 2
*/


#include <bits/stdc++.h>
using namespace std;

void findithbit(int num,int i)
{
    cout<<"\n finding ith bit of num: "<<num<<endl;
    //1101   (i=3)
    //0100  (shift 1 by i-1)
    //
    if(num&(1<<i-1)) cout<<i<<"th bit is: "<<1<<endl;
    else cout<<i<<"th bit is: "<<0<<endl;
}
void setithbit(int num,int i)
{
      cout<<"\nsetting ith : "<<i<<" bit of num: "<<num<<endl;  
     //1101   (i=2)
     //0010  (shift 1 by i-1)
     //do or 1111
     num=(num|(1<<(i-1)));
     cout<<"now num is :"<<num<<endl;
}
void clearithbit(int num,int i)
{
    cout<<"\nclearing ith : "<<i<<" bit of num: "<<num<<endl;
    //1101   (i=3)
    //0100  (shift 1 by i-1)
    //reverse all bits
    //1011
    //do and 1111
    num=(num&(~(1<<(i-1))));
    cout<<"now num is :"<<num<<endl;
}
void toggleithbit(int num,int i)
{
      cout<<"\ntoggling ith : "<<i<<" bit of num: "<<num<<endl;
      int ans=(num&(1<<i-1));
      //if 1 call clearbit else call setbit;
      if(ans)
      {
         num=(num&(~(1<<(i-1))));
         cout<<"now num is :"<<num<<endl;  
      }
      else
      {
         num=(num|(1<<(i-1)));
         cout<<"now num is :"<<num<<endl;  
      }
}
void isevenodd(int num)
{
      cout<<"\nchecking is num: "<<num<<" even or odd?"<<endl;
      if(!num&1) cout<<num<<" is even:\n";
      else cout<<num<<" is odd:\n";
}
void noofsetbits(int num)
{
        cout<<"\nchecking no of set bits in num: "<<num<<endl;
        int cnt=0;
        while(num>0)
        {
            num=num&(num-1);
            cnt++;
        }
        cout<<"no of set bits in num is: "<<cnt<<endl;
}
void ispoweroftwo(int num)
{
     cout<<"\nchecking is num: "<<num<<" power of 2";
     if(!num&(num-1)) cout<<"\nnum: "<<num<<" is power of 2"<<endl;
     else cout<<"\nnum: "<<num<<" is not power of 2"<<endl;
}


int main() {
    int num=13; //1101
    findithbit(num,2);
    setithbit(num,2);
    clearithbit(num,3);
    toggleithbit(num,2);
    isevenodd(num);
    noofsetbits(num);
    ispoweroftwo(num);
    return 0;
}


