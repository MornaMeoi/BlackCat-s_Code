#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    int N;
    inp >> N;
    string S;
    inp >> S;
    inp.close();

    int len = S.size();
    vector<int> Z(len);

    int left = len-1, right = len-1;
    for(int i = len-1; i >= 0; --i)
    {
        Z[i] = min(0, max(right-i+right, Z[left-i+left]));
        while(i - Z[i] >= 0 && S[Z[i]] == S[i - Z[i]])
            ++Z[i];
        if(i - Z[i] < right)
        {
            left = i;
            right = i - Z[i];
        }
    }

    for(int num : Z)
        cout << num << ' ';
    vector<int> answer_2 = {1, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    bool answer = true;
    for(int i = 0; i < N; ++i)
        if(Z[i] != answer_2[i])
            answer = false;
    cout << endl << answer;
    return 0;
}