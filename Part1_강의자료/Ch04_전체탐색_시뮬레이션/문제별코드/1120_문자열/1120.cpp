#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;

char A[52], B[52];

int get_diff(int len, int idx)
{
	int cnt = 0;

	for (int j = 0; j < len; ++j)
		if (A[j] != B[j + idx])
			++cnt;
	return cnt;
}

int main()
{
	int len_diff, res = 50;

	scanf(" %s %s", A, B);
	len_diff = strlen(B) - strlen(A);
	for (int i = 0; i <= len_diff; ++i)
		res = min(res, get_diff(strlen(A), i));
	printf("%d\n", res);
	return 0;
}