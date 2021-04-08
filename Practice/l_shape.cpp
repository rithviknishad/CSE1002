#include <iostream>

using namespace std;

class Board
{
public:
    Board(int rows, int cols)
        : rows(rows), cols(cols),
          m_storage((char *)malloc(rows * cols * sizeof(char)))
    {
    }

    void input() const
    {
        for (int i = 0; i < rows * cols; ++i)
            scanf("%c", m_storage + i);
    }

    bool hasL() const
    {
        for (int i = 0; i < rows - 1; ++i)
        {
            for (int j = 0; j < cols - 1; ++j)
            {
                char v = _elem(i, j);
                if (v == _elem(i + 1, j) && v == _elem(i + 1, j + 1))
                    return true;
            }
        }
        return false;
    }

private:
    int rows, cols;
    char *m_storage;

    char &_elem(int r, int c) const { return m_storage[r * rows + c]; }
};

int main()
{

    return 0;
}