#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define DIGITS 10
using namespace std;

void PrintArr(const vector<string>& arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i];
        if(i != n-1)
            cout << ", ";
    }
}

void PrintBuckets(const vector<vector<string>>& buckets)
{
    for(int i = 0; i < DIGITS; ++i)
    {
        cout << "Bucket " << i << ": ";
        if(buckets[i].size() == 0)
            cout << "empty";
        else
            PrintArr(buckets[i], buckets[i].size());
        cout << endl;
    }
    cout << "**********\n";
}

void RadixSort(vector<vector<string>>& buckets, int cur)
{
    vector<vector<string>> new_buckets(DIGITS);
    for(int i = 0; i < DIGITS; ++i)
        for(int j = 0; j < buckets[i].size(); ++j)
            new_buckets[(buckets[i][j][cur] - '0')].push_back(buckets[i][j]);
    buckets = new_buckets;
}

int main()
{
    ifstream inp("input.txt");
    int n;
    inp >> n;
    vector<string> strings(n);
    for(int i = 0; i < n; ++i)
        inp >> strings[i];
    inp.close();

    cout << "Initial array:\n";
    PrintArr(strings, n);
    cout << "\n**********\n";

    vector<vector<string>> buckets(DIGITS);
    int len = strings[0].size();
    for(int i = 0; i < n; ++i)
        buckets[strings[i][len-1] - '0'].push_back(strings[i]);
    cout << "Phase 1\n";
    PrintBuckets(buckets);
    for(int i = 1; i < len; ++i)
    {
        cout << "Phase " << i + 1 << endl;
        RadixSort(buckets, len-i-1);
        PrintBuckets(buckets);
    }

    int idx = 0;
    for(int i = 0; i < DIGITS; ++i)
        for(int j = 0; j < buckets[i].size(); ++j)
            strings[idx++] = buckets[i][j];
    cout << "Sorted array:\n";
    PrintArr(strings, n);
    return 0;
}