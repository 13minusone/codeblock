#include<bits/stdc++.h>
using namespace std;
#define task "string"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
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
void nhap()
{
        string s,t;
        cin >> s >> t;
        vector<int>d(300,0);
        for(int i = 0 ;i<SZ(s);i++)
        {
            d[s[i]]++;
            if(s[i]!=t[i])
            {
               // cout << i << " " << d[t[i]] << " " << endl;
                if(d[t[i]]==0)
                {
                    cout << "Yes" ;
                    return ;
                }
            }
        }
        cout << "No";
}
int main()
{

    fastio();
    inti();
    nhap();
}



