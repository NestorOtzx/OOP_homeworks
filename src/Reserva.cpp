//
// Created by itsre on 16/03/2023.
//

#include "Reserva.h"

Reserva::Reserva(Propietario * propietario, Huesped * huesped, std::string fechaInicio, std::string fechaFin) {
    this->propietario = propietario;
    this->huesped = huesped;
    this->fechaFin = fechaFin;
    this->fechaInicio = fechaInicio;
    propietario->setRecibeHuespedes(false);
}

Reserva::~Reserva() {
    this->propietario->setRecibeHuespedes(true);
}

void Reserva::mostrarInfo() {
    std::cout<<"Propietario: "<<propietario->getNombre()<<std::endl;
    std::cout<<"Huesped: "<<huesped->getNombre()<<std::endl;
    std::cout<<"Fecha de inicio: "<<fechaInicio<<std::endl;
    std::cout<<"Fecha de fin: "<<fechaFin<<std::endl;
}
