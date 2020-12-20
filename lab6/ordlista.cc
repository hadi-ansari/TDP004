#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

// Komplettering: Ni använder fortfarane loopar.
// Komplettering: Programmet tar inte bort ord som har icke-alfabetiska tecken eller bindesträck i sig. ex.hej|||san som är ogiltigt ord.

using namespace std;

// Returnerar true om ordet är ogiltig annars false. Utför alla kontrollerna
// för giltigheten på ett ord
bool not_valid(string &word)
{
	string prefix_trash = "\"\'(";
	string suffix_trash = "!?;,:.\"\')";
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	if (((word.find_first_of(prefix_trash) != 0) && (!isalpha(word.front()))) || (((word.find_last_of(suffix_trash) != word.size() - 1) && (!isalpha(word.back())))))
	{
		return true;
	}
	else
	{
		// Kommentar: Använd inte auto för datatyper med korta namn eller när funktioner inte returnerar olika datatyper.
	       string::size_type pos = word.find("--");

		if (pos != string::npos)
			return true;
		// Kommentar: Det skulle passa mer att köra word.find_firt_not_of(prefix_trash) då den inte behöver
		// 			  jämföra varje tecken med 50 andra karaktärer utan kan jämföra med 3 tecken istället.
		int first_alpha = word.find_first_not_of(prefix_trash);
		// Kommentar: Det skulle passa mer att köra word.find_last_not_of(suffix_trash) då den inte behöver
		// 			  jämföra varje tecken med 50 andra karaktärer utan kan jämföra med 3 tecken istället.
		int last_alpha = word.find_last_not_of(suffix_trash);

		// Kommentar: Smart!
		if (last_alpha - first_alpha < 2)
			return true;

		string substr = word.substr(first_alpha, last_alpha - first_alpha + 1);

		pos = substr.find_first_not_of(alphabet + '-');

		if ((pos != string::npos && substr[pos] != '\'') || (pos != string::npos && pos != substr.length() - 2))
			return true;
	}
	return false;
}

// En funktion som med std::transform konverterar strängen till små bokstäver
string convert(string &word)
{
	transform(word.begin(), word.end(), word.begin(),
			  [](char &c) {
				  c = ::tolower(c);
				  return c;
			  });
	return word;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cerr << "Error: No arguments given.\nUsage: a.out FILE [-a] [-f] [-o N]"
			 << endl;
		return 1;
	}
	if (argc < 3)
	{
		cerr << "Error: Second argument missing or invalid.\n";
		cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
		return 1;
	}
	ifstream ifs{argv[1]};

	if (!ifs)
	{
		cerr << "Error: The file does not exist." << endl;
		return 1;
	}
	vector<string> words{istream_iterator<string>{ifs},
	    istream_iterator<string>{}};

	if (words.size() == 0)
	{
		cerr << "Error: The file is empty." << endl;
		return 1;
	}

	// Tar bort alla ogiltiga ord från vectorn
	words.erase(remove_if(words.begin(), words.end(), not_valid), words.end());

	// Tar bort inledande skräptecken för varje ord i vector
	// T.e -> "(Hello") (Bye")
	// Efter detta steg -> Hello") Bye")
	// Komplettering: Ni ska inte använda loopar för detta, ni har redan använt en bra strängfunktion som kan lösa detta åt er.
	string prefix_trash = "\"\'(";
	transform(words.begin(), words.end(), words.begin(),
			  [&prefix_trash](string &x) {
			    int pos = x.find_first_not_of(prefix_trash);
			    x.erase(0, pos);
			    return x;
			  });

	// Tar bort avslutande skräptecken för varje ord i vector
	// T.e -> Hello") Bye")
	// Efter detta steg -> Hello Bye
	// Komplettering: Ni ska inte använda loopar för detta, ni har redan använt en bra strängfunktion som kan lösa detta åt er.
	string suffix_trash = "!?;,:.\"\')";
	transform(words.begin(), words.end(), words.begin(),
			  [&suffix_trash](string &x) {
			    int pos = x.find_last_not_of(suffix_trash);
			    x.erase(pos + 1, x.size());
			    return x;
			  });

	// Tar bort "'s" från slutet av de ord som har engelsk genitivändelse.
	// Johan's -> Johan
	transform(words.begin(), words.end(), words.begin(),
			  [](string &x) {
				  int indx = x.find("'s");
				  int size = x.size();
				  if (indx == size - 2 && size > 2)
					  x.erase(indx, size);
				  return x;
			  });

	//Konverteras till små bokstäver
	transform(words.begin(), words.end(), words.begin(), convert);

	// Giltiga ord läggas till en map med antal förekomster
	map<string, int> valid_words{};
	// Komplettering: Använd inte loop för detta, använd for_each istället
	for_each(words.begin(), words.end(),
		 [&valid_words](string &x)
		 {
		   valid_words[x]++;
		 }
		 );
	

	// Hittar max storlek för ord och antal förekomster
	unsigned int max_word_size = 0;
	unsigned int max_number_size = 0;

	auto it1 = max_element(valid_words.begin(), valid_words.end(),
						   [](pair<string, int> const &p1, pair<string, int> const &p2) {
							   return p1.first.size() < p2.first.size();
						   });
	max_word_size = it1->first.size();

	auto it2 = max_element(valid_words.begin(), valid_words.end(),
						   [](pair<string, int> const &p1, pair<string, int> const &p2) {
							   return p1.second < p2.second;
						   });
	max_number_size = (to_string(it2->second)).size();

	//Kommentar: Om ni låter vectorn ha pair<string, int> i sig kan ni använda copy för att
	//           kopiera från map till den (detta för att map innehåller pair<> av datatypen ni skapade den med),
	//           sorteringen kan ni utföra sedan med en lambda till sort som jämför it->second.
	//           Vi utskrift behöver ni då inte hantera två olika behållare.
	vector<pair<string, int>> pairs(valid_words.size());
	copy(valid_words.begin(), valid_words.end(), pairs.begin());

	string flag = argv[2];

	if (flag == "-a")
	{
		sort(pairs.begin(), pairs.end(),
			 [](pair<string, int> const &p1, pair<string, int> const &p2) {
				 return p1.first < p2.first;
			 });

		for_each(pairs.begin(), pairs.end(),
				 [&max_word_size, &max_number_size](pair<string, int> const &p) {
					 cout << setw(max_word_size) << left << p.first << "  "
						  << setw(max_number_size) << p.second << endl;
				 });
	}
	else if (flag == "-f")
	{
		sort(pairs.begin(), pairs.end(),
			 [](pair<string, int> const &p1, pair<string, int> const &p2) {
				 return p1.second > p2.second;
			 });

		for_each(pairs.begin(), pairs.end(),
				 [&max_word_size, &max_number_size](pair<string, int> const &p) {
					 cout << setw(max_word_size) << p.first << "  "
						  << setw(max_number_size) << right << p.second << endl;
				 });
	}
	else if (flag == "-o")
	{
		int number{};
		int sum{0};

		if (argc < 4)
		{
			cerr << "Error: Last argument missing a value.\n";
			cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
			return 1;
		}
		try
		{
			number = stoi(argv[3]);
		}
		catch (invalid_argument const &error)
		{
			cerr << "Error: Incorrect entry of arguments after \"-o\". Enter only integers."
				 << endl;
			return 1;
		}
		for_each(words.begin(), words.end(),
				 [&sum, &number](string &x) {
					 int size = x.size();
					 if (sum + size < number)
					 {
						 cout << x << " ";
						 sum += size + 1;
					 }
					 else
					 {
						 cout << "\n"
							  << x << " ";
						 sum = size + 1;
					 }
				 });
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
