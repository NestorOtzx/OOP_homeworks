//
// Created by itsre on 16/03/2023.
//

#include "Propietario.h"

Propietario::Propietario(int documento, std::string nombre, std::string sexo, std::string fechaNacimiento, Hogar hogar) {
    this->documento = documento;
    this->nombre = nombre;
    this->sexo = sexo;
    this->fechaNacimiento = fechaNacimiento;
    this->puntos=5; //Puntos iniciales
    this->recibeHuespedes = true;
    this->hogar = hogar;
}

void Propietario::setRecibeHuespedes(bool b) {
    this->recibeHuespedes = b;
}

void Propietario::mostrarInfo() {
    std::cout<<"Hola!, soy el propietario: "<<nombre<<std::endl;
    std::cout<<"Vivo en: "<<hogar.getDireccion()<<", "<<hogar.getCamas()<<" camas disponibles, "<<(hogar.getBebes() ? "Se" : "No se")<<" admiten bebes."<<std::endl;
    std::cout<<"Descripcion: "<<hogar.getDescripcion()<<std::endl;
    std::cout<<"Puntaje: "<<puntos<<std::endl;
}

bool Propietario::getRecibeHuespedes() {
    return recibeHuespedes;
}

std::string Propietario::getNombre() {
    return nombre;
}

float Propietario::getPuntos() {
    return puntos;
}

void Propietario::setPuntos(float puntos) {
    this->puntos = puntos;
}

Hogar Propietario::getHogar() {
    return hogar;
}
