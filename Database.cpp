#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <exception>

using namespace std;

struct Date
{
public:
    int GetYear() const
    {
        return year;
    }

    int GetMonth() const
    {
        return month;
    }

    int GetDay() const
    {
        return day;
    }

    int& GetYearLink()
    {
        return year;
    }

    int& GetMonthLink()
    {
        return month;
    }

    int& GetDayLink()
    {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator == (const Date& lhs, const Date& rhs)
{
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator < (const Date& lhs, const Date& rhs)
{
    if(lhs.GetYear() == rhs.GetYear())
    {
        if(lhs.GetMonth() == rhs.GetMonth())
        {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

void EnsureNextSymbolAndSkip(istream& stream)
{
    if(stream.peek() != '-')
    {
        throw runtime_error("Wrong date format: ");
    }
    stream.ignore(1);
}

istream& operator >> (istream& stream, Date& date)
{
    int check;
    stream >> date.GetYearLink();
    EnsureNextSymbolAndSkip(stream);
    stream >> check;
    if(check < 1 || check > 12)
    {
        throw runtime_error("Month value is invalid: " + to_string(check));
    }
    date.GetMonthLink() = check;
    EnsureNextSymbolAndSkip(stream);
    stream >> check;
    if(check < 1 || check > 31)
    {
        throw runtime_error("Day value is invalid: " + to_string(check));
    }
    date.GetDayLink() = check;
    return stream;
}

ostream& operator << (ostream& stream, const Date& date)
{
    cout << setw(4) << setfill('0') << date.GetYear() << '-'
    << setw(2) << setfill('0') << date.GetMonth() << '-'
    << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

class Database
{
public:
    void AddEvent(const Date& date, const string& event)
    {
        database[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event)
    {
        if(database[date].count(event) == 1)
        {
            database[date].erase(event);
            return true;
        }
        return false;
    }

    int DeleteDate(const Date& date)
    {
        int a = database[date].size();
        database.erase(date);
        return a;
    }

    void Find(const Date& date) const
    {
        for(const auto& s : database.at(date))
        {
            cout << s << endl;
        }
    }

    void Print() const
    {
        for(const auto& d : database)
        {
            for(const auto& s : d.second)
            {
                cout << d.first << ' ' << s << endl;
            }
        }
    }

private:
    map<Date, set<string>> database;
};

void IfCaught(const exception& ex, const Date& date)
{
    cout << ex.what();
    if(ex.what() == "Wrong date format: ")
    {
        cout << date << endl;
    }
    else
    {
        cout << endl;
    }
}

int main()
{
    Database db;
    string command;
    while (getline(cin, command))
    {
        Date date;
        stringstream stream(command);
        string com, event;
        stream >> com;
        if(com == "Add")
        {
            try
            {
                stream >> date >> event;
                db.AddEvent(date, event);
            }
            catch(const exception& ex)
            {
                IfCaught(ex, date);
            }
        }
        else if(com == "Del")
        {
            try
            {
                stream >> date;
                if(stream.peek() != EOF)
                {
                    stream >> event;
                    if(db.DeleteEvent(date, event) == true)
                    {
                        cout << "Deleted successfully" << endl;
                    }
                    else
                    {
                        cout << "Event not found" << endl;
                    }
                }
                else
                {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
            }
            catch(const exception& ex)
            {
                IfCaught(ex, date);
            }
        }
        else if(com == "Find")
        {
            try
            {
                stream >> date;
                db.Find(date);
            }
            catch(const exception& ex)
            {
                IfCaught(ex, date);
            }
        }
        else if(com == "Print")
        {
            db.Print();
        }
        else if(com == "End")
        {
            break;
        }
        else
        {
            cout << "Unknown command: " << com << endl;
        }
    }
    return 0;
}
