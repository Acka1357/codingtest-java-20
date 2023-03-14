#include <stdio.h>
#include <string.h>

int num[30];
char str[1000005];

int main() {
	int len;

	scanf(" %s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] <= 'Z')
			++num[str[i] - 'A'];
		else
			++num[str[i] - 'a'];
	}

	char max_alp = '?';
	int max_count = -1;
	for (int i = 0; i < 26; i++) 
	{
		if (num[i] == 0) continue;
		if (max_count == num[i])
			max_alp = '?';
		else if (max_count < num[i]) 
		{
			max_alp = i + 'A';
			max_count = num[i];
		}
	}
	printf("%c\n", max_alp);
	return 0;
}
