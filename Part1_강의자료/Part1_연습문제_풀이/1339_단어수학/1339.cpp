#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int alp_value[26] = {0, };
    char word[11];

    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", word);
        int place_value = 1;
        for (int i = strlen(word) - 1; i >= 0; i--)
        {
            alp_value[word[i] - 'A'] += place_value;
            place_value *= 10;
        }
    }

    sort(alp_value, alp_value + 26);

    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans += alp_value[25 - i] * (9 - i);
    printf("%d\n", ans);
    return 0;
}
