#include <bits/stdc++.h>
#define TASK "segmenttree"
using namespace std;

int st[1000005], n, cc, a[1000005];

void build(int l,int r,int i) {
  // cout << l <<" " <<r <<" "<<i<<endl;
    if (l == r) {
        st[i] = a[l]; //st[i] = a[r];
        return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, 2 * i);
    build(mid + 1, r , 2 * i + 1);
    st[i] = min(st[2 * i] , st [2 * i + 1]);
    //st[i] = min(st[2 * i], st [2 * i + 1]);
}

int get(int ss,int se,int qs, int qe,int i)
{
    //cout <<ss <<" " <<se<< " " << qs<<" "<<qe<<" "<<i<<endl;
    if (ss > qe) return INT_MAX;
    //return INT_MAX
    if (se < qs) return INT_MAX;
    //return INT_MAX
    if (ss >= qs && se <= qe)
    {
        return st[i];
    }
    int mid = ss + (se - ss) / 2;
    return min(get(ss, mid, qs, qe, 2 * i), get(mid + 1, se, qs, qe, 2 * i + 1));
}

int main() {
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> cc;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while (cc-- )
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, n, l, r, 1) << endl;
    }
    return 0;
}
