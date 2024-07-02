#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    string S;
    inp >> S;
    vector<int64_t> part_sum(S.size()+1, 0);
    for(int i = 1; i < part_sum.size(); ++i)
        part_sum[i] = part_sum[i-1] + S[i-1] - 'a' + 1;
    int Q;
    inp >> Q;
    int L, A, B;
    for(int i = 0; i < Q; ++i)
    {
        inp >> L >> A >> B;
        bool good = true;
        if(part_sum[A+L] - part_sum[A] == part_sum[B+L] - part_sum[B])
        {
            for(int j = 0; j < L && good; ++j)
                if(S[A+j] != S[B+j])
                    good = false;
        }
        else
            good = false;
        cout << (good ? "yes" : "no") << endl;
    }
    inp.close();
    return 0;
}