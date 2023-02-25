#include <iostream>
using namespace std;

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
	FASTIO;
	int K;
	bool flag = false;

	cin >> K;
	for (int i = 29; i >= 1; --i)
	{
		if (K >= (1 << i) - 1)
		{
			if (!flag)
				flag = true;
			if (K >= (1 << i) - 1 + (1 << (i - 1)))
			{
				cout << 7;
				K -= (1 << i);
			}
			else
			{
				cout << 4;
				K -= (1 << (i - 1));
			}
		}
		else if (flag)
			cout << 7;
	}
	cout << '\n';
	return 0;
}
