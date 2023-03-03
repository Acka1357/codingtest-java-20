#include <stack>
#include <stdio.h>
#include <cstring>

using namespace std;

stack<char> st;
int N, B;

int main()
{
	char ch;

	scanf(" %d %d", &N, &B);
	while (N > 0)
	{
		ch = N % B;
		if (ch < 10)
			ch += '0';
		else
			ch += 'A' - 10;
		st.push(ch);
		N /= B;
	}
	while (!st.empty())
	{
		printf("%c", st.top());
		st.pop();
	}
	printf("\n");
	return 0;
}