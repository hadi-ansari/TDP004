#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "Simulator.h"



/*       Connection          */
struct Connection
{
  Connection()
    : charge{0}
  {}
  Connection(double v)
    : charge{v}
  {}
  
  double charge;
};


/*      Component          */

Component::Component(std::string name, Connection& p, Connection& n)
  :name{name}, p{p}, n{n}
{}


/*       Resistor          */
Resistor::Resistor(std::string name, double resistance, Connection& p, Connection& n)
  : Component::Component{name, p, n}, resistance{resistance}
{}

void Resistor::simulate(double t)
{
  double temp{};
  if(n.charge < p.charge)
    {
      temp = (p.charge - n.charge) / resistance * t;
      n.charge += temp;
      p.charge -= temp;
      
    }
  else
    {
      temp = (n.charge - p.charge) / resistance * t;
      p.charge += temp;
      n.charge -= temp;
    }
}
double Resistor::get_voltage()
{
  return p.charge - n.charge;
}
double Resistor::get_current()
{
  return get_voltage() / resistance; 
}


/*       Battery          */
Battery::Battery(std::string name, double voltage, Connection& p, Connection& n)
  : Component::Component{name, p, n}, voltage{voltage}
{}
void Battery::simulate(double t)
{
   p.charge = voltage;
   n.charge = 0;
}
double Battery::get_voltage()
{
  return voltage;
}
double Battery::get_current()
{
  return 0;
}
void Battery::set_voltage(double const v)
{
  voltage = v;
}

/*       Capacitor          */
Capacitor::Capacitor(std::string name, double capacity,
		     Connection& p, Connection& n)
  : Component::Component{name, p, n}, capacity{capacity}, load{0}
{}
void Capacitor::simulate(double t)
{
  double temp{};
  
  if(n.charge < p.charge)
    {
      temp = capacity * (p.charge - n.charge - load) * t;
      n.charge += temp;
      load += temp;
      p.charge -= temp;
    }
  else
    {
      temp = capacity * (n.charge - p.charge - load) * t;
      p.charge += temp;
      load += temp;
      n.charge -= temp;
    }
}
double Capacitor::get_voltage()
{
  return p.charge - n.charge;
}
double Capacitor::get_current()
{
  return capacity * ( get_voltage() - load);
}




void print(std::vector<Component*>& n)
{
  for(Component* component: n)
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
      for(Component* component: net)
  	{
  	  component -> simulate(t);
  	}
      if(counter == iteration / number)
	{
	  print(net);
	  counter = 0;
  	}
      ++counter;
    }
}

int arg_error_check(char* argv[], int arg1, int arg2, double arg3, double arg4)
{
try
  {
    arg1 = std::stoi(argv[1]);
    arg2 = std::stoi(argv[2]);
    arg3 = std::stod(argv[3]);
    arg4 = std::stod(argv[4]);
  }

  catch (std::invalid_argument const& ia_error)
  {
    std::cerr << "Felaktig inmatning av argument. Mata endast in heltal eller decimaler." << std::endl;
    exit(1);
  }
  
try
  {
    if (arg1 < 0 || arg2 < 0 || arg3 < 0 || arg4 < 0)
    {
      throw 1;
    }
  }
  catch (int error_code)
  {
    std::cerr << "Felaktig inmatning av argument. Talen måste vara positiva"<< std::endl;
    exit(1);
  }
  return 0;

}
int main(int argc, char* argv[])
{
    int iterations{};
    int printed_its{};
    double time_per_it{};
    double battery_current{};

    arg_error_check(argv, iterations, printed_its, time_per_it, battery_current);

    iterations = std::stoi(argv[1]);
    printed_its = std::stoi(argv[2]);
    time_per_it = std::stod(argv[3]);
    battery_current = std::stod(argv[4]);



  // Connection P, N, R124, R23, R12;
  // std::vector <Component*> net{};

  // net.push_back(new Battery("Bat", battery_current, P, N));
  // net.push_back(new Resistor{"R1", 6.0, P, R124});
  // net.push_back(new Resistor{"R2", 4.0, R124, R23});
  // net.push_back(new Resistor{"R3", 8.0, R23, N});
  // net.push_back(new Resistor{"R4", 12.0, R124, N});
   
  Connection P, N, L, R;       
  std::vector <Component*> net{};

  net.push_back(new Battery("Bat", battery_current, P, N));
  net.push_back(new Resistor("R1", 150.0, P, L));
  net.push_back(new Resistor("R2", 50.0, P, R));
  net.push_back(new Resistor("R3", 100.0, R, L));
  net.push_back(new Resistor("R4", 300.0, L, N));
  net.push_back(new Resistor("R5", 250.0, R, N));
  
  // Connection P, N, L, R;
  // std::vector <Component*> net{};
  // net.push_back(new Battery("Bat", battery_current, P, N));
  // net.push_back(new Resistor("R1", 150.0, P, L));
  // net.push_back(new Resistor("R2", 50.0, P, R));
  // net.push_back(new Capacitor("C3", 1.0, R, L));
  // net.push_back(new Resistor("R4", 300.0, L, N));
  // net.push_back(new Capacitor("C5", 0.75, R, N));

  // std::cout << "Iterations: " << iterations << " Lines: " << printed_its << " Time per iteration: " << time_per_it << " Battery current: " << battery_current << std::endl;

   simulate(net, iterations, printed_its, time_per_it);

  
  return 0;
}
