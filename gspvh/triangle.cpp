#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vi a[101];
ll d[101][101];
ll n,m,b,c;
void nhap()
{
    cin >> n >> m;
    for(int  i =1 ;i<=m;i++)
    {
        cin >> b >> c;
        d[b][c]=1;
        d[c][b]=1;
        a[b].push_back(c);
        a[c].push_back(b);
    }

   int ans=3;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1 ; j<=n;j++)
        {
            if(j!=i)
            {

            if(d[i][j]==1)
            {
                ans=min(ans,2);
                for(int h = 1 ; h<=n;h++)
                {
                    if(h!=i&&h!=j)
                    {

                        if(d[i][h]*d[j][h]==1)
                        {
                            ans=min(ans,0);
                        }
                        else
                        {
                            if(d[i][h]==1||d[j][h]==1)
                            {
                                ans=min(ans,1);
                            }
                        }
                    }
                }
            }
            }

        }

    }
    cout << ans ;

}
int main()
{

    fastio();
    // inti();
    nhap();
}



