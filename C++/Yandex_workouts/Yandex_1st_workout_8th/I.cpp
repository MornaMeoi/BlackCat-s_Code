#include <bits/stdc++.h>

using namespace std;

int count_descendants(map<string, pair<vector<string>, int>> &tree, const string &node)
{
    for(int i = 0; i < tree[node].first.size(); ++i)
        tree[node].second += count_descendants(tree, tree[node].first[i]);
    return tree[node].second;
}

int main()
{
    int N;
    ifstream inp("input.txt");
    inp >> N;
    map<string, pair<vector<string>, int>> tree;
    vector<string> children;
    for(int i = 0; i < N-1; ++i)
    {
        string child, parent;
        inp >> child >> parent;
        tree[parent].first.push_back(child);
        tree[child].first;
        ++tree[parent].second;
        tree[child].second;
        children.push_back(child);
    }
    vector<string> guys;
    for(const auto &item : tree)
        guys.push_back(item.first);
    sort(begin(children), end(children));
    sort(begin(guys), end(guys));
    string batya;
    for(int i = 0; i < N-1; ++i)
        if((children[i] <=> guys[i]) != 0)
        {
            batya = guys[i];
            break;
        }
    count_descendants(tree, batya);
    for(const string &guy : guys)
        cout << guy << " " << tree[guy].second << endl;
    inp.close();
    return 0;
}