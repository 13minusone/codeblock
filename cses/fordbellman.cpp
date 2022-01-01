#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
typedef pair<ll, ll> ii;
vector<ii> a[230997];
int n, m;

ll d[230997];
bool check[230997];

void bellman(int u) {
    queue<int> qu;

    for (int i = 1; i <= n; i++)
        d[i] = -1000000000;
    d[u] = 0;
    qu.push(u);
    bool tr=true;
    check[u] = false;

    while (qu.size()) {
        u = qu.front();
        qu.pop();

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].Y;
            int uv = a[u][i].X;
            if(check[v]==false)
            {
                if(d[v]<d[u]+uv)
                {
                    cout << "-1" ;
                    return;
                }
            }
            else{
                if(d[v]<d[u]+uv)
                {
                    qu.push(v);
                    check[v]=false;
                }
            }
        }
    }
    cout << d[n];
}

int main() {
    int u, v;
    scanf("%d%d", &n, &m);
    while (m--) {
        int p, q, w;
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w, q));

    }
    bellman(1);
}
