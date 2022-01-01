/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define all(x) x.begin(),x.end()
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 500005;
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
int n,q,l,r,s=0;
ll a[maxsize],dd[maxsize+5];
void nhap()
{
    cin >> n >> q;
    vector<ll>vec;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        vec.push_back(a[i]);
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(all(vec))-vec.begin());
    for(int i = 1 ; i < n; i++)
    {
        ll k=lower_bound(all(vec),a[i])-vec.begin();
        a[i]=k;
    }
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> l >> r;
        s=0;
        for(int j = l ; j <= r ; j++)
        {
            dd[a[j]]=0;
        }
        for(int j = l ; j <= r ; j++)
        {
            dd[a[j]]++;
            if(dd[a[j]]==2)
            {
                s++;
            }
            if(dd[a[j]]==3)
            {
                s--;
            }
        }
        cout << s << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



