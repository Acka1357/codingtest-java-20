#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    string ans;

    scanf("%d", &k);

    k++;
    while (k)
    {
        if (k % 2 == 0)
            ans.push_back('4');
        else
            ans.push_back('7');
        k /= 2;
    }
    reverse(ans.begin(), ans.end());

    printf("%s\n", ans.c_str() + 1);
    return 0;
}
