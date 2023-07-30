#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll calc_need_amount(vector<int> &cost, vector<int> &budget, int assign_cnt)
{
    ll need_amount = 0;
    for (int i = 0; i < assign_cnt; i++)
        need_amount += max(cost[i] - budget[budget.size() - assign_cnt + i], 0);
    return need_amount;
}

int main()
{
    int N, M, X;

    scanf("%d %d %d", &N, &M, &X);

    vector<int> cost(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &cost[i]);
    
    vector<int> budget(M);
    for (int i = 0; i < M; i++)
        scanf("%d", &budget[i]);

    sort(cost.begin(), cost.end());
    sort(budget.begin(), budget.end());

    int l = 0, r = min(N, M), ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (calc_need_amount(cost, budget, m) <= X)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    printf("%d\n", ans);
    return 0;
}
