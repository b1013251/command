#include <string>
using namespace std;

#define  STR(var)  #var

enum CommandType {
  RUN = 0,
  ROTATE = 1
};

class Command {
private:
  string rawData;
  CommandType type; 
  double arg;
  string      stringFromType(CommandType);
  CommandType typeFromString(string);
public:
  Command(CommandType, double);
  Command(string);
  ~Command();
  void parse();
  string toString();
};
