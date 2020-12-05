#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

// Komplettering: Lambdas ska inte koperia parametrar av klasstyp i onödan.

// Komplettering: Ni har delat upp validering och borttagning av ord i flera olika steg, 
//                detta innebär att ni måste iterera igenom vectorn och ta bort flera gånger.
//                Skapa istället en funktion för validering som utför alla kontrollerna på ett ord.

/* Komplettering: Ni ska inte använda loopar och for_each ska inte användas om en mer passande algoritm finns. 

Syftet med laborationen är att ni ska lära er och öva på att använda algoritmer,
genom att använda loopar missar ni många läromål som laborationen lär ut,
läromål som ni dels behöver kunna för att programmera i C++ men som ni också behöver
kunna inför tentan.

Ni ska därför använda algoritmer så långt det går för att lösa problemen, algortimer
som passar problemet i fråga. Att använda for_each ska enbart användas när ingen algoritm
passar bra, ex. vid utskrift och kopiering mellan containrar som inte lagrar samma datatyp.

C++ har många bra sträng-funktioner som ni kan använda för att manipulera strängar,
ni behöver därför inte hantera strängar på teckennivå utan kan istället utnyttja funktionerna.
ex. find_first_not_of("("'") istället för att söka igenom hela strängen med en loop.

Ni hittar de flesta algoritmer och funktioner på följande sidor:
https://en.cppreference.com/w/cpp/string/basic_string
https://en.cppreference.com/w/cpp/algorithm
https://en.cppreference.com/w/cpp/container
https://en.cppreference.com/w/cpp/string/byte/isalpha

Algoritmer ni kan komma att behöva:
https://en.cppreference.com/w/cpp/algorithm/count
https://en.cppreference.com/w/cpp/algorithm/find
https://en.cppreference.com/w/cpp/algorithm/adjacent_find
https://en.cppreference.com/w/cpp/algorithm/copy
https://en.cppreference.com/w/cpp/algorithm/transform
https://en.cppreference.com/w/cpp/algorithm/remove
https://en.cppreference.com/w/cpp/algorithm/sort
https://en.cppreference.com/w/cpp/algorithm/max_element

Sträng-funktioner ni kan komma att behöva:
https://en.cppreference.com/w/cpp/string/basic_string/front
https://en.cppreference.com/w/cpp/string/basic_string/back
https://en.cppreference.com/w/cpp/string/basic_string/size
https://en.cppreference.com/w/cpp/string/basic_string/erase
https://en.cppreference.com/w/cpp/string/basic_string/substr
https://en.cppreference.com/w/cpp/string/basic_string/find
https://en.cppreference.com/w/cpp/string/basic_string/rfind
https://en.cppreference.com/w/cpp/string/basic_string/find_first_of
https://en.cppreference.com/w/cpp/string/basic_string/find_last_of
https://en.cppreference.com/w/cpp/string/basic_string/find_last_not_of

Container-funktioner som ni kan komma att behöva:
https://en.cppreference.com/w/cpp/container/vector/begin
https://en.cppreference.com/w/cpp/container/vector/end
https://en.cppreference.com/w/cpp/container/vector/erase
https://en.cppreference.com/w/cpp/container/vector/push_back
https://en.cppreference.com/w/cpp/container/map/operator_at

 

Utnyttja även slides från föreläsningarna då dessa ofta går igenom metoder för att lösa

specifika problem, exempelvis att läsa in från en ström till vector.

https://www.ida.liu.se/~TDP004/current/sal/forelasning.sv.shtml

Om ni har frågor eller är osäkra hur ni kan lösa ett specifikt problem med en algoritm
kan ni alltid maila oss.
*/

using namespace std;


// Returnerar true om ordet är ogiltig annars false. Utför alla kontrollerna
// för giltigheten på ett ord
bool not_valid(string & word)
{
  string prefix_trash = "\"\'(";
  string suffix_trash = "!?;,:.\"\')";
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  
  if( (( word.find_first_of(prefix_trash) != 0 ) && ( !isalpha(word.front()) ))
    || ((( word.find_last_of(suffix_trash) != word.size() - 1 )
	&& ( !isalpha(word.back()) ) )) )
    {
      return true;
    }
  else
    {
      auto pos = word.find("--");
  
      if(pos != string::npos)
	return true;
      int first_alpha = word.find_first_of(alphabet);
      int last_alpha = word.find_last_of(alphabet);
      
      if(last_alpha - first_alpha < 2)
  	return true;
      
      string substr = word.substr(first_alpha, last_alpha - first_alpha + 1);
      
      
      pos = substr.find_first_of(prefix_trash + suffix_trash);
      
      if( (pos != string::npos && substr[pos] != '\'' )
  	  || (pos != string::npos && pos != substr.length() - 2) )
  	return true;
      
    }
  return false;
}

// En funktion som med std::transform konverterar strängen till små bokstäver
string convert(string & word)
{
  transform(word.begin(), word.end(), word.begin(),
  	    [](char & c) {
  	      c = ::tolower(c);
	      return c;
   	    });
  return word;
}



int main(int argc, char * argv[])
{
  if(argc < 2)
    {
      cerr << "Error: No arguments given.\nUsage: a.out FILE [-a] [-f] [-o N]"
	   << endl;
      return 1;
    }
  if(argc < 3)
    {
      cerr << "Error: Second argument missing or invalid.\n";
      cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
      return 1;
    } 
  ifstream ifs{argv[1]};
  
  if(!ifs)
    {
      cerr << "Error: The file does not exist." << endl;
      return 1;
    }
  vector<string> words{istream_iterator<string>{ifs},
      istream_iterator<string>{}};
  
  if(words.size() == 0)
    {
      cerr << "Error: The file is empty." << endl;
      return 1;
    }

  // Tar bort alla ogiltiga ord från vectorn
  words.erase(remove_if(words.begin(), words.end(), not_valid), words.end());
  
  // Tar bort inledande skräptecken för varje ord i vector
  // T.e -> "(Hello") (Bye")
  // Efter detta steg -> Hello") Bye")
  transform(words.begin(), words.end(), words.begin(),
	    [](string & x)
	    {
	      for(auto it = x.begin(); it != x.end(); it++)
		{
		  if(isalpha(*it))
		    {
		      return x;
		    }
		  else
		    {
		      x.erase(it);
		      it --;
		    }
		}
	      return x;
	    }
	    );
  
  // Tar bort avslutande skräptecken för varje ord i vector
  // T.e -> Hello") Bye")
  // Efter detta steg -> Hello Bye
  transform(words.begin(), words.end(), words.begin(),
	    [](string & x)
	    {
	      for(auto it = x.rbegin(); it != x.rend(); it++)
		{
		  if(isalpha(*it))
		    {
		      return x;
		    }
		  else
		    {
		      x.erase( (it + 1).base() );
		    }
		}
	      return x;
	    }
	    );
  
  
  // Tar bort "'s" från slutet av de ord som har engelsk genitivändelse.
  // Johan's -> Johan
  transform(words.begin(), words.end(), words.begin(),
  		  [](string & x)
  		  {
  		    int indx = x.find("'s");
  		    int size = x.size();
  		    if(indx == size - 2  && size > 2)
  		      x.erase(indx, size);
  		    return x;
  		  }
  		  );

// Komplettering: std::transform över vektorn följst av en funktion som kör transform över ordet.
  //Konverteras till små bokstäver
  transform(words.begin(), words.end(), words.begin(), convert);
  
  // Giltiga ord läggas till en map med antal förekomster
  map<string, int> valid_words{};
  for(auto it = words.begin(); it != words.end(); it ++)
    {
      valid_words[*it]++;
    }
  
  // Hittar max storlek för ord och antal förekomster
  unsigned int max_word_size = 0;
  unsigned int max_number_size = 0;
  // Komplettering: std::max_element.
  auto it1 = max_element(valid_words.begin(), valid_words.end(),
			 [](pair<string, int> const& p1, pair<string, int> const& p2)
			 {
			   return p1.first.size() < p2.first.size();
			 }
			 );
  max_word_size = it1 -> first.size();
  
  auto it2 = max_element(valid_words.begin(), valid_words.end(),
			[](pair<string, int> const& p1, pair<string, int> const& p2)
			{
			  return p1.second < p2.second;
			}
			);
  max_number_size = (to_string(it2 -> second)).size();

//Kommentar: Om ni låter vectorn ha pair<string, int> i sig kan ni använda copy för att 
//           kopiera från map till den (detta för att map innehåller pair<> av datatypen ni skapade den med),
//           sorteringen kan ni utföra sedan med en lambda till sort som jämför it->second.
//           Vi utskrift behöver ni då inte hantera två olika behållare.
  vector<pair <string, int> > pairs(valid_words.size());
  copy(valid_words.begin(), valid_words.end(), pairs.begin());
  
  string flag = argv[2];
  
  if(flag == "-a")
    {
      sort(pairs.begin(), pairs.end(),
	   [](pair<string, int> const& p1, pair<string, int> const& p2)
	   {
	     return p1.first < p2.first;
	   }
	   );
      // Användning av for_each för utskrift istället för loop enligt komementar.
      for_each(pairs.begin(), pairs.end(),
	       [&max_word_size, &max_number_size](pair<string, int> const& p)
	       {
		 cout << setw(max_word_size) << left << p.first << "  "
		      << setw(max_number_size) << p.second << endl;
	       }
	       );
    }
  else if (flag == "-f")
    {
      sort(pairs.begin(), pairs.end(),
	   [](pair<string, int> const& p1, pair<string, int> const& p2)
	   {
	     return p1.second > p2.second;
	   }
	   );
      // Användning av for_each för utskrift istället för loop enligt komementar.
      for_each(pairs.begin(), pairs.end(),
	       [&max_word_size, &max_number_size](pair<string, int> const& p)
	       {
		 cout << setw(max_word_size) << p.first << "  "
		      << setw(max_number_size) << right <<  p.second << endl;
	       }
	       );
    }
  else if(flag == "-o")
    {
      int number{};
      int sum{0};
      
      if(argc < 4)
	{
	  cerr << "Error: Last argument missing a value.\n";
	  cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
	  return 1;
	}
      try
	{
	  number = stoi(argv[3]);
	}
      catch(invalid_argument const& error)
	{
	  cerr << "Error: Incorrect entry of arguments after \"-o\". Enter only integers."
	       << endl;
	  return 1;
	}      
      for_each(words.begin(), words.end(),
	       [&sum, &number](string & x)
      	   {
	     int size = x.size();
	     if ( sum + size < number )
	       {
		 cout << x << " ";
		 sum += size + 1;
	       }
	     else
	       {
		 cout << "\n" << x << " ";
		 sum = size + 1;
	       }
      	   }
      	   );
      cout << endl;
    }
  else
    {
      cerr << "Error: invalid flag. \n"
	   << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
      return 1;
    }

  return 0;
}
