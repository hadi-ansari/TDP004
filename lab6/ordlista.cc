#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char * argv[])
{
  vector<string> words{};
  string word{};
  ifstream ifs{argv[1]};
  string flag = argv[2];
  
  if(argc < 2)
    {
      cerr << "Error: No arguments given.\nUsage: a.out FILE [-a] [-f] [-o N]"
  	  << endl;
      return 1;
    }
  else if(argc < 3)
    {
      cerr << "Error: Second argument missing or invalid.\n";
      cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
      return 1;
    }


  
  while(ifs >> word)
    {
      words.push_back(word);
    } 

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
      for(auto it = word.begin(); it != word.end(); it++)
	{
	  if(isalpha(*it)) break;
	  else
	    {
	      word.erase(it);
	      it --;
	    }
	    
	}
    }
  
  for (auto & word : words)
    {
      for(auto it = word.rbegin(); it != word.rend(); it++)
  	{
  	  if(isalpha(*it)) break;
  	  else
  	    {
  	      word.erase((it + 1).base());
  	    }
  	}
    }
  
  // removing words with invalid "'s" from vector
  words.erase(remove_if(words.begin(), words.end(),
  			 [](string x)
  			 {
  			   int indx = x.find("'s");
			   int size = x.size();
  			   return( ( indx != size - 2 ) && ( indx > 0 ) ) ;
  			 }),
  	      words.end());
  
  // removing "'s"from end of the words in vector
  transform(words.begin(), words.end(), words.begin(),
  		  [](string x)
  		  {
		    int indx = x.find("'s");
		    int size = x.size();
		    if(indx == size - 2 )
		      x.erase(indx, size);
  		    return x;
  		  }
  		  );

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


  words.erase(remove_if(words.begin(), words.end(),
  			 [](string x)
  			 {
			   int i = x.find("--");
			   return !(i < 0);
  			 }),
  	      words.end());
  

  words.erase(remove_if(words.begin(), words.end(),
			[](string x)
			{
			  return x.size() < 3;
			}),
  	      words.end());

  map<string , int> m1{};

  for(auto it = words.begin(); it != words.end(); it ++)
    {
      m1[*it]++;
    }
  
  vector<int> values{};
  
  for (auto it = m1.begin(); it != m1.end(); ++it)
    {
      values.push_back(it -> second);
    }
  sort(values.begin(), values.end(), greater<int>());

  // for (auto it = begin(words); it != end(words); ++it)
  //   {
  //     cout << *it << endl;
  //   }


  if(flag == "-a")
    {
      //flagga -a
      for (auto it = m1.begin(); it != m1.end(); ++it)
	{
	  cout << it -> first << " " << it -> second << endl;
	}
    }
  else if(flag == "-f")
    {
      // flagga -f
  
      for(auto it = values.begin(); it != values.end(); ++it)
        {
          for (auto it2 = m1.begin(); it2 != m1.end(); ++it2)
	    {
	      if(*it == it2 -> second)
		{
		  cout << it2 -> first << " " << it2 -> second << endl;
		  it2 = m1.erase(it2);
		  break;
		}
	    }
        }
    }
  // else
  //   {
  //     // flagga -o n
  //     int sum{0};
  //      for(auto it = begin(words); it != end(words); ++it)
  //       {
  //         sum += (*it).size();
  //         if(sum < n)
  //     	cout << *it << " ";
  //         else
  //     	{
  //     	  cout << "\n" << *it << " ";
  //     	  sum = (*it).size();
  //     	}
  //       }

  //     for_each(words.begin(), words.end(),
  //     	   [](string x)
  //     	   {
  //     	     sum = 12;
  //     	     x.append('*'); 
  //     	   }
  //     	   );
  //   }
  return 0;
}
