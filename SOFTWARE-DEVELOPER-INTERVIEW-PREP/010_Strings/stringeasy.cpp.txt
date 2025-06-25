/*
Check if two strings are anagrams //anagrams =same charcater with same freq present
Find the first non-repeating character
Find the most frequent character in a string
Count occurrences of each character using map
Check if one string is a rotation of another
Find the longest word in a sentence
Reverse Words in String
Remove characters from the first string which are present in the second
Check if two strings are isomorphic
*/

#include <iostream>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

 void isanagram(string s1,string s2)
 {
     cout<<"checking strings s1: "<<s1<<" and s2:"<<s2<<" are anagrams ?\n";
     //m1 sort both string and compare
     //m2 use map
     unordered_map<char,int> mp;
     for(char ch:s1) mp[ch]++;
     for(char ch:s2) mp[ch]--;
     for(auto it:mp)
     {
         if(it.second!=0) 
         {
             cout<<"not anagrams \n\n"; 
             return;
         }
     }
     cout<<"they are anagrams \n\n";
 }
 
  void nonRepfirstchar(string s)
 {
     cout<<"finding first non repeating char in strings s: "<<s<<endl;
     
     //use freq array instead of map
     vector<int> freq(26,0);
     for(char ch:s) freq[ch-'a']++;
     for(char ch:s)
     {
         if(freq[ch-'a']==1) 
         {
             // for last non repeating char store ch and let the loop finish
             cout<<"first non repeating char is: "<<ch<<endl<<endl; 
             return;
         }
     }
     cout<<"first non repeating char not found \n\n";
 }
 
   void mostfreqchar(string s)
 {
     cout<<"finding most freq char in strings s: "<<s<<endl;
     
     //m1 use freq array
     //use freq array instead of map
     vector<int> freq(26,0);
     for(char ch:s) freq[ch-'a']++;
     int max=0;
     char c='\0';
     for(char ch:s)
     {
         if(freq[ch-'a']>max) 
         {
             max=freq[ch-'a'];
             c=ch;
         }
     }
    cout<<"most freq char is: "<<c<<" occured "<<max<<" times \n\n";
    
    //m2 use map of char and int
 }
 
    void eachcharfreq(string s)
 {
     cout<<"finding each char freq in strings s: "<<s<<endl;
     //m1 use freq array
     //use freq array instead of map
     vector<int> freq(26,0);
     for(char ch:s) freq[ch-'a']++;
     for(char ch:s)
     {
       if(freq[ch-'a'])
       cout<<"char "<<ch<<" occured "<<freq[ch-'a']<<" times \n";
       freq[ch-'a']=0;
     }
     cout<<endl;
     
    //m2 use map of char and int
 }
 
     void isstringrotation(string s1,string s2)
 {
      cout<<"checking strings s2:"<<s2<<" rotation of strings s1:"<<s1<<endl;
     //m1 inbuilt string func if not found npos is -1
     s1=s1+s1;
     if(s1.find(s1)!=string::npos)
     {
         cout<<"strings s2:"<<s2<<" is rotation of strings s1:"<<s1<<endl<<endl;
     }
     else
     {
           cout<<" strings s2:"<<s2<<" is not rotation of strings s1:"<<s1<<endl<<endl;
     }
    
    //m2 
 }
 
      void reversewords(string s)
 {
      cout<<"revsersing words of string: "<<s<<endl;
      cout<<"also finding longest words in string: "<<s<<endl;
      stack<string> st;
      string ans="";
      int max=0;
      for(int i=0;i<s.size();i++)
      {
          char ch=s[i];
          if(ch==' ')
          {
             st.push(ans);
             ans="";
          }
          else
          {
              ans+=ch;
          }
      }
      st.push(ans);
      while(!st.empty())
      {
          string str=st.top();
          int longestname=str.size();
          if(longestname>max)
          {
              max=longestname;
              ans=str;
          }
          cout<<st.top()<<" ";
          st.pop();
      }
      cout<<"\nlongest word is: "<<ans<<endl<<endl;
 }

int main() 
{
    cout<<"STRING EASY PROBLEMS\n";
    string s1 = "geeks";
    string s2 = "kseegi";
    string s4 = "ksgee";
    string s = "geeksforgeeks";
    string s3 = "my name is khansir";
    isanagram(s1,s2);
    nonRepfirstchar(s);
    mostfreqchar(s);
    eachcharfreq(s);
    isstringrotation(s1,s4);
    reversewords(s3);
    return 0;
}

