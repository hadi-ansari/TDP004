#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void get_valid(vector<string> & words)
{
  vector<string> valid{};
  string valid_prefix = "\"\'(";
  string valid_suffix = "!?;,:.\"\')";

  for (auto it = begin(words); it != end(words); ++it)
  {
    // if(((*it)[0] == '(' || (*it)[0] == '"' || (*it)[0] == '\'' || isalpha((*it)[0])) 
    //    && ( (*it).back() == '.' || isalpha((*it).back()) || (*it).back() == ')' 
    //    || (*it).back() == '"' || (*it).back() == '\'' || (*it).back() == '!' 
    //    || (*it).back() == '?' || (*it).back() == ';' || (*it).back() == ',' 
    //    || (*it).back() == ':'  )) //Förlåt för denna raden
    
    if ( (*it).find_first_of(valid_prefix) != 0
	 && !isalpha((*it).front())
	 && (*it).find_last_of(valid_suffix) != (*it).size() - 1
	 && !isalpha((*it).back()) )
      {
	words.erase(it);
	it --;
      }
  }
}


int main(/*int argc, char *argv[]*/)
{
  ifstream ifs{"testfil.txt"};
  vector<string> words{};
  string word{};
  string valid_prefix = "\"\'(";
  string valid_suffix = "!?;,:.\"\')";

  while(ifs >> word)
    {
      words.push_back(word);
    }
  
  // get_valid(words);

  // 
  words.erase(remove_if(words.begin(), words.end(),
			 [](string x)
			 {
			   return ( ( x.find_first_of("\"\'(") != 0
				    && !isalpha(x.front()) )
				    || ( x.find_last_of("!?;,:.\"\')") != x.size() - 1
					 && !isalpha(x.back()) ) );
			     }),
	      words.end());


  for (auto & word : words)
    {
      for(string::iterator it = word.begin(); it != word.end(); it++)
	{
	  if(isalpha(*it)) break;
	  else
	    {
	      word.erase(it);
	      it --;
	    }
	    
	}
    }
  // for (auto & word : words)
  //   {
  //     for(auto it = word.end() - 1; it == word.begin(); it--)
  // 	{
  // 	  if(isalpha(*it)) break;
  // 	  else
  // 	    {
  // 	      word.erase(it);
  // 	      it ++;
  // 	    }
  // 	}
  //   }

   for (auto it = begin(words); it != end(words); ++it)
    {
      cout << *it << endl;
    }

  return 0;
}
