#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll howManyPass(ll givenTime, vector<int> &timePerPass)
{
    ll count = 0;
    for (int i = 0; i < timePerPass.size(); i++)
        count += givenTime / timePerPass[i];
    return count;
}

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    vector<int> timePerPass(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &timePerPass[i]);
    
    ll ans;
    ll l = 1;
    ll r = (ll)(*min_element(timePerPass.begin(), timePerPass.end())) * M;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (howManyPass(m, timePerPass) >= M)
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
