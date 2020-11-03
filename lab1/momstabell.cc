#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

float tax_calc(float tax, float price){
  float tax_value{};
  tax_value = price * tax / 100;
  
  return tax_value;
}

float taxed_price(float tax, float price){
  float taxed_price{};
  taxed_price = price + tax_calc(tax, price);
  
  return taxed_price;
}
int main(){
  float start_price{};
  float max_price{};
  float step{};
  float tax_percent{};

  cout << "INMATNINGSDEL" << endl << "============" << endl;

  do{
    cout << "Mata in första pris: " << flush;
    cin >> start_price;
    if(start_price <= 0){
      cout << "Fel: Priset måste vara positivt" << endl;
    }

  }
  
  while(start_price <= 0);

  do{
  cout << "Mata in sista pris: " << flush;
  cin >> max_price;

    if(max_price <= 0){
      cout << "Fel: Priset måste vara positivt" << endl;
    }

    else if(max_price < start_price){
      cout << "Fel: Priset måste vara större än det första priset" << endl;
    }

  }
  
  while(max_price < start_price);
 
  cout << start_price << " " << max_price << endl;

  do{
  cout << "Mata in steglängd: " << flush;
  cin >> step;
  if(step <= 0){
      cout << "Fel: Stegvärdet måste större än noll" << endl;
    }

    else if(step > max_price - start_price){
      cout << "Fel: Stegvärdet är för stort" << endl;
    }
 
  }
  while(step > max_price - start_price || step <= 0);
  
  do{
  cout << "Mata in momsprocent: " << flush;
  cin >> tax_percent;

  if(tax_percent <= 0){
    cout << "Fel: momspricenten måste vara större än noll" << endl;
  }
  }
  while(tax_percent <= 0);
  cout << "MOMSTABELLEN" << endl << "============" << endl;
  cout << right << setw(12) << "Pris" << setw(17) << "Moms"
       << setw(20) << "Pris med moms" << endl;
  cout << "-------------------------------------------------"<< endl;

  while(start_price <= max_price){
    
    cout << right << setw(11) << fixed << setprecision(2) << start_price << "  " << step
	 << setw(17) << setprecision(2) << tax_calc(tax_percent, start_price)
	 << setw(15) << setprecision(2) << taxed_price(tax_percent, start_price) << endl;

    start_price += step;
  }
  
  return 0;
}
