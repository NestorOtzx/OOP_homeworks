//
// Created by itsre on 16/03/2023.
//

#ifndef OOP_HOMEWORKS_RESERVA_H
#define OOP_HOMEWORKS_RESERVA_H
#include <iostream>
#include "Propietario.h"
#include "Huesped.h"

class Reserva {
private:
    Propietario * propietario;
    Huesped * huesped;
    std::string fechaInicio, fechaFin;

public:
    Reserva() = default;
    Reserva(Propietario * propietario, Huesped * huesped, std::string fechaInicio, std::string fechaFin);
    ~Reserva();

    void mostrarInfo();
};


#endif //OOP_HOMEWORKS_RESERVA_H
