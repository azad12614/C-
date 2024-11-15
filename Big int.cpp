#include<bits/stdc++.h>
using namespace std;

string sum(string a,string b)
{
    long long int i,len=0,value=0,carry=0;
    string ans;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.size()>=b.size())
        len=b.size();
    else
        len=a.size();
    for(i=0;i<len;i++)
    {
        value=(a[i]-'0')+(b[i]-'0')+carry;
        carry=value/10;
        string temp=to_string(value%10);
        ans+=temp;
    }
    if(a.size()>b.size())
    {
        for(i=len;i<a.size();i++)
        {
            value=(a[i]-'0')+carry;
            carry=value/10;
            string temp=to_string(value%10);
            ans+=temp;
        }
    }
    else if(a.size()<b.size())
    {
        for(i=len;i<b.size();i++)
        {
            value=(a[i]-'0')+carry;
            carry=value/10;
            string temp=to_string(value%10);
            ans+=temp;
        }
    }

    while(carry!=0)
    {
        string temp=to_string(carry%10);
        ans+=temp;
        carry=carry/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    string a,b,s;
    cin >> a >> b;
    s=sum(a,b);
    cout << s;

    return 0;
}
