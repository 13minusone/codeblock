#include <bits/stdc++.h>
using namespace std;
#define taskname "MINIMUM"
const int maxN = 5e5 + 1;
int n, k, a[maxN];
deque<int> q;

void nhap()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    for(int i=1;i<=k-1;i++)
    {
        while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
    }
    for (int i = k; i <= n; i++)
    {
        //cout<<a[i]<<" ";
        while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        if (q.front() + k <= i) q.pop_front();
        cout << a[q.front()] << '\n';
        //cout << q.front() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    nhap();
    Solve();
}
