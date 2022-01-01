/*2021/08/10 10:31:18.*/
#include<bits/stdc++.h>
using namespace std;
#define task "FC124BINARYSTRING"
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
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int n=SZ(s)-1,d=SZ(s);
        int i=0;
        bool te=true;
        while(s[i]!='1')
        {
            i++;
            if(i>=d)
            {
                cout << -1 << endl;
                te=false;
                break;
            }
        }
        if(te==false)continue;
        while(s[n]!='1')
        {
            n--;
            if(n<0)
            {
                cout << -1<< endl;
                te=false;
                break;
            }
        }
        if(te==false)continue;
        int su=0;
        for(;i<=n; i++)
        {
            if(s[i]=='0')
            {
                su++;
            }
        }
        cout << su << endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}



