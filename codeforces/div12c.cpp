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
ll a[maxsize+5],b[maxsize+5],n;
bool cmp(ll a,ll b)
{
    return a<b;
}
bool check(int m)
{
    int s=0, s2=0;
    vector<int> se, te;
    for(int j=0; j<n; j++)
    {
        se.push_back(a[j]);
    }
    for(int j=0; j<n; j++)
    {
        te.push_back(b[j]);
    }
    for(int i=1; i<=m; i++)
    {
        se.push_back(100);
        te.push_back(0);
    }
    sort(se.rbegin(), se.rend());
    sort(te.rbegin(), te.rend());
    for(int i=0; i<(int)se.size()-(int)se.size()/4; i++)
    {
        s+=se[i];
        s2+=te[i];
    }
    return s>=s2;
}
void nhap()
{
    ll t;

    cin >> t;
    while(t--)
    {
        cin >> n ;
        for(int i = 0 ; i<n;i++)
        {
            cin >> a[i];
        }
        for(int i = 0 ;i<n;i++)
        {
            cin >> b[i];
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        int h=n/4;
        ll s=0,s1=0;
        for(int i = 0;i<n-h;i++)
        {
            s+=a[i];
            s1+=b[i];
        }
        if(s>=s1)
        {
            cout << 0 << endl;
            continue;
        }
        ll le=0,rig=4*n,sum=0;
        while(le<=rig)
        {
            int m=(le+rig)>>1;
            if(check(m))
            {


                rig=m-1;
                sum=m;
            }
            else le=m+1;

        }
        cout << sum << endl;

    }
}
int main()
{

    fastio();
    nhap();
}



