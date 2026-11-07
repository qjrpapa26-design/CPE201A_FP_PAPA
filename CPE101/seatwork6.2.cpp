#include <iostream>   
#include <fstream>    
#include <sstream>    
#include <string>     

using namespace std;

int main()
{
    // 1. WORK WITH FILES: open the file for reading.
    ifstream inFile("numbers.txt");

    // Always check that the file opened successfully.
    if (!inFile)
    {
        cerr << "Error: could not open 'numbers.txt'." << endl;
        cerr << "Place the file in the same folder as the program." << endl;
        return 1;
    }

    string line;            // holds one line of text
    double value;           // holds the number parsed from the line
    double sum = 0.0;       // running total of valid numbers
    int lineNo = 0;         // current line number (for the warning log)
    int validCount = 0;     // how many lines were valid numbers
    int skippedCount = 0;   // how many lines were skipped

    // 2. READ FROM A FILE / 5. LOOP OVER FILE CONTENT:
    // getline() reads one whole line each pass and returns false at end-of-file.
    while (getline(inFile, line))
    {
        lineNo++;

        // Treat a line as a stream so we can use >> to convert text to double.
        istringstream iss(line);
        string leftover;    // used to detect junk after the number (e.g. "12abc")

        // Skip blank lines quietly (nothing to convert).
        if (line.find_first_not_of(" \t\r") == string::npos)
        {
            cout << "Line " << lineNo << ": (blank line, skipped)" << endl;
            skippedCount++;
            continue;
        }

        // 4. PROCESS SIMPLE DATA:
        // Success only if (a) a double was extracted AND (b) nothing else follows.
        if (iss >> value && !(iss >> leftover))
        {
            cout << "Line " << lineNo << ": valid number = " << value << endl;
            sum += value;
            validCount++;
        }
        else
        {
            // Log a warning for the bad line.
            cerr << "WARNING: Line " << lineNo
                 << " has non-numeric data -> \"" << line << "\" (skipped)" << endl;

            // Clear the error flags (failbit) on the stream so it is in a
            // good state again. Here the stream is rebuilt every loop, but
            // clear() shows the proper recovery step when reusing a stream.
            iss.clear();

            skippedCount++;
        }
    }

    // 3. Close the file when finished.
    inFile.close();

    // Summary report.
    cout << "\n----- Summary -----" << endl;
    cout << "Valid numbers : " << validCount << endl;
    cout << "Skipped lines : " << skippedCount << endl;
    cout << "Sum of valid  : " << sum << endl;
    if (validCount > 0)
        cout << "Average       : " << sum / validCount << endl;

    return 0;
}
