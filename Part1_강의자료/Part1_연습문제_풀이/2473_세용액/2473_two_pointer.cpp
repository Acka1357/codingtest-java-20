#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());

    int ans1 = vec[0];
    int ans2 = vec[1];
    int ans3 = vec[2];
    long long ans_abs = abs((long long)vec[0] + vec[1] + vec[2]);
    for (int i = 0; i < N - 2; i++) {
        int left_idx = i + 1;
        int right_idx = N - 1;
        while (left_idx < right_idx) {
            long long cur_sum = (long long)vec[i] + vec[left_idx] + vec[right_idx];
            long long cur_abs = abs(cur_sum);
            if (ans_abs > cur_abs) {
                ans1 = vec[i];
                ans2 = vec[left_idx];
                ans3 = vec[right_idx];
                ans_abs = cur_abs;
            }
            if (cur_sum <= 0)
                left_idx++;
            else
                right_idx--;
        }
    }

    printf("%d %d %d", ans1, ans2, ans3);
    return 0;
}
