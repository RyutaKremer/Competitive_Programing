#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,v) for (int i = 0; i < v.size(); i++)
#define SORT(v) sort(v.begin(), v.end())
#define MIN_ELEMENT(v) min_element(v.begin(), v.end())
#define MAX_ELEMENT(v) max_element(v.begin(), v.end())
#define COUNT(v,n) count(v.begin(), v.end(), n);
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char mlist[] = {'D', 'T', 'L', 'R'};

vector<vector<char> > b(30, vector<char>(30, '#'));
vector<vector<int> > cnt(30, vector<int>(30, 0));
int n, m, l, x, y, r, tcnt;
string s;

void move(char c)
{
  if (c == 'S') {
    if (b[x+dx[r]][y+dy[r]] != '#') {
      x += dx[r];
      y += dy[r];
    }
  } else if (c == 'L') {
      r = (r+3)%4;
  } else if (c == 'R') {
      r = (r+1)%4;
  }
}

void turn (char c) {
  switch (b[x][y]) {
    case '.':
      move(c);
      break;
    case '#':
      cout<<"error"<<endl;
      exit(1);
      break;
    case 'D':
      move(c);
      move(c);
      break;
    case 'T':
      move(c);
      move(c);
      move(c);
      break;
    case 'L':
      move(c == 'R' ? 'L' : c);
      break;
    case 'R':
      move(c == 'L' ? 'R' : c);
      break;
  }
}

void robot(string s)
{
  x = 15, y = 15, r = 0;
  REP(i,300) {
    turn(s[i]);
  }
  cnt[x][y]++;
}

int main()
{
  cin>>n>>m>>l;

  FOR(i,2,29) {
    FOR(j,2,29) {
      b[i][j] = '.';
    }
  }

  REP(i,n) {
    //cout<<i<<" ";
    cin>>s;
    robot(s);
  }

  FOR(i,2,29) {
    FOR(j,2,29) {
      if (cnt[i][j] < 3 || (i == 15 && j == 15))
        b[i][j] = '.';
      else
        b[i][j] = '#';
    }
  }

  FOR(i,1,30) {
    FOR(j,1,30) {
      cout<<b[i][j];
    }
    printf("\r\n");
  }

  return 0;
}
