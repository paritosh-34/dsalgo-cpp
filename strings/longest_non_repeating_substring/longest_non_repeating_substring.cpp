#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
  int n = s.length();
  vector<int> mpp(256, -1);

  int l = 0, r = 0;
  int maxL = 0;

  while (r < n)
  {
    if (mpp[s[r]] != -1)
    {
      l = max(mpp[s[r]] + 1, l);
    }

    mpp[s[r]] = r;

    maxL = max(maxL, r - l + 1);
    r++;
  }

  return maxL;
}

int main()
{
  string s = "abcabcbb";

  int l = lengthOfLongestSubstring(s);
  cout << "Longest length: " << l << endl;

  return 0;
}