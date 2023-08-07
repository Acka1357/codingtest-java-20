#include <stdio.h>
#include <vector>
using namespace std;

struct Query {
    int num, strike, ball;
};

int main()
{
    int N;
    scanf("%d", &N);

    vector<Query> vec(N);
    for (int i = 0; i < N;i++)
        scanf("%d %d %d", &vec[i].num, &vec[i].strike, &vec[i].ball);

    int ans = 0;
    for (int x = 1; x <= 9; x++)
    {
        for (int y = 1; y <= 9; y++)
        {
            for (int z = 1; z <= 9; z++)
            {
                if (x == y || y == z || x == z)
                    continue;
                bool psb = true;
                for (int i = 0; i < N; i++)
                {
                    int qx = vec[i].num / 100;
                    int qy = (vec[i].num / 10) % 10;
                    int qz = vec[i].num % 10;

                    int strike = 0;
                    int ball = 0;
                    if (x == qx)
                        strike++;
                    else if (x == qy || x == qz)
                        ball++;
                    if (y == qy)
                        strike++;
                    else if (y == qx || y == qz)
                        ball++;
                    if (z == qz)
                        strike++;
                    else if (z == qx || z == qy)
                        ball++;
                    if (strike != vec[i].strike || ball != vec[i].ball)
                    {
                        psb = false;
                        break;
                    }
                }
                if (psb)
                    ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
