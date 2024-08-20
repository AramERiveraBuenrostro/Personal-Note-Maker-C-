
class Data 
{
    protected:
        string diaNombre[7], mesNombre[12];
        int anioNumero, diaNumero, diaIndice, mesIndice;
        void Inicializar_Nombres (void);
        void Actualizar_Fecha(void);
    public:
        string eleccion;
        Data();
        void mensajes(int,string);
        ~Data() { }

};


class construccion : public Data
{
    private:
        void Crear_Nota(string, string);
        void Ver_Nota(void);
        void Editar_Nota(void);
        void Eliminar_Nota(string, string);
    public:
        construccion();
        void pantalla_Principal (void);
        void comportamiento     (void);
        void Pantalla_Final     (void);
        ~construccion() { }
};


