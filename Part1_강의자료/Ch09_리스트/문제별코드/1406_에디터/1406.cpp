#include <stdio.h>
#include <list>
#include <string>
using namespace std;

int main(void)
{
    char origin[100001];
    list<char> lst;
    int M;

    scanf("%s", origin);
    for (int i = 0; origin[i]; i++)
        lst.push_back(origin[i]);

    scanf("%d", &M);
    list<char>::iterator it = lst.end();
    while (M--)
    {
        char cmd;
        scanf(" %c", &cmd);
        if (cmd == 'L')
        {
            if (it != lst.begin())
                it--;
        }
        else if (cmd == 'D')
        {
            if (it != lst.end())
                it++; 
        }
        else if (cmd == 'B')
        {
            if (it != lst.begin())
            {
                it--;
                it = lst.erase(it);
            }
        }
        else if (cmd == 'P')
        {
            char c;
            scanf(" %c", &c);
            lst.insert(it, c);
        }
    }

    string result(lst.begin(), lst.end());
    printf("%s\n", result.c_str());
    return 0;
}
