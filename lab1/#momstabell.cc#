#include <iomanip>
#include <string>
#include <iostream>

// Bra jobbat! Tycker det ser fint ut men har några små kompletteringar
// ni ska fixa, samt en del kommentarer att läsas!

// Kommentar: Vill vi använda hela namespace std i framtiden?
using namespace std;

// Komplettering: Indenteringen är lite off ibland, om det beror
//                på att ni inte indenterat korrekt så fixa det.
//                Om det bara är våra editors som krånglar det så
//                strunta i den här kompletteringen.

// Kommentar: Vad är skillnad mellan endl och '\n'?

// Kommentar: Kan skrivas som:
//            return price * tax / 100;
// Kommentar: Riktigt fint med whitespace mellan operatorer!!
float tax_calc(float tax, float price)
{
  return price * tax / 100;
}

float taxed_price(float tax, float price)
{
  float taxed_price{};
  taxed_price = price + tax_calc(tax, price);
  return taxed_price;
}

int main()
{
  float start_price{};
  float max_price{};
  float step{};
  float tax_percent{};

  // Kommentar: Här känns det rimligare att använda '\n' efter första texten
  //            "INMATNINGSDEL\n" liksom. Men det är väl smaksak!
  cout << "INMATNINGSDEL\n" << string(12, '=') << endl;

  do
    {
      cout << "Mata in första pris: " << flush;
      cin >> start_price;
      if(start_price <= 0)
	{
	  cerr << "Fel: Priset måste vara positivt" << endl;
	}

    }
  while(start_price <= 0);

  
  do
    {
      cout << "Mata in sista pris: " << flush;
      cin >> max_price;
    if(max_price <= 0)
      {
	cout << "Fel: Priset måste vara positivt" << endl;
      }
    else if(max_price < start_price)
      {
	cout << "Fel: Priset måste vara större än det första priset" << endl;
      }

  }
  while(max_price < start_price);

  
  do
    {
      cout << "Mata in steglängd: " << flush;
      cin >> step;
      if(step <= 0)
	{

	  cout << "Fel: Stegvärdet måste större än noll" << endl;
	}
      else if(step > max_price - start_price)
	{
	  cout << "Fel: Stegvärdet är för stort" << endl;
	}
 
    }
  while(step > max_price - start_price || step <= 0);

  
  do
    {
      cout << "Mata in momsprocent: " << flush;
      cin >> tax_percent;
      if(tax_percent <= 0)
	{
	  cout << "Fel: momspricenten måste vara större än noll" << endl;
	}
    }
  while(tax_percent <= 0);

  cout << "MOMSTABELLEN\n" << string(12, '=') << endl;
  cout << right << setw(12) << "Pris" << setw(17) << "Moms"
       << setw(20) << "Pris med moms" << endl;
  cout << string(49, '-') << endl;

  while(start_price <= max_price)
    {
      // Komplettering: Ska indenteras rätt enligt 1-4
      cout << right << setw(12) << fixed << setprecision(2)
	   << start_price << setw(17) << setprecision(2)
	   << tax_calc(tax_percent, start_price) << setw(20)
	   << setprecision(2) << taxed_price(tax_percent, start_price)
	   << endl;

      start_price += step;
    }
  
  return 0;
}
