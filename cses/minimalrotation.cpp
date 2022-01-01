#include<bits/stdc++.h>
using namespace std;
#define task "c"
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
const ll maxsize = 1000000;
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
string s,minn;
string a[maxsize+5],b[maxsize+5];
void nhap()
{

    cin >> s;
    minn=s;
    a[0]=s[0];
    for(int i = 1; i <SZ(s) ; i++)
    {
        a[i]=a[i-1]+s[i];
        //cout << i << " "<< a[i] << endl;
    }
    b[SZ(s)-1]=s[SZ(s)-1];
    for(int j = SZ(s)-2; j>=0;j--)
    {
        b[j]=s[j]+b[j+1];
        //cout << j << " " << b[j] << endl;
    }
    for(int i = 1 ; i<SZ(s);i++)
    {
        string t;
        t=b[i]+a[i-1];
        //cout << t << endl;
        minn=min(minn,t);
    }
    cout << minn ;
}
int main()
{

    fastio();
     inti();
    nhap();
}



