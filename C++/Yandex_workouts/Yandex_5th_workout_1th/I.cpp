#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int day_of_the_week_into_num(const string& day_of_the_week)
{
    if(day_of_the_week == "Monday")
        return 0;
    else if(day_of_the_week == "Tuesday")
        return 1;
    else if(day_of_the_week == "Wednesday")
        return 2;
    else if(day_of_the_week == "Thursday")
        return 3;
    else if(day_of_the_week == "Friday")
        return 4;
    else if(day_of_the_week == "Saturday")
        return 5;
    else
        return 6;
}

int month_into_num(const string& day_of_the_week)
{
    if(day_of_the_week == "January")
        return 0;
    else if(day_of_the_week == "February")
        return 1;
    else if(day_of_the_week == "March")
        return 2;
    else if(day_of_the_week == "April")
        return 3;
    else if(day_of_the_week == "May")
        return 4;
    else if(day_of_the_week == "June")
        return 5;
    else if(day_of_the_week == "July")
        return 6;
    else if(day_of_the_week == "August")
        return 7;
    else if(day_of_the_week == "September")
        return 8;
    else if(day_of_the_week == "October")
        return 9;
    else if(day_of_the_week == "November")
        return 10;
    else
        return 11;
}

int calculate_day_by_code(const vector<int>& codes, int year, int year_const, int day, int month)
{
    return ((day + codes[month] + (year_const + (year % 100) + (year % 100) / 4) % 7) % 7 + 5) % 7;
}

string num_into_day_of_the_week(int num)
{
    switch(num)
    {
        case 0: return "Monday";
        case 1: return "Tuesday";
        case 2: return "Wednesday";
        case 3: return "Thursday";
        case 4: return "Friday";
        case 5: return "Saturday";
        default: return "Sunday";
    }
}

int main()
{
    ifstream inp("input.txt");
    int N, year;
    inp >> N >> year;
    vector<pair<int, int>> weekends(N);
    string first;
    for(int i = 0; i < N; ++i)
    {
        inp >> weekends[i].first >> first;
        weekends[i].second = month_into_num(first);
    }
    inp >> first;
    inp.close();

    bool is_leap = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
    const vector<int> codes = {is_leap ? 0 : 1, is_leap ? 3 : 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    vector<int> days_of_the_week_in_year(12, 52);
    int starting_day = day_of_the_week_into_num(first), year_const = 6 - (year / 100 % 16 % 4 * 2);
    for(int i = 0; i < 1 + is_leap; ++i)
        ++days_of_the_week_in_year[(starting_day + i) % 7];
    for(int i = 0; i < N; ++i)
        --days_of_the_week_in_year[calculate_day_by_code(codes, year, year_const, weekends[i].first, weekends[i].second)];

    int max_days = 0, min_days = 0;
    for(int i = 0; i < 7; ++i)
        if(days_of_the_week_in_year[i] > days_of_the_week_in_year[max_days])
            max_days = i;
        else if(days_of_the_week_in_year[i] < days_of_the_week_in_year[min_days])
            min_days = i;
    cout << num_into_day_of_the_week(max_days) << ' ' << num_into_day_of_the_week(min_days);
    return 0;
}