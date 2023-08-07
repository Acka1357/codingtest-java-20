#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    int number;
    int scr;
    int posted_at;
};

int main()
{
    int N, R;
    vector<student> post;

    scanf("%d", &N);
    scanf("%d", &R);
    for (int i = 0; i < R; i++)
    {
        int voted_number;
        scanf("%d", &voted_number);

        bool already_posted = false;
        for (int j = 0; j < post.size(); j++)
        {
            if (post[j].number == voted_number)
            {
                post[j].scr++;
                already_posted = true;
                break;
            }
        }

        if (!already_posted)
        {
            if (post.size() < N)
                post.push_back({voted_number, 1, i});
            else
            {
                sort(post.begin(), post.end(), [](student o1, student o2)->bool{ return o1.scr == o2.scr ? o1.posted_at < o2.posted_at : o1.scr < o2.scr; });
                post[0] = {voted_number, 1, i};
            }
        }
    }

    sort(post.begin(), post.end(), [](student o1, student o2)->bool{ return o1.number < o2.number; });
    for (int i = 0; i < post.size(); i++)
        printf("%d ", post[i]);
    printf("\n");
    return 0;
}
