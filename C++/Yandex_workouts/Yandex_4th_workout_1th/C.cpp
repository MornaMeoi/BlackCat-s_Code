#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void ReadArr(ifstream& inp, vector<int64_t>& arr, int N)
{
    for(int i = 0; i < N; ++i)
        inp >> arr[i];
}

void PrintArr(const vector<int64_t>& arr)
{
    for(const int64_t& num : arr)
        cout << num << ' ';
    cout << endl;
}

vector<int64_t> Merge(const vector<int64_t> first, int n, const vector<int64_t> second, int m)
{
    vector<int64_t> result(m+n);
    for(int i = 0, j = 0, k = 0; k < m+n; ++k)
        if(i < n && j < m)
        {
            if(first[i] < second[j])
                result[k] = first[i++];
            else
                result[k] = second[j++];
        }
        else if(j < m)
            result[k] = second[j++];
        else
            result[k] = first[i++];
    return result;
}

int main()
{
    ifstream inp("input.txt");
    int N, M;
    inp >> N;
    vector<int64_t> a(N);
    ReadArr(inp, a, N);
    inp >> M;
    vector<int64_t> b(M);
    ReadArr(inp, b, M);
    inp.close();

    PrintArr(Merge(a, N, b, M));
    return 0;
}