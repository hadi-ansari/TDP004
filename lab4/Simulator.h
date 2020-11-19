#ifndef SIMULATOR_H
#define SIMULATOR_H

struct Connection;

class Component
{
 public:
  Component(std::string, Connection& ,Connection& );
  virtual void simulate(double)=0;
  virtual double get_voltage()=0;
  virtual double get_current()=0;

  std::string name;
  Connection& p;
  Connection& n;
};

class Resistor: public Component
{
 public:
  Resistor(std::string , double, Connection&, Connection&);
  void simulate(double ) override;
  double get_voltage() override;
  double get_current() override;
  
 private:
  double resistance;
};

class Battery: public Component
{
public:
  Battery(std::string , double, Connection&, Connection&);
  void simulate(double) override;
  double get_voltage() override;
  double get_current() override;
  void set_voltage(double const);
  
private:
  double voltage;
  
};
  
class Capacitor: public Component
{
 public:
  Capacitor(std::string , double, Connection&, Connection&);
  void simulate(double) override;
  double get_voltage() override;
  double get_current() override;
  
 private:
  double capacity;
  double load;
};

#endif
