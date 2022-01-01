#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
unsigned ll dem(int i)
{
    unsigned ll  s=1;
    fu(j,1,i-1,1)
    {
        s=s*10+1;
    }
    return s;
}
vector<unsigned ll>vec;
void tao()
{
    fu(i,1,19,1)
    {
        unsigned ll f=dem(i);

        fu(j,1,9,1)
        {
            vec.push_back(f*j);
        }
    }
}
void nhap()
{

cin>>n;
tao();
int g=vec.size();
fu(i,0,g-1,1)
{
    if(vec[i]%n==0)
    {
        cout << vec[i]/n;
        return ;
    }
    //cout <<vec[i];
}
cout << "-1" ;
}
int main()
{
IOS
//inti()
nhap();

}

