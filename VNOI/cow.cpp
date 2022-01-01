#include <bits/stdc++.h>

using namespace std;
long long a,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a;
    long long s;
    if(n%2==0)
    {
        s=(n+1)*(n/2);
    }
    else
    {
        s=n*((n-1)/2+1);
    }
    cout << s - a << endl;
    return 0;
}
