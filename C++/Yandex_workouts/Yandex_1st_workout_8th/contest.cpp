#include <bits/stdc++.h>

using namespace std;
using btree = map<string, pair<vector<string>, set<string>>>;

const set<string>& count_descendants(btree& tree, const string &node)
{
    tree[node].second.insert(node);
    for(const string& s : tree[node].first)
    {
        set<string> temp = count_descendants(tree, s);
        tree[node].second.insert(begin(temp), end(temp));
    }
    return tree[node].second;
}

int main()
{
    string root_val;
    cin >> root_val;
    btree tree;
    count_descendants(tree, root_val);
    for(const auto& [key1, value1] : tree)
        for(const auto& [key2, value2] : tree)
            if(key1 != key2 && value1.second == value2.second)
                cout << key1 << ' ' << key2 << endl;
    return 0;
}