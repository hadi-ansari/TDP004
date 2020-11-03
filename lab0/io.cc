#include <iostream>
#include <iomanip>

using namespace std;


int main(){
  int num{};
  string str{""};
  float f{3.3};
  char ch[80];
  
  // cout << "Skriv in ett heltal: " << flush;
  // cin >> num;
  // cout << "Du skrev in talet: " << num << endl << endl;

  // // discards the input buffer 
  // cin.ignore(numeric_limits<streamsize>::max(),'\n');

  // cout << "Skriv in fem heltal: " << flush;
  // cin >> num;
  // str += to_string(num) + ", ";
  // cin >> num;
  // str += to_string(num) + ", ";
  // cin >> num;
  // str += to_string(num) + ", ";
  // cin >> num;
  // str += to_string(num) + ", ";
  // cin >> num;
  // str += to_string(num);
  // cout << "Du skrev in talen: " << str <<endl << endl;
  // cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in ett flyttal: " << flush;
  cin >> f;
  cout << "Du skrev in flyttalet: " << setprecision(4) << f << endl << endl;



  
}
