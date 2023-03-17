//
// Created by itsre on 16/03/2023.
//

#ifndef OOP_HOMEWORKS_EVALUACION_H
#define OOP_HOMEWORKS_EVALUACION_H
#include <iostream>
#include "Propietario.h"
#include "Huesped.h"


class Evaluacion {
private:
    Propietario * propietario;
    Huesped * huesped;
    std::string fecha, comentario;
    float puntaje;

public:
    Evaluacion()=default;
    Evaluacion(Huesped * huesped, Propietario * propietario, std::string fecha, std::string comentario, float puntaje);

    void mostrarInfo();
};


#endif //OOP_HOMEWORKS_EVALUACION_H
