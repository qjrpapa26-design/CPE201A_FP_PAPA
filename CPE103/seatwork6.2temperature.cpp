#include <iostream>
#include <iomanip>   

using namespace std;

const int COLS = 6;   // number of column groups per line

// Function prototypes
int celsius(int);
int fahrenheit(int);
void printCelsiusChart();
void printFahrenheitChart();

int main()
{
    printCelsiusChart();
    cout << endl;
    printFahrenheitChart();
    return 0;
}

// Returns the Celsius equivalent of a Fahrenheit temperature.
// Integer arithmetic, so the result is truncated.
int celsius(int f)
{
    return 5 * (f - 32) / 9;
}

// Returns the Fahrenheit equivalent of a Celsius temperature.
int fahrenheit(int c)
{
    return 9 * c / 5 + 32;
}

// Chart 1: Celsius 0..100 (101 values) -> Fahrenheit
void printCelsiusChart()
{
    int count = 101;
    int rows = (count + COLS - 1) / COLS;   // lines needed (rounded up)

    cout << "FAHRENHEIT EQUIVALENTS OF CELSIUS 0 TO 100" << endl;
    for (int col = 0; col < COLS; col++)
        cout << setw(4) << "C" << setw(6) << "F" << "   ";
    cout << endl;

    for (int r = 0; r < rows; r++)
    {
        for (int col = 0; col < COLS; col++)
        {
            int celsiusTemp = r + col * rows;   // fill down each column group
            if (celsiusTemp <= 100)
                cout << setw(4) << celsiusTemp
                     << setw(6) << fahrenheit(celsiusTemp) << "   ";
        }
        cout << endl;
    }
}

// Chart 2: Fahrenheit 32..212 (181 values) -> Celsius
void printFahrenheitChart()
{
    int count = 181;
    int rows = (count + COLS - 1) / COLS;

    cout << "CELSIUS EQUIVALENTS OF FAHRENHEIT 32 TO 212" << endl;
    for (int col = 0; col < COLS; col++)
        cout << setw(4) << "F" << setw(6) << "C" << "   ";
    cout << endl;

    for (int r = 0; r < rows; r++)
    {
        for (int col = 0; col < COLS; col++)
        {
            int fahrenheitTemp = 32 + r + col * rows;
            if (fahrenheitTemp <= 212)
                cout << setw(4) << fahrenheitTemp
                     << setw(6) << celsius(fahrenheitTemp) << "   ";
        }
        cout << endl;
    }
}
