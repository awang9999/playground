#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lamps){

  if(lamps.size() <= 0) {
    return 0;
  }

  map<int, int> m;

  for(int i = 0; i < lamps.size(); i++) {
    int left = lamps[i][0] - lamps[i][1];
    int right = lamps[i][0] + lamps[i][1];

    for(int j = left; j < right + 1; j++) {
      m[j]++;
    }
  }

  int count = 0;
  
  for (auto c : m) {
    cout << c.first << ", " << c.second << "\n";
    count += c.second == 1;
  }
  
  return count;
}

int eval_test_case(int case_num, int expected, int actual) {

  string pf = "";

  if (expected == actual) {
    pf = "Passed.";
  } else {
    string a = "Failed. Expected ";
    string b = " but got ";
    pf = a + to_string(expected) + b + to_string(actual);
  }
  
  cout << "Test Case " << case_num << ": " << pf << "\n";

  return expected == actual;
}

int test_cases() {
  int errors = 0;

  int result = 0;
  int expected = 0;

  // Case 1: given example
  vector<vector<int>> lamps1{{-2, 3}, {2, 3}, {2, 1}};
  result = solution(lamps1);
  expected = 6;
  errors = eval_test_case(1, expected, result) ? errors : errors + 1;

  // Case 2: single lamp
  vector<vector<int>> lamps2{{-2, 2}};
  result = solution(lamps2);
  expected = 5;
  errors = eval_test_case(2, expected, result) ? errors : errors + 1;

  // Case 3: zero lamps
  vector<vector<int>> lamps3{};
  result = solution(lamps3);
  expected = 0;
  errors = eval_test_case(3, expected, result) ? errors : errors + 1;

  // Case 4: completely overlapping lamps
  vector<vector<int>> lamps4{{-2, 3}, {-2, 3}};
  result = solution(lamps4);
  expected = 0;
  errors = eval_test_case(4, expected, result) ? errors : errors + 1;

  // Case 5: disjoint lamps
  vector<vector<int>> lamps5{{-2, 3}, {0, 2}, {11, 2}};
  result = solution(lamps5);
  expected = 9;
  errors = eval_test_case(5, expected, result) ? errors : errors + 1;
  
  return errors;
}

int main() {

  int errors = test_cases();
  
  if(errors > 0) {
    cout << "Failed " << errors << " test cases! \n";
  } else {
    cout << "Passed all test cases! \n";
  }

  return 0;
}

