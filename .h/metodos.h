
//constructor de la clase Data*
Data::Data()
{
    // esta funcion rellena los arrays de datos estaticos, como los nombres de los meses y dias.*
    Inicializar_Nombres();
    Actualizar_Fecha();
}

// Esta funcion actualiza la fecha cada vez que se manda a llamar
void Data::Actualizar_Fecha(void){
    // Funciones con las que se trabajan para obtener los datos necesitados*
    time_t now = time(0);
    tm * time = localtime(&now);

    anioNumero = 1900 + time->tm_year;
    diaIndice = time->tm_wday;
    mesIndice = time->tm_mon;
    diaNumero = time->tm_mday;
/*
cout<<anioNumero<<endl;
cout<<diaNombre[diaIndice]<<endl;
cout<<mesNombre[mesIndice]<<endl;
cout<<diaNumero<<endl;
*/

}

// Esta funcion asigna los valores constantes que se utilizaran "nombres de meses y dias, etc"*
void Data::Inicializar_Nombres(void)
{
    diaNombre[0] = "Domingo";
    diaNombre[1] = "Lunes";
    diaNombre[2] = "Martes";
    diaNombre[3] = "Miercoles";
    diaNombre[4] = "Jueves";
    diaNombre[5] = "Viernes";
    diaNombre[6] = "Sabado";

    mesNombre[0]  = "Enero";
    mesNombre[1]  = "Febrero";
    mesNombre[2]  = "Marzo";
    mesNombre[3]  = "Abril";
    mesNombre[4]  = "Mayo";
    mesNombre[5]  = "Junio";
    mesNombre[6]  = "Julio";
    mesNombre[7]  = "Agosto";
    mesNombre[8]  = "Septiembre";
    mesNombre[9]  = "Octubre";
    mesNombre[10] = "Noviembre";
    mesNombre[11] = "Diciembre";
}

// esta funcion Maneja los diferentes tipos de mensajes manejados "error, aviso y Correcto"*
void Data::mensajes(int _NumeroMensajes, string _Mensaje)
{
    if(_NumeroMensajes == 1)
    {
        color(hConsole,13);system("cls");
        cout<<"\n****************************************";
        cout<<"\n*  Error                               *";
        cout<<"\n****************************************";
        cout<<"\n*    "<<_Mensaje<<" *";
        cout<<"\n****************************************\n";
        system("pause");

    }else if(_NumeroMensajes == 2)
    {
        color(hConsole,14);system("cls");
        cout<<"\n****************************************";
        cout<<"\n*  Aviso                               *";
        cout<<"\n****************************************";
        cout<<"\n*    "<<_Mensaje<<" *";
        cout<<"\n****************************************\n";
        system("pause");

    }else if(_NumeroMensajes == 3)
    {
        color(hConsole,10);system("cls");
        cout<<"\n****************************************";
        cout<<"\n*  Correcto                            *";
        cout<<"\n****************************************";
        cout<<"\n*    "<<_Mensaje<<" *";
        cout<<"\n****************************************\n";
        system("pause");

    }else mensajes(1,"error con el codigo de mensaje");
}

// Constructor de la clase construccion, tambien crea la carpeta necesaria para uzar los ficheros*
construccion::construccion(void) : Data()
{
    bool creada = false;
    string Localizar_carpeta = "Archivos/Biembenido.txt";

    do{
        // ifstream es para sacar datos de un archivo
        ifstream comprobararchivo;
        comprobararchivo.open(Localizar_carpeta.c_str());

        if(comprobararchivo.fail())
        {
            comprobararchivo.close();
            ofstream comprobarCarpeta;
            comprobarCarpeta.open(Localizar_carpeta.c_str(),ios::out); // ios::out va a crear o sobre escribir el archivo segun sea el caso

            if(!comprobarCarpeta.fail())
            {
                comprobarCarpeta<<"Bienvenido a este programa.\n  Todo esta listo para ser usado Correctamente..";
                creada = true;

                ofstream AbrirRegistro;
                AbrirRegistro.open("Archivos/Registro.txt",ios::out);
                AbrirRegistro.close();

            } else mkdir("Archivos");
            comprobarCarpeta.close();

        }else creada = true; 
        
        comprobararchivo.close();

    }while(!creada);
}

// Esta funcion crea la pantalla principal y obtiene la eleccion del usuario*
void construccion::pantalla_Principal(void)
{
    bool aprobado = false;
    do{
        system("cls"); color(hConsole,9);
        cout<<"\n****************************************************************************";
        cout<<"\n* Elige una opcion de esta agenda:                                         *";
        cout<<"\n****************************************************************************";
        cout<<"\n*                                                 *                        *";
        cout<<"\n*         '1' Para crear una nueva nota           * Fecha actual:          *";
        cout<<"\n*                                                 *  Fecha:     ";color(hConsole,15);cout<<setfill('0')<<setw(2)<<diaNumero<<"/"<<setw(2)<<mesIndice+1<<"/"<<setw(4)<<anioNumero;color(hConsole,9);cout<<" *";
        cout<<"\n***************************************************  Dia  :     ";color(hConsole,15);cout<<setfill(' ')<<setw(10)<<diaNombre[diaIndice];color(hConsole,9);cout<<" *";
        cout<<"\n*                                                 *  Mes  :     ";color(hConsole,15);cout<<setfill(' ')<<setw(10)<<mesNombre[mesIndice];color(hConsole,9);cout<<" *";
        cout<<"\n*         '2' Para ver las notas                  *  Anio :     ";color(hConsole,15);cout<<setfill(' ')<<setw(10)<<anioNumero;          color(hConsole,9);cout<<" *";
        cout<<"\n*                                                 *                        *";
        cout<<"\n****************************************************************************";
        cout<<"\n*                                                                          *";
        cout<<"\n*         '3' Para editar una nota                                         *";
        cout<<"\n*                                                                          *";
        cout<<"\n****************************************************************************";
        cout<<"\n*         '10' Para salir del programa                                     *";
        cout<<"\n****************************************************************************";
        cout<<"\n*  ";color(hConsole,15); fflush(stdin); getline(cin,eleccion);color(hConsole,9);
        
        if(eleccion.compare("1")==0 || eleccion.compare("2")==0 || eleccion.compare("3")==0 || eleccion.compare("10")==0) aprobado = true;
        else mensajes(1,"Ingrese un valor valido");
        system("cls");

    }while(!aprobado);
    comportamiento();
}

// Esta funcion establese el comportamiento que tendra el programa depentiendo de la seleccion del usuario*
void construccion::comportamiento(void)
{
    if(eleccion.compare("1")==0) Crear_Nota("","");

    else if(eleccion.compare("2")==0) Ver_Nota();

    else if(eleccion.compare("3")==0) Editar_Nota();

    else if(eleccion.compare("10")==0) Pantalla_Final();

    else mensajes(1,"Hubo un error con la ejecucion");
}

//Pantalla de final de ejecucion*
void construccion::Pantalla_Final(void)
{
    color(hConsole,14); system("cls");

    cout<<"\n******************************************\n";
    cout<<"*                                        *\n";
    cout<<"*   Programa finalizado correctamente    *\n";
    cout<<"*                                        *\n";
    cout<<"******************************************\n";
    system("pause");
}

// Esta funcion Crea los archivos ".txt" que manipularan*
void construccion::Crear_Nota(string tituloNuevo, string contenidoNuevo)
{
    color(hConsole,9); system("cls");

    string Titulo, contenido , concatenar, nombre;

    Titulo = tituloNuevo;
    contenido = contenidoNuevo;

    if((tituloNuevo.compare("")==0) && (contenidoNuevo.compare("")==0)){

        cout<<"\n**********************************************************************************************\n";
        cout<<"\n*    Ingresa el nombre del archivo:                                                          *\n";
        cout<<"\n**********************************************************************************************\n";
        cout<<"*       ";color(hConsole,15);fflush(stdin); getline(cin,Titulo);color(hConsole,9);

        cout<<"**********************************************************************************************\n";
        cout<<"\n Ingresa El contenido de la nota, y cuando termines, presiona 'enter': \n";
        cout<<"\n**********************************************************************************************\n\n";
        cout<<"*  ";color(hConsole,15);fflush(stdin); getline(cin,contenido);color(hConsole,9);
        cout<<"\n**********************************************************************************************\n";
        system("pause");
    }

    nombre = Titulo;
    concatenar = "Archivos/"+Titulo+".txt";

    ofstream crear_archivo;
    crear_archivo.open(concatenar.c_str(),ios::out);

    if(!crear_archivo.fail()){

        crear_archivo<<Titulo+"\n";

        crear_archivo<<contenido+"\n";


        // actualiza la ultima fecha dada
        Actualizar_Fecha();
        // envia la fecha asi para saber cual fue la ultima actualizacion del archivo
        if ((diaNumero/10)<1 && (mesIndice/10)<1 )      crear_archivo<<"0"<<diaNumero<<"/"<<"0"<<mesIndice<<"/"<<anioNumero<<"\n";

        else if ((diaNumero/10)>=1 && (mesIndice/10)<1) crear_archivo<<     diaNumero<<"/"<<"0"<<mesIndice<<"/"<<anioNumero<<"\n";

        else if((diaNumero/10)<1 && (mesIndice/10)>=1)  crear_archivo<<"0"<<diaNumero<<"/"<<     mesIndice<<"/"<<anioNumero<<"\n";

        else                                            crear_archivo<<     diaNumero<<"/"<<     mesIndice<<"/"<<anioNumero<<"\n";


        ofstream AbrirRegistro;
        AbrirRegistro.open("Archivos/Registro.txt",ios::app);

        if(!AbrirRegistro.fail()){
            AbrirRegistro<<nombre<<"\n";
        }else mensajes(1,"No se pudo agregar al registro");

        AbrirRegistro.close();

        mensajes(3,"se creo el registro correctamente");

    }else mensajes(1,"No se pudo crear el archivo");
    
    crear_archivo.close();

    system("cls");

}


void construccion::Ver_Nota(void)
{

    int i, eleccionIterador;

    ifstream AbrirRegistro; string Registro = "Archivos/Registro.txt";
    AbrirRegistro.open(Registro.c_str());

    string arrayRegistros[50],obtensionRegistros;

    if(!AbrirRegistro.fail())
    {

        cout<<"\n****************************************************************************";
        cout<<"\n*  ";color(hConsole, 15);cout<<"  Registros disponibles: ";color(hConsole, 9);cout<<"                       *  Numero para abrir    *";
        cout<<"\n****************************************************************************";                                                      

                    // eof nos regres false siempre y cuando no alla contenido en un registro
        for(i = 0; !AbrirRegistro.eof(); i++){

            getline(AbrirRegistro,obtensionRegistros);

                arrayRegistros[i] = obtensionRegistros;
                
                if(obtensionRegistros.compare("")!=0){

                cout<<"\n*                                                  *                       *";
                cout<<"\n*      ";color(hConsole, 15);cout<<"        "<<setfill(' ')<<obtensionRegistros<<setw((44-obtensionRegistros.size()));color(hConsole, 9) ;cout<<"         *       ";color(hConsole, 15);cout<<i+1;color(hConsole, 9);cout<<"               *";
                cout<<"\n*                                                  *                       *";
                cout<<"\n****************************************************************************";
            }

        }

    }else mensajes(1,"No se encontro ningun registro, error inesperado");


    AbrirRegistro.close();

    cout<<"\n*  Ingresa el numero de la nota que quieres leer o presiona 0 para salir   *\n";
    cout<<"\n****************************************************************************\n";
    cout<<"\n*                                                                          *\n";
    cout<<"*  ";color(hConsole, 15); cin>>eleccionIterador; color(hConsole, 9);
    cout<<"\n*                                                                          *\n";
    cout<<"\n****************************************************************************\n";
    system("cls");
    

    if(eleccionIterador!=0){
        
        obtensionRegistros = "Archivos/"+arrayRegistros[eleccionIterador-1]+".txt";
        string direccion = obtensionRegistros;

        ifstream Abrir_nota;
        Abrir_nota.open(obtensionRegistros.c_str());
    
        if (!Abrir_nota.fail())
        {
            cout<<"\n****************************************************************************\n";
            while (!Abrir_nota.eof())
            {
                getline(Abrir_nota,obtensionRegistros);

                if(obtensionRegistros.compare("")!=0){
                    cout<<"\n*    ";color(hConsole, 15);cout<<setfill(' ')<<obtensionRegistros<<setw((76-obtensionRegistros.size()));color(hConsole, 9); cout<<"*\n";
                    cout<<"\n****************************************************************************\n";
                }
            }
            
        }else mensajes(1,"No se encontro el archivo seleccionado archivo");
        Abrir_nota.close();
    
        cout<<"\n\n****************************************************************************\n";
        cout<<"\n*  ";color(hConsole, 15);cout<<"  Quieres eliminar el registro?  ";color(hConsole, 9);cout<<"                                       *\n";
        cout<<"\n****************************************************************************\n";
        cout<<"*                                    *                                     *\n";
        cout<<"*  ";color(hConsole, 15);cout<<"    presiona '1' para si  ";color(hConsole, 9);cout<<"        *     ";color(hConsole, 15);cout<<" Presiona '2' para no   ";color(hConsole, 9);cout<<"        *\n";
        cout<<"*                                    *                                     *\n";
        cout<<"****************************************************************************\n";
        cout<<"*                                    *                                     *\n";
        cout<<"*     "; color(hConsole, 15);fflush(stdin); getline(cin,obtensionRegistros);color(hConsole, 9);
        
            if(obtensionRegistros.compare("1")==0) Eliminar_Nota(direccion,arrayRegistros[eleccionIterador-1]);

    }

}

void construccion::Editar_Nota(void)
{
    
    string datos_A_Editar[4];
    int i, eleccionIterador;

    ifstream AbrirRegistro; string Registro = "Archivos/Registro.txt";
    AbrirRegistro.open(Registro.c_str());

    string arrayRegistros[50],obtensionRegistros;

    if(!AbrirRegistro.fail())
    {
        cout<<"\n****************************************************************************";
        cout<<"\n*  ";color(hConsole, 15);cout<<"  Registros disponibles: ";color(hConsole, 9);cout<<"                       *  Numero para abrir    *";
        cout<<"\n****************************************************************************";                                                      

        for(i = 0; !AbrirRegistro.eof(); i++)
        {
            getline(AbrirRegistro,obtensionRegistros);

                arrayRegistros[i] = obtensionRegistros;
                
                if(obtensionRegistros.compare("")!=0){

                cout<<"\n*                                                  *                       *";
                cout<<"\n*      ";color(hConsole, 15);cout<<"        "<<setfill(' ')<<obtensionRegistros<<setw((44-obtensionRegistros.size()));color(hConsole, 9) ;cout<<"         *       ";color(hConsole, 15);cout<<i+1;color(hConsole, 9);cout<<"               *";
                cout<<"\n*                                                  *                       *";
                cout<<"\n****************************************************************************";
            }

        }

        cout<<"\n*    Ingresa el numero de la nota que quieres editar o presiona 0 para salir     *\n";
        cout<<"\n**********************************************************************************\n";
        cout<<"\n*                                                                                *\n";
        cout<<"*  ";color(hConsole, 15); cin>>eleccionIterador; color(hConsole, 9);
        cout<<"\n*                                                                                *\n";
        cout<<"\n**********************************************************************************\n";
        system("cls");
    }

    AbrirRegistro.close();
    system("cls");
    
    if(eleccionIterador!=0){
        
        ifstream Abrir_nota;
        obtensionRegistros = "Archivos/"+arrayRegistros[eleccionIterador-1]+".txt";
        Abrir_nota.open(obtensionRegistros.c_str());
        
        if (!Abrir_nota.fail())
        {
            cout<<"\n**********************************************************************************\n";
            cout<<"\n*      Datos anteriores:                                                         *\n";
            cout<<"\n**********************************************************************************\n";
            for (int i = 0; !Abrir_nota.eof(); i++)
            {
                fflush(stdin); getline(Abrir_nota,obtensionRegistros);

                if(obtensionRegistros.compare("")!=0){
                    cout<<"\n*    ";color(hConsole, 15);cout<<setfill(' ')<<obtensionRegistros<<setw((76-obtensionRegistros.size()));color(hConsole, 9); cout<<"*\n";
                    cout<<"\n**********************************************************************************\n";
                }
                datos_A_Editar[i] = obtensionRegistros;
            }
            
            string nuevosDatos[2];

            color(hConsole,11);
            cout<<"\n**********************************************************************************\n";
            cout<<"\n* Ingresa los nuevos datos de la nota:                                           *\n";
            cout<<"\n**********************************************************************************\n";
            cout<<"\n*  Ingresa El titulo de la nota:                                                 *\n";
            cout<<"\n**********************************************************************************\n";
            cout<<"\n*                                                                                *\n";
            cout<<"*  ";color(hConsole, 15); fflush(stdin); getline(cin,nuevosDatos[0]); color(hConsole, 11);
            cout<<"\n*                                                                                *\n";
            cout<<"\n**********************************************************************************\n";
            cout<<"\n*  Ingresa el contenido de la nota:                                              *\n";
            cout<<"\n**********************************************************************************\n";
            cout<<"\n*                                                                                *\n";
            cout<<"*  ";color(hConsole, 15); fflush(stdin); getline(cin,nuevosDatos[1]); color(hConsole, 11);
            cout<<"\n*                                                                                *\n";
            cout<<"\n**********************************************************************************\n";
            
            string Direccion_Editar = "Archivos/"+datos_A_Editar[0]+".txt";
            
            if(nuevosDatos[0].compare("")!=0) nuevosDatos[0] = nuevosDatos[0]; else nuevosDatos[0] = datos_A_Editar[0];

            if(nuevosDatos[1].compare("")!=0) nuevosDatos[1] = nuevosDatos[1]; else nuevosDatos[1] = datos_A_Editar[1];

            Eliminar_Nota(Direccion_Editar,datos_A_Editar[0]);

            Crear_Nota(nuevosDatos[0],nuevosDatos[1]);

        }else mensajes(1,"No se encontro el archivo seleccionado ");
        Abrir_nota.close();
    }

}


void construccion::Eliminar_Nota(string _Direccion_nota, string _nombreNota)
{
    int iterador = 0;
    remove(_Direccion_nota.c_str()); 
    string notaAnterior[50];

    _Direccion_nota = "Archivos/Registro.txt";

    ifstream eliminar_Nota;
    eliminar_Nota.open(_Direccion_nota.c_str());
    
    if(!eliminar_Nota.fail()){
        for (iterador = 0; !eliminar_Nota.eof(); iterador++)
        {
            getline(eliminar_Nota,notaAnterior[iterador]);
        }

    }else mensajes(1,"no se encontro el Registro");
    eliminar_Nota.close();
    

    ofstream Reescribir_Nota;
    Reescribir_Nota.open("Archivos/Registro.txt",ios::out);

    if(!Reescribir_Nota.fail()){
        string nota;
        for (int i = 0; i < iterador; i++)
        {   
            nota = notaAnterior[i];
            if(nota.compare(_nombreNota)!=0) 
            {
                Reescribir_Nota<<nota+"\n";
            }
        }

    }else mensajes(1,"no se encontro el Registro");
    Reescribir_Nota.close();

}
