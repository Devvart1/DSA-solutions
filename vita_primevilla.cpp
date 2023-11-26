#include<bits/stdc++.h>


using namespace std;

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int y, m, d, n;
  string dowww;
  cin >> y >> m >> d >> dowww >> n;

  vector<int> primeDays;
  for (int i = 1; i <= n; i++) {
    if (isPrime(i) && (m == 2 || m == 3 || m == 5 || m == 7 || m == 11)) {
      primeDays.push_back(i);
    }
  }

  if (primeDays.empty()) {
    cout << "No 0" << endl;
    return 0;
  }

  int r = -1;
  for (size_t i = 0; i < primeDays.size(); i++) {
    if (primeDays[i] >= n) {
      r = primeDays[i];
      break;
    }
  }

  if (r == -1) {
    cout << "No 0" << endl;
    return 0;
  }

  if (dowww == "Sun" && (r % 7 == 0))
    cout << "Yes " << r << endl;
  else if (dowww == "Mon" && (r % 7 == 1))
    cout << "Yes " << r << endl;
  else if (dowww == "Tue" && (r % 7 == 2))
    cout << "Yes " << r << endl;
  else if (dowww == "Wed" && (r % 7 == 3))
    cout << "Yes " << r << endl;
  else if (dowww == "Thu" && (r % 7 == 4))
    cout << "Yes " << r << endl;
  else if (dowww == "Fri" && (r % 7 == 5))
    cout << "Yes " << r << endl;
  else if (dowww == "Sat" && (r % 7 == 6))
    cout << "Yes " << r << endl;
  else
    cout << "No " << r << endl;


  return 0;
}