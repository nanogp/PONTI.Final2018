/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Producto.h"

/**************************** GETTERS ************************************************************/
int eProducto_getId(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eProducto*)this)->idProducto;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eProducto_getDescripcion(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eProducto*)this)->descripcion;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_getCantidad(void* this)
{
    int returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eProducto*)this)->cantidad;
    }
    return returnAux;
}
/**************************** SETTERS ************************************************************/
int eProducto_setId(void* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eProducto*)this)->idProducto = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_setDescripcion(void* this, char* descripcion)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(((eProducto*)this)->descripcion, descripcion);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_setCantidad(void* this, int cantidad)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eProducto*)this)->cantidad = cantidad;
        returnAux = OK;
    }
    return returnAux;
}
/**************************** CONSTRUCTORES ******************************************************/
void* eProducto_new()
{
    void* producto;

    producto = malloc(sizeof(eProducto));

    return producto;
}
//-----------------------------------------------------------------------------------------------//
void* eProducto_newParam(int id, char* descripcion, int cantidad)
{
    void* producto;

    producto = eProducto_new();

    if(producto != NULL)
    {
        eProducto_setId(producto, id);
        eProducto_setDescripcion(producto, descripcion);
        eProducto_setCantidad(producto, cantidad);
    }
    return producto;
}
/**************************** ENTRADA DE DATOS ***************************************************/
//char* eProducto_pedirDescripcion()
//{
//    return eString_newParam(PRODUCTO_MSJ_INGRESE_DESCRIPCION, PRODUCTO_MSJ_REINGRESE_DESCRIPCION, PRODUCTO_LARGO_DESCRIPCION);
//}
////-----------------------------------------------------------------------------------------------//
//int eProducto_pedirCantidad()
//{
//    return pedirIntValido(PRODUCTO_MSJ_INGRESE_CANTIDAD, PRODUCTO_MSJ_REINGRESE_CANTIDAD, PRODUCTO_CANT_MIN, PRODUCTO_CANT_MAX);
//}
////-----------------------------------------------------------------------------------------------//
//void* eProducto_pedirProducto(ArrayList* this)
//{
//    void* producto;
//    char* descripcion;
//    char* cantidad;
//    float tarjeta;
//
//    if(this != NULL)
//    {
//        descripcion = eProducto_pedirDescripcion();
//        cantidad = eProducto_pedirCantidad();
//        tarjeta = eProducto_pedirTarjeta();
//
//        producto = eProducto_newParam(eGestion_siguienteId(this, eProducto_getId),
//                                            descripcion,
//                                            cantidad,
//                                            tarjeta);
//    }
//    return producto;
//}
/**************************** LISTADO DE DATOS ***************************************************/
void eProducto_mostrarUno(void* this)
{
    if(this != NULL)
    {
        printf(PRODUCTO_MOSTRAR_UNO_MASCARA,
               eProducto_getId(this),
               eProducto_getDescripcion(this),
               eProducto_getCantidad(this));
    }
}
/**************************** GESTION DE DATOS ***************************************************/
//int eProducto_modificarUno(void* this)
//{
//    int returnAux = CHECK_POINTER;
//    eMenu menuModificar = {/*titulo del menu*/{"Que desea modificar?"},
//                           /*cantidad de opciones*/5,
//                           /*codigos*/{1,2,3,
//                                       9,0},
//                           /*descripciones*/"\n  1. Descripcion"
//                                            "\n  2. Cantidad"
//                                            "\n  3. Tarjeta"
//                                            "\n  9. FINALIZAR CAMBIOS"
//                                            "\n  0. CANCELAR"};
//    void* registro;
//    int opcion;
//    const int huboCambios = 1;
//    char finalizar = 'N';
//
//    if(this != NULL)
//    {
//        returnAux = OK;
//        registro = (eProducto*) this;
//        do
//        {
//            limpiarPantallaYMostrarTitulo(MSJ_MODIFICANDO_REGISTRO);
//            imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);
//
//            imprimirEnPantalla(PRODUCTO_MOSTRAR_UNO_CABECERA);
//            eProducto_mostrarUno(registro);
//            saltoDeLinea();
//
//            opcion = eMenu_pedirOpcion(&menuModificar);
//            switch(opcion)
//            {
//                case 1:
//                    eProducto_setDescripcion(registro, eProducto_pedirDescripcion());
//                    returnAux = huboCambios;
//                    break;
//                case 2:
//                    eProducto_setCantidad(registro, eProducto_pedirCantidad());
//                    returnAux = huboCambios;
//                    break;
//                case 3:
//                    eProducto_setTarjeta(registro, eProducto_pedirTarjeta());
//                    returnAux = huboCambios;
//                    break;
//                case 4:
//                    returnAux = huboCambios;
//                    break;
//                case 5:
//                    returnAux = huboCambios;
//                    break;
//                case 6:
//                    returnAux = huboCambios;
//                    break;
//                case 7:
//                    returnAux = huboCambios;
//                    break;
//                case 8:
//                    returnAux = huboCambios;
//                    break;
//                case 9:
//                    finalizar = 'S';
//                    break;
//                case 0:
//                    finalizar = 'S';
//                    returnAux = OK;
//                    break;
//            }
//        }
//        while(finalizar == 'N');
//    }
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
//char* eProducto_parserATexto(void* this, int bufferSize)
//{
//    char* returnAux = NULL;
//    void* producto;
//
//    if(this != NULL)
//    {
//        returnAux = eString_new(bufferSize);
//
//        if(returnAux != NULL)
//        {
//            producto = (eProducto*) this;
//            strcpy(returnAux, "");
//            strcat(returnAux, intToChar(eProducto_getId(producto)));
//            strcat(returnAux, ",");
//            strcat(returnAux, eProducto_getDescripcion(producto));
//            strcat(returnAux, ",");
//            strcat(returnAux, eProducto_getCantidad(producto));
//            strcat(returnAux, ",");
//            strcat(returnAux, floatToChar(eProducto_getTarjeta(producto), 0));
//            strcat(returnAux, "\n");
//        }
//    }
//
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
void* eProducto_parserAVoid(char* this, int bufferSize)
{
    void* returnAux = NULL;
    int id;
    char descripcion[PRODUCTO_LARGO_DESCRIPCION];
    int cantidad;

    if(this != NULL)
    {
        sscanf(this, "%d,%[^,],%d\n", &id, descripcion, &cantidad);
        returnAux = eProducto_newParam(id, descripcion, cantidad);
    }

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void eProducto_cargarArchivos(ArrayList* this, ArrayList* that)
{
    eGestion_cargarArchivoTexto(this,
                                eProducto_parserAVoid,
                                eProducto_compararPorId,
                                "CARGAR ARCHIVO DEPOSITO 0",
                                2000,
                                "dep0.csv");

    eGestion_cargarArchivoTexto(that,
                                eProducto_parserAVoid,
                                eProducto_compararPorId,
                                "CARGAR ARCHIVO DEPOSITO 1",
                                2000,
                                "dep1.csv");
}
//-----------------------------------------------------------------------------------------------//
void eProducto_listarDeposito(ArrayList* this, ArrayList* that)
{
    if(this != NULL && that != NULL)
    {
        eMenu menuPrincipal = {/*titulo del menu*/{"ELIJA DEPOSITO PARA LISTAR"},
                               /*cantidad de opciones*/3,
                               /*codigos*/{1,2,
                               0},
                               /*descripciones*/{"\n 1. Deposito 0"
                                                 "\n 2. Deposito 1"
                                                 "\n 0. Cancelar"}};
        int opcion;
        opcion = eMenu_pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                eGestion_listado(this,
                                 eProducto_mostrarUno,
                                 PRODUCTO_LISTADO_TITULO,
                                 PRODUCTO_MOSTRAR_UNO_CABECERA,
                                 PRODUCTO_MSJ_LISTA_VACIA,
                                 PRODUCTO_MOSTRAR_UNO_PAGINADO);
                                 pausa();
                break;
            case 2:
                eGestion_listado(that,
                                 eProducto_mostrarUno,
                                 PRODUCTO_LISTADO_TITULO,
                                 PRODUCTO_MOSTRAR_UNO_CABECERA,
                                 PRODUCTO_MSJ_LISTA_VACIA,
                                 PRODUCTO_MOSTRAR_UNO_PAGINADO);
                                 pausa();
                break;
            case 0:
                break;
        }
    }
}
/**************************** ORDENAMIENTO *******************************************************/
int eProducto_compararPorId(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, eProducto_getId);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_compararPorDescripcion(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorString(this, that, eProducto_getDescripcion);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_ordenarPorDescripcion(ArrayList* this)
{
    int returnAux = CHECK_POINTER;

    if(this != NULL)
    {
        returnAux = OK;
        this->sort(this, eProducto_compararPorDescripcion, ASC);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
