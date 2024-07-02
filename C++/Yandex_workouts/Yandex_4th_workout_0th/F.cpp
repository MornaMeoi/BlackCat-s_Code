#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    uint64_t k;
    int size;
    inp >> k >> size;
    vector<int64_t> people(size);
    for(int i = 0; i < size; ++i)
        inp >> people[i];
    inp.close();

    int last_floor = size-1;
    for(; last_floor >= 0 && !people[last_floor]; --last_floor);
    uint64_t capacity = k, result = 0;
    while(last_floor >= 0)
    {
        if(people[last_floor] == 0)
        {
            --last_floor;
            continue;
        }
        if(people[last_floor] != 0 && people[last_floor] >= k)
        {
            result += people[last_floor]/k * 2 * (last_floor+1);
            people[last_floor] %= k;
        }
        else if(people[last_floor] <= capacity)
        {
            if(capacity == k)
                result += 2*(last_floor+1);
            capacity -= people[last_floor];
            people[last_floor] = 0;
            --last_floor;
        }
        else
        {
            people[last_floor] -= capacity;
            capacity = k;
        }
    }
    cout << result;
    return 0;
}