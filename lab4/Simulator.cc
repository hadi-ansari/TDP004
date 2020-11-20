#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "Simulator.h"

/*       Connection          */
struct Connection
{
  Connection()
    : charge{0}
  {}
  
  double charge;
};


/*      Component          */
Component::Component(std::string name, Connection& connection1, Connection& connection2)
  :name{name}, connection1{connection1}, connection2{connection2}
{}


/*       Resistor          */
Resistor::Resistor(std::string name, double resistance,
		   Connection& connection1, Connection& connection2)
  : Component::Component{name, connection1, connection2}, resistance{resistance}
{}

void Resistor::simulate(double const time)
{
  double temp{};
  
  if(connection2.charge < connection1.charge)
    {
      temp = (connection1.charge - connection2.charge) / resistance * time;
      connection2.charge += temp;
      connection1.charge -= temp;
      
    }
  else
    {
      temp = (connection2.charge - connection1.charge) / resistance * time;
      connection1.charge += temp;
      connection2.charge -= temp;
    }
}
double Resistor::get_voltage() const
{
  return connection1.charge - connection2.charge;
}
double Resistor::get_current() const
{
  return get_voltage() / resistance; 
}


/*       Battery          */
Battery::Battery(std::string name, double voltage, Connection& connection1,
		 Connection& connection2)
  : Component::Component{name, connection1, connection2}, voltage{voltage}
{}
void Battery::simulate(double const time)
{
  connection1.charge = voltage;
  connection2.charge = 0;
}
double Battery::get_voltage() const
{
  return voltage;
}
double Battery::get_current() const
{
  return 0;
}

/*       Capacitor          */
Capacitor::Capacitor(std::string name, double capacity,
		     Connection& connection1, Connection& connection2)
  : Component::Component{name, connection1, connection2}, capacity{capacity}, load{0}
{}
void Capacitor::simulate(double time)
{
  double temp{};
  
  if(connection2.charge < connection1.charge)
    {
      temp = capacity * (connection1.charge - connection2.charge - load) * time;
      connection2.charge += temp;
      load += temp;
      connection1.charge -= temp;
    }
  else
    {
      temp = capacity * (connection2.charge - connection1.charge - load) * time;
      connection1.charge += temp;
      load += temp;
      connection2.charge -= temp;
    }
}
double Capacitor::get_voltage() const
{
  return connection1.charge - connection2.charge;
}
double Capacitor::get_current() const
{
  return capacity * ( get_voltage() - load);
}




void print_statistics(std::vector<Component*>& net)
{
  for(Component* component: net)
    {
      std::cout << std::fixed << std::setprecision(2) << std::setw(6)
		<< component -> get_voltage() << std::setw(6)
		<< component -> get_current();
    }
  std::cout << std::endl;
}

void simulate(std::vector<Component*>& net, int iteration, int number, double t)
{
  int counter {0};

  //Skriver ut header
  {
    for (Component* component: net) 
      { 
	std::cout << std::setw(12) << component -> name;
      }
    std::cout << std::endl;

    int size = net.size();
    for (int i= 0; i < size; ++i) 
      {
	std::cout << std::setw(6) <<"volt" << std::setw(6) << "curr";
      }
    std::cout << std::endl;
  }
  //
  
  for( int i = 0; i < iteration; ++i)
    {
      ++counter;
      for(Component* component: net)
  	{
  	  component -> simulate(t);
  	}
      if(counter == iteration / number)
	{
	  print_statistics(net);
	  counter = 0;
  	}
    }
}
// int arg_error_check(char* argv[], int arg1, int arg2, double arg3, double arg4)
// {
// try
//   {
//     arg1 = std::stoi(argv[1]);
//     arg2 = std::stoi(argv[2]);
//     arg3 = std::stod(argv[3]);
//     arg4 = std::stod(argv[4]);
//   }

//   catch (std::invalid_argument const& ia_error)
//   {
//     std::cerr << "Felaktig inmatning av argument. Mata endast in heltal eller decimaler." << std::endl;
//     exit(1);
//   }
  
// try
//   {
//     if (arg1 < 0 || arg2 < 0 || arg3 < 0 || arg4 < 0)
//     {
//       throw 1;
//     }
//   }
//   catch (int error_code)
//   {
//     std::cerr << "Felaktig inmatning av argument. Talen måste vara positiva"<< std::endl;
//     exit(1);
//   }
//   return 0;
// }
