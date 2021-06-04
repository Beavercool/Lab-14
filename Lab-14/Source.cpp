#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration<double, ratio<1> >;

    chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int main(int argc, char* argv[])
{
    Timer t;

    const unsigned int a1 = 3;
    const unsigned int a2 = 5;

    double A[] = { 1, 2, 3, 4, 5, 6, 7 };
    double Summ;

    cout << "Original: [ ";
    for (int i = 0; i < 7; ++i) {
        cout << A[i] << " ";
    }
    cout << "]" << endl;

    Summ = 0;

    for (int i = 0; i < 7; i++)
        Summ = Summ + A[i];

    cout << "Summ: " << Summ << endl;
    cout << "Average: " << Summ / 7 << "\n" << endl;

    int ary[a1][a2] = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 6, 8, 10 },
        { 3, 6, 9, 12, 15 }
    };

    cout << "Original: " << endl;

    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < a2; j++) {
            cout << setw(4) << ary[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < a2; j++)
        {
            Summ += ary[i][j];
        }
    }

    cout << "Summ: " << Summ << endl;
    cout << "Average: " << Summ / 15 << "\n" << endl;

    cout << "Elapsed time: " << t.elapsed() << " seconds\n";

    getchar();
}