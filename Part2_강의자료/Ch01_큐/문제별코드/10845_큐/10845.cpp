#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int main()
{
    int N;
    queue<int> q;
    char cmd[6];
    int value = -1;

    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0)
        {
            scanf("%d", &value);
            q.push(value);
        }
        else if (strcmp(cmd, "pop") == 0)
        {
            printf("%d\n", q.empty() ? -1 : q.front());
            if (!q.empty()) q.pop();
        }
        else if (strcmp(cmd, "size") == 0)
        {
            printf("%d\n", q.size());
        }
        else if (strcmp(cmd, "empty") == 0)
        {
            printf("%d\n", q.empty() ? 1 : 0);
        }
        else if (strcmp(cmd, "front") == 0)
        {
            printf("%d\n", q.empty() ? -1 : q.front());
        }
        else if (strcmp(cmd, "back") == 0)
        {
            printf("%d\n", q.empty() ? -1 : q.back());
        }
    }
    return 0;
}
