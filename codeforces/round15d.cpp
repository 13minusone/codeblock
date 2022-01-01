#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<ll,ll> ii;
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
void nhap()
{
    int t,n;
    ll s=0,a[20];
    ii b[20];
    cin >> t;
    while(t--)
    {
        s=0;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        s/=n;
        cout << s << endl;
        bool te=true;
        for(int i = 0;i<mu2(n);i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(getbit(i,j)==1)
                {
                    b[j].first=a[j]-s;
                    b[j].second=s-a[j];
                }
                else
                {
                    b[j].first=b[j].second=a[j]+s;
                }
            }
            bool tr=true;
            for(int k = 0 ; k < n ; k++)
            {
                if(a[k]==0)continue;
                tr=false;
                for(int j = 0 ; j < n ; j++)
                {
                    for(int o = j+1 ; o < n ; o++)
                    {
                        if(a[k]==b[o].first-b[j].first||a[k]==b[o].first-b[j].second||a[k]==b[o].second-b[j].second||a[k]==b[o].second-b[j].first||a[k]==b[j].first-b[o].first||a[k]==b[j].first-b[o].second||a[k]==b[j].second-b[o].second||a[k]==b[j].second-b[o].first)
                        {
                            tr=true;
                            break;
                        }
                    }
                }
                if(tr==false)
                {
                    break;
                }
            }
            if(tr==true)
            {
                cout << "YES" << endl;
                te=false;
                break;
            }
        }
        if(te==true)
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



