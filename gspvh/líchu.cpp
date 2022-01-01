#include<bits/stdc++.h>
using namespace std;
#define task "lichsu-thptqg"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define popb pop_back
#define ll long long
#define ull unsigned long long
#define rt return
#define ctn continue
#define fi first
#define se second
const int mod = int(1e9)+7;
const ll MOD=1e12 + 7;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int t, n;
char a[50]={'C','A','C','C','B','D','B','C','A','A','C','B','B','C','D','A','B','B','A','D','D','C','C','D','A','D','D','B','C','A','A','C','B','D','B','D','A','B','C','A'};
int main()
{

    fastio();
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << a[n-1] << endl;
    }
}
