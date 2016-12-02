#include "Manager.h"
#include "Usuarios.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Manager::Manager(string Nom_Usuario,string Correo,string Password,double Sueldo):Usuarios(Nom_Usuario,Correo,Password){
  this->Sueldo = Sueldo;
}
Manager::~Manager(){
}

string Manager::toString(){
	stringstream ss;
	ss << Usuarios::toString();
	return ss.str();
}