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
void nhap()
{

cin>>n;
vector<int> vec1;
vector<int>vec2;
fu(i,1,n,1)
{
 cin >> m ;
 fu(g,1,m,1)
 {

     cin >> x;
     if(x%2==0)
     {
         vec2.pb(x);
     }
     else
     {
         vec1.pb(x);
     }

 }
     int f=vec1.size();
     int g=vec2.size();
     fu(k,0,f-1,1)
     {
         cout << vec1[k] << " ";
     }
     fu(j,0,g-1,1)
     {
         cout << vec2[j] << " ";
     }
     cout <<endl;
     vec1.clear();
     vec2.clear();
}
}
int main()
{
IOS
//inti()
nhap();

}

