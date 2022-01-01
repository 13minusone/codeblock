#include<bits/stdc++.h>
using namespace std;
static const int MAXN = 1502;
static const int ALPHABET = 26;

int n;
char s[MAXN];
int ans[ALPHABET][MAXN] = {{ 0 }};
int q, m_i;
char c_i;

int main()
{
    scanf("%d", &n);
    string d;
    cin >> d;
    //cout << int('a');
    for (int i = 0; i < n; ++i)
    {
        s[i] = d[i];
    }



    for (int c = 0; c < ALPHABET; ++c)
    {
        for (int i = 0; i < n; ++i)
        {
            int replace_ct = 0;
            for (int j = i; j < n; ++j)
            {
                if (s[j] != char(c+97))
                {
                    ++replace_ct;
                }
                ans[c][replace_ct] = max(ans[c][replace_ct], j - i + 1);

            }
        }
        for (int i = 1; i < MAXN; ++i)
            ans[c][i] = max(ans[c][i], ans[c][i - 1]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %c", &m_i, &c_i);
        printf("%d\n", ans[int(c_i - 'a')][m_i]);
    }

    return 0;
}
