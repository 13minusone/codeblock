    #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x,y,z;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}

bool solve(int x,int y ,int z)
{
    int s=0,s1=0;
    s=s+x-1;
    s=s+x*(y-1);
    s1=s1+y-1;
    s1=s1+y*(x-1);

   if(z==s||z==s1)
   {
       return true;

   }
   else
   {
       return false;
   }
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{
    cin>>x >> y >> z;
    if(solve(x,y,z))
    {
        cout << "YES" <<endl;
    }
    else
    {
        cout << "NO" <<endl;
    }
}
}
int main()
{
IOS
//inti()
nhap();

}

