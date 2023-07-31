#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> vec(N), ans(N);
    for (int i = 0; i < N; i++)
        vec[i] = i + 1;

    int past_idx = 0;
    for (int i = 0; i < N; i++)
    {
        int target_idx = (past_idx + K - 1) % vec.size();
        ans[i] = vec[target_idx];
        vec.erase(vec.begin() + target_idx);
        past_idx = target_idx;
    }

    printf("<");
    for (int i = 0; i < N - 1; i++)
        printf("%d, ", ans[i]);
    printf("%d>\n", ans[N - 1]);
    return 0;
}
