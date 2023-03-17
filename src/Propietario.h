//
// Created by itsre on 16/03/2023.
//

#ifndef OOP_HOMEWORKS_PROPIETARIO_H
#define OOP_HOMEWORKS_PROPIETARIO_H
#include <iostream>
#include "Hogar.h"

class Propietario {
private:
    //info
    int documento;
    std::string nombre, sexo, fechaNacimiento;
    float puntos;
    Hogar hogar;


    bool recibeHuespedes;
public:
    Propietario() { documento = 0; nombre = "", sexo = "", fechaNacimiento = "", puntos = 5, recibeHuespedes = true; }
    Propietario(int documento, std::string nombre,std::string sexo,std::string fechaNacimiento, Hogar hogar);

    //getters
    std::string getNombre();
    bool getRecibeHuespedes();
    float getPuntos();
    Hogar getHogar();

    //setters
    void setPuntos(float puntos);
    void setRecibeHuespedes(bool b);


    void mostrarInfo();
};


#endif //OOP_HOMEWORKS_PROPIETARIO_H
