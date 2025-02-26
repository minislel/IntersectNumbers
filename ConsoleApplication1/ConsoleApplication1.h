#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    string line;
    while (getline(cin, line)) {
        char del = ';';
        int pos = line.find(del);
        std::list <string> lines;
        line+=del;
        while (pos != string::npos)
        {
            lines.push_front(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find(del);
        }
        std::list <int> A;
        std::list <int> B;
        for (int i = 0; i < lines.size() + 1; i++)
        {
            string temp = lines.front();
            lines.pop_front();
            char del = ',';
            temp += del;
            int pos = temp.find(del);
            while (pos != string::npos)
            {
                int num = stoi(temp.substr(0, pos));
                if (i == 0)
                {
                    A.push_front(num);
                }
                else {
                    B.push_front(num);
                }
                temp.erase(0, pos + 1);
                pos = temp.find(del);
            }
        }
        std::list<int> result;
            if (A.size() > B.size())
            {
                for (list<int>::iterator it = A.begin(); it != A.end(); ++it)
                {
                    auto found = std::find(B.begin(), B.end(), *it);
                    if (found != B.end())
                    {
                        result.push_front(*it);
					}
                }
            }
            else
            {
                for (list<int>::iterator it = B.begin(); it != B.end(); ++it)
                {
                    auto found = std::find(A.begin(), A.end(), *it);
                    if (found != A.end())
                    {
                        result.push_front(*it);
                    }
                }
            }
            result.sort();
            for (list<int>::iterator it = result.begin(); it != result.end(); ++it)
            {
                if (it != result.begin()) cout << ",";
                cout << *it;
			}

    }
    return 0;
}
