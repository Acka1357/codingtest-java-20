#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int N, K;

    scanf("%d", &N);
    scanf("%d", &K);

    ll l = 1;
    ll r = (ll)N * N;
    ll ans = -1;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        ll count = 0;
        for (int i = 1; i <= N; i++)
            count += min(m / i, (ll)N);
        if (count >= K)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
