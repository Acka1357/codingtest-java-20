#include <algorithm>
#include <stdio.h>

using namespace std;

char castle[55][55];
int N, M;

int is_exist(int x, int y, int dx, int dy, int end)
{
	for (int i = 0; i < end; ++i)
	{
		if (castle[y][x] == 'X')
			return 0;
		x += dx;
		y += dy;
	}
	return 1;
}

int main()
{
	scanf(" %d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf(" %s", castle[i]);

	int row = 0;
	for (int i = 0; i < N; ++i)
		row += is_exist(0, i, 1, 0, M);
	
	int col = 0;
	for (int i = 0; i < M; ++i)
		col += is_exist(i, 0, 0, 1, N);
	
	printf("%d\n", max(row, col));
	return 0;
}