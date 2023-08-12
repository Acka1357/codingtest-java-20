#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int N;

    scanf("%d", &N);
    queue<int> router;
    while (1)
    {
        int cmd;
        scanf("%d", &cmd);
        if (cmd > 0)
        {
            if (router.size() < N)
                router.push(cmd);
        }
        else if (cmd == 0)
            router.pop();
        else
            break;
    }

    if (router.empty())
        printf("empty");
    else
    {
        while (!router.empty())
        {
            printf("%d ", router.front());
            router.pop();
        }
        printf("\n");
    }
    return 0;
}
