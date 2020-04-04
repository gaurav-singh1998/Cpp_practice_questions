#include<bits/stdc++.h>
using namespace std;

int CalcMHWScore(vector<int> scores)
{
  size_t size = scores.size();

  if (size == 0)
  {
    return 0;  // Undefined, really.
  }
  else
  {
    sort(scores.begin(), scores.end());
    if (size % 2 == 0)
    {
      return (scores[size / 2 - 1] + scores[size / 2]) / 2;
    }
    else
    {
      return scores[size / 2];
    }
  }
}

int main()
{
    int n;
    cin >> n;
    vector<int>v1(n);
    vector<int>v2(n);
    for(int i=0; i<n; i++)
    {
        cin >> v1[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> v2[i];
    }
    vector<int>v3(2*n);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << CalcMHWScore(v3) << endl;
    
}
