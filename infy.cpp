#include <bits/stdc++.h>

using namespace std;

int convertToMinutes(string &s)
{
    int minutes = 0;
    if (s[2] == ':')
    {
        minutes += (s[0] - '0') * 60 * 10;
        minutes += (s[1] - '0') * 60;
        minutes += (s[3] - '0') * 10;
        minutes += s[4] - '0';
    }
    else
    {
        minutes += (s[0] - '0') * 60;
        minutes += (s[2] - '0') * 10;
        minutes += s[3] - '0';
    }

    return minutes;
}

int main()
{
    vector<vector<string>> meetings = {{"9:00", "10:30"}, {"12:00", "13:00"}, {"16:00", "18:00"}};

    vector<string> freeTimeInput = {"9:00", "20:00"};
    vector<int> freeTime(2);
    freeTime[0] = convertToMinutes(freeTimeInput[0]);
    freeTime[1] = convertToMinutes(freeTimeInput[1]);
    int totalDuration = 90;
    int last = 24 * 60;
    string lastString = "24:00";
    vector<vector<string>> answer;
    for (auto &meeting : meetings)
    {
        int currentStart = convertToMinutes(meeting[0]);
        if (last >= freeTime[0] && currentStart <= freeTime[1] && (currentStart - last) >= totalDuration)
        {
            answer.push_back({lastString, meeting[0]});
        }
        lastString = meeting[1];
        last = convertToMinutes(lastString);
    }
    int currentStart = freeTime[1];
    if (last >= freeTime[0] && currentStart <= freeTime[1] && (currentStart - last) >= totalDuration)
    {
        answer.push_back({lastString, freeTimeInput[1]});
    }
    for (auto &a : answer)
    {
        cout << a[0] << ' ' << a[1] << endl;
    }
}