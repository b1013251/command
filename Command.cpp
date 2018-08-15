#include "Command.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Command::Command(string str) {
  this->rawData = str;
  this->parse();
}

Command::Command(CommandType type, double arg) {
  this->type = type;
  this->arg  = arg;
}

Command::~Command() {
}

void Command::parse() {
  char delimiter = '|';
  string field;
  vector<string> result;

  istringstream stream(this->rawData);
  while (getline(stream, field, delimiter)) {
      result.push_back(field);
  }
  this->type = this->typeFromString(result[0]);
  this->arg = stod(result[1]);
}

string Command::toString() {
  string str = "";
  str.append(this->stringFromType(this->type));
  str.append("|");
  str.append(to_string((int)this->arg));
  return str;
}

string Command::stringFromType(CommandType type) {
  switch(type) {
    case RUN:
      return "RUN";
    case ROTATE:
      return "ROTATE";
    default:
      return "DEFAULT";
  }
}

CommandType Command::typeFromString(string str) {
  if (str == "RUN") {
    return RUN;
  } else if (str == "ROTATE") {
    return ROTATE;
  }
}
