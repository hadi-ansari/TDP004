#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main(){
  
  int num{};
  string str{};
  
  float f{};
  char ch{};
  
  cout << "Skriv in ett heltal: " << flush;
  cin >> num;
  cout << "Du skrev in talet: " << num << endl << endl;

  // discards the input buffer 
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in fem heltal: " << flush;
  cin >> num;
  str += to_string(num) + ", ";
  cin >> num;
  str += to_string(num) + ", ";
  cin >> num;
  str += to_string(num) + ", ";
  cin >> num;
  str += to_string(num) + ", ";
  cin >> num;
  str += to_string(num);
  cout << "Du skrev in talen: " << str <<endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in ett flyttal: " << flush;
  cin >> f;
  cout << "Du skrev in flyttalet: " << fixed << setprecision(3) << f << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  
  cout << "Skriv in ett heltal och ett flyttal: " << flush;
  cin >> num;
  cin >> f;
  cout << "Du skrev in heltalet: " << setw(11) << num << endl;
  cout << "Du skrev in flyttalet: " << setw(10) << setprecision(3) << f << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');


  cout << "Skriv in ett flyttal och ett heltal: " << flush;
  cin >> f;
  cin >> num;
  cout << "Du skrev in heltalet:" << setfill('-') << setw(11) << num << endl;
  cout << "Du skrev in flyttalet:" << setfill('-') << setw(10) << setprecision(3) << f << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  
  cout << "Skriv in ett tecken: " << flush;
  cin >> ch;
  cout << "Du skrev in tecknet: " << ch << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  
  cout << "Skriv in en sträng: " << flush;
  cin >> str;
  cout << "Strängen '" << str << "' har " << str.size() << " tecken." << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in ett heltal och en sträng: " << flush;
  cin >> num >> str;
  cout << "Du skrev in talet |" << num << "| och strängen |" << str << "|."<< endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in en sträng och ett flyttal: " << flush;
  cin >> str >> f;
  cout << "Du skrev in \"" << fixed << setprecision(3) << f << "\" och \"" << str << "\"." << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  
  cout << "Skriv in en hel rad med text: " << flush;
  getline(cin, str);
  cout << "Du skrev in textraden: '" << str <<"'" << endl << endl;
  

  cout << "Skriv in en textrad som slutar med ett negativt heltal: " << flush;
  getline(cin, str, '-');
  cin >> num;
  cout << "Du skrev in textraden: '" << str << " ' och heltalet '-" << num << "'" << endl;
  
  return 0;
}
