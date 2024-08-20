
//Arizmendi Ponce Jhoana Michel 
//Rivera Buenrostro Aram Elias 
// libreria estandar para c++*
#include <iostream>
using namespace std;

//libreria para obtener la fecha exacta*
#include <ctime>

// se usa para crear las nuevas carpetas*
#include <direct.h>

// se usa para darle estilos al codigo*
#include <iomanip>
#include <Windows.h>

#include <stdint.h>

// librerias para manipular los strings*
#include <string>
#include <stdlib.h>
#include <cstring>


// libreria para manipular los ficheros*
#include <fstream>


// esta linea ayuda a usar la palabra "color" para usar los colores del programa*
#define color SetConsoleTextAttribute
// Esta linea ayuda a controlar mejor los colores del programa, usando solo hconsole, en lugar que GetStdHandle(STD_OUTPUT_HANDLE)*
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


// insercion de archivos de cabecera*
#include ".h/clases.h"
#include ".h/metodos.h"

/**
 * Descripsion del proyecto:
 *          agenda que guarda los datos ingresados
 *          cada dato ingresado es una lista asi que se tienen que motrsr como tal
 *          esta agenda funcionara con ficheros y obtension de la hora del equipo de computo.*
 *          
 **/

int main()
{
    construccion obj1;
    
    color(hConsole,11);
    cout<<"******************************************************\n";
    cout<<"*                                                    *\n";
    cout<<"*   Bienvenido a esta agenda para guardar notas      *\n";
    cout<<"*                                                    *\n";
    cout<<"******************************************************\n";
    cout<<"*                                                    *\n";
    cout<<"*  Integrantes del equipo:                           *\n";
    cout<<"*  Rivera Buenrostro Aram Elias                      *\n";
    cout<<"*  Arizmendi Ponce Jhoana Michel                     *\n";
    cout<<"******************************************************\n";
    system("pause"); system("cls");

    do{
        obj1.pantalla_Principal();

    }while(obj1.Data::eleccion.compare("10")!=0);

}
