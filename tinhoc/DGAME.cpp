#include<bits/stdc++.h>
using namespace std;
long long a[1000];
vector<int>p;
int main()
{
    string s;
    while(cin>>s)
    {
        p.clear();
        for(int i=0;i<s.size();i++)
        {
            if(a[int(s[i])]==0)
            {
                p.push_back(int(s[i]));
            }
            a[int(s[i])]++;
        }
        long long d=a[p[0]],k=1;
        for(int i=1;i<p.size();i++)
        {
            if(d!=a[p[i]])
            {
                cout<<"NO"<<'\n';
                k=0;
                break;
            }
            a[p[i]]=0;

            }
            if(k==1)cout<<"YES"<<'\n';
        }
    }
