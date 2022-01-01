#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
ll f[3][2*maxsize+5];
void nhap()
{
    int t,n;
    string s,r;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s >> r;
        ll su=0;
        s=" " + s+" ";
        r= " " + r+" ";
        for(int i = 1 ; i <= n ; i++)
        {
            if(r[i]=='1')
            {
                if(s[i]=='0')
                {
                    su++;
                }
                else
                {
                    if(s[i-1]=='1')
                    {
                        su++;
                        s[i-1]='0';
                    }
                    else
                    {
                        if(s[i+1]=='1')
                        {
                            su++;
                            s[i+1]='0';
                        }
                    }
                }
            }

        }
        cout << su << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



