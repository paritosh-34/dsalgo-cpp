#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS_brute(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);

    for (int len = 1; len <= n; len++)
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

    for (int ele : lps)
    {
        cout << ele << " ";
    }
    cout << endl;

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
            j = lps[j - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

int kmp_search(string haystack, string needle, vector<int> &lps)
{
    int i = 0;
    int j = 0;
    int n = haystack.length();
    int m = needle.length();

    while (j < m && i < n)
    {
        if (haystack[i] == needle[j])
        {
            i++, j++;
        }
        else if (j != 0)
        {
            int prevMatchIndex = j - 1;
            int lastMatchPlusOne = lps[(j - 1) - 1 + 1];
            j = lps[j - 1];
        }
        else
        {
            i++;
        }
    }

    if (j == m)
        return i;
    return -1;
}

int main()
{
    string needle = "ababc";
    string haystack = "ababcabcabababd";

    vector<int> lps = computeLPS_brute(needle);
    int foundIndex = kmp_search(haystack, needle, lps);

    if (foundIndex != -1)
    {
        cout << "pattern found at index: " << foundIndex << endl;
    }
    else
    {
        cout << "pattern not found" << endl;
    }

    return 0;
}
