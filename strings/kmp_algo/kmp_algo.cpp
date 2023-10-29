#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);

    for (int len = 1; len < n; len++)
    {
        int maxLen = 0;
        for (int i=1;i<len;i++) {
            int suffixIndex = len-i;

            string pprefix = s.substr(0, i);
            string suffix = s.substr(suffixIndex, len - suffixIndex);

            cout << "(" << i << " -> " << len << ")  pprefix: " << pprefix; 
            cout << "\t|| suffix: " << suffix << endl;

            if (pprefix == suffix) {
                maxLen = i;
            }
        }
        cout << endl;

        lps[len-1] = maxLen;
    }

    return lps;
}

int main()
{
    string s = "ababc";

    vector<int> lps = computeLPS(s);

    for (int ele : lps) {
        cout << ele << " ";
    }

    return 0;
}
