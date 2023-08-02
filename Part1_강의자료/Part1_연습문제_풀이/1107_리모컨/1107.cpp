#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

bool can_make_num(int x, bool is_broken[10])
{
    if (x == 0)
        return !is_broken[0];
    while (x > 0) {
        if (is_broken[x % 10])
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    bool is_broken[10];
    memset(is_broken, 0, sizeof(is_broken));

    for (int i = 0; i < M; i++) {
        int broken;
        scanf("%d", &broken);
        is_broken[broken] = true;
    }

    int ans = N > 100 ? N - 100 : 100 - N;
    for (int delta = 0; delta < ans; delta++) {
        int number_to_make[2] = { N + delta, N - delta };
        for (auto& num : number_to_make)
            if (num >= 0 && can_make_num(num, is_broken))
                ans = min(ans, (int)to_string(num).length() + delta);
    }
    printf("%d\n", ans);
    return 0;
}
