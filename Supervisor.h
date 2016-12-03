#pragma once
#include "Supervisor.h"
#include "Usuarios.h"
#include <string>
using std::string;
 
class Supervisor : public Usuarios{
    int Cont;
  public:
    Supervisor(string,string,string,string,int=0);
    int getCont();
    virtual ~Supervisor();
    virtual string toString();
};