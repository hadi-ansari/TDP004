#include <iostream>
#include <string>
#include <iomanip>
// KlaAr36: kanske tomrad här?

using namespace std;
// KlaAr36: varför extra tomrad?
// KlaAr36 Komplettering: 1-7 ni har överlag bra gruppering av koden, men på flera ställen har ni en (extra) omotiverad tomrad
// KlaAr36 Komplettering: 4-3 manipulatorer (setprecision mfl) med permanent effekt ska inte upprepas
// KlaAr36 Komplettering: 5-1 variabler ska namnges med beskrivande relevanta namn
// KlaAr36 Kompletering: utför konsekvent sammanhängande inmatning i en sats

// KlaAr36: Gott att ni använt numeric_limits
// KlaAr36: helhet: Snyggt och prydligt! Bra jobbat!

int main()
{
  int num_input{};
  string string_input{};
  float float_input{};// KlaAr36: varför tomrad?
  char char_input{};
  
  cout << "Skriv in ett heltal: " << flush;
  cin >> num_input;
  cout << "Du skrev in talet: " << num_input << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');// discards the input buffer

  cout << "Skriv in fem heltal: " << flush;
  cin >> num_input;
  string_input += to_string(num_input) + ", ";
  cin >> num_input;
  string_input += to_string(num_input) + ", ";
  cin >> num_input;
  string_input += to_string(num_input) + ", ";
  cin >> num_input;
  string_input += to_string(num_input) + ", ";
  cin >> num_input;
  string_input += to_string(num_input);
  cout << "Du skrev in talen: " << string_input <<endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in ett flyttal: " << flush;
  cin >> float_input;
  cout << "Du skrev in flyttalet: " << fixed << setprecision(3) << float_input << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  
  cout << "Skriv in ett heltal och ett flyttal: " << flush;
  cin >> num_input >> float_input ; // KlaAr36: exempel på inmatning som kan görast i en sats
  cout << "Du skrev in heltalet: " << setw(11) << num_input << endl;
  cout << "Du skrev in flyttalet: " << setw(10) << float_input << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
// KlaAr36: varför extra tomrad?
  cout << "Skriv in ett flyttal och ett heltal: " << flush;
  cin >> float_input >> num_input;
  cout << "Du skrev in heltalet:" << setfill('-') << setw(11) << num_input << endl;
  cout << "Du skrev in flyttalet:" << setfill('-') << setw(10) << float_input << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  
  cout << "Skriv in ett tecken: " << flush;
  cin >> char_input;
  cout << "Du skrev in tecknet: " << char_input << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
// KlaAr36: varför extra tomrad?
  cout << "Skriv in en sträng: " << flush;
  cin >> string_input;
  cout << "Strängen '" << string_input << "' har " << string_input.size() << " tecken." << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in ett heltal och en sträng: " << flush;
  cin >> num_input >> string_input; // KlaAr36: exempel på inmatning som ni redan gör i en sats!
  cout << "Du skrev in talet |" << num_input << "| och strängen |" << string_input << "|."<< endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Skriv in en sträng och ett flyttal: " << flush;
  cin >> string_input >> float_input;
  cout << "Du skrev in \"" << float_input << "\" och \"" << string_input << "\"." << endl << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  
  cout << "Skriv in en hel rad med text: " << flush;
  getline(cin, string_input);
  cout << "Du skrev in textraden: '" << string_input <<"'" << endl << endl;
// KlaAr36: varför extra tomrad?
  cout << "Skriv in en textrad som slutar med ett negativt heltal: " << flush;
  getline(cin, string_input, '-');
  cin >> num_input;
// KlaAr36: Komplettering: 8-8 Skriver ut ett extra blanksteg som inte fanns på inmatad rad
// Exempel:
// Skriv in en textrad som slutar med ett negativt heltal: ojdå-1
// Du skrev in textraden: 'ojdå ' och heltalet '-1'
// ----------------------------^
  cout << "Du skrev in textraden: '" << string_input << "' och heltalet '-" << num_input << "'" << endl;
  
  return 0;
}
