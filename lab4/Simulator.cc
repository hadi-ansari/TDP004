#include <iostream>
#include <vector>
#include <string>

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
  n.charge += (p.charge - n.charge) / resistance * t;
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

void simulate(std::vector<Component*> n, int number, int print, double t)
{
  for( int i = 0; i < number; ++i)
    {
      for(Component* component: n)
	{
	  component -> simulate(t);
	}
    }
}

int main()
{
  Connection p, n;
  std::vector <Component*> net{};
  Battery B1{"Bat", 21, p, n};
  net.push_back(new Battery("Bat", 24.0, p, n));
  net.push_back(new Ressistor{"R1", 6.0, p, n});
  net.push_back(new Ressistor{"R2", 8.0, p, n});
  simulate(net, 1000, 10, 0.1);
  std::cout << "ok" << std::endl;
  //  std::cout << "P: " << p.charge << "\nN: " << n.charge << std::endl;
  return 0;
}
