#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

int main(void) {
  cout << "文字列パーサー" << endl;

  Command command(ROTATE, 90);
  cout << command.toString() << endl;

  string cmd2 = "RUN|-30";
  Command command2(cmd2);
  cout << command2.toString() << endl;

  string cmd3 = "ROTATE|-90";
  Command command3(cmd3);
  cout << command3.toString() << endl;

  return 0;
}
