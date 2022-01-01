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
ll a,s=0,b[maxsize+5];
map<ll,vector<int>>d;
void nhap()
{
    int n;
    cin >> n;
    b[0]=0;
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> a;
        s+=a;
        if(d[s].size()!=0)
        {
            //cout << s << endl;
            for(int j = 0 ; j < SZ(d[s]); j++)
            {
                int k=d[s][j];
                //cout << i << " "<< k << endl;
                b[k+1]++;
                b[i+1]--;
            }
        }

        d[s].push_back(i);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        b[i]=b[i-1]+b[i];
        cout << b[i] << " ";
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



