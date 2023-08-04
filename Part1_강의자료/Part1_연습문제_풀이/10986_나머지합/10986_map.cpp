#include <map>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int cur_remain = 0;
    map<int, int> remain_cnt;
    remain_cnt[cur_remain] = 1;
    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        cur_remain = (cur_remain + num) % M;
        ans += remain_cnt[cur_remain];
        remain_cnt[cur_remain]++;
    }

    printf("%lld\n", ans);
    return 0;
}
