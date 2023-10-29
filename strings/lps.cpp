#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <deque>
#include <list>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> prefix_function(string s)
{
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 0; i < n; i++)
  {
    for (int k = 0; k <= i; k++) // k increases the length of the substring on each iteration
    {
      string s1 = s.substr(0, k);
      string s2 = s.substr(i - k + 1, k);
      cout << "i: " << i << ", k: " << k << endl;
      cout << "s1: " << s1 << ", s2: " << s2 << endl
           << endl;

      if (s1 == s2)
      {
        pi[i] = k;
      }
    }
  }
  return pi;
}

int main()
{
  vector<int> ans = prefix_function("abcabcd");

  cout << endl;
  for (int ele : ans)
  {
    cout << ele << " ";
  }

  return 0;
}
