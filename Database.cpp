#include <iostream>
#include <map>
#include <set>
#include <iomanip>
#include <exception>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;

    Date()
    {
        year = 1;
        month = 1;
        day = 1;
    }

    Date(const int& new_year, const int& new_month, const int& new_day)
    {
        year = new_year;
        if(new_month <= 12 && new_month >= 1)
        {
            month = new_month;
        }
        else
        {
            throw runtime_error("Month value is invalid: " + to_string(new_month));
        }
        if(new_day <= 31 && new_day >= 1)
        {
            day = new_day;
        }
        else
        {
            throw runtime_error("Day value is invalid: " + to_string(new_day));
        }
    }
};

ostream& operator << (ostream& stream, const Date& date)
{
    stream << setw(4) << setfill('0') << date.year << '-'
    << setw(2) << setfill('0') << date.month << '-'
    << setw(2) << setfill('0') << date.day;
    return stream;
}

void WDFFunction(istream& stream, const Date& date)
{
    string d;
    getline(stream, d);
    throw runtime_error("Wrong date format: " + d);
}

void EnsureNextSymbolAndSkip(istream& stream, const Date& date)
{
    if(stream.peek() != '-')
    {
        WDFFunction(stream, date);
    }
    else
    {
        stream.ignore(1);
        if(sizeof(stream.peek()) != sizeof(int))
        {
            WDFFunction(stream, date);
        }
    }
}

istream& operator >> (istream& stream, Date& date)
{
    int year, month, day;
    stream >> year;
    EnsureNextSymbolAndSkip(stream, date);
    stream >> month;
    EnsureNextSymbolAndSkip(stream, date);
    stream >> day;
    date = {year, month, day};
    return stream;
}

bool operator < (const Date& lhs, const Date& rhs)
{
    if(lhs.year == rhs.year)
    {
        if(lhs.month == rhs.month)
        {
            return lhs.day < rhs.day;
        }
        return lhs.month < rhs.month;
    }
    return lhs.year < rhs.year;
}

class DataBase
{
public:
    void AddEvent(const Date& date, const string& event)
    {
        database[date].insert(event);
    }

    void DeleteEvent(const Date& date, const string& event)
    {
        if(database.at(date).count(event) == 1)
        {
            database[date].erase(event);
            cout << "Deleted successfully" << endl;
        }
        else
        {
            cout << "Event not found" << endl;
        }
    }

    void DeleteEvents(const Date& date)
    {
        unsigned n = database.at(date).size();
        database.erase(date);
        cout << "Deleted " << n << " events" << endl;
    }

    void FindEvents(const Date& date)
    {
        for(const string& s : database[date])
        {
            cout << s << endl;
        }
    }

    void PrintAllEvents()
    {
        for(const auto& d : database)
        {
            for(const string& s : d.second)
            {
                cout << d.first << ' ' << s << endl;
            }
        }
    }

private:
    map<Date, set<string>> database;
};

int main()
{
    DataBase database;
    while(true)
    {
        string command, event;
        Date date;
        cin >> command;
        try
        {
            if(command == "Add")
            {
                cin >> date >> event;
                database.AddEvent(date, event);
            }
            else if(command == "Del")
            {
                cin >> date;
                if(cin.peek() == EOF)
                {
                    cin >> event;
                    database.DeleteEvent(date, event);
                }
                else
                {
                    database.DeleteEvents(date);
                }
            }
            else if(command == "Find")
            {
                cin >> date;
                database.FindEvents(date);
            }
            else if(command == "Print")
            {
                database.PrintAllEvents();
            }
            else
            {
                cout << "Unknown command: " << command << endl;
                return 0;
            }
        }
        catch(exception& ex)
        {
            cout << ex.what() << endl;
            return 0;
        }
    }
    return 0;
}
