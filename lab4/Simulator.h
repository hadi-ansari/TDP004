#ifndef SIMULATOR_H
#define SIMULATOR_H

struct Connection;

class Component
{
 public:
  Component(Connection& , Connection& );
  virtual void simulate(double)=0;
  // void set_p(double );
  // void set_n(double );
  // double get_p()const;
  // double get_n()const;
  double current;
  double voltage;
  Connection& p;
  Connection& n;
};

class Ressistor: public Component
{
 public:
  Ressistor(std::string , double, Connection& , Connection&);
  void simulate(double ) override;
 private:
  std::string name;
  double resistance;
};

// class Capacitor: public Component
// {
//  public:
  
//  private:
  
// };

#endif
