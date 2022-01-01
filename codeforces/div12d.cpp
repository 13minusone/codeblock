#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define vec vector
#define pb push_back
typedef long long ll;
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int maxsize = int(1e6) + 1;
int n, a[maxsize], c[maxsize], deg[maxsize];
vector<vector<int>> muon(maxsize);
set<int> q;
int main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        muon.clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
                deg[i] = 0;
        }
        muon.resize(n + 1);
        q.clear();
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            muon[a[i]].push_back(i);
            deg[a[i]]++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(deg[i] == 0){
                q.insert(i);
            }
        }
        for(int i = 1; i <= n; i++)
        {
                while(deg[i] > 1)
                {
                    for(int k = 0; k < (int)muon[i].size(); k++)
                    {
                        int pe = muon[i][k];
                        bool tr = 0;
                        for(int j = 0; j < (int)q.size(); j++)
                        {
                            int *g = q[j];
                            if(pe != *g)
                            {
                                deg[i]--;
                                deg[*g]++;
                                q.erase(q.begin() + j);
                                muon[i].erase(muon[i].begin() + k);
                                muon[g].push_back(pe);
                                tr= 1;
                                break;
                            }
                        }
                        if(tr) break;
                    }
                }
            }

        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            c[muon[i].back()] = i;
        }
        for(int i = 1; i <= n; i++)
        {
            if(c[i] == a[i])
            {
                sum++;
            }
        }
        cout << sum<< endl;
        for(int i = 1; i <= n; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
}
    return 0;
}
