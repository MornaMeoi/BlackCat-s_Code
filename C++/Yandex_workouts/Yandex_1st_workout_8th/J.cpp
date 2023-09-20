#include <bits/stdc++.h>

using namespace std;
using nt = map<string, pair<vector<string>, int>>;

void count_height(nt &tree, const string &node, int level)
{
    tree[node].second = level;
    for(int i = 0; i < tree[node].first.size(); ++i)
        count_height(tree, tree[node].first[i], level+1);
}

int main()
{
    int N;
    ifstream inp("input.txt");
    inp >> N;
    nt tree;
    vector<string> children;
    for(int i = 0; i < N-1; ++i)
    {
        string child, parent;
        inp >> child >> parent;
        tree[parent].first.push_back(child);
        tree[child];
        children.push_back(child);
    }
    vector<string> guys;
    for(const auto item : tree)
        guys.push_back(item.first);
    sort(begin(children), end(children));
    sort(begin(guys), end(guys));
    string batya;
    bool flag = true;
    for(int i = 0; (i < N-1) && flag; ++i)
        if((children[i] <=> guys[i]) != 0)
        {
            batya = guys[i];
            flag = false;
        }
    if(flag)
        batya = guys[N-1];
    count_height(tree, batya, 0);
    for(const string &guy : guys)
        cout << guy << " " << tree[guy].second << endl;
    inp.close();
    return 0;
}