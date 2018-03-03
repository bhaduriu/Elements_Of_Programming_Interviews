/*
WARNING: C++ 14
The Run-Length Encoding of "aaaabcccaa" is "4a1b3c2a". The decoding of "3e4f2e" returns "eeeffffee".
Implement Run-Length Encoding and Decoding functions.
*/

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

void decode(string s)
{
    int pos;
    for(int i=0;i<s.length();++i)
    {
        if(!isdigit(s.at(i)))
        {
            string str=s.substr(pos,i-pos);
            int d=stoi(str);
            while(d--)
                cout<<s.at(i);
        }
        else
            pos=i;
    }
}
void encode(string s)
{
    int count=1;char c;int i;
    for(i=0;i<s.length()-1;++i)
    {
        if(s.at(i)==s.at(i+1))
            count++;
        else
        {
            cout<<count<<s.at(i);
            count=1;
        }
    }
    cout<<count<<s.at(i);
}
int main()
{
    string s;
    cin>>s;
    if(isdigit(s.at(0)))
        decode(s);
    else
        encode(s);
    return 0;
}

