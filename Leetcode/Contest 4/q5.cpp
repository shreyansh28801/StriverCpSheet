#include <bits/stdc++.h>
using namespace std;

int min_max_sum(vector<int> &a, int K)
{

  int n = a.size();
  int high = 0, low = 0, mid = 0;

  for (int i = 0; i < n; ++i)
  {
    high += a[i];
    low = max(a[i], low);
  }

  while (low <= high)
  {
    mid = (low + high) / 2;

    long long part_sum = 0;
    int parts = 1;
    for (int i = 0; i < n; ++i)
    {
      if (part_sum + a[i] > mid)
      {
        part_sum = 0;
        parts++;
      }
      else
      {
        part_sum += a[i];
      }
    }

    // if no. of parts in less than (or equal to) K then mid needs to (,or can) be more constrained by reducing upper limit
    if (parts <= K)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return mid;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v{8, 15, 10, 20, 8};
 
  cout<<min_max_sum(v,2);

  return 0;
}