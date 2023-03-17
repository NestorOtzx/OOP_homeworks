//
// Created by itsre on 16/03/2023.
//

#include "Sistema.h"
#include <limits>

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
                try {
                    registrarPropietario();
                }catch (std::invalid_argument ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                catch (std::out_of_range ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                break;
            case 2:
                try {
                    registrarHuesped();
                }catch (std::invalid_argument ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                catch (std::out_of_range ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                break;
            default:
                std::cout<<"Opcion no valida"<<std::endl;
                break;
        }
    }
}
void Sistema::registrarPropietario() {
    int documento;
    std::string nombre, genero, fechaNacimiento;

    std::cout << "Digite el numero de documento del propietario: "<<std::endl;
    std::cin >> documento;

    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("El documento debe ser un numero");
    }else{
        std::cout << std::endl;
    }

    int limiteCaracteres = 20;

    std::cout << "Escriba el nombre del propietario: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);

    if (nombre.length() > limiteCaracteres)
    {
        throw std::out_of_range("El nombre es demasiado largo");
    }

    std::cout << std::endl;


    std::cout << "Escriba el genero del propietario: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, genero);

    if (genero.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para el genero");
    }

    std::cout << std::endl;


    std::cout << "Escriba la fecha de nacimiento del propietario: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, fechaNacimiento);

    if (fechaNacimiento.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la fecha de nacimiento");
    }

    std::cout << "-|Informacion del hogar|-"<<std::endl;

    std::string direccion;
    int camas;
    int bebes;
    std::string descripcion;

    std::cout << "Escriba la direccion de la casa: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, direccion);

    if (direccion.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la direccion");
    }


    std::cout << "Escriba el numero de camas disponibles en la casa: "<<std::endl;
    std::cin >> camas;
    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("La cantidad de camas debe ser un numero");
    }else{
        std::cout << std::endl;
    }


    std::cout << "Permiten bebes en la casa?: " << std::endl;
    std::cout << "1. Si." << std::endl;
    std::cout << "2. No." << std::endl;
    std::cin >> bebes;
    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("Opcion no valida");
    }else{
        std::cout << std::endl;
    }


    std::cout<<"Escriba una descripcion sobre la casa: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, descripcion);

    if (descripcion.length() > 25)
    {
        throw std::out_of_range("Demasiados caracteres para la descripcion");
    }


    Hogar hogarPropietario = Hogar(direccion, camas, bebes<2, descripcion);

    Propietario * propietario = new Propietario(documento, nombre, genero, fechaNacimiento, hogarPropietario);
    this->listaPropietarios.push_back(propietario);

    std::cout<<"Propietario creado con exito."<<std::endl;
}

void Sistema::registrarHuesped() {
    int documento;
    std::string nombre, genero, fechaNacimiento;
    std::string clinicaNombre;
    std::string ubicacionPaciente;

    std::cout<<"Digite el numero de documento del huesped: ";
    std::cin>>documento;
    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("El documento debe ser un numero");
    }else{
        std::cout << std::endl;
    }

    int limiteCaracteres = 20;

    std::cout << "Escriba el nombre del huesped: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);

    if (nombre.length() > limiteCaracteres)
    {
        throw std::out_of_range("El nombre es demasiado largo");
    }

    std::cout << std::endl;


    std::cout << "Escriba el genero del huesped: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, genero);

    if (genero.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para el genero");
    }

    std::cout << std::endl;


    std::cout << "Escriba la fecha de nacimiento del huesped: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, fechaNacimiento);

    if (fechaNacimiento.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la fecha de nacimiento");
    }


    std::cout<<"Escriba el nombre de la clinica donde esta el paciente: ";
    std::cin.ignore();
    std::getline(std::cin, clinicaNombre);

    if (clinicaNombre.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para el nombre de la clinica");
    }


    std::cout<<"Escriba donde esta siendo atendido el paciente: "<<std::endl;
    std::cout<<"(ciudad/municipio/corregimiento de origen): ";
    std::cin.ignore();
    std::getline(std::cin, ubicacionPaciente);

    if (ubicacionPaciente.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la ubicacion del paciente");
    }

    Huesped * huesped = new Huesped(documento, nombre, genero, fechaNacimiento, clinicaNombre, ubicacionPaciente);
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

    Propietario * a = new Propietario(0, "nombre a", "genero", "dia 1", hogarBasico);
    agregarListaPropietarios(a);
    Propietario * b = new Propietario(1, "nombre b", "genero", "dia 2", hogarBasico);
    agregarListaPropietarios(b);
    Propietario * c = new Propietario(2, "nombre c", "genero", "dia 3", hogarBasico);
    agregarListaPropietarios(b);

    Huesped * d = new Huesped(0, "nombre d", "genero", "dia 1", "clinica a", "lugar a");
    agregarListaHuespedes(d);
    Huesped * e = new Huesped(1, "nombre e", "genero", "dia 2", "clinica b", "lugar b");
    agregarListaHuespedes(e);
    Huesped * f = new Huesped(2, "nombre f", "genero", "dia 3", "clinica c", "lugar c");
    agregarListaHuespedes(f);


    Reserva * reserva = new Reserva(a, d, "fecha 1", "fecha 2");
    reservas.push_back(reserva);

}

void Sistema::agregarListaHuespedes(Huesped *h) {
    this->listaHuespedes.push_back(h);
}

void Sistema::agregarListaPropietarios(Propietario *p) {
    this->listaPropietarios.push_back(p);
}
