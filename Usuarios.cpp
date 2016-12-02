#include "Usuarios.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Usuarios::Usuarios(string Nom_Usuario,string Correo,string Password):Nom_Usuario(Nom_Usuario),Correo(Correo), Password(Password){
}

string Usuarios::getNom_Usuario(){
	return Nom_Usuario;
}

string Usuarios::getCorreo(){
	return Correo;
}

string Usuarios::getPassword(){
	return Password;
}

Usuarios::~Usuarios(){
}

string Usuarios::toString(){
	stringstream ss;
	ss << "Usuarios: " << Nom_Usuario << ", " << Correo<< ", "<<Password;
	return ss.str();
}
