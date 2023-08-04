#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> unhear(N);
    for (int i = 0; i < N; i++)
        cin >> unhear[i];

    vector<string> unseen(M);
    for (int i = 0; i < M; i++)
        cin >> unseen[i];

    sort(unhear.begin(), unhear.end());
    sort(unseen.begin(), unseen.end());

    int pair_idx = 0;
    vector<string> ans;
    for (int i = 0; i < N; i++)
    {
        while (pair_idx < M && unseen[pair_idx] < unhear[i])
            pair_idx++;
        if (pair_idx < M && unseen[pair_idx] == unhear[i])
            ans.push_back(unhear[i]);
    }

    cout << ans.size() << '\n';
    for (auto& name : ans)
        cout << name << '\n';

    return 0;
}
