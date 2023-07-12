#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int number;
    int scr;
    int postedAt;
};

int main()
{
    int N, R;
    vector<Student> post;

    scanf("%d", &N);
    scanf("%d", &R);
    for (int i = 0; i < R; i++)
    {
        int votedNumber;
        scanf("%d", &votedNumber);

        bool alreadyPosted = false;
        for (int j = 0; j < post.size(); j++)
        {
            if (post[j].number == votedNumber)
            {
                post[j].scr++;
                alreadyPosted = true;
                break;
            }
        }

        if (!alreadyPosted)
        {
            if (post.size() < N)
                post.push_back({votedNumber, 1, i});
            else
            {
                sort(post.begin(), post.end(), [](Student o1, Student o2)->bool{ return o1.scr == o2.scr ? o1.postedAt < o2.postedAt : o1.scr < o2.scr; });
                post[0] = {votedNumber, 1, i};
            }
        }
    }

    sort(post.begin(), post.end(), [](Student o1, Student o2)->bool{ return o1.number < o2.number; });
    for (int i = 0; i < post.size(); i++)
        printf("%d ", post[i]);
    printf("\n");
    return 0;
}
