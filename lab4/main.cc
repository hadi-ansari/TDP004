#include <iostream>
#include <vector>
#include <stdexcept>

#include "Simulator.h"

// int argc, char* argv[]

/* Komplettering
 * Undantags och throw ska inte användas som
 * en slags kontrollstruktur. Att fånga undantag
 * från en funktion är korrekt, men inte att göra
 * på följande sätt:
 * Fel:
 * if (argc < 5) {
 *	throw 1;
 * }

 * För att sedan fånga ettan längre ner i koden.
 *
 * Rätt: Detta kan även läggas utanför try catch.
 * if (argc < 5) {
 *	std::cerr << ....
 *	return 1;
 * }
 * Det blir också en onödigt komplicerad och dyr kod.
*/

int main(int argc, char* argv[])
{
  int iterations{};
  int printed_its{};
  double time_per_it{};
  double battery_voltage{};
  
  if(argc < 5)
    {
      std::cerr << "Fel! Argument saknas."
		    << std::endl;
      return 1;
    }
  
  try
    {
      iterations = std::stoi(argv[1]);
      printed_its = std::stoi(argv[2]);
      time_per_it = std::stod(argv[3]);
      battery_voltage = std::stod(argv[4]);
    }
  catch (std::invalid_argument const& ia_error)
    {
      std::cerr << "Felaktig inmatning av argument. Mata endast in heltal eller decimaler."
		<< std::endl;
      return 1;
    }

  if( iterations < 0 || printed_its < 0 || time_per_it < 0 || battery_voltage < 0)
    {
      std::cerr << "Felaktig inmatning av argument. Talen måste vara positiva"
		<< std::endl;
      return 1;
    }

  std::cout << std::endl;
  // första kretsen
  Connection P, N, R124, R23, R12;
  std::vector <Component*> net{};

  net.push_back(new Battery("Bat", battery_voltage, P, N));
  net.push_back(new Resistor{"R1", 6.0, P, R124});
  net.push_back(new Resistor{"R2", 4.0, R124, R23});
  net.push_back(new Resistor{"R3", 8.0, R23, N});
  net.push_back(new Resistor{"R4", 12.0, R124, N});
  simulate(net, iterations, printed_its, time_per_it);

  for (Component* component: net) 
    { 
      delete component;
    }

  net.clear();
  std::cout << std::endl;
  // andra kretsen  
  Connection L, R;  

  net.push_back(new Battery("Bat", battery_voltage, P, N));
  net.push_back(new Resistor("R1", 150.0, P, L));
  net.push_back(new Resistor("R2", 50.0, P, R));
  net.push_back(new Resistor("R3", 100.0, R, L));
  net.push_back(new Resistor("R4", 300.0, L, N));
  net.push_back(new Resistor("R5", 250.0, R, N));
  simulate(net, iterations, printed_its, time_per_it);

  for (Component* component: net) 
    { 
      delete component;
    }
  L.charge = 0;
  R.charge = 0;
  net.clear();
  std::cout << std::endl;

  // tredje kretsen
  net.push_back(new Battery("Bat", battery_voltage, P, N));
  net.push_back(new Resistor("R1", 150.0, P, L));
  net.push_back(new Resistor("R2", 50.0, P, R));
  net.push_back(new Capacitor("C3", 1.0, R, L));
  net.push_back(new Resistor("R4", 300.0, L, N));
  net.push_back(new Capacitor("C5", 0.75, R, N));
  simulate(net, iterations, printed_its, time_per_it);

  for (Component* component: net) 
    { 
      delete component;
    }
  return 0;
}
