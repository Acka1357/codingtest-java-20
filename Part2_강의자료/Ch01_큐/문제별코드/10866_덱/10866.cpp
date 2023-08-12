#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;

int main()
{
    int N;
    deque<int> q;
    char cmd[11];
    int value;

    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "push_front") == 0)
        {
            scanf("%d", &value);
            q.push_front(value);
        }
        else if (strcmp(cmd, "push_back") == 0)
        {
            scanf("%d", &value);
            q.push_back(value);
        }
        else if (strcmp(cmd, "pop_front") == 0)
        {
            printf("%d\n", q.empty() ? -1 : q.front());
            if (!q.empty()) q.pop_front();
        }
        else if (strcmp(cmd, "pop_back") == 0)
        {
            printf("%d\n", q.empty() ? -1 : q.back());
            if (!q.empty()) q.pop_back();
        }
        else if (strcmp(cmd, "size") == 0)
            printf("%d\n", q.size());
        else if (strcmp(cmd, "empty") == 0)
            printf("%d\n", q.empty() ? 1 : 0);
        else if (strcmp(cmd, "front") == 0)
            printf("%d\n", q.empty() ? -1 : q.front());
        else if (strcmp(cmd, "back") == 0)
            printf("%d\n", q.empty() ? -1 : q.back());
    }
    return 0;
}
