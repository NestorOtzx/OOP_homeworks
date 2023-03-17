//
// Created by itsre on 16/03/2023.
//

#include "Evaluacion.h"

Evaluacion::Evaluacion(Huesped * huesped, Propietario * propietario, std::string fecha, std::string comentario,  float puntaje) {
    this->huesped = huesped;
    this->propietario = propietario;
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->comentario = comentario;
}

void Evaluacion::mostrarInfo() {
    std::cout<<"Fecha de hospedaje: "<<fecha<<std::endl;
    std::cout<<"Evaluacion de "<<huesped->getNombre()<<" para "<<propietario->getNombre()<<std::endl;
    std::cout<<"Comentarios: "<<std::endl<<comentario<<std::endl;
    std::cout<<"Puntaje final: "<<puntaje<<std::endl;
}
