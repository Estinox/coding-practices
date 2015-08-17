#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

void displayPathtoPrincess(int n, vector <string> grid)
{
  int princessM = -1, princessN = -1, botM = -1, botN = -1;

  int i = 0;
  for (vector<string>::iterator it = grid.begin(); it != grid.end(); ++it)
  {
    //cout << *it << endl;
    std::size_t location = it->find("m");

    cout << location << "\n";

    if (location != string::npos)
    {
      princessM = i;
      princessN = location;
    }

    location = it->find("p");
    if (location != string::npos)
    {
      botM = i;
      botN = location;
    }

    if (princessM != -1
        && princessN != -1
        && botM != -1
        && botN != -1)
    {
      break;
    }

    ++i;
  }

  for (
}
int main(void)
{

  int m;
  vector <string> grid;

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    string s = "";
    cin >> s;
    grid.push_back(s);
  }

  displayPathtoPrincess(m, grid);

  return 0;
}

