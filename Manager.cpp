#include "Manager.h"
#include "Usuarios.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Manager::Manager(string Nom_Usuario,string Correo,string Password,string Tipo,double Sueldo):Usuarios(Nom_Usuario,Correo,Password,Tipo){
  this->Sueldo = Sueldo;
}

Manager::~Manager(){
}

double Manager::getSueldo(){
	return Sueldo;
}

string Manager::toString(){
	stringstream ss;
	ss << Usuarios::toString()<<" "<<Sueldo;
	return ss.str();
}