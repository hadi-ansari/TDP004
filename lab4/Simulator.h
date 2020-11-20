#ifndef SIMULATOR_H
#define SIMULATOR_H

struct Connection;

class Component
{
 public:
  Component(std::string, Connection& ,Connection& );
  virtual void simulate(double const)=0;
  virtual double get_voltage()const=0;
  virtual double get_current()const=0;

  std::string const name;
  Connection& connection1;
  Connection& connection2;
};

class Resistor: public Component
{
 public:
  Resistor(std::string , double, Connection&, Connection&);
  void simulate(double const ) override;
  double get_voltage() const override;
  double get_current() const override;
  
 private:
  double const resistance;
};

class Battery: public Component
{
public:
  Battery(std::string , double, Connection&, Connection&);
  void simulate(double const) override;
  double get_voltage() const override;
  double get_current() const override;
  
private:
  double const voltage;
};
  
class Capacitor: public Component
{
 public:
  Capacitor(std::string , double, Connection&, Connection&);
  void simulate(double const) override;
  double get_voltage() const override;
  double get_current() const override;
  
 private:
  double const capacity;
  double load;
};

#endif
