#include<bits/stdc++.h>

using namespace std;
#define task "select"
#define ll long long
#define SZ(c) (ll)c.size()
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
const ll maxsize = 1000005;
const int base = 311;
const ll mod =1e9+9;
int n;
ll hasht[maxsize],powb[maxsize+5];
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll geth(int i,int j)
{
    return (hasht[j]-hasht[i-1]*powb[j-i+1]+mod*mod)%mod;
}
bool check(int a)
{
    for(int i = 1 ; i+a<n; i++)
    {
        if(geth(i,i+a-1)==geth(0,a-1))
        {
            return 1;
        }
    }
    return 0;
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void nhap()
{
    string s;
    cin >>s ;
    n=SZ(s);

    powb[0]=1;
    hasht[0]=s[0];
    for(int i = 1 ; i < n ; i++)
    {
        hasht[i]=(hasht[i-1]*base+s[i])%mod;
        powb[i]=(powb[i-1]*base)%mod;
    }
    int vec[maxsize+5],cnt=0;
    for(int i = 1; i <n-1 ; i++ )
    {
        //cout << hasht[i] << endl;
        if(geth(0,i-1)==geth(n-i,n-1))
        {
            //cout<<i << " "<< hasht[i] << " "<< geth(n-i-1,n-1) << endl;
            vec[cnt++]=i;
        }
    }
    //cout << cnt;
    if(cnt==0)
    {
        cout << "Just a legend";
        return;
    }
    int i=0,j=cnt-1;
    //cout << i << " " << j << endl;
    int m;
    while(i<j-1)
    {
        m=(i+j)/2;
        //cout << m << endl;

        if(check(vec[m]))
        {
            //cout << m << endl;
            i=m;
        }
        else
        {
            j=m;
        }
    }
    //cout << vec[i] <<endl;
   if(check(vec[j])) i = j;
	if(check(vec[i])) {
		for(int o = 0 ; o<vec[i];o++)
        {
            cout << s[o];
        }
	}
	else printf("Just a legend\n");
}
int main()
{

    fastio();
    // inti();
    nhap();
}



