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
void solve()
{

}
void nhap()
{
   int  n;
    cin >> n;
    int  a[105],b[105],c[105],e[105];
    float s=0,s1=0,s2=0,s3=0;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> e[i];
        s+=a[i];
        s1+=b[i];
        s2+=c[i];
        s3+=e[i];
    }
    s1/=float(n);
    s/=float(n);
    s2/=float(n);
    s3/=float(n);
    int ans=0;
    for(int i =1 ; i<= n ; i++)
    {
        if(a[i]>=s&&b[i]>=s1&&c[i]>=s2&&e[i]>=s3)
        {
            ans++;
        }
    }
    cout << ans;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



