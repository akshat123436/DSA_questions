#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
    int inputNum;
    string instruction;
    cin >> inputNum >> instruction;
    string input = to_string(inputNum);
    int ptr = 0;
    int n = instruction.length();
    for (int i = 0; i < n; i++)
    {
        // cout << input << endl;
        if (instruction[i] == 'R')
        {
            ptr++;
        }
        else if (instruction[i] == 'L')
        {
            ptr--;
        }
        else if (instruction[i] == 'T')
        {
            if (input[ptr] != '9')
                (int)input[ptr]++;
        }
        else if (instruction[i] == 'D')
        {
            if (input[ptr] != '0')
                (int)input[ptr]--;
        }
        else
        {
            int swapIndex = (instruction[i + 1] - '0') - 1;
            char temp = input[ptr];
            input[ptr] = input[swapIndex];
            input[swapIndex] = temp;
            i++;
        }
    }

    cout << input << endl;
}