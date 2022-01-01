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
bool check(string r[6][25],ll a,ll b)
{
    if(r[a][b]=="1"||r[a][b+1]=="1"||r[a][b-1]=="1"||r[a+1][b]=="1"||r[a-1][b]=="1"||r[a-1][b-1]=="1"||r[a+1][b+1]=="1"||r[a-1][b+1]=="1"||r[a+1][b-1]=="1")
    {
        return false;
    }
    return true;
}
void solve(ll a,ll b)
{
    ll maxx=0;
    string r[6][25],f[6][25];
    for(int i = 1 ; i<=b;i++)
    {
        ll s=0;
        for(int j=i;j<=b;j+=2 )
        {
            r[1][j]=="1";
            s++;
        }
        for(int j = 1; j<= a;j++)
        {
            if(check(r,j,1)==true)
            {
                r[j][1]=="1";
                s++;
                j++;
            }
        }
        for(int j = 1;j<=b;j+=2)
        {
             if(check(r,j,1)==false)
            {
                j--;
            }
            else
            {
                r[a][j]=="1";
                s++;
            }

        }
        for(int j = 1;j<=a;j+=2)
        {
             if(check(r,j,1)==false)
            {
                j--;
            }
            else
            {
                r[j][b]=="1";
                s++;
            }
        }
        if(s>maxx)
        {
            maxx=s;
            for(int k = 1 ;k<=a;k++)
            {
                for(int j = 1;j<=b;j++ )
                {
                    f[i][j]=r[i][j];
                }
            }
        }
    }
    for(int i = 1 ;i<=a;i++)
    {
        for(int j=1 ;j<=b;j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}
void nhap()
{
    ll t,a,b;
    cin >> t;
    for(int i = 1 ;i<=t;i++)
    {
        cin >> a >> b;
        solve(a,b);
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}



