#include <stdio.h>
#include <vector>

using namespace std;

int T;
vector<int> vec;

int is_palindrome(int num, int B)
{
	while (num > 0)
	{
		vec.push_back(num % B);
		num /= B;
	}
	
	int size = vec.size();

	for (int i = 0; i < size / 2; ++i)
		if (vec[i] != vec[size - i - 1])
			return 0;

	return 1;
}

int main()
{
	int flag, num;

	scanf(" %d", &T);
	while (T--)
	{
		scanf(" %d", &num);
		for (int B = 2; B <= 64; ++B)
		{
			flag = is_palindrome(num, B);
			if (flag)
				break;
			vec.clear();
		}
		printf("%d\n", flag);
		vec.clear();
	}
	return 0;
}