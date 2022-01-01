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
char a[401][401];
typedef pair<int,int> ii ;

vector<ii>vec;
void solve(int l,int r,int u,int v,int n)
{
    int d[401][401];
    if( l == u )
    {
        d[l][r]=1;

        d[(l+1)%n][r]=1;
        d[l][v]=1;
        d[(l+1)%n][v]=1;
        if((l+1)%n==0)
        {
            d[n][r]=1;
            d[n][v]=1;
        }
        fu(i,1,n,1)
        {
            fu(j,1,n,1)
            {
                if(d[i][j]==0)
                {cout << ".";

                }
                else
                {
                    cout << "*";
                    d[i][j]=0;
                }
            }
            cout <<endl;
        }
        return;
    }
    if( r == v )
    {
        d[l][r]=1;
        d[l][(r+1)%n]=1;
        d[u][(v+1)%n]=1;
        d[u][v]=1;
        if((r+1)%n==0)
        {
            d[l][n]=1;
            d[u][n]=1;
        }
        fu(i,1,n,1)
        {
            fu(j,1,n,1)
            {
                if(d[i][j]==0)
                {cout << ".";
                }
                else
                {
                    cout << "*" ;
                    d[i][j]=0;
                }
            }
            cout <<endl;
        }
        return;
    }

        d[l][r]=1;
        d[l][v]=1;
        d[u][v]=1;
        d[u][r]=1;
        fu(i,1,n,1)
        {
            fu(j,1,n,1)
            {
                if(d[i][j]==0)
                {cout << ".";}
                else
                {
                    cout << "*";
                    d[i][j]=0;
                }
            }
            cout <<endl;
        }
        return;

}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{
    cin>>x;
    fu(j,1,x,1)
    {
        fu(f,1,x,1)
        {
            cin >> a[j][f];
            if(a[j][f] =='*')
            {
                vec.pb(ii(j,f));
            }

        }
    }
    solve(vec[0].first,vec[0].second,vec[1].first,vec[1].second,x);
    vec.clear();
}
}
int main()
{
IOS
//inti()
nhap();

}

