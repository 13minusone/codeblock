#include<bits/stdc++.h>
using namespace std;
#define task "equivalent"
#define ll long long
#define SZ(c) c.size()
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
vector<string>t;
vector<ll>block[3000];
vi deg(3000,0);
vi vt(300,-1);
string chuyendoi(string x)
{
    int n=x.size();
    for(int i =1 ;i<n+5;i++)deg[i]=0;
    for(int i = '0'-1;i<='9'+1;i++)vt[i]=-1;
    for(int i=n-1 ; i>=0 ; i--)
    {
        block[i].clear();

        for(int c = x[i]-1;c<=x[i]+1;c++)
        {
            if(vt[c]!=-1)
            {
                block[i].push_back(vt[c]);
                deg[vt[c]]++;
            }

        }
        vt[x[i]]=i;
    }

    priority_queue<ii,vector<ii>,greater<ii>>q;
    for(int i = 0 ; i <n ; i++)
    {
        if(deg[i]==0)q.push({x[i],i});
    }
    string result;
    while(!q.empty())
    {
        int digit=q.top().first,pos=q.top().second;
        q.pop();
        result.push_back(digit);
        for(int j:block[pos])
        {
            deg[j]--;
            if(deg[j]==0)
            {
                q.push({x[j],j});
            }
        }

    }
    return result;
}

void nhap()
{
    ll n;

    string s;
    cin >> n;
   set<string>d;
    for(int j =1 ; j<=n; j++)
    {
        cin >> s;
        for(int i =0; i<s.size(); i++)
        {
            string h=s.substr(i)+s.substr(0,i);
          // cout << h << " " << chuyendoi(h) << endl;
            d.insert(chuyendoi(h));
        }

    }


    cout << d.size();

}
int main()
{

    fastio();
    inti();
    nhap();
}



