//
// Created by michael on 21/12/2019.
//

#include "WhileCommand.h"
#include "VarCommand.h"

int IfCommand::execute(vector<string> lexerVector, int index) {

  int backUpIndex = index;
  int tmpIndex = 0;// return index

  string leftExp = lexerVector[index + 1];
  string oper = lexerVector[index + 2];
  string rightExp = lexerVector[index + 3];

  VarCommand *v = new VarCommand();
  Expression *newLeftExp = v->createExp(leftExp);
  Expression *newRightExp = v->createExp(rightExp);

  // creating the bollean expression
  BooleanExpression *boolExp = new BooleanExpression(newLeftExp, newRightExp, oper);

  // running the loop
  if (boolExp->calculate() == 1) {
    index += 5;
    // executing the commands in the while loop
    while (index < lexerVector.size() && lexerVector[index] != "}") {
      tmpIndex = 0;

      if (commandsMap.find(lexerVector[index]) != commandsMap.end()) {
        Command *command = commandsMap.find(lexerVector[index])->second;
        tmpIndex += command->execute(lexerVector, index);
        index += tmpIndex;
      } else {
        // the rest of the cases: x = 4
        Command *command = commandsMap.find("var")->second;
        tmpIndex += command->execute(lexerVector, index);
        index += tmpIndex;
      }
      cout << "while index: ";
      cout << index << endl;
    }

    newLeftExp = v->createExp(leftExp);
    newRightExp = v->createExp(rightExp);

    // creating the boolean expression
    boolExp = new BooleanExpression(newLeftExp, newRightExp, oper);

    index = backUpIndex;
  }

  return tmpIndex + 6;
}