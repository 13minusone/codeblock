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
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
vector<int>vec[maxsize*5+5];
    vector<ii>g;
void nhap()
{
    int n,k,x;
    cin >> n >> k;

    for(int i = 1 ; i<= n*k ; i++)
    {
        cin >> x;
        vec[x].push_back(i);
    }
    for(int i = 1 ; i<= n*k ; i++)
    {
        cin >> x;
        for(int j = 0 ; j<k ; j++)
        {
            g.push_back({vec[x][j],i});
        }
    }
    sort(g.begin(),g.end(),cmp);
    vector<int>p;
    for(int i = 0 ; i <SZ(g); i++)
    {
        int k=lower_bound(p.begin(),p.end(),g[i].second)-p.begin();
        if(k==p.size())
        {
            //cout << g[i].first << " " << g[i].second << endl;
            p.push_back(g[i].second);
        }
        else
        {
            p[k]=g[i].second;
        }
    }
    cout << p.size();
}
int main()
{

    fastio();
    // inti();
    nhap();
}



