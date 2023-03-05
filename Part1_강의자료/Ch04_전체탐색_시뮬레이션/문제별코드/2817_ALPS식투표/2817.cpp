#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int X, N;
int chip_cnt[256];
int check[256];
pair<char, int> staff[10];
vector<pair<double, char>> v;

int main()
{
	scanf(" %d", &X);
	scanf(" %d", &N);
	for (int i = 0; i < N; i++)
		scanf(" %c %d", &staff[i].first, &staff[i].second);

	for (int i = 0; i < N; i++)
	{
		if (staff[i].second * 20 >= X)
		{
			check[staff[i].first] = 1;
			for (int j = 1; j <= 14; j++)
				v.push_back({staff[i].second / (double)j, staff[i].first});
		}
	}

	sort(v.begin(), v.end());

	int size = v.size();
	for (int i = 0; i < size && i < 14; i++)
		chip_cnt[v[size - 1 - i].second]++;

	for (int i = 'A'; i <= 'Z'; i++)
		if (check[i])
			printf("%c %d\n", (char)i, chip_cnt[i]);

	return 0;
}