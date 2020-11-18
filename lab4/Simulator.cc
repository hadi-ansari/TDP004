#include <iostream>
#include <string>

#include "Simulator.h"

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

Component::Component(Connection& p, Connection& n)
  :p{p}, n{n}
{}

// void Component::set_p(double value)
// {
//   p.charge = value;
// }
// void Component::set_n(double value)
// {
//   n.charge = value;
// }
// double Component::get_p()const
// {
//   return p.charge;
// }
// double Component::get_n()const
// {
//   return n.charge;
// }
Ressistor::Ressistor(std::string name, double resistance, Connection& p, Connection& n)
  : Component::Component{p, n}, name{name}, resistance{resistance}
{}

void Ressistor::simulate(double t)
{
  
  n.charge += (p.charge - n.charge) / resistance * t;
  std::cout << n.charge << std::endl;
}

int main()
{
  Connection p{24}, n{0};
  Ressistor r{"R1", 2, p, n};
  r.simulate(0.1);
  std::cout << "hej" << std::endl;
  return 0;
}
