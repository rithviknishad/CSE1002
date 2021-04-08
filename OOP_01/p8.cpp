#include <iostream>
#include <math.h>

using namespace std;

class Average
{
public:
    Average(int length, double *samples)
        : m_Length(length), m_Samples(samples) {}

    void computeAndPrintAverage()
    {
        double sum = 0;
        for (int i = 0; i < m_Length; ++i)
            sum += m_Samples[i];

        cout << "Average: " << sum / m_Length << endl;
    }

private:
    int m_Length;
    double *m_Samples;
};

int main()
{
    double samples[] = {1.0, 2.0, 3.0};
    Average(3, samples).computeAndPrintAverage();

    return 0;
}