#include <stdio.h>
#include <cstring>

int alp[30], N, K;
char wheel[30];

int main()
{
	int cur = 0, changed;
	char ch;
	bool flag;

	scanf(" %d %d", &N, &K);
	memset(wheel, '?', sizeof(wheel));
	flag = false;

	while (K--)
	{
		scanf(" %d %c", &changed, &ch);
		if (flag)
			continue;
		cur = (cur - changed) % N;
		cur = (cur < 0) ? cur + N : cur;
		if (wheel[cur] == ch)
			continue;
		if (wheel[cur] != '?')
		{
			flag = true;
			continue;
		}
		wheel[cur] = ch;
		if (alp[ch - 'A']++ > 0)
			flag = true;
	}

	if (flag)
		printf("!");
	else
	{
		wheel[N] = 0;
		printf("%s", wheel + cur);
		for (int i = 0; i < cur; ++i)
			printf("%c", wheel[i]);
	}
	printf("\n");

	return 0;
}