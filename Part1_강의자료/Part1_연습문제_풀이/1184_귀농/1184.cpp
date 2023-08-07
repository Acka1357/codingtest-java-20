#include <algorithm>
#include <map>
#include <stdio.h>
#include <vector>
using namespace std;

int get_sum(int top, int left, int bottom, int right, int acc[52][52])
{
    return (acc[bottom][right] - acc[bottom][left - 1] - acc[top - 1][right] + acc[top - 1][left - 1]);
}

int main()
{
    int N, acc[52][52];
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int num;
            scanf("%d", &num);
            acc[i][j] = acc[i][j - 1] + acc[i - 1][j] - acc[i - 1][j - 1] + num;
        }
    }

    int ans = 0;
    for (int r1 = 1; r1 < N; r1++)
    {
        for (int c1 = 1; c1 < N; c1++)
        {
            vector<int> lt_vertex, lb_vertex;
            map<int, int> rt_vertex, rb_vertex;

            for (int r2 = 1; r2 <= r1; r2++)
            {
                for (int c2 = 1; c2 <= c1; c2++)
                    lt_vertex.push_back(get_sum(r2, c2, r1, c1, acc));
                for (int c2 = c1 + 1; c2 <= N; c2++)
                    lb_vertex.push_back(get_sum(r2, c1 + 1, r1, c2, acc));
            }

            for (int r2 = r1 + 1; r2 <= N; r2++)
            {
                for (int c2 = 1; c2 <= c1; c2++)
                    rt_vertex[get_sum(r1 + 1, c2, r2, c1, acc)]++;
                for (int c2 = c1 + 1; c2 <= N; c2++)
                    rb_vertex[get_sum(r1 + 1, c1 + 1, r2, c2, acc)]++;
            }

            for (auto& score : lt_vertex)
                ans += rb_vertex[score];
            for (auto& score : lb_vertex)
                ans += rt_vertex[score];
        }
    }

    printf("%d\n", ans);
    return 0;
}
