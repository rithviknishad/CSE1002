#include <iostream>

using namespace std;

class Board
{
public:
    Board(int n)
        : n(n),
          m_storage((int *)malloc(n * n * sizeof(int)))
    {
    }

    void input() const
    {
        for (int i = 0; i < n * n; ++i)
            scanf("%d", m_storage + i);
    }

    void printRowsMax() const
    {
        for (int i = 0; i < n; ++i)
        {
            int max = _elem(i, 0);

            for (int j = 1; j < n; ++j)
            {
                int val = _elem(i, j);
                if (val > max)
                    max = val;
            }

            cout << max << endl;
        }
    }

private:
    int n, *m_storage;

    int &_elem(int r, int c) const { return m_storage[r * n + c]; }
};

int main()
{

    Board(4);

    return 0;
}