#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,x,y;
void inti()
{
   freopen("queue860.inp","r",stdin);
   freopen("queue860.out","w",stdout);
}
stack<int>mode;
void nhap()
{
vector<int>vec;
cin>>n;
fu(1,n,1)
{cin>>x;

if(x==0)
{
    cin>>y;
    vec.push_back(y);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}
else
{
    if(vec.size()>0)
   {

cout<<vec[0]<< " ";

    for(int i=1;i<=vec.size()-1;i++)
    {
        cout<<vec[i]<<" ";
    }
vec.erase(vec.begin() );
}
else
{
    cout<<"-1"<<endl;
    break;
}
}
cout<<endl;
}}
int main()
{
    inti();
nhap();
}

