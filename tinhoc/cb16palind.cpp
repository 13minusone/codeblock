#include<bits/stdc++.h>
using namespace std;
string s;
string doixungle(long long mid)
{
    long long k=0;
    string d="";
        for(int i=mid+1;i<=s.size()-1;i++)
        {

        if(s[mid-k-1]!=s[mid+k+1])
        {
            return doixungle(mid+1);
        }
k++;
        }

        for(int i=mid-k-1;i>=0;i--)
        {

                d=d+s[i];

        }
        return s+d;
}
/*string doixungchan(long long mid)
{
    if(a[mid]!=a[mid-1])
    {
        return doixungle(mid+1);
    }
    else
    {
        for(int )
    }
}*/
int main()
{

    cin>>s;
    if(s.size()%2!=0)
    {
        long long mid=s.size()/2+1;
cout<<doixungle(mid);
    }
    else
    {
        long long mid=s.size()/2;
        cout<<doixungchan(mid);
    }
}
