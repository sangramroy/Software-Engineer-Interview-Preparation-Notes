// Online C++ compiler to run C++ program online
/*
Substrings of Size Three with Distinct Characters
Find All Anagrams in a String
Maximum Number of Vowels in a Substring of Given Length
Remove All Occurrences of String
Permutation in String
Maximum Number of Occurrences of a Substring
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

void print(string s)
{
    cout<<"\nprinting string\n";
       for(auto it:s)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

 void countGoodSubstrings(string s) {
     cout<<"\nSubstrings of Size Three with Distinct Characters:";
     print(s);
     if (s.size() < 3) cout<<"\nSubstrings Size is: "<<0<<endl;
     int count = 0;
     for (int i = 0; i < s.size() - 2; i++) {
         char a = s[i], b = s[i+1], c = s[i+2];
         if (a != b && b != c && a != c) {
             count++;
         }
     }
      cout<<"Substrings Size is: "<<count<<endl;
 }
 
bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

  void maxVowels(string s, int k) {
     cout<<"\nMaximum Number of Vowels in a Substring of Given Length:";
     print(s);
     int maxcnt=0,cnt=0;
     for(int j=0;j<k;j++)
    {
        if(isVowel(s[j])) cnt++;
    }

    if(cnt>maxcnt) maxcnt=cnt;
    for(int i=k;i<s.size();i++)
        {
           if(isVowel(s[i])) cnt++;
           if(isVowel(s[i-k])) cnt--;
           if(cnt>maxcnt) maxcnt=cnt;
        }

          cout<<"Maximum Number of Vowels in a Substring is: "<<maxcnt<<endl;;
}

void findAnagrams(string s, string p) {
     cout<<"\nFind All Anagrams in a String:";
     print(s);
    vector<int> phash(26,0);
    vector<int> shash(26,0);
    vector<int> ans;

    // Fix: Avoid loop if s is smaller than p
    if (s.size() < p.size()) cout<<"\ninvalid sizes:\n";

    for(int i = 0; i < p.size(); i++) {
         phash[p[i]-'a']++;
         shash[s[i]-'a']++;
    }
    if (phash==shash) ans.push_back(0);
    for(int i = p.size(); i < s.size(); i++) {
         shash[s[i]-'a']++;
         shash[s[i-p.size()]-'a']--;
         if (phash==shash) ans.push_back(i+1-p.size());
    }
    cout<<"indexes where anagram is:\n";
    for(auto it:ans)
    {
       cout<<it<<" "; 
    }
    cout<<endl;
}

   void removeOccurrences(string s, string part) {
       cout<<"\nFind substring n remove it from String:";
       print(s);
        while(s.size()>0 && s.find(part)<s.size())
        {
            s.erase(s.find(part),part.size());
        }
        cout<<"final string is:" <<s<<endl;
    }
void countFreq(string pat, string txt)
{
     cout<<"\nFrequency of a Substring in a String:";
      cout<<"\nstring is:";
      print(txt);
     cout<<"pattern is:";
     print(pat);
    int M = pat.length();
    int N = txt.length();
    int res = 0;

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M) {
            res++;
        }
    }
      cout<<"Maximum Frequency is: "<<res<<endl;
}

bool issame(int freq1[],int freq2[])
{
    for(int i=0;i<26;i++)
    {
        if(freq1[i]!=freq2[i]) return false;
    }
 return true;
} 

void checkInclusion(string s1, string s2) {
    cout<<"\nchecking string: "<<s1<<" is permutation of string: "<<s2<<endl;
    int freq1[26]={0};
    for(int i=0;i<s1.size();i++)
    {
        freq1[s1[i]-'a']++;
    }
    int windsize=s1.size();
    for(int i=0;i<s2.size();i++)
    {
        int idx=i;
        int widx=0;
        int freq2[26]={0};
        while(widx<windsize && idx<s2.size())
        {
                   freq2[s2[idx]-'a']++; 
                   widx++;idx++;
        }

        if(issame(freq1,freq2)) 
        cout<<"given string is permutation"<<endl;
    }
    cout<<"given string is not permutation is: "<<endl;
}
 

int main() {
string s = "xyzzaz";
string s1 = "abciiidef";int k = 3;
string s2 = "cbaebabacd", p = "abc";
string s3 = "daabcbaabcbc", part = "abc";
string txt = "dhimanman";
string pat = "man";
string s4 = "ab", s5 = "eidbaooo";
countGoodSubstrings(s);
maxVowels(s1,k);
findAnagrams(s2,p);
removeOccurrences(s3,part);
countFreq(pat, txt);
checkInclusion(s4,s5);
return 0;
}



