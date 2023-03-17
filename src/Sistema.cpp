//
// Created by itsre on 16/03/2023.
//

#include "Sistema.h"

void Sistema::menu() {
    int opcion = 0;
    usuariosDePrueba();

    while (opcion != 8)
    {
        //Personas iniciales

        std::cout<<"--------------|MENU|------------"<<std::endl;
        std::cout<<"| 1. Registrar Persona         |"<<std::endl;
        std::cout<<"| 2. Listar personas inscritas |"<<std::endl;
        std::cout<<"| 3. Crear reserva             |"<<std::endl;
        std::cout<<"| 4. Mostrar reservas          |"<<std::endl;
        std::cout<<"| 5. Eliminar reserva          |"<<std::endl;
        std::cout<<"| 6. Crear evaluacion          |"<<std::endl;
        std::cout<<"| 7. Ver evaluaciones          |"<<std::endl;
        std::cout<<"| 8. Salir                     |"<<std::endl;
        std::cout<<"--------------------------------"<<std::endl;

        std::cin>>opcion;
        switch(opcion)
        {
            case 1:
                registro();
                break;
            case 2:
                listarPersonas();
                break;
            case 3:
                crearReserva();
                break;
            case 4:
                listarReservas();
                break;
            case 5:
                liberarReserva();
                break;
            case 6:
                evaluar();
                break;
            case 7:
                listarEvaluaciones();
                break;
            case 8:
                std::cout<<"Adios."<<std::endl;
                break;
            default:
                std::cout<<"Opcion no valida"<<std::endl;
                break;
        }
    }
}

void Sistema::registro() {
    int opcion = 0;

    while (opcion < 1 || opcion > 2)
    {
        std::cout<<"--------------|REGISTRO|------------"<<std::endl;
        std::cout<<"| 1. Registrar Propietario         |"<<std::endl;
        std::cout<<"| 2. Registrar Huesped             |"<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;

        std::cin>>opcion;
        switch(opcion)
        {
            case 1:
                registrarPropietario();
                break;
            case 2:
                registrarHuesped();
                break;
            default:
                std::cout<<"Opcion no valida"<<std::endl;
                break;
        }
    }
}

void Sistema::registrarPropietario() {
    int documento;
    std::string nombre, sexo, fechaNacimiento;

    std::cout << "Digite el numero de documento del propietario: ";
    std::cin >> documento;
    std::cout << std::endl;

    fflush(stdin);

    std::cout << "Escriba el nombre del propietario: ";
    std::cin >> nombre;
    std::cout << std::endl;

    fflush(stdin);

    std::cout << "Escriba el sexo del propietario: ";
    std::cin >> sexo;
    std::cout << std::endl;

    fflush(stdin);

    std::cout << "Escriba la fecha de nacimiento del propietario: ";
    std::cin >> fechaNacimiento;
    std::cout << std::endl;

    fflush(stdin);

    std::cout << "-|Informacion del hogar|-"<<std::endl;

    std::string direccion;
    int camas;
    int bebes;
    std::string descripcion;

    std::cout << "Escriba la direccion de la casa: ";
    std::cin >> direccion;
    std::cout << std::endl;

    std::cout << "Escriba el numero de camas disponibles en la casa: ";
    std::cin >> camas;
    std::cout << std::endl;

    std::cout << "Permiten bebes en la casa?: " << std::endl;
    std::cout << "1. Si." << std::endl;
    std::cout << "2. No." << std::endl;
    std::cin >> bebes;

    std::cout<<"Escriba una descripcion sobre la casa: "<<std::endl;
    std::cin>>descripcion;

    Hogar hogarPropietario = Hogar(direccion, camas, bebes<2, descripcion);



    Propietario * propietario = new Propietario(documento, nombre, sexo, fechaNacimiento, hogarPropietario);
    this->listaPropietarios.push_back(propietario);

    std::cout<<"Propietario creado con exito."<<std::endl;
}

void Sistema::registrarHuesped() {
    int documento;
    std::string nombre, sexo, fechaNacimiento;
    std::string clinicaNombre;
    std::string ubicacionPaciente;

    std::cout<<"Digite el numero de documento del huesped: ";
    std::cin>>documento;

    std::cout<<"Escriba el nombre del huesped: ";
    std::cin>>nombre;

    std::cout<<"Escriba el sexo del huesped: ";
    std::cin>>sexo;

    std::cout<<"Escriba la fecha de nacimiento del huesped: ";
    std::cin>>fechaNacimiento;

    std::cout<<"Escriba el nombre de la clinica donde esta el paciente: ";
    std::cin>>clinicaNombre;

    std::cout<<"Escriba donde esta siendo atendido el paciente: "<<std::endl;
    std::cout<<"(ciudad/municipio/corregimiento de origen): ";
    std::cin>>fechaNacimiento;

    Huesped * huesped = new Huesped(documento, nombre, sexo, fechaNacimiento, clinicaNombre, ubicacionPaciente);
    listaHuespedes.push_back(huesped);

    std::cout<<"Huesped creado con exito."<<std::endl;
}


void Sistema::crearReserva() {

    mostrarHuespedes();

    std::cout<<"Seleccione un huesped para la reserva: ";
    int seleccion = 0;
    std::cin>>seleccion;

    std::list<Huesped*>::iterator huespedIterator = listaHuespedes.begin();
    std::advance(huespedIterator, seleccion-1);


    bool seleccionado = false;

    std::list<Propietario*>::iterator propietarioIterator;

    while(!seleccionado)
    {
        mostrarPropietarios();

        std::cout<<"Seleccione un propietario para la reserva: ";
        std::cin>>seleccion;

        propietarioIterator = listaPropietarios.begin();
        std::advance(propietarioIterator, seleccion-1);

        if ((*propietarioIterator)->getRecibeHuespedes())
        {
            seleccionado = true;
        }else{
            std::cout<<"---------El propietario "<<seleccion<<" no esta disponible-----------"<<std::endl;
        }
    }

    std::string fechaInicio, fechaFin;

    Reserva * reserva = new Reserva(*propietarioIterator, *huespedIterator, fechaInicio, fechaFin);
    reservas.push_back(reserva);
    std::cout<<"Reserva creada con exito";
}

void Sistema::liberarReserva() {
    listarReservas();
    std::cout<<"Que reserva desea eliminar?: "<<std::endl;
    int opcion;
    std::cin>>opcion;

    std::list<Reserva*>::iterator iterator = reservas.begin();
    std::advance(iterator, opcion-1);
    delete *iterator;

    reservas.erase(iterator);
}


void Sistema::mostrarPropietarios() {
    std::cout<<"||Propietarios||"<<std::endl;
    std::list<Propietario*>::iterator propietario;
    int contador=0;
    for(propietario = listaPropietarios.begin(); propietario != listaPropietarios.end(); ++propietario)
    {
        contador++;
        std::cout<<contador<<". "<<((*propietario)->getRecibeHuespedes()? "": "[No disponible!] ");
        (*propietario)->mostrarInfo();
    }
}

void Sistema::mostrarHuespedes() {
    std::cout<<"||Huespedes||"<<std::endl;
    std::list<Huesped*>::iterator huesped;
    int contador = 0;
    for(huesped = listaHuespedes.begin(); huesped != listaHuespedes.end(); ++huesped)
    {
        contador++;
        std::cout<<contador<<". ";
        (*huesped)->mostrarInfo();
    }
}

void Sistema::listarPersonas() {
    mostrarPropietarios();
    mostrarHuespedes();
}



void Sistema::listarReservas() {
    std::cout<<"||Reservas||"<<std::endl;
    std::list<Reserva*>::iterator reserva;
    int contador=0;
    for(reserva = reservas.begin(); reserva != reservas.end(); ++reserva)
    {
        contador++;
        std::cout<<"----||Reserva #"<<contador<<"||----"<<std::endl;
        (*reserva)->mostrarInfo();
    }
}


void Sistema::listarEvaluaciones() {
    std::cout<<"||Evaluaciones||"<<std::endl;
    std::list<Evaluacion*>::iterator eval;
    int contador=0;
    for(eval = evaluaciones.begin(); eval != evaluaciones.end(); ++eval)
    {
        contador++;
        std::cout<<"----||Evaluacion #"<<contador<<"||----"<<std::endl;
        (*eval)->mostrarInfo();
    }
}


void Sistema::evaluar() {

    std::string fecha, comentario;
    float puntaje;

    int huespedID = -1, propietarioID = -1;

    //Huesp
    mostrarHuespedes();
    std::cout<<"Quien hace la evaluacion?: ";
    std::cin>>huespedID;

    std::list<Huesped*>::iterator huespIter = listaHuespedes.begin();
    std::advance(huespIter, huespedID-1);

    //Prop
    mostrarPropietarios();
    std::cout<<"Hacia quien hace la evaluacion?: ";
    std::cin>>propietarioID;

    std::list<Propietario*>::iterator propIter = listaPropietarios.begin();
    std::advance(propIter, propietarioID-1);

    std::cout<<"En que fecha se hospedo?: ";
    std::cin>>fecha;

    std::cout<<"Que comentarios tiene?: ";
    std::cin>>comentario;

    std::cout<<"Que puntaje merece?: ";
    std::cin>>puntaje;

    (*propIter)->setPuntos(((*propIter)->getPuntos()+puntaje)/26);
    Evaluacion * evaluacion = new Evaluacion(*huespIter,*propIter, fecha, comentario, puntaje);
    evaluaciones.push_back(evaluacion);
    std::cout<<"Evaluacion realizada con exito."<<std::endl;
}



//Usado solo para testeo
void Sistema::usuariosDePrueba() {
    Hogar hogarBasico = Hogar("direccion", 2, true, "una casa");

    Propietario * a = new Propietario(0, "nombre a", "sexo", "dia 1", hogarBasico);
    this->listaPropietarios.push_back(a);
    Propietario * b = new Propietario(1, "nombre b", "sexo", "dia 2", hogarBasico);
    this->listaPropietarios.push_back(b);
    Propietario * c = new Propietario(2, "nombre c", "sexo", "dia 3", hogarBasico);
    this->listaPropietarios.push_back(c);

    Huesped * d = new Huesped(0, "nombre d", "sexo", "dia 1", "clinica a", "lugar a");
    this->listaHuespedes.push_back(d);
    Huesped * e = new Huesped(1, "nombre e", "sexo", "dia 2", "clinica b", "lugar b");
    this->listaHuespedes.push_back(e);
    Huesped * f = new Huesped(2, "nombre f", "sexo", "dia 3", "clinica c", "lugar c");
    this->listaHuespedes.push_back(f);


    Reserva * reserva = new Reserva(a, d, "fecha 1", "fecha 2");
    reservas.push_back(reserva);

}
