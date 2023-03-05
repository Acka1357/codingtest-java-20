#include <stdio.h>
#include <string>
#include <map>
#include <utility>

using namespace std;

int N;
map<string, int> mp;

int main()
{
	char book[55];

	scanf(" %d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf(" %s", book);
		++mp[book];
	}

	int max_cnt = -1;
	string ans;
	for (auto &it : mp)
	{
		if (it.second > max_cnt)
		{
			ans = it.first;
			max_cnt = it.second;
		}
	}

	printf("%s\n", ans.c_str());
	return 0;
}