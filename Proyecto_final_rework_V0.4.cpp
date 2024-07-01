//-----------------------//
//   CODIGO HECHO POR    //
//   Aquiles Millán      //
//   V31.706.783         //
//   Alonso Acosta       //
//   V31.460.751         //
//   Nicole Becerra      //
//   V                   //
// Cátedra: Algortimos   //
// y estructuras de datos //
//-----------------------//

// Proyecto finalizado:
// Falta por terminar funciones del combate...

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> 
#include <random>
#include <cstdlib>    
using namespace std;

struct Ambientes
{
    std:: string nombre;
};

std::vector<Ambientes>Ambienteslista;

struct Objetos
{
    std:: string nombre;
    std:: string tipo;
    int valor;
    std:: string recuperacion;
    int energia;
    int contenedor;
};

std::vector<Objetos>Objetoslista;

struct Especies
{
    std:: string nombre;
    int energia;
    int salud;
    std:: string ambiente;
};

std::vector<Especies>Especieslista;

struct Soldados
{
    std::string nombre;
    std::string especie;
    int energia;
    int salud;
    std::vector<Objetos>MochilaList;
};

std::vector<Soldados>Soldadoslista;
std::vector<Soldados>equipo1;
std::vector<Soldados>equipo2;

std::string elegirambiente(std::string& ambienterandom)
{
    int randomIndex = rand() % Ambienteslista.size();
    ambienterandom = Ambienteslista[randomIndex].nombre;
    return ambienterandom;
}

void mostrarequipos()
{
    std::cout << "=================\n";
    std::cout << "    EQUIPO 1:\n";
    std::cout << "=================\n";
    for(int i = 0; i < equipo1.size(); i++)
    {
        std::cout <<"Soldado " << i << ": " << equipo1[i].nombre << "\n";
        std::cout << "Energia: " << equipo1[i].energia << "\n";
        std::cout << "Salud: " << equipo1[i].salud << "\n";
        std::cout << "=================\n";

    }
    std::cout << "\n=================\n";
    std::cout << "    EQUIPO 2:\n";
    std::cout << "=================\n";
    for(int i = 0; i < equipo2.size(); i++)
    {
        std::cout <<"Soldado " << i << ": " << equipo2[i].nombre << "\n";
        std::cout << "Energia: " << equipo2[i].energia << "\n";
        std::cout << "Salud: " << equipo2[i].salud << "\n";
        std::cout << "=================\n";
    }
}

void randomizarequipos()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(Soldadoslista.begin(), Soldadoslista.end(), gen);

    equipo1.assign(Soldadoslista.begin(), Soldadoslista.begin() + 3);
    equipo2.assign(Soldadoslista.begin() + 3, Soldadoslista.end());
}

void creaciondesoldados(int z,Soldados soldado1)
{
    std::cout << "\nNombre del soldado " << z << ": ";
    std::getline(std::cin, soldado1.nombre);
    bool verif = false;
    while(verif == false)
    {
        std::cout << "\nEspecie del soldado " << z << ": ";
        std::string especie;
        std::cin.clear();
        std::getline(std::cin, especie);
        for(int i = 0; i < Especieslista.size(); i++)
        {
            if(Especieslista[i].nombre == especie)
            {
                soldado1.especie = especie;
                soldado1.energia = Especieslista[i].energia;
                soldado1.salud = Especieslista[i].salud;
                verif = true;
            }
        }
        if(verif == false)
        {
            std::cout << "\nEspecie no valida, ingresa una especie valida.\n";
        }
    }
    
    std::cout<< "==================================================\n";
    std::cout <<" Selecciona los objetos en la mochila del soldado: \n";
    std::cout<< "==================================================\n";
    for(int i = 0; i < 5; i++)
    {
        bool verif2 = false;
        while(verif2 == false)
        {
            std::cout << "\n\nObjeto " << i+1 << ": ";
            std::string nombreobjeto;
            std::getline(std::cin, nombreobjeto);
            for(int j = 0; j < Objetoslista.size(); j++)
            {
                if(Objetoslista[j].nombre == nombreobjeto)
                {
                    soldado1.MochilaList.push_back(Objetoslista[j]);
                    verif2 = true;
                }
            }
            if(verif2 == false)
            {
                std::cout << "\nObjeto no valido, ingresa un objeto valido.\n";
            }
        }
    }

    Soldadoslista.push_back(soldado1);
}

void creaciondeequipos()
{
    system("cls");
    Soldados soldado1;
    Soldados soldado2;
    Soldados soldado3;
    Soldados soldado4;
    Soldados soldado5;
    Soldados soldado6;
    std::cout << "================================================================\n";
    std::cout << "                      VAMOS A PREPARARNOS!!!\n";
    std::cout << "================================================================\n";
    std::cout << "\n";
    std::cout << "CREACION SOLDADOS:\n";
    std::cin.ignore();
    creaciondesoldados(1, soldado1);
    system("cls");
    creaciondesoldados(2, soldado2);
    system("cls");
    creaciondesoldados(3, soldado3);
    system("cls");
    creaciondesoldados(4, soldado4);
    system("cls");
    creaciondesoldados(5, soldado5);
    system("cls");
    creaciondesoldados(6, soldado6);
    system("cls");

}

void combate()
{
    system("cls");
    std::cout << "\n";
    std::cout << "===========================================\n";
    std::cout << "            EMPIEZA EL COMBATE!\n";
    std::cout << "===========================================\n";
    std::cout << "\n";
    std::cout << "En esta batalla, los soldados deben sobrevivir hasta que uno de los equipos pierda a todos sus soldados.\n";
    std::cout << "\n";
 
    while(equipo1.size() > 0 && equipo2.size() > 0)
    {
        std::cout << "=====================\n";
        std::cout << "    TURNO EQUIPO 1:\n";
        std::cout << "=====================\n";
        for(int i = 0; i < equipo1.size(); i++)
        {
            std::cout <<"Soldado " << i << ": " << equipo1[i].nombre << "\n";
            std::cout << "Energia: " << equipo1[i].energia << "\n";
            std::cout << "Salud: " << equipo1[i].salud << "\n";
            std::cout << "=================\n";

        }

        bool verifsoldado1 = false;
        while(verifsoldado1 == false)
        { 
            std::cout << "\nSeleccione un personaje para este turno: ";
            std::string soldado;
            std::getline(std::cin, soldado);

            for(int j = 0; j < equipo1.size(); j++)
            {
                if(equipo1[j].nombre == soldado)
                {
                    verifsoldado1 = true;
                    std::cout << "\nTurno de: " << equipo1[j].nombre << "\n";
                    break;
                }
            }
            if(verifsoldado1 == false)
            {
                std::cout << "\nPersonaje no valido, ingresa un personaje valido.\n";
            }
        }
        
        bool verifobjeto1 = false;
        while(verifobjeto1 == false)
        {
            std::cout << "\nSeleccione el primer objeto para este turno: ";
            std::string objeto1;
            std::getline(std::cin, objeto1);
            for(int j = 0; j < (equipo1[j].MochilaList).size(); j++)
            {
                if((equipo1[j].MochilaList)[j].nombre == objeto1)
                {
                    verifobjeto1 = true;
                    std::cout << "\nObjeto seleccionado: " << objeto1 << "\n";
                    break;
                }
            }
            if(verifobjeto1 == false)
            {
                std::cout << "\nObjeto no valido, ingresa un objeto valido.\n";
            }
        }

        bool verifobjeto2 = false;
        while(verifobjeto2 == false)
        {
            std::cout << "\nSeleccione el segundo objeto para este turno: ";
            std::string objeto2;
            std::getline(std::cin, objeto2);
            for(int j = 0; j < (equipo1[j].MochilaList).size(); j++)
            {
                if((equipo1[j].MochilaList)[j].nombre == objeto2)
                {
                    verifobjeto2 = true;
                    std::cout << "\nObjeto seleccionado: " << objeto2 << "\n";
                    break;
                }
            }
            if(verifobjeto2 == false)
            {
                std::cout << "\nObjeto no valido, ingresa un objeto valido.\n";
            }
        }
  
    }
}

void guerra()
{
    if(Ambienteslista.size() == 0 or Objetoslista.size() < 5 or Especieslista.size() == 0)
    {
        std::cout << "\nNo hay suficientes datos cargados para combatir!\n";
        return;
    }
    else
    {
        creaciondeequipos();
        randomizarequipos();
        system("cls");
        mostrarequipos();
        std::string ambienterandom;
        elegirambiente(ambienterandom);
        std::cout << "\nEl combate se librara en " << ambienterandom <<"!!!\n" ;
        std::cout << "\nPresiona ENTER para comenzar el combate...\n";
        std::string comenzarcombate;
        std::cin.get();
        std::cin.ignore();

        combate();
    }
}

void verambientes()
{
    system("cls");
    std:: cout << "--------------------------------\n";
    std:: cout << "      Lista de Ambientes\n";
    std:: cout << "--------------------------------\n";

    for(int i = 0; i < Ambienteslista.size(); i++)
    {
        std:: cout << Ambienteslista[i].nombre << "\n" << std:: endl;
        std:: cout << "--------------------------------\n";
    }

}

void crearambientes()
{
    Ambientes ambiente;
    std:: string nombreambiente;
    std:: cout << "\nNombre del ambiente: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, nombreambiente);
    ambiente.nombre = nombreambiente;
    Ambienteslista.push_back(ambiente);
    system("cls");
    std::cout << "\nAmbiente creado.\n";
}

void eliminarambientes()
{
    system("cls");
    Ambientes ambiente;
    std::string ambienteeliminar;
    std::cout << "\nNombre del ambiente a eliminar: ";
    std::cin.ignore();
    getline(std::cin, ambienteeliminar);
    bool existe = false;

    for(int i = 0; i < Ambienteslista.size(); i++)
    {
        if(ambienteeliminar == Ambienteslista[i].nombre)
        {
            Ambienteslista.erase(Ambienteslista.begin() + i);
            std::cout << "\nAmbiente eliminado.\n";
            existe = true;
        }
    }
    if(existe == false)
    {
        std::cout << "\nAmbiente no encontrado.\n";
    }

}

void editarambientes()
{
    Ambientes ambiente;
    std::string ambienteeditar;
    std::cout << "\nNombre del ambiente a editar: ";
    std::cin.ignore();
    getline(std::cin, ambienteeditar);
    bool existe = false;
    
    for(int i = 0; i < Ambienteslista.size(); i++)
    {
        if(ambienteeditar == Ambienteslista[i].nombre)
        {
            std::string nuevoambiente;
            std::cout << "\nNuevo nombre del ambiente: ";
            getline(std::cin, nuevoambiente);
            system("cls");
            Ambienteslista[i].nombre = nuevoambiente;
            std::cout << "\nAmbiente editado.\n";
            existe = true;
        }
    }
    if(existe == false)
    {
        std::cout << "\nAmbiente no encontrado.\n";
    }
}

void guardarambientes()
{
    system("cls");
    std::ofstream archivo("ambiente.inv");
    if(archivo.is_open())
    {
        archivo << Ambienteslista.size() << "\n";

        for(int i = 0; i < Ambienteslista.size(); i++)
        {
            archivo << "--\n";
            archivo << Ambienteslista[i].nombre << "\n";
        }
        archivo.close();
        std::cout << "\nArchivo guardado con exito.\n";
    }

}

void cargarambientes()
{
    system("cls");
    std::ifstream archivo("ambiente.inv");

    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << "ambiente.inv" << std::endl;
        return;
    }

    std::string linea;
    int contadorAmbientes = 0;

    while (std::getline(archivo, linea))
    {
        if (linea == "--")
        {
            continue;
        }
        else
        {
            if (contadorAmbientes == 0)
            {
                // La primera línea contiene el número de ambientes
                contadorAmbientes = std::stoi(linea);  // Convertimos a entero
            }
            else
            {
                Ambientes ambiente;
                ambiente.nombre = linea;
                Ambienteslista.push_back(ambiente);
            }
        }

    }
    archivo.close();

    std::cout << "\nArchivo cargado con exito.\n";

}

void ambientes()
{
    bool volveralmenu;
    volveralmenu = false;

    while(volveralmenu == false)
    {
    
        bool verificacion;
        verificacion = false;

        while(verificacion == false)
        {
        
            int menuvalue;
            std::cout << "-----------------------------------------\n";
            std::cout << "             MENU DE AMBIENTES\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "1. ver ambientes\n";
            std::cout << "2. crear ambientes\n";
            std::cout << "3. eliminar ambientes\n";
            std::cout << "4. editar ambientes\n";
            std::cout << "5. guardar ambientes\n";
            std::cout << "6. cargar ambientes\n";
            std::cout << "0. volver al menu principal\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "   Selecciona una opcion [Del 0 al 6]: \n";
            std::cin >> menuvalue;

            if(std::cin.fail())
            { 
                std::cout << "eso no es una opcion valida, por favor intente de nuevo usando un numero.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            else
            {
                if(menuvalue != 1 and menuvalue != 2 and menuvalue != 3 and menuvalue != 4 and menuvalue != 5 and menuvalue != 6 and menuvalue != 0)
                {
                    std::cout<< "\nNumero invalido, intenta de nuevo.\n";
                }
                else
                {
                    switch (menuvalue)
                    {
                    case 1:
                        verambientes();
                        verificacion = true;
                        break;
                    case 2:
                        crearambientes();
                        verificacion = true;
                        break;    
                    case 3:
                        eliminarambientes();
                        verificacion = true;
                        break;
                    case 4:
                        editarambientes();
                        verificacion = true;
                        break; 
                    case 5:
                        guardarambientes();
                        verificacion = true;
                        break;
                    case 6:
                        cargarambientes();
                        verificacion = true;
                        break;
                    case 0:
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        std::cout<< "\n"<<"        Volviendo al menu principal!!!    "<< "\n";
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        verificacion = true;
                        volveralmenu = true;
                        break;
                    }
                }
            }
        }
    }

    system("cls");

}

void verobjetos()
{
    system("cls");
    std::cout << "----------------------------------------\n";
    std::cout << "           Lista de Objetos\n";
    std::cout << "----------------------------------------\n";
    
    for(int i = 0; i < Objetoslista.size(); i++)
    {
        std::cout << Objetoslista[i].nombre << "\n";
        std::cout << "Tipo: " << Objetoslista[i].tipo << "\n";
        std::cout << "Valor: " << Objetoslista[i].valor << "\n";
        std::cout << "Recuperacion: " << Objetoslista[i].recuperacion << "\n";
        std::cout << "Energia: " << Objetoslista[i].energia << "\n";
        std::cout << "Contenedor: " << Objetoslista[i].contenedor << "\n";
        std::cout << "----------------------------------------\n";
    }

}

void crearobjetosataque(Objetos& objeto)
{
    objeto.valor = 0;
    objeto.energia = 0;
    objeto.contenedor = 0;
    bool verif1 = false;
    bool verif2 = false;
    while(verif1 == false)
    {
        std::cout << "\nValor[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> objeto.valor;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(objeto.valor > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(objeto.valor < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif1 = true;
            }
        }
    }
    while(verif2 == false)
    {
        std::cout << "\nEnergia[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> objeto.energia;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(objeto.energia > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(objeto.energia < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif2 = true;
            }
        }
    }
    system("cls");
    std::cout << "\nobjeto creado con exito.\n";
}

void crearobjetosdefensa(Objetos& objeto)
{
    objeto.valor = 0;
    objeto.energia = 0;
    objeto.contenedor = 0;
    bool verif1 = false;
    bool verif2 = false;
    bool verif3 = false;
    while(verif1 == false)
    {
        std::cout << "\nValor[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> objeto.valor;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(objeto.valor > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(objeto.valor < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif1 = true;
            }
        }
    }
    while(verif2 == false)
    {
        std::cout << "\nEnergia[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> objeto.energia;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(objeto.energia > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(objeto.energia < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif2 = true;
            }
        }
    }
    while(verif3 == false)
    {
        std::cout << "\nContenedor[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> objeto.contenedor;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(objeto.contenedor > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(objeto.contenedor < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif3 = true;
            }
    
        }
    }
    system("cls");
    std::cout<< "\nobjeto creado con exito.\n";
}

void crearobjetoscondicionamiento(Objetos& objeto)
{
    objeto.valor = 0;
    objeto.energia = 0;
    objeto.contenedor = 0;
    std::cout << "\nRecuperacion: ";
    getline(std::cin, objeto.recuperacion);

    bool verif = false;
    for(int i = 0; i < Ambienteslista.size(); i++)
    {
        if(Ambienteslista[i].nombre == objeto.recuperacion)
        {
            verif = true;
            Objetoslista.push_back(objeto);
            system("cls");
            std::cout << "\nObjeto creado con exito.\n";
            break;
        }
    }
    if(verif == false)
    {
        std::cout << "\nEl ambiente no existe. Desea crearlo? [S/N]: ";
        std::string respuesta;
        std::cin >> respuesta;
        if(respuesta == "S" || respuesta =="s")
        {
            Ambientes ambiente;
            ambiente.nombre = objeto.recuperacion;
            Ambienteslista.push_back(ambiente);
            system("cls");
            std::cout << "\nAmbiente creado con exito.\n";
            Objetoslista.push_back(objeto);
            std::cout << "\nObjeto creado con exito.\n";
        }
        else
        {
            system("cls");
            std::cout<<"\nvolviendo al menu de objetos\n";
        }

    }
}

void crearobjetossupervivencia(Objetos& objeto)
{
    std::string recuperacion;
    bool verif = false;
    objeto.valor = 0;
    objeto.energia = 0;
    objeto.contenedor = 0;
    bool verif1 = false;
    bool verif2 = false;
    while(verif1 == false)
    {
        std::cout << "\nValor[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> objeto.valor;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(objeto.valor > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(objeto.valor < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif1 = true;
            }
        }
    }
    while(verif2 == false)
    {
        std::cout << "\nEnergia[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> objeto.energia;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(objeto.energia > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(objeto.energia < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif2 = true;
            }
        }
    }
    while (verif == false)
    {
        std::cout << "\nRecuperacion[Salud/Energia]: ";
        getline(std::cin, recuperacion);
        if (recuperacion == "Salud" or recuperacion == "Energia")
        {
            objeto.recuperacion = recuperacion;
            Objetoslista.push_back(objeto);
            system("cls");
            std::cout << "\nObjeto creado con exito.\n";
            verif = true;
            break;
        }
        else
        {
            std::cout << "\nEsa no es una opcion valida.\n";
        }
    }
}

void crearobjetos()
{
    system("cls");
    Objetos objeto;

    std::cout << "\nNombre del objeto: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, objeto.nombre);
    
    std::string tipo;
    std::cout << "\nTipo de objeto [Ataque/Defensa/Condicionamiento/Supervivencia]: ";
    getline(std::cin, objeto.tipo);
    
    if(objeto.tipo == "Ataque" || objeto.tipo == "Defensa" || objeto.tipo == "Condicionamiento" || objeto.tipo == "Supervivencia")
    {

        if(objeto.tipo == "Ataque")
        {
            crearobjetosataque(objeto);
            Objetoslista.push_back(objeto);
        }

        if(objeto.tipo == "Defensa")
        {
            crearobjetosdefensa(objeto);
            Objetoslista.push_back(objeto);
        }

        if(objeto.tipo == "Condicionamiento")
        {
            crearobjetoscondicionamiento(objeto);
        }
        
        if(objeto.tipo == "Supervivencia")
        {
            crearobjetossupervivencia(objeto);
        }

    }
    else
    {
        std::cout << "\nEsa no es una opcion valida.\n";
    }

}

void eliminarobjetos()
{

    system("cls");
    Objetos objeto;
    std::string objetoeliminar;
    std::cout << "\nNombre del objeto a eliminar: ";
    std::cin.ignore();
    getline(std::cin, objetoeliminar);
    bool verif = false;
    for(int i = 0; i < Objetoslista.size(); i++)
    {
        if(objetoeliminar == Objetoslista[i].nombre)
        {
            Objetoslista.erase(Objetoslista.begin() + i);
            std::cout << "\nObjeto eliminado.\n";
            verif = true;
        }
    }

    if(verif==false)
    {
        std::cout << "\nEl objeto no existe.\n";
    }
}

void editarobjetos()
{

    system("cls");
    Objetos objeto;
    std::string objetoeditar;
    std::cout << "\nNombre del objeto a editar: ";
    std::cin.ignore();
    getline(std::cin, objetoeditar);
    bool verif = false;
    for(int i = 0; i < Objetoslista.size(); i++)
    {
        if(objetoeditar == Objetoslista[i].nombre)
        {
            objeto = Objetoslista[i];
            std::cout << "\nNombre del objeto: " << objeto.nombre << "\n";
            std::cout << "Tipo de objeto: " << objeto.tipo << "\n";
            if(objeto.tipo == "Ataque")
            {
                objeto.valor = 0;
                objeto.energia = 0;
                objeto.contenedor = 0;
                bool verif1 = false;
                bool verif2 = false;
                while(verif1 == false)
                {
                    std::cout << "\nnuevo valor[Un numero mayor a 1 y menor que 1000]: ";
                    std::cin >> Objetoslista[i].valor;
                    if(std::cin.fail())
                    {
                        std::cout << "\nEso no es una opcion valida.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else
                    {
                        if(Objetoslista[i].valor > 1001)
                        {
                            std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                        }
                        else if(Objetoslista[i].valor < 1)
                        {
                            std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                        }
                        else
                        {
                            verif1 = true;
                        }
                    }
                }
                while(verif2 == false)
                {
                    std::cout << "\nnueva energia[Un numero mayor a 1 y menor que 1000]: ";
                    std::cin >> Objetoslista[i].energia;
                    if(std::cin.fail())
                    {
                        std::cout << "\nEso no es una opcion valida.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else
                    {
                        if(Objetoslista[i].energia > 1001)
                        {
                            std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                        }
                        else if(Objetoslista[i].energia < 1)
                        {
                            std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                        }
                        else
                        {
                            verif2 = true;
                        }
                    }
                }
                system("cls");
                std::cout << "\nobjeto editado con exito.\n";
            }
            if(objeto.tipo == "Defensa")
            {
                objeto.valor = 0;
                objeto.energia = 0;
                objeto.contenedor = 0;
                bool verif1 = false;
                bool verif2 = false;
                bool verif3 = false;
                while(verif1 == false)
                {
                    std::cout << "\nnuevo valor[Un numero mayor a 1 y menor que 1000]: ";
                    std::cin >> Objetoslista[i].valor;
                    if(std::cin.fail())
                    {
                        std::cout << "\nEso no es una opcion valida.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else
                    {
                        if(Objetoslista[i].valor > 1001)
                        {
                            std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                        }
                        else if(Objetoslista[i].valor < 1)
                        {
                            std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                        }
                        else
                        {
                            verif1 = true;
                        }
                    }
                }
                while(verif2 == false)
                {
                    std::cout << "\nnueva energia[Un numero mayor a 1 y menor que 1000]: ";
                    std::cin >> Objetoslista[i].energia;
                    if(std::cin.fail())
                    {
                        std::cout << "\nEso no es una opcion valida.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else
                    {
                        if(Objetoslista[i].energia > 1001)
                        {
                            std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                        }
                        else if(Objetoslista[i].energia < 1)
                        {
                            std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                        }
                        else
                        {
                            verif2 = true;
                        }
                    }
                }
                while(verif3 == false)
                {
                    std::cout << "\nnuevo ontenedor[Un numero mayor a 1 y menor que 1000]: ";
                    std::cin >> Objetoslista[i].contenedor;
                    if(std::cin.fail())
                    {
                        std::cout << "\nEso no es una opcion valida.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else
                    {
                        if(Objetoslista[i].contenedor > 1001)
                        {
                            std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                        }
                        else if(Objetoslista[i].contenedor < 1)
                        {
                            std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                        }
                        else
                        {
                            verif3 = true;
                        }
                
                    }
                }
                system("cls");
                std::cout<< "\nobjeto editado con exito.\n";

            }
            if(objeto.tipo == "Condicionamiento")
            {
                objeto.valor = 0;
                objeto.energia = 0;
                objeto.contenedor = 0;
                std:: string recuperacion;
                std::cout << "\nNueva recuperacion: ";
                getline(std::cin, recuperacion);

                bool verif = false;
                for(int i = 0; i < Ambienteslista.size(); i++)
                {
                    if(Ambienteslista[i].nombre == recuperacion)
                    {
                        verif = true;
                        Objetoslista[i].recuperacion = recuperacion;
                        system("cls");
                        std::cout << "\nObjeto editado con exito.\n";
                        break;
                    }
                }
                if(verif == false)
                {
                    std::cout << "\nEl ambiente no existe. Desea crearlo? [S/N]: ";
                    std::string respuesta;
                    std::cin >> respuesta;
                    if(respuesta == "S" || respuesta =="s")
                    {
                        Ambientes ambiente;
                        ambiente.nombre = recuperacion;
                        Ambienteslista.push_back(ambiente);
                        system("cls");
                        std::cout << "\nAmbiente creado con exito.\n";
                        Objetoslista[i].recuperacion = recuperacion;
                        std::cout << "\nObjeto editado con exito.\n";
                    }
                    else
                    {
                        system("cls");
                        std::cout<<"\nvolviendo al menu de objetos\n";
                    }

                }


            }
            if(objeto.tipo == "Supervivencia")
            {
                std::string recuperacion;
                bool verif = false;
                objeto.valor = 0;
                objeto.energia = 0;
                objeto.contenedor = 0;
                bool verif1 = false;
                bool verif2 = false;
                while(verif1 == false)
                {
                    std::cout << "\nnuevo valor[Un numero mayor a 1 y menor que 1000]: ";
                    std::cin >> Objetoslista[i].valor;
                    if(std::cin.fail())
                    {
                        std::cout << "\nEso no es una opcion valida.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else
                    {
                        if(Objetoslista[i].valor > 1001)
                        {
                            std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                        }
                        else if(Objetoslista[i].valor < 1)
                        {
                            std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                        }
                        else
                        {
                            verif1 = true;
                        }
                    }
                }
                while(verif2 == false)
                {
                    std::cout << "\nnueva energia[Un numero mayor a 1 y menor que 1000]: ";
                    std::cin >> Objetoslista[i].energia;
                    if(std::cin.fail())
                    {
                        std::cout << "\nEso no es una opcion valida.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else
                    {
                        if(Objetoslista[i].energia > 1001)
                        {
                            std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                        }
                        else if(Objetoslista[i].energia < 1)
                        {
                            std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                        }
                        else
                        {
                            verif2 = true;
                        }
                    }
                }
                while (verif == false)
                {
                    std::cout << "\nnueva recuperacion[Salud/Energia]: ";
                    getline(std::cin, recuperacion);
                    if (recuperacion == "Salud" or recuperacion == "Energia")
                    {
                        Objetoslista[i].recuperacion = recuperacion;
                        system("cls");
                        std::cout << "\nObjeto editado con exito.\n";
                        verif = true;
                        break;
                    }
                    else
                    {
                        std::cout << "\nEsa no es una opcion valida.\n";
                    }
                }
            }
            verif = true;
        }

    }
    if(verif==false)
    {
        std::cout << "\nEl objeto no existe.\n";
    }
}

void guardarobjetos()
{
    system("cls");
    std::ofstream archivo("accesorios.inv");
    if(archivo.is_open())
    {
        archivo << Objetoslista.size() << "\n";

        for(int i = 0; i < Objetoslista.size(); i++)
        {
            archivo << "--\n";
            archivo << Objetoslista[i].nombre << "\n";
            archivo << "Tipo:"<<Objetoslista[i].tipo << "\n";
            archivo << "Valor:"<<Objetoslista[i].valor << "\n";
            archivo << "Recuperacion:"<<Objetoslista[i].recuperacion << "\n";
            archivo << "Energia:"<<Objetoslista[i].energia << "\n";
            archivo << "Contenedor:"<<Objetoslista[i].contenedor << "\n";
        }
        archivo.close();
        std::cout << "\nArchivo guardado con exito.\n";
    }


}

void cargarobjetos() 
{
    system("cls");

    std::ifstream archivo("accesorios.inv");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: accesorios.inv" << std::endl;
        return;
    }

    std::string linea;
    int contadorObjetos = 0;

    // Expresión regular para extraer datos de la línea del valor
    std:: regex energiaRegex("(?:Energia: )?(\\d+)");
    std:: regex contenedorRegex("(?:Contenedor: )?(\\d+)");
    std::regex valorRegex("(?:Valor: )?(\\d+)");

    while (std::getline(archivo, linea)) 
    {
        if (linea == "--") 
        {
          continue;
        } else 
        {
            if (contadorObjetos == 0) {
              contadorObjetos = std::stoi(linea);
            } 
            else 
            {
                Objetos obj;  
                // Extract nombre
                obj.nombre = linea;   
                // Extract Tipo
                std::string lineaTipo;
                std::getline(archivo, lineaTipo); 
                if (lineaTipo.find("Tipo:") == 0) 
                {
                  std::istringstream ss(lineaTipo.substr(5)); // Skip "Tipo"
                  std::string tipo;
                  ss >> tipo;
                  obj.tipo = tipo;
                } 

                // Leer y procesar la línea del valor
                std::string lineaValor;
                std::getline(archivo, lineaValor);    
                // Extraer valor usando expresión regular
                std::smatch match;
                if (std::regex_search(lineaValor, match, valorRegex)) 
                {
                    obj.valor = std::stoi(match[1]);
                } else {
                    std::cerr << "Error al extraer valor para objeto: " << obj.nombre << std::endl;
                } 
                // Leer y procesar el resto de los datos (recuperación, energía, contenedor)

                // Leer y procesar recuperación
                std::string lineaRecuperacion;
                std::getline(archivo, lineaRecuperacion); 
                if (lineaRecuperacion.find("Recuperacion:") == 0) 
                {
                  std::istringstream ss(lineaRecuperacion.substr(13)); // Skip "Tipo"
                  std::string recuperacion;
                  ss >> recuperacion;
                  obj.recuperacion = recuperacion;
                }

                // Leer y procesar energía
                std::string lineaEnergia;
                std::getline(archivo, lineaEnergia);

                std::smatch matchenergia;
                if (std::regex_search(lineaEnergia, matchenergia, energiaRegex)) 
                {
                    obj.energia = std::stoi(matchenergia[1]);
                } else {
                    std::cerr << "Error al extraer energia para objeto: " << obj.nombre << std::endl;
                } 

                // Leer y procesar contenedor

                std::string lineaContenedor;
                std::getline(archivo, lineaContenedor);

                std::smatch matchcontenedor;
                if (std::regex_search(lineaContenedor, matchcontenedor, contenedorRegex))
                {
                    obj.contenedor = std::stoi(matchcontenedor[1]);
                }
                else
                {
                    std::cerr << "Error al extraer contenedor para objeto: " << obj.nombre << std::endl;
                }
 
                Objetoslista.push_back(obj);
            }
            contadorObjetos++;
        }
    }

    archivo.close();
    std::cout << "\nObjetos cargados con exito.\n";
}

void objetos()
{
    bool volveralmenu;
    volveralmenu = false;

    while(volveralmenu == false)
    {
    
        bool verificacion;
        verificacion = false;

        while(verificacion == false)
        {
        
            int menuvalue;
            std::cout << "-----------------------------------------\n";
            std::cout << "             MENU DE OBJETOS\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "1. ver objetos\n";
            std::cout << "2. crear objetos\n";
            std::cout << "3. eliminar objetos\n";
            std::cout << "4. editar objetos\n";
            std::cout << "5. guardar objetos\n";
            std::cout << "6. cargar objetos\n";
            std::cout << "0. volver al menu principal\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "   Selecciona una opcion [Del 0 al 6]: \n";
            std::cin >> menuvalue;

            if(std::cin.fail())
            { 
                std::cout << "eso no es una opcion valida, por favor intente de nuevo usando un numero.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            else
            {
                if(menuvalue != 1 and menuvalue != 2 and menuvalue != 3 and menuvalue != 4 and menuvalue != 5 and menuvalue != 6 and menuvalue != 0)
                {
                    std::cout<< "\nNumero invalido, intenta de nuevo.\n";
                }
                else
                {
                    switch (menuvalue)
                    {
                    case 1:
                        verobjetos();
                        verificacion = true;
                        break;
                    case 2:
                        crearobjetos();
                        verificacion = true;
                        break;    
                    case 3:
                        eliminarobjetos();
                        verificacion = true;
                        break;
                    case 4:
                        editarobjetos();
                        verificacion = true; 
                        break;
                    case 5:
                        guardarobjetos();
                        verificacion = true;
                        break;
                    case 6:
                        cargarobjetos();
                        verificacion = true;
                        break;
                    case 0:
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        std::cout<< "\n"<<"        Volviendo al menu principal!!!    "<< "\n";
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        verificacion = true;
                        volveralmenu = true;
                        break;
                    }
                }
            }
        }
    }
    
    system("cls");
}

void verespecies()
{
    system("cls");
    std::cout<< "\n"<<"-------------------------------------------"<< "\n";
    std::cout<< "\n"<<"            Lista de especies              "<< "\n";
    std::cout<< "\n"<<"-------------------------------------------"<< "\n";
    
        for(int i = 0; i < Especieslista.size(); i++)
    {
        std::cout << "Nombre: " << Especieslista[i].nombre << "\n";
        std::cout << "Energia: " << Especieslista[i].energia << "\n";
        std::cout << "Salud: " << Especieslista[i].salud << "\n";
        std::cout << "Ambiente: " << Especieslista[i].ambiente << "\n";
        std::cout << "---------------------------------------------\n";
    }
}

void crearespecies()
{
    system("cls");
    Especies especie;
    std::string nombredelaespecie;
    std::cout << "\nNombre de la especie: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, nombredelaespecie);
    especie.nombre = nombredelaespecie;

    bool verif1 = false;
    bool verif2 = false;
    while(verif1 == false)
    {
        std::cout << "\nSalud[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> especie.salud;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(especie.salud > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(especie.salud < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif1 = true;
            }
        }
    }
    while(verif2 == false)
    {
        std::cout << "\nEnergia[Un numero mayor a 1 y menor que 1000]: ";
        std::cin >> especie.energia;
        if(std::cin.fail())
        {
            std::cout << "\nEso no es una opcion valida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            if(especie.energia > 1001)
            {
                std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
            }
            else if(especie.energia < 1)
            {
                std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
            }
            else
            {
                verif2 = true;
            }
        }
    }


    std::cout << "\nAmbiente de la especie: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, especie.ambiente);

    bool verif = false;
    for(int i = 0; i < Ambienteslista.size(); i++)
    {
        if(Ambienteslista[i].nombre == especie.ambiente)
        {
            verif = true;
            Especieslista.push_back(especie);
            system("cls");
            std::cout << "\nObjeto creado con exito.\n";
            break;
        }
    }
    if(verif == false)
    {
        std::cout << "\nEl ambiente no existe. Desea crearlo? [S/N]: ";
        std::string respuesta;
        std::cin >> respuesta;
        if(respuesta == "S" || respuesta =="s")
        {
            Ambientes ambiente;
            ambiente.nombre = especie.ambiente;
            Ambienteslista.push_back(ambiente);
            system("cls");
            std::cout << "\nAmbiente creado con exito.\n";
            Especieslista.push_back(especie);
            std::cout << "\nEspecie creada con exito.\n";
        }
        else
        {
            system("cls");
            std::cout<<"\nvolviendo al menu de especies\n";
        }
    }

}

void eliminarespecies()
{
    system("cls");
    std::cout<< "\n"<<"-------------------------------------------"<< "\n";
    std::cout<< "\n"<<"            Eliminar especie               "<< "\n";
    std::cout<< "\n"<<"-------------------------------------------"<< "\n";
    std::cout << "Nombre de la especie a eliminar: ";
    std::string nombredelaespecie;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, nombredelaespecie);

    bool verif = false;
    for(int i = 0; i < Especieslista.size(); i++)
    {
        if(Especieslista[i].nombre == nombredelaespecie)
        {
            verif = true;
            Especieslista.erase(Especieslista.begin() + i);
            system("cls");
            std::cout << "\nEspecie eliminada con exito.\n";
            break;
        }
    }
    if(verif == false)
    {
        std::cout << "\nNo se encontro la especie.\n";
    }

}

void editarespecies()
{
    system("cls");
    std::cout<< "\n"<<"-------------------------------------------"<< "\n";
    std::cout<< "\n"<<"             Editar especie               "<< "\n";
    std::cout<< "\n"<<"-------------------------------------------"<< "\n";
    std::cout << "Nombre de la especie a editar: ";
    std::string nombredelaespecie;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, nombredelaespecie);
    bool verif = false;
    for(int i = 0; i < Especieslista.size(); i++)
    {
        if(Especieslista[i].nombre == nombredelaespecie)
        {
            std::cout << "Nuevo nombre: ";
            getline(std::cin, Especieslista[i].nombre);

            bool verif1 = false;
            bool verif2 = false;
            while(verif1 == false)
            {
                std::cout << "Nueva salud[Un numero mayor a 1 y menor que 1000]: ";
                std::cin >> Especieslista[i].salud;
                if(std::cin.fail())
                {
                    std::cout << "\nEso no es una opcion valida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
                else
                {
                    if(Especieslista[i].salud > 1001)
                    {
                        std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                    }
                    else if(Especieslista[i].salud < 1)
                    {
                        std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                    }
                    else
                    {
                        verif1 = true;
                    }
                }
            }

            while(verif2 == false)
            {
                std::cout << "Nueva energia[Un numero mayor a 1 y menor que 1000]: ";
                std::cin >> Especieslista[i].energia;
                if(std::cin.fail())
                {
                    std::cout << "\nEso no es una opcion valida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
                else
                {
                    if(Especieslista[i].energia > 1001)
                    {
                        std::cout<< "\nese valor es muy alto, trabaja dentro del rango indicado\n";
                    }
                    else if(Especieslista[i].energia < 1)
                    {
                        std::cout<< "\nese valor es muy bajo, trabaja dentro del rango indicado\n";
                    }
                    else
                    {
                        verif2 = true;
                    }	
                }
            }

            std::cout << "Nuevo ambiente: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string nuevoambiente;
            getline(std::cin, nuevoambiente);
            bool verif3 = false;
            for(int i = 0; i < Ambienteslista.size(); i++)
            {
                if(Ambienteslista[i].nombre == nuevoambiente)
                {
                    verif3 = true;
                    break;
                }
            }
            if(verif3 == false)
            {
                std::cout << "\nEl ambiente no existe. Desea crearlo? [S/N]: ";
                std::string respuesta;
                std::cin >> respuesta;
                if(respuesta == "S" || respuesta == "s")
                {
                    Ambientes ambiente;
                    Especieslista[i].ambiente = nuevoambiente;
                    ambiente.nombre = Especieslista[i].ambiente;
                    Ambienteslista.push_back(ambiente);
                    system("cls");
                    std::cout << "\nAmbiente creado con exito.\n";
                }
                else
                {
                    system("cls");
                    std::cout<<"\nno se edito el ambiente\n";
                }
            }

            std::cout << "\nEspecie editada con exito.\n";
            verif = true;
            break;

        }
    }
}

void guardarespecies()
{
    system("cls");
    std::ofstream archivo("especies.inv");
    if(archivo.is_open())
    {
        archivo << Especieslista.size() << "\n";

        for(int i = 0; i < Especieslista.size(); i++)
        {
            archivo << "--\n";
            archivo << Especieslista[i].nombre << "\n";
            archivo << "Energia:"<<Especieslista[i].energia << "\n";
            archivo << "Salud:"<<Especieslista[i].salud << "\n";
            archivo << Especieslista[i].ambiente << "\n";
        }
        archivo.close();
        std::cout << "\nArchivo guardado con exito.\n";
    }
}

void cargarespecies()
{
    system("cls");

    std::ifstream archivo("especies.inv");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: accesorios.inv" << std::endl;
        return;
    }

    std::string linea;
    int contadorEspecies = 0;

    // Expresión regular para extraer datos de la línea del valor
    std:: regex energiaRegex("(?:Energia: )?(\\d+)");
    std:: regex saludRegex("(?:Salud: )?(\\d+)");

    while (std::getline(archivo, linea)) 
    {
        if (linea == "--") 
        {
          continue;
        } else 
        {
            if(contadorEspecies == 0)
            {
                contadorEspecies = std::stoi(linea);
            }
            else
            {
                Especies especie;
                especie.nombre = linea;

                std::string lineaEnergia;
                std::getline(archivo, lineaEnergia);    

                std::smatch matchenergia;
                if (std::regex_search(lineaEnergia, matchenergia, energiaRegex)) 
                {
                    especie.energia = std::stoi(matchenergia[1]);
                } else {
                    std::cerr << "Error al extraer energia para especie: " << especie.nombre << std::endl;
                }

                std::string lineaSalud;
                std::getline(archivo, lineaSalud);

                std::smatch matchSalud;
                if (std::regex_search(lineaSalud, matchSalud, saludRegex))
                {
                    especie.salud = std::stoi(matchSalud[1]);
                } else {
                    std::cerr << "Error al extraer salud para especie: " << especie.nombre << std::endl;
                }

                std::string lineaAmbiente;
                std::getline(archivo, lineaAmbiente);
                especie.ambiente = lineaAmbiente;

                Especieslista.push_back(especie);

            }
            contadorEspecies++;
        }
    }
    archivo.close();
    std::cout << "\nArchivo cargado con exito.\n";

}

void especies()
{
    bool volveralmenu;
    volveralmenu = false;

    while(volveralmenu == false)
    {
    
        bool verificacion;
        verificacion = false;

        while(verificacion == false)
        {
        
            int menuvalue;
            std::cout << "-----------------------------------------\n";
            std::cout << "             MENU DE ESPECIES\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "1. ver especies\n";
            std::cout << "2. crear especies\n";
            std::cout << "3. eliminar especies\n";
            std::cout << "4. editar especies\n";
            std::cout << "5. guardar especies\n";
            std::cout << "6. cargar especies\n";
            std::cout << "0. volver al menu principal\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "   Selecciona una opcion [Del 0 al 6]: \n";
            std::cin >> menuvalue;

            if(std::cin.fail())
            { 
                std::cout << "eso no es una opcion valida, por favor intente de nuevo usando un numero.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            else
            {
                if(menuvalue != 1 and menuvalue != 2 and menuvalue != 3 and menuvalue != 4 and menuvalue != 5 and menuvalue != 6 and menuvalue != 0)
                {
                    std::cout<< "\nNumero invalido, intenta de nuevo.\n";
                }
                else
                {
                    switch (menuvalue)
                    {
                    case 1:
                        verespecies();
                        verificacion = true;
                        break;
                    case 2:
                        crearespecies();
                        verificacion = true;
                        break;    
                    case 3:
                        eliminarespecies();
                        verificacion = true;
                        break;
                    case 4:
                        editarespecies();
                        verificacion = true;
                        break; 
                    case 5:
                        guardarespecies();
                        verificacion = true;
                        break;
                    case 6:
                        cargarespecies();
                        verificacion = true;
                        break;
                    case 0:
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        std::cout<< "\n"<<"        Volviendo al menu principal!!!    "<< "\n";
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        verificacion = true;
                        volveralmenu = true;
                        break;
                    }
                }
            }
        }
    }
    
    system("cls");
}

int main()
{

    bool salir;
    salir = false;

    while(salir == false)
    {
    
        bool verificacion;
        verificacion = false;

        while(verificacion == false)
        {
        
            int menuvalue;
            std::cout << "-----------------------------------------\n";
            std::cout << "  BIENVENIDO JEFE, QUE TIENES EN MENTE?\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "1. Guerra\n";
            std::cout << "2. Ambientes\n";
            std::cout << "3. Objetos\n";
            std::cout << "4. Especies\n";
            std::cout << "0. Salir\n";
            std::cout << "-----------------------------------------\n";
            std::cout << "   Selecciona una opcion [Del 0 al 4]: \n";
            std::cin >> menuvalue;

            if(std::cin.fail())
            { 
                std::cout << "eso no es una opcion valida, por favor intente de nuevo usando un numero.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            else
            {
                if(menuvalue != 1 and menuvalue != 2 and menuvalue != 3 and menuvalue != 4 and menuvalue != 0)
                {
                    std::cout<< "\nNumero invalido, intenta de nuevo.\n";
                }
                else
                {
                    switch (menuvalue)
                    {
                    case 1:
                        system("cls");
                        guerra();
                        verificacion = true;
                        break;
                    case 2:
                        system("cls");
                        ambientes();
                        verificacion = true;
                        break;                    
                    case 3:
                        system("cls");                        
                        objetos();
                        verificacion = true;
                        break;
                    case 4:
                        system("cls"); 
                        especies();
                        verificacion = true;
                        break;
                    case 0:
                        system("cls");
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        std::cout<< "\n"<<"   Gracias por jugar, hasta la proxima!!!"<< "\n";
                        std::cout<< "\n"<<"-------------------------------------------"<< "\n";
                        verificacion = true;
                        salir = true;
                        break;
                    }
                }
            }
        }
    }    
}