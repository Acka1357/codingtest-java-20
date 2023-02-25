#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;

char A[52], B[52];

int get_diff(char *a, char *b, int len)
{
	int cnt = 0;

	for (int i = 0; i < len; ++i)
		if (a[i] != b[i])
			++cnt;
	return cnt;
}

int main()
{
	int len_diff = strlen(B) - strlen(A), res = 50;

	scanf(" %s %s", A, B);
	for (int i = 0; i <= len_diff; ++i)
		res = min(res, get_diff(A + i, B, strlen(A)));
	printf("%d\n", res);
	return 0;
}