#ifndef SIMULATOR_H
#define SIMULATOR_H

/* Komplettering
 * Alla datamedlemmar i Component är public de ska 
 * vara protected eller private.
*/

// Komplettering: 5-4

// Komplettering: Se även main.cc

/* Komplettering
 * Ni får en massa varingar vid kompileringen, Tror alla
 * relaterade till att ni inte har en destruktor.
 * alias w++17="\g++ -std=c++17 -Wall -Wextra -pedantic -g -Weffc++"
*/

/* Komplettering
 * Ni har ingen destruktor.
*/

/* Komplettering
 * Ni har minnesläckor i ert program.
 * Testa att köra programmet med valgrind.
*/

struct Connection
{
  Connection()
    : charge{0}
  {}
  
  double charge;
};


class Component
{
 public:
  Component(std::string const&, Connection&, Connection& );
	/* Komplettering
	 * Var konsekventa med mellanrum
	 * i detta fallet mellanrum mellan () och const.
	 * Även const=0 -> const = 0;
	*/
  virtual ~Component() = default;
  
  virtual void simulate(double const) = 0;
  virtual double get_voltage() const = 0;
  virtual double get_current() const = 0;
  std::string get_name() const;

protected:
  std::string const name;
  Connection& connection1;
  Connection& connection2;
};

class Resistor: public Component
{
 public:
  Resistor(std::string , double, Connection&, Connection& );
  ~Resistor() = default;
  
  void simulate(double const ) override;
  double get_voltage() const override;
  double get_current() const override;
  
 private:
  double const resistance;
};

class Battery: public Component
{
public:
  Battery(std::string , double, Connection&, Connection& );
  ~Battery() = default;
  
  void simulate(double const) override;
  double get_voltage() const override;
  double get_current() const override;
  
private:
  double const voltage;
};
  
class Capacitor: public Component
{
 public:
  Capacitor(std::string , double, Connection&, Connection& );
  ~Capacitor() = default;
  
  void simulate(double const) override;
  double get_voltage() const override;
  double get_current() const override;
  
 private:
  double const capacity;
  double load;
};

void print_statistics(std::vector<Component*> const&);
void simulate(std::vector<Component*>  const& net, int iteration, int number, double time);
void clear(std::vector<Component*> & net);
#endif
