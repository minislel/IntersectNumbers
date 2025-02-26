#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> split(string str, char del) {
    vector<string> result;
    str += del;
    int pos = str.find(del);
    while (pos != string::npos)
    {
        result.push_back(str.substr(0, pos));
        str.erase(0, pos + 1);
        pos = str.find(del);
    }
    return result;
}
vector<int> splitNums(string str, char del)
{
    vector<int> result;
    str += del;
    int pos = str.find(del);

    while (pos != string::npos)
    {
        int num = stoi(str.substr(0, pos));
        result.push_back(num);
        str.erase(0, pos + 1);
        pos = str.find(del);
    }
    return result;
}
int main() {
    string line;
    while (getline(cin, line)) {
        vector<string> input = split(line, ';');
        vector<vector<int>> lines;
        for (int i = 0; i < input.capacity(); i++)
        {
            lines.push_back(splitNums(input.front(), ','));
            input.erase(input.begin());
        }
        std::list<int> result;
        int maxIndex = 0;
        auto maxLength = lines[0].size(); 

        for (int i = 1; i < lines.size(); ++i) {
            if (lines[i].size() > maxLength) {
                maxLength = lines[i].size();
                maxIndex = i;
            }
        }
        for (int i = 0; i < lines.size(); i++)
        {
            if (i != maxIndex)
            {
                for (auto it = lines[maxIndex].begin(); it != lines[maxIndex].end(); ++it)
                {
                    auto found = std::find(lines[i].begin(), lines[i].end(), *it);
                    if (found != lines[i].end())
                    {
                        result.push_front(*it);
                    }
                }
            }
        }
            result.sort();
            for (list<int>::iterator it = result.begin(); it != result.end(); ++it)
            {
                if (it != result.begin()) cout << ",";
                cout << *it;
			}
			cout << endl;
    }
    return 0;
}

