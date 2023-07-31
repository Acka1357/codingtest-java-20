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

    string name;
    set<string> unhear;
    for (int i = 0; i < N; i++) {
        cin >> name;
        unhear.insert(name);
    }

    vector<string> ans;
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (unhear.find(name) != unhear.end())
            ans.push_back(name);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& name : ans)
        cout << name << '\n';

    return 0;
}
