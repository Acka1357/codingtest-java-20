#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll how_many_pass(ll given_time, vector<int> &time_per_pass)
{
    ll count = 0;
    for (int i = 0; i < time_per_pass.size(); i++)
        count += given_time / time_per_pass[i];
    return count;
}

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    vector<int> time_per_pass(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &time_per_pass[i]);
    
    ll ans;
    ll l = 1;
    ll r = (ll)(*min_element(time_per_pass.begin(), time_per_pass.end())) * M;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (how_many_pass(m, time_per_pass) >= M)
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
