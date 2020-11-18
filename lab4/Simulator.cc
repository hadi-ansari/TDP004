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
  Connection(double v)
    : charge{v}
  {}
  
  double charge;
};


/*      Component          */

Component::Component(std::string name, Connection& p, Connection& n)
  :name{name}, p{p}, n{n}
{}


/*       Ressistor          */
Ressistor::Ressistor(std::string name, double resistance, Connection& p, Connection& n)
  : Component::Component{name, p, n}, resistance{resistance}
{}

void Ressistor::simulate(double t)
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
double Ressistor::get_voltage()
{
  return p.charge - n.charge;
}
double Ressistor::get_current()
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
		     double load, Connection& p, Connection& n)
  : Component::Component{name, p, n}, capacity{capacity}, load{load}
{}
void Capacitor::simulate(double t)
{
  n.charge += capacity * (p.charge - n.charge) * t;
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
  // std::cout << std::setprecision(4) << "\np: " << n[0] -> p.charge << "  R124: "<< n[1] -> n.charge
  // 	     << "  R23: "<< n[2] -> n.charge << std::endl;
  std::cout <<  std::endl;

}

void simulate(std::vector<Component*>& n, int iteration, int number, double t)
{
  // std::cout  << n[0] -> p.charge << "  "<< n[0] -> n.charge << std::endl;
  int counter {0};
  
  for(Component* component: n)
    {
      std::cout << std::setw(12) << component -> name;
    }
  std::cout << std::endl;
  for(Component* component: n)
    {
      std::cout << std::setw(6) <<"volt" << std::setw(6) << "curr";
    }
  std::cout << std::endl;
  for( int i = 0; i < iteration; ++i)
    {
      for(Component* component: n)
  	{
  	  component -> simulate(t);
  	}
      if(counter == iteration / number)
	{
	  print(n);
	  counter = 0;
  	}
      ++counter;
    }
}

int main()
{
  Connection p, n, R124, R23, R12;
  std::vector <Component*> net{};

  net.push_back(new Battery("Bat", 24.0, p, n));
  net.push_back(new Ressistor{"R1", 6.0, p, R124});
  net.push_back(new Ressistor{"R2", 4.0, R124, R23});
  net.push_back(new Ressistor{"R3", 8.0, R23, n});
  net.push_back(new Ressistor{"R4", 12.0, R124, n});
   

  simulate(net, 200000, 10, 0.01);
  
  
  return 0;
}
