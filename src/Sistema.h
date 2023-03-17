//
// Created by itsre on 16/03/2023.
//

#ifndef OOP_HOMEWORKS_SISTEMA_H
#define OOP_HOMEWORKS_SISTEMA_H
#include <list>
#include "Propietario.h"
#include "Reserva.h"
#include "Hogar.h"
#include "Evaluacion.h"

class Sistema {
private:
    std::list<Propietario*> listaPropietarios;
    std::list<Huesped*> listaHuespedes;
    std::list<Reserva*> reservas;
    std::list<Evaluacion*> evaluaciones;

    void mostrarPropietarios();
    void mostrarHuespedes();

public:
    Sistema() = default;

    //Registro
    void menu();
    void registro();
    void registrarPropietario();
    void registrarHuesped();
    void agregarListaPropietarios(Propietario * p);
    void agregarListaHuespedes(Huesped * h);


    //Utilidades
    void listarPersonas();
    void listarReservas();
    void listarEvaluaciones();
    void crearReserva();
    void liberarReserva();
    void evaluar();



    //Otros
    void usuariosDePrueba();
};


#endif //OOP_HOMEWORKS_SISTEMA_H
