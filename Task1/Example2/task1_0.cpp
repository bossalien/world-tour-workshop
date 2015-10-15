#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  for (int i = 0; i < 31; ++i)
  {
    cout << i << " ";
    if (i != 0)
    {
      cout << (i % 3 == 0 ? "three " : "");
      cout << (i % 5 == 0 ? "five " : "");
    }
  }
  return 0;
}