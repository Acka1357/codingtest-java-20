#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);

    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    vector<int> ans(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < K; j++)
        {
            q.push(q.front());
            q.pop();
        }
        ans[i] = q.front();
        q. pop();
    }

    printf("<");
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i]);
		if (i + 1 < ans.size())
			printf(", ");
	}
	printf(">\n");
    return 0;
}
