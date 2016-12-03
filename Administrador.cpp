#include "Administrador.h"
#include "Usuarios.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Administrador::Administrador(string Nom_Usuario,string Correo,string Password,string Tipo,string Fecha):Usuarios(Nom_Usuario,Correo,Password,Tipo){
  this->Fecha = Fecha;
}

Administrador::~Administrador(){
}

string Administrador::getFecha(){
	return Fecha;
}

string Administrador::toString(){
	stringstream ss;
	ss << Usuarios::toString()<<" "<<Fecha;
	return ss.str();
}