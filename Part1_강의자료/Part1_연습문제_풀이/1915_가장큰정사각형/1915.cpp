#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

bool is_exist(vector<vector<int>>& acc, int N, int M, int len)
{
    for (int i = 1; i <= N - len + 1; i++)
    {
        for (int j = 1; j <= M - len + 1; j++)
        {
            int count = acc[i + len - 1][j + len - 1] - acc[i + len - 1][j - 1] - acc[i - 1][j + len - 1] + acc[i - 1][j - 1];
            if (count == len * len)
                return true;
        }
    }
    return false;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    char row[1001];
    vector<vector<int>> acc(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++)
    {
        scanf(" %s", row);
        for (int j = 1; j <= M; j++)
        {
            acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
            if (row[j - 1] == '1')
                acc[i][j]++;
        }
    }

    int l = 1;
    int r = min(N, M);
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (is_exist(acc, N, M, m))
        {
            ans = m * m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    printf("%d\n", ans);
    return 0;
}
