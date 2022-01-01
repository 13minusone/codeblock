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
int f[131080];
char a[150000];
int chat(const string &s, char c) {
	if (s.size() == 1) {
		return s[0] != c;
	}
	int mid = s.size() / 2;
	int cntl = chat(string(s.begin(), s.begin() + mid), c + 1);
	cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
	int cntr = chat(string(s.begin() + mid, s.end()), c + 1);
	cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
	return min(cntl, cntr);
}
void nhap()
{
    int test,n;
    cin >> test;
    while(test--)
    {
        cin >> n;
        string s;
        cin >> s;
        cout <<chat(s,'a') << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



