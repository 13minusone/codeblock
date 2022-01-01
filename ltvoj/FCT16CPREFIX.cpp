#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;


const int mod = int(1e9)+7;
void inti()
{
    freopen("FCT16CPREFIX.inp","r",stdin);
    freopen("FCT16CPREFIX.out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
string s;
typedef pair<int, int> ii;
queue<ii> er;
void nhap()
{
    cin >> s;
    int n=SZ(s);
    s=" "+s;
    fu(i,1,n,1)
    {
        if (s[i]==s[1]) er.push(ii(i,1));
    }
    int sum=0, t=0;
    string st="", re;
    while(!er.empty())
    {
        ii x=er.front();
        int cnt=x.second;
        re="";
        for(int i=x.first; i<x.first+x.second; i++)
        {
            re+=s[i];
        }
        while(x.second==cnt)
        {
            er.pop();
            for(int i=x.first; i<x.first+x.second; i++)
            {
                st+=s[i];
            }
            if (st==re)
            {
                sum++;
                er.push(ii(x.first, x.second+1));
            }
            x=er.front();
            st="";
        }
        cout << sum << " ";
        t++;
        if (er.size()==1)
        {
            break;
        }
        sum=0;
    }
    t++;
    fu(i,t,n,1)
    {
        re+=s[i];
        if (s.find(re)!=-1)
        {
            cout << 1 << " ";
        }
        else
        {
            fu(j,t,n,1)
            {
                cout << 0 << " ";
            }
            return;
        }
    }
}
int main()
{
    inti();
    fastio();
    nhap();
}
