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
const int LIM = 2e8;
bitset<LIM> isPrime;
vector<int> prime;
void sieve(int n = LIM)
{
    isPrime[2] = true;
    prime.assign(1, 2);

    int sqrtn = sqrt(n);
    for (int i = 3; i <= n; i += 2) isPrime.set(i);
    for (int i = 3; i <= n; i += 2)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            if (i > sqrtn) continue;
            for (int j = i * i; j <= n; j += 2 * i)
                isPrime.reset(j);
        }
    }
}

int main()
{
    sieve();

    int q;
    for (cin >> q; q--; )
    {
        int l, r;
        cin >> l >> r;

        if (l > r)
        {
            cout << 0 << '\n';
            continue;
        }
        int p1 = lower_bound(prime.begin(), prime.end(), l) - prime.begin();
        int p2 = upper_bound(prime.begin(), prime.end(), r) - prime.begin();
        cout << p2 - p1 << '\n';
    }
    return 0;
}



