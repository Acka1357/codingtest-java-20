#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> vec(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        vec[i] = num % M;
    }

    vector<int> acc_remain_cnt(M);
    int cur_remain = 0;
    acc_remain_cnt[cur_remain]++;
    long long ans = 0;

    for (int i = 1; i <= N; i++)
    {
        cur_remain = (cur_remain + vec[i]) % M;
        ans += acc_remain_cnt[cur_remain];
        acc_remain_cnt[cur_remain]++;
    }
    printf("%lld\n", ans);
    return 0;
}
