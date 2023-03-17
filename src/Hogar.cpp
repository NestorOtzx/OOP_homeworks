//
// Created by itsre on 16/03/2023.
//

#include "Hogar.h"

Hogar::Hogar(std::string direccion, int camas, bool bebes, std::string descripcion) {
    this->direccion = direccion;
    this->camas = camas;
    this->bebes = bebes;
    this->descripcion = descripcion;
}

std::string Hogar::getDireccion() {
    return direccion;
}

int Hogar::getCamas() {
    return this->camas;
}

bool Hogar::getBebes() {
    return this->bebes;
}

std::string Hogar::getDescripcion() {
    return this->descripcion;
}
