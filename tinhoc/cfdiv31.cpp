#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x;

typedef pair<int,int> ii ;
  int d[101],g;
vector<pair<int,int>>vec;
void solve()
{
    int j=vec.size()-1;
        fu(o,0,j,1)
        {
            if(d[vec[o].first]==1)
            {

                cout <<vec[o].second ;

            }
            d[vec[o].first]=0;
        }
        vec.resize(0);
}
void nhap()
{
    cin>>n;


    fu(i,1,n,1)
    {
        cin>>x;

        fu(h,1,x,1)
        {
            cin >> g ;
            if(d[g]==0)
            {
                vec.push_back(ii(g,h));
            }
            d[g]++;
        }
        solve();
        cout <<endl;
    }
}
int main()
{

    nhap();

}

