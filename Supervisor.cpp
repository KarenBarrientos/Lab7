#include "Supervisor.h"
#include "Usuarios.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Supervisor::Supervisor(string Nom_Usuario,string Correo,string Password,int Cont):Usuarios(Nom_Usuario,Correo,Password){
  this->Cont = Cont;
}
Supervisor::~Supervisor(){
}

string Supervisor::toString(){
	stringstream ss;
	ss << Usuarios::toString();
	return ss.str();
}