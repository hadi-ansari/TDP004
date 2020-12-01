#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

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
  vector<string> words{};
  string word{};
  string flag = argv[2];
  
  while(ifs >> word)
    {
      words.push_back(word);
    }
  
  if(words.size() == 0)
    {
      cerr << "Error: The file is empty." << endl;
      return 1;
    }
  
  // Tar bort ord som inte börjar/slutar med vanliga bokstav/giltiga skräptecken
  // T.e tas bort dessa ord -> #hej "Hello"/ )bye. osv...
  words.erase(remove_if(words.begin(), words.end(),
			 [](string x)
			 {
			   return ( ( x.find_first_of("\"\'(") != 0
				    && !isalpha(x.front()) )
				    || ( x.find_last_of("!?;,:.\"\')") != x.size() - 1
					 && !isalpha(x.back()) ) );
			     }),
	      words.end());
  
  // Tar bort inledande skräptecken för varje ord i vector
  // T.e -> "(Hello") (Bye")
  // Efter detta steg -> Hello") Bye")
  for (auto & word : words)
    {
      for(auto it = word.begin(); it != word.end(); it++)
  	{
  	  if(isalpha(*it))
  	    {
  	      break;
  	    }
  	  else
  	    {
  	      word.erase(it);
  	      it --;
  	    }
	    
  	}
    }
  
  // Tar bort avslutande skräptecken för varje ord i vector
  // T.e -> Hello") Bye")
  // Efter detta steg -> Hello Bye
  for (auto & word : words)
    {
      for(auto it = word.rbegin(); it != word.rend(); it++)
  	{
  	  if(isalpha(*it))
  	    {
  	      break;
  	    }
  	  else
  	    {
  	      word.erase((it + 1).base());
  	    }
  	}
    }
  
  // Tar bort alla ord som innehåller ogiltiga "'s" från vector
  // T.e tas bort -> Johan's's he'skjr's O'scar
  // Men inte Emma's Johan's osv
  words.erase(remove_if(words.begin(), words.end(),
  			 [](string x)
  			 {
  			   int indx = x.find("'s");
  			   int size = x.size();
			   if(size < 3) return false;
  			   return( ( indx != size - 2 ) && ( indx > 0 ) ) ;
  			 }),
  	      words.end());
  
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

  // Tar bort alla ord som innehåller tecken som är varken bokstav eller binstreck
  // T.e tas bort hej.hej Oscar/Johan Han/hon osv
  // men inte Oscar--Johan han-hon ha---ha
  words.erase(remove_if(words.begin(), words.end(),
  			 [](string x)
  			 {
  			   for(char c: x)
  			     {
  			       if(!isalpha(c) && c != '-') return true;
  			     }
  			   return false;
			   
  			 }),
  	      words.end());

  // Tar bort alla ord som har minst två bindstreck
  //T.e tas bort Min--bok min---bok
  // men inte min-fin-bok
  words.erase(remove_if(words.begin(), words.end(),
  			 [](string x)
  			 {
  			   int i = x.find("--");
  			   return !(i < 0);
  			 }),
  	      words.end());
  
  // Tar bort ord som är mindre än 3 bokstav lång
  words.erase(remove_if(words.begin(), words.end(),
  			[](string x)
  			{
  			  return x.size() < 3;
  			}),
  	      words.end());

  //Konverteras till små bokstäver
  for(auto & word: words)
    {
      for_each(word.begin(), word.end(), [](char & c) {
					   c = ::tolower(c);
					 });
    }
    
  // Giltiga ord läggas till en map med antal förekomster 
  map<string , int> m1{};
  for(auto it = words.begin(); it != words.end(); it ++)
    {
      m1[*it]++;
    }
  
  // Hittar max storlek för ord
  unsigned int max_size = 0;

  for(auto m: m1)
    {
      if (m.first.size() > max_size)
	max_size = m.first.size();
    }
  
  // En vector för att spara antal förekomster
  // Använs när mappen ska sorteras efter värde (-f flaggan)
  vector<int> values{};
  
  for (auto it = m1.begin(); it != m1.end(); ++it)
    {
      values.push_back(it -> second);
    }
  sort(values.begin(), values.end(), greater<int>());

  // Sparar storlek på största siffran i mappen
  unsigned int max_number = size( to_string(values[0]) );

  if(flag == "-a")
    {
      for (auto it = m1.begin(); it != m1.end(); ++it)
  	{
  	  cout << setw(max_size) << left << it -> first << "  "
	       << setw(max_number) << it -> second << endl;
  	}
    }
  else if(flag == "-f")
    {
      for(auto value: values)
        {
          for (auto it = m1.begin(); it != m1.end(); ++it)
  	    {
  	      if(value == it -> second)
  		{
  		  cout << setw(max_size) << it -> first << "  "
		       << setw(max_number) << it -> second << endl;
  		  it = m1.erase(it);
  		  break;
  		}
  	    }
        }
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
	       [&sum, &number](string x)
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
