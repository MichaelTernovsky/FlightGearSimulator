//
// Created by michael on 20/12/2019.
//

#include "Command.h"
#ifndef EX3__SLEEPCOMMAND_H_
#define EX3__SLEEPCOMMAND_H_

class SleepCommand : public Command {
 public:
  int execute(vector<string> lexerVector, int index);
};

#endif //EX3__SLEEPCOMMAND_H_