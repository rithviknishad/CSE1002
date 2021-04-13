#include <iostream>

using namespace std;

class Time
{
public:
    Time(int hour = 0, int minute = 0, int seconds = 0)
        : h(hour),
          m(minute),
          s(seconds) {}

    Time operator+(const Time &rval) const
    {
        Time result = Time(rval.h + h, rval.m + m, rval.s + s);

        result.m += result.s / 60;
        result.s %= 60;

        result.h += result.m / 60;
        result.m %= 60;

        result.h %= 24;

        return result;
    }

    friend ostream &operator<<(ostream &, const Time &);
    friend istream &operator>>(istream &, Time &);

private:
    int h, m, s;
};

ostream &operator<<(ostream &out, const Time &time) { return out << time.h << ':' << time.m << ':' << time.s; }
istream &operator>>(istream &in, Time &time) { return in >> time.h >> time.m >> time.s; }

int main()
{
    Time t1, t2, t3;

    cout << "Time 1: " << endl;
    cin >> t1;

    cout << "Time 2: " << endl;
    cin >> t2;

    cout << t1 << endl
         << t2 << endl
         << (t1 + t2) << endl;
}