#include <iostream>
using namespace std;

int main() {
  int num;

  while(true){
    cin >> num;
    if(num == 42){
      return 0;
    }
    cout << num << "\n";
  }
  
}
