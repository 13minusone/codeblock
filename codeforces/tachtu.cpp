#include <cmath>
#include <cstring>
#include <iostream>
#define MOD 1337377
using namespace std;

struct trie
{
    int val;
    int d[26];
} tx[400110];

int n,k,cnt = -1;
char S[300010];
char a[105];
int F[300010];

int create()
{
    cnt++;  tx[cnt].val = 0;
    memset(tx[cnt].d,-1,sizeof(tx[cnt].d));
    return cnt;
}

int main()
{
//  freopen("strings.inp","r",stdin);
//  freopen("strings.out","w",stdout);
    scanf("%s", &S);  n = strlen(S);
    int tmp = create();

    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%s", &a);
        int s = 0;
        for (int j = 0; j < strlen(a); j++)
        {
            int next = tx[s].d[a[j] - 'a'];
            if (next < 0)
            {
                next = create();
                tx[s].d[a[j] - 'a'] = next;
            }
            s = next;
        }
        tx[s].val++;
    }

    memset(F,0,sizeof(F));
    F[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int s = 0,j = i;
        while (j < n)
        {
            s = tx[s].d[S[j] - 'a'];
            if (s < 0) break;
            j++;
            F[i] = (F[i] + tx[s].val * F[j]) % MOD;
        }
    }
    printf("%d\n", F[0]);
}

