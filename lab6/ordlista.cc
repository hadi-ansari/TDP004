#include <fstream>
#include <string>
#include <iostream>
#include <vector>
// !?;,:."')
using namespace std;

vector<string> get_valid(vector<string> const& words)
{
  vector<string> valid{};

  for (auto it = begin(words); it != end(words); ++it)
  {
    if(((*it)[0] == '(' || (*it)[0] == '"' || (*it)[0] == '\'' || isalpha((*it)[0])) 
       && ( (*it).back() == '.' || isalpha((*it).back()) || (*it).back() == ')' 
       || (*it).back() == '"' || (*it).back() == '\'' || (*it).back() == '!' 
       || (*it).back() == '?' || (*it).back() == ';' || (*it).back() == ',' 
       || (*it).back() == ':'  )) //Förlåt för denna raden
    {
      valid.push_back(*it);
    }
  }

  return valid;
}


int main(/*int argc, char *argv[]*/) {
  ifstream ifs{"testfil.txt"};
  vector<string> words{};
   string word{};

  while(ifs >> word)
{
    words.push_back(word);
}

  vector<string> valid = get_valid(words);
  
  for (auto it = begin(valid); it != end(valid); ++it)
{
  cout << *it << endl;
}
  
  return 0;
}
