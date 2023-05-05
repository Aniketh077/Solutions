/*
a) String compression

Implement a method to perform string compression. Eg aabcccccaaa' should be a2b1c5a3. The code to implement this is given in the link-https://www.educative.io/answer/string compression waing run length encoding
Think about memory occupied and how it can be improved. The answer should be taken into second compressor and compress further.
Eg a2b2c1a3c3 should become ab2ciac
decompress2  ab2c1ac3 should returns aabbcaaaccc
*/



#include <bits/stdc++.h>
using namespace std;

string compress1(string s){
    if(!s.length()) return s;
    int i=1,count=1;
    string ans="";
    char prev=s[0];
    while(i<s.length()){
        if(s[i]!=prev){
            ans+=prev;
            prev=count+'0';
            ans+=to_string(count);
            prev=s[i];
            count=1;
        }
        else count++;
        i++;
    }
    ans+=prev;
    prev=count+'0';
    ans+=to_string(count);
    return ans;
}

string compress2(string s){
    if(!s.length()) return s;
    string ans="",prev="";
    int i=0,pcount=0,ccount=0; // pcount is prevcount ccount is curcount
    char cur;
    while(i<s.length()){
        cur=s[i++];
        ccount=0;
        while(i<s.length() && s[i]>='0' && s[i]<='9'){
            ccount=ccount*10+s[i]-'0';
            i++;
        }
        if(prev==""){
            prev+=cur;
            pcount=ccount;
        }
        else{
            if(pcount==ccount) prev+=cur;
            else{
                ans+=prev;
                ans+=to_string(pcount);
                prev=cur;pcount=ccount;
            }
        }
    }
    ans+=prev;
    ans+=to_string(ccount);
    return ans;
}

string decompress(string s){
    if(!s.length()) return s;
    string ans="",cur="";
    int i=0,count=0;
    while(i<s.length()){
        cur="";count=0;
        while(i<s.length() && s[i]>='a' && s[i]<='z'){
            cur+=s[i];
            i++;
        }
        while(i<s.length() && s[i]>='0' && s[i]<='9'){
            count=count*10+s[i]-'0';
            i++;
        }
        for(int j=0;j<cur.size();j++){
            for(int k=0;k<count;k++) ans+=cur[j];
        }
    }
    return ans;
}

int main()
{
    string s,s1,s2;
    cin>>s;
    s1=compress1(s);
    cout<<s1<<endl;
    s2=compress2(s1);
    cout<<s2<<endl;
    cout<<decompress(s2)<<endl;
    
    return 0;
}