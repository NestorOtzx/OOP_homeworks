//
// Created by itsre on 16/03/2023.
//

#include "Huesped.h"


Huesped::Huesped(int documento, std::string nombre, std::string sexo, std::string fechaNacimiento,
                 std::string clinicaNombre, std::string ubicacionPaciente) {
    this->documento = documento;
    this->nombre = nombre;
    this->sexo = sexo;
    this->fechaNacimiento = fechaNacimiento;
    this->puntos=5; //Puntos iniciales
    this->clinicaNombre = clinicaNombre;
    this->ubicacionPaciente = ubicacionPaciente;
}

void Huesped::mostrarInfo() {
    std::cout<<"Hola, soy un huesped y mi nombre es: "<<nombre<<std::endl;
    std::cout<<"El paciente esta en la clinica: "<<clinicaNombre<<" en "<<ubicacionPaciente<<std::endl;
}

std::string Huesped::getNombre() {
    return nombre;
}
