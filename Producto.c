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
int eProducto_cargarArchivos(ArrayList* this, ArrayList* that)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && that != NULL)
    {
        returnAux = OK;

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
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_elegirDeposito()
{
    eMenu menuPrincipal = {/*titulo del menu*/{"ELIJA DEPOSITO ORIGEN"},
                       /*cantidad de opciones*/3,
                       /*codigos*/{1,2,
                       0},
                       /*descripciones*/{"\n 1. Deposito 0"
                                         "\n 2. Deposito 1"
                                         "\n 0. Cancelar"}};
    return eMenu_pedirOpcion(&menuPrincipal);
}
//-----------------------------------------------------------------------------------------------//
int eProducto_listarDeposito(ArrayList* this, ArrayList* that)
{
    int returnAux = CHECK_POINTER;

    if(this != NULL && that != NULL)
    {
        returnAux = OK;
        switch(eProducto_elegirDeposito())
        {
            case 1:
                eGestion_listado(this,
                                 eProducto_mostrarUno,
                                 PRODUCTO_LISTADO_TITULO,
                                 PRODUCTO_MOSTRAR_UNO_CABECERA,
                                 PRODUCTO_MSJ_LISTA_VACIA,
                                 PRODUCTO_MOSTRAR_UNO_PAGINADO);
                break;
            case 2:
                eGestion_listado(that,
                                 eProducto_mostrarUno,
                                 PRODUCTO_LISTADO_TITULO,
                                 PRODUCTO_MOSTRAR_UNO_CABECERA,
                                 PRODUCTO_MSJ_LISTA_VACIA,
                                 PRODUCTO_MOSTRAR_UNO_PAGINADO);
                break;
            case 0:
                break;
        }
    }
    else
    {
        imprimirEnPantalla("\nError en asignacion de punteros");
    }
    pausa();
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_moverProductos(ArrayList* this, ArrayList* that)
{
    int returnAux = CHECK_POINTER;
    void* pElement = NULL;
    char confirmacion;

    if(this != NULL && that != NULL)
    {
        switch(eProducto_elegirDeposito())
        {

            case 1:
                if(!eGestion_informarListadoVacio(this, PRODUCTO_MSJ_LISTA_VACIA))
                {
                    while(pElement == NULL)
                    {
                        eGestion_listado(this,
                                 eProducto_mostrarUno,
                                 PRODUCTO_LISTADO_TITULO,
                                 PRODUCTO_MOSTRAR_UNO_CABECERA,
                                 PRODUCTO_MSJ_LISTA_VACIA,
                                 PRODUCTO_MOSTRAR_UNO_PAGINADO);
                        saltoDeLinea();
                        imprimirTitulo("MOVER PRODUCTO DE 0 A 1");
                        pElement = eGestion_pedirIdYBuscar(this,
                                                           eProducto_getId,
                                                           PRODUCTO_MSJ_INGRESE_ID,
                                                           PRODUCTO_MSJ_REINGRESE_ID,
                                                           PRODUCTO_ID_MIN,
                                                           PRODUCTO_ID_MAX);
                        if(pElement == NULL)
                        {
                            imprimirEnPantalla("\nNo se encontro el ID ingresado");
                            pausa();
                        }
                    }

                    limpiarPantallaYMostrarTitulo("MOVER PRODUCTO DE 0 A 1");
                    imprimirEnPantalla(PRODUCTO_MOSTRAR_UNO_CABECERA);
                    eProducto_mostrarUno(pElement);
                    confirmacion = pedirConfirmacion("\nConfirma que desea mover dicho producto");

                    if(confirmacion == 'S')
                    {
                        pElement = this->pop(this, this->indexOf(this, pElement));
                        that->add(that, pElement);
                        this->sort(this, eProducto_compararPorId, ASC);
                        this->sort(that, eProducto_compararPorId, ASC);
                        imprimirEnPantalla("\nSe movio el producto del deposito 0 al 1");
                    }
                    else
                    {
                        imprimirEnPantalla(MSJ_CANCELO_GESTION);
                    }
                    returnAux = OK;
                }
                break;
            case 2:
                if(!eGestion_informarListadoVacio(that, PRODUCTO_MSJ_LISTA_VACIA))
                {
                    while(pElement == NULL)
                    {
                        eGestion_listado(that,
                                 eProducto_mostrarUno,
                                 PRODUCTO_LISTADO_TITULO,
                                 PRODUCTO_MOSTRAR_UNO_CABECERA,
                                 PRODUCTO_MSJ_LISTA_VACIA,
                                 PRODUCTO_MOSTRAR_UNO_PAGINADO);
                        saltoDeLinea();
                        imprimirTitulo("MOVER PRODUCTO DE 1 A 0");
                        pElement = eGestion_pedirIdYBuscar(that,
                                                           eProducto_getId,
                                                           PRODUCTO_MSJ_INGRESE_ID,
                                                           PRODUCTO_MSJ_REINGRESE_ID,
                                                           PRODUCTO_ID_MIN,
                                                           PRODUCTO_ID_MAX);
                        if(pElement == NULL)
                        {
                            imprimirEnPantalla("\nNo se encontro el ID ingresado");
                            pausa();
                        }
                    }

                    limpiarPantallaYMostrarTitulo("MOVER PRODUCTO DE 1 A 0");
                    imprimirEnPantalla(PRODUCTO_MOSTRAR_UNO_CABECERA);
                    eProducto_mostrarUno(pElement);
                    confirmacion = pedirConfirmacion("\nConfirma que desea mover dicho producto");

                    if(confirmacion == 'S')
                    {
                        pElement = that->pop(that, that->indexOf(that, pElement));
                        this->add(this, pElement);
                        that->sort(that, eProducto_compararPorId, ASC);
                        that->sort(this, eProducto_compararPorId, ASC);
                        imprimirEnPantalla("\nSe movio el producto del deposito 1 al 0");
                    }
                    else
                    {
                        imprimirEnPantalla(MSJ_CANCELO_GESTION);
                    }
                    returnAux = OK;
                }

                break;
            case 0:
                break;
        }
    }
    else
    {
        imprimirEnPantalla("\nError en asignacion de punteros");pausa();
    }

    pausa();
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eProducto_manejarStockProductos(ArrayList* this, ArrayList* that, int operacion)
{
    //operacion 1 agrega, operacion -1 descuenta
    int returnAux = CHECK_POINTER;
    void* pElement = NULL;
    int cantidadDisponible;
    int cantidadIngresada;
    int cantidadCalculada;
    int id;
    char confirmacion;
    char* tituloDescontar = "DESCONTAR PRODUCTOS A DEPOSITO";
    char* tituloAgregar = "AGREGAR PRODUCTOS A DEPOSITO";

    if(operacion > 0)
    {
        limpiarPantallaYMostrarTitulo(tituloAgregar);
    }
    else
    {
        limpiarPantallaYMostrarTitulo(tituloDescontar);
    }

    if(this != NULL && that != NULL)
    {
        returnAux = OK;
        id = pedirIntValido(PRODUCTO_MSJ_INGRESE_ID, PRODUCTO_MSJ_REINGRESE_ID, PRODUCTO_ID_MIN, PRODUCTO_ID_MAX);
        pElement = eGestion_buscarPorId(this, eProducto_getId, id);

        if(pElement == NULL)
        {
            pElement = eGestion_buscarPorId(that, eProducto_getId, id);

        }

        if(pElement == NULL)
        {
            imprimirEnPantalla("\nNo se encontro el producto ingresado en ningun deposito");
        }
        else
        {
            eProducto_mostrarUno(pElement);
            cantidadDisponible = eProducto_getCantidad(pElement);
            printf("\nLa cantidad disponible es de %d", cantidadDisponible);
            if(operacion < 0)
            {
                cantidadIngresada = pedirIntValido("\nIngrese la cantidad: ", "\nLa cantidad no es valida. Reingrese por favor: ", 1, cantidadDisponible);
            }
            else
            {
                cantidadIngresada = pedirIntValido("\nIngrese la cantidad: ", "\nLa cantidad no es valida. Reingrese por favor: ", 1, PRODUCTO_CANT_MAX);
            }
            cantidadCalculada = (cantidadDisponible + (operacion * cantidadIngresada));
            printf("\nNueva cantidad: %d",cantidadCalculada);
            confirmacion = pedirConfirmacion("\nConfirma que desea modificar la cantidad");

            if(confirmacion == 'S')
            {
                eProducto_setCantidad(pElement, cantidadCalculada);
            }
            else
            {
                imprimirEnPantalla("\nSe cancelo la gestion");
            }
        }
    }
    else
    {
        imprimirEnPantalla("\nError en asignacion de punteros");pausa();
    }

    pausa();
    return returnAux;
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
