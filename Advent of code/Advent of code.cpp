// Advent of code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    std::cout << "Input depth measurements, one per line, incorrect input will be skipped:\n";

    //reading input
    string inputLine;
    vector  <int> depthMeasurements;
    bool skipLine = false;
    while (getline(cin, inputLine)) 
    {
        for (char c: inputLine) 
        {
            // checking inputLine if there are only numbers
            if ((c < '0' || c > '9') && !(c == '\n'))
            {
                cout << "Wrong input, skipping.\n";
                skipLine = true;
                break;
            }
        }
        if (skipLine)
        {
            skipLine = false;            
        }
        else
        {
            depthMeasurements.push_back(stoi(inputLine));
        }
    }

    /*
    // Counting how many times input has increased and decreased PART ONE
    if (!depthMeasurements.empty())
    {
        int currentDepth = depthMeasurements.at(0);
        int nDepthInc = 0;
        int nDepthDec = 0;
        for (int n : depthMeasurements)
        {
            if (n > currentDepth) nDepthInc++;
            else if (n < currentDepth) nDepthDec++;
            currentDepth = n;
        }

        cout << "Depth has increased " << nDepthInc << " times.\n";
        cout << "Depth has decreased " << nDepthDec << " times.\n";
    }
    else cout << "ERR: No valid input.\n";
    */

    // Counting how many times input has increased and decreased PART TWO
    if (!depthMeasurements.empty() && (depthMeasurements.size() > 3))
    {
        int currentDepthSum = 0;
        int nextDepthSum = 0;
        int nDepthsLoad = 3;    // Number of depth measurements to load and sum
        int nDepthInc = 0;
        int nDepthDec = 0;

        vector <int> depthMeasurementGroup;
        int i = 1;      // iteration counter, used for checking number of loaded values for first calculation
        for (int n : depthMeasurements)
        {
            if (nDepthsLoad < i) 
            {
                
                // moving measurements group by one (remove first, add next)
                nextDepthSum -= depthMeasurementGroup.front();
                nextDepthSum += n;
                depthMeasurementGroup.erase(depthMeasurementGroup.begin());
                depthMeasurementGroup.push_back(n);
                
                // checking for increment/ decrement of depth
                if (nextDepthSum > currentDepthSum) nDepthInc++;
                else if (nextDepthSum < currentDepthSum) nDepthDec++;
                currentDepthSum = nextDepthSum;
            }
            else
            {
                depthMeasurementGroup.push_back(n);
                currentDepthSum += n;
                nextDepthSum = currentDepthSum;
                i++;
            }
            
            
        }

        cout << "Depth sum has increased " << nDepthInc << " times.\n";
        cout << "Depth sum has decreased " << nDepthDec << " times.\n";
    }
    else cout << "ERR: No valid input.\n";

    /* //Debug
    for (int n : depthMeasurements)
    {
        cout << n << "\n";
    }
    */
    cin >> inputLine; // console pause
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
