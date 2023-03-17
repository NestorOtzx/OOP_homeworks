//
// Created by itsre on 16/03/2023.
//

#ifndef OOP_HOMEWORKS_HUESPED_H
#define OOP_HOMEWORKS_HUESPED_H
#include <iostream>


class Huesped {
private:
    //info
    int documento;
    std::string nombre, sexo, fechaNacimiento;
    int puntos;

    //paciente
    std::string clinicaNombre;
    std::string ubicacionPaciente;
public:

    Huesped() { documento = 0; nombre = "", sexo = "", fechaNacimiento = "", puntos = 5, clinicaNombre = "", ubicacionPaciente = ""; }
    Huesped(int documento, std::string nombre,std::string sexo,std::string fechaNacimiento, std::string clinicaNombre, std::string ubicacionPaciente);

    //getters
    std::string getNombre();


    void mostrarInfo();

};


#endif //OOP_HOMEWORKS_HUESPED_H
