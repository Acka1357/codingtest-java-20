#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int cnt[10] = {0, };

    scanf("%d", &N);
    while (N > 0)
    {
        cnt[N % 10]++;
        N /= 10;
    }

    int ans = (cnt[6] + cnt[9] + 1) / 2;
    for (int i = 0; i < 9; i++)
        if (i != 6)
            ans = max(ans, cnt[i]);
    
    printf("%d\n", ans);
    return 0;
}
