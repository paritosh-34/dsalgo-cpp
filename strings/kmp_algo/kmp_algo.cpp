#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS_brute(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);

    for (int len = 1; len < n; len++)
    {
        int maxLen = 0;
        for (int i = 1; i < len; i++)
        {
            string pprefix = s.substr(0, i);
            string suffix = s.substr(len - i, i);

            cout << "(" << i << " -> " << len << ")  pprefix: " << pprefix;
            cout << "\t|| suffix: " << suffix << endl;

            if (pprefix == suffix)
            {
                maxLen = i;
            }
        }
        cout << endl;

        lps[len - 1] = maxLen;
    }

    return lps;
}

vector<int> computeLPS_optimal(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);

    int j = 0;
    for (int i = 1; i < n;)
    {
        if (s[i] == s[j])
        {
            lps[i] = j + 1;
            i++, j++;
        }
        else if (j != 0)
        {
            j = lps[j];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

int main()
{
    string s = "ababc";

    vector<int> lps = computeLPS_brute(s);

    cout << lps.size() << endl;

    for (int ele : lps)
    {
        cout << ele << " ";
    }

    return 0;
}
