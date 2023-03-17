//
// Created by itsre on 16/03/2023.
//

#ifndef OOP_HOMEWORKS_HOGAR_H
#define OOP_HOMEWORKS_HOGAR_H
#include <iostream>

class Hogar {
private:
    std::string direccion;
    int camas;
    bool bebes;
    std::string descripcion;
public:
    Hogar() = default;
    Hogar(std::string direccion, int camas, bool bebes, std::string descripcion);

    std::string getDireccion();

    int getCamas();
    bool getBebes();
    std::string getDescripcion();
};


#endif //OOP_HOMEWORKS_HOGAR_H
