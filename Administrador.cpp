#include "Administrador.h"
#include "Usuarios.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Administrador::Administrador(string Nom_Usuario,string Correo,string Password,string Fecha):Usuarios(Nom_Usuario,Correo,Password){
  this->Fecha = Fecha;
}
Administrador::~Administrador(){
}

string Administrador::toString(){
	stringstream ss;
	ss << Usuarios::toString();
	return ss.str();
}