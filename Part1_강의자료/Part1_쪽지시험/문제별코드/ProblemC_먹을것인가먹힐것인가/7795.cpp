#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;

    scanf("%d", &T);
    while (T--)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        vector<int> a(N);
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        
        vector<int> b(M);
        for (int i = 0; i < M; i++)
            scanf("%d", &b[i]);
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans = 0;
        int bi = 0;
        for (int i = 0; i < N; i++)
        {
            while (bi < M && b[bi] < a[i])
                bi++;
            ans += bi;
        }
        printf("%d\n", ans);
    }
    return 0;
}
