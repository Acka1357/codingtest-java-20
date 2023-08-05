#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N, D, K, C;
    scanf("%d %d %d %d", &N, &D, &K, &C);

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &vec[i]);

    vector<int> dish_count(D + 1);
    int kind = 0;
    for (int i = 0; i < K - 1; i++)
        if (dish_count[dist[i]]++ == 0)
            kind++;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (dish_count[dish[(i + K - 1) % N]]++ == 0)
            kind++;
        ans = max(ans, kind + (dish_count[C] == 0 ? 1 : 0));
        if (--dish_count[dish[i]] == 0)
            kind--;
    }

    printf("%d\n", ans);
    return 0;
}
