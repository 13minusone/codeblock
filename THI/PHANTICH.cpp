/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "phantich"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
map<string, int> mep;
int doi(string s)
{
    int r = 0, i = 0;
    bool pos = false;
    if (s[0]=='-')
    {
        pos = true;
        i = 1;
    }
    for(; i<s.size(); i++) r = r * 10 + s[i] - '0';
    if (pos) r*=-1;
    return r;
}
vector<int> a[N];
struct data
{
    int type;
    string s;
    data(int _type=0, string _s = "")
    {
        type = _type;
        s = _s;
    }
};
string s;
int main()
{
    fastio();
    inti();
    int c = 0;
    stack<data> st;
    int v = 0;
    for(int i=1; i<=1e5; i++) a[i].push_back(0);
    while(cin >> s)
    {
        if (s=="{") st.push(data(0, s));
        else if (s=="}")
        {
            while(true)
            {
                data tmp = st.top();
                st.pop();
                int type = tmp.type;
                if (type == 0) break;
                a[mep[tmp.s]].pop_back();
            }
        }
        else
        {
            int e = -1;
            string v1, v2;
            for(int i=0; i<s.size(); i++)
            {
                if (s[i]=='=')
                {
                    e= i;
                    continue;
                }
                if (e==-1) v1.push_back(s[i]);
                else v2.push_back(s[i]);
            }
            if (mep[v1] == 0) mep[v1] = ++v;
            if (s[e+1] >= 'a' && s[e+1] <='z')
            {
                st.push(data(1, v1));
                if (mep[v2] == 0) mep[v2] = ++v;
                int v = a[mep[v2]].back();
                a[mep[v1]].push_back(v);
                cout << v << "\n";
            }
            else
            {
                st.push(data(2, v1));
                int v = doi(v2);
                a[mep[v1]].push_back(v);
            }
        }
    }
}
