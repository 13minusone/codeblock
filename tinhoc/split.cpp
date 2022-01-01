#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x;
    string s;
void inti()
{
   freopen("split.inp","r",stdin);
   freopen("split.out","w",stdout);
}
void le(string s,int r)
{
    int l=s.size()/2;
    //cout<<s.size()<<endl;
    int i=1,t=0;
    while(i<=l)
    {
        if(s[l+i]!=s[l-i])
        {
            t=1;
            break;

        }
        else
        {
            break;
        }
        i++;
    }
    if(l+1>=r+1&&t==0)
    {
        cout<<"YES"<<endl;

    }
    else
    {
        cout<<"NO"<<endl;
    }
}
void chan(string s,int r)
{
    int l=s.size()/2-1;
    int i=0,t=0;
    cout<<s.size()<<" "<<l<<endl;
    while(i<=l)
    {
        if(s[l+i+2]!=s[l-i]&&t<=2)
        {
            t=1;
            break;
        }
        i++;
    }
    if(l+1>=r+1&&t==0)
    {
        cout<<"YES"<<endl;

    }
    else
    {
        cout<<"NO"<<endl;
    }
}
void solve(int l,int r,string s)
{
    if(r==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(l<=r+1)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        if(l%2==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            le(s,r);
        }
    }
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{
    cin>>m>>x;
    cin>>s;
    solve(m,x,s);
}
}
int main()
{
IOS
//inti();
nhap();

}

