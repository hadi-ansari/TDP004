#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "Simulator.cc"

// int argc, char* argv[]

int main(int argc, char* argv[])
{
  // std::cout << argv[0] << " " << argv[1] << " " << argv[2] << " "  << argv[3]
  // 	    << " "  << argv[4] << std::endl;

  // std::cout << argv[0] << " " << std::stoi(argv[1]) << " " << std::stoi(argv[2])
  // 	    << " "  << std::stod(argv[3]) << " "  << std::stod(argv[4]) << std::endl;

  int iterations{};
  int printed_its{};
  double time_per_it{};
  double battery_voltage{};
  
  try
    {
      if(argc < 5)
	{
	  throw 1;
	}
      
      iterations = std::stoi(argv[1]);
      printed_its = std::stoi(argv[2]);
      time_per_it = std::stod(argv[3]);
      battery_voltage = std::stod(argv[4]);

      if (iterations < 0 || printed_its < 0 || time_per_it < 0 || battery_voltage < 0)
	{
	  throw 2;
	}

    }
  catch (std::invalid_argument const& ia_error)
    {
      std::cerr << "Felaktig inmatning av argument. Mata endast in heltal eller decimaler."
		<< std::endl;
      return 1;
    }
  catch (int exeption)
    {
      if(exeption == 1)
	{
	  std::cerr << "Fel! Argument saknas."
		    << std::endl;	  
	}
      else if(exeption == 2)
	{
	  std::cerr << "Felaktig inmatning av argument. Talen måste vara positiva"
		    << std::endl;
	}
      return 1;
    }

    // arg_error_check(argv, iterations, printed_its, time_per_it, battery_current);

    // iterations = std::stoi(argv[1]);
    // printed_its = std::stoi(argv[2]);
    // time_per_it = std::stod(argv[3]);
    // battery_current = std::stod(argv[4]);



  Connection P, N, R124, R23, R12;
  std::vector <Component*> net{};

  net.push_back(new Battery("Bat", battery_voltage, P, N));
  net.push_back(new Resistor{"R1", 6.0, P, R124});
  net.push_back(new Resistor{"R2", 4.0, R124, R23});
  net.push_back(new Resistor{"R3", 8.0, R23, N});
  net.push_back(new Resistor{"R4", 12.0, R124, N});
  simulate(net, iterations, printed_its, time_per_it);

  P.charge = 0;
  N.charge = 0;
  net.clear();
  std::cout << std::endl;
  
  Connection L, R;  

  net.push_back(new Battery("Bat", battery_voltage, P, N));
  net.push_back(new Resistor("R1", 150.0, P, L));
  net.push_back(new Resistor("R2", 50.0, P, R));
  net.push_back(new Resistor("R3", 100.0, R, L));
  net.push_back(new Resistor("R4", 300.0, L, N));
  net.push_back(new Resistor("R5", 250.0, R, N));
  simulate(net, iterations, printed_its, time_per_it);

  P.charge = 0;
  N.charge = 0;
  L.charge = 0;
  R.charge = 0;
  net.clear();
  std::cout << std::endl;
  
  net.push_back(new Battery("Bat", battery_voltage, P, N));
  net.push_back(new Resistor("R1", 150.0, P, L));
  net.push_back(new Resistor("R2", 50.0, P, R));
  net.push_back(new Capacitor("C3", 1.0, R, L));
  net.push_back(new Resistor("R4", 300.0, L, N));
  net.push_back(new Capacitor("C5", 0.75, R, N));
  simulate(net, iterations, printed_its, time_per_it);

  return 0;
}
