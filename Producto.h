#pragma once
#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "ArrayList.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************************** LIMITES ************************************************************/
#define PRODUCTO_LARGO_DESCRIPCION 50
#define PRODUCTO_ID_MIN 1
#define PRODUCTO_ID_MAX 1000000
#define PRODUCTO_CANT_MIN 1
#define PRODUCTO_CANT_MAX 1000000

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    //------------id
    int idProducto;
    //------------properties
    char descripcion[PRODUCTO_LARGO_DESCRIPCION];
    int cantidad;
}eProducto;


/**************************** GETTERS ************************************************************/
int eProducto_getId(void* this);
char* eProducto_getDescripcion(void* this);
int eProducto_getCantidad(void* this);

/**************************** SETTERS ************************************************************/
int eProducto_setId(void* this, int id);
int eProducto_setDescripcion(void* this, char* descripcion);
int eProducto_setCantidad(void* this, int cantidad);

/**************************** CONSTRUCTORES ******************************************************/
void* eProducto_new();
void* eProducto_newParam(int id, char* descripcion, int cantidad);

/**************************** ENTRADA DE DATOS ***************************************************/
//char* eProducto_pedirDescripcion();
//int eProducto_pedirCantidad();
//void* eProducto_pedirProducto(ArrayList* this);

/**************************** GESTION DE DATOS ***************************************************/
int eProducto_modificarUno(void* this);
char* eProducto_parserATexto(void* this, int bufferSize);
void* eProducto_parserAVoid(char* this, int bufferSize);
void eProducto_cargarArchivos(ArrayList* this, ArrayList* that);

/**************************** LISTADO DE DATOS ***************************************************/
void eProducto_mostrarUno(void* producto);

/**************************** ORDENAMIENTO *******************************************************/
int eProducto_compararPorId(void* this, void* that);
int eProducto_compararPorDescripcion(void* this, void* that);
int eProducto_compararPorCantidad(void* this, void* that);
int eProducto_ordenarPorDescripcion(ArrayList* this);

/**************************** TITULOS ************************************************************/
#define PRODUCTO_ALTA_TITULO "ALTA DE PRODUCTO"
#define PRODUCTO_MODIFICACION_TITULO "MODIFICACION DE PRODUCTO"
#define PRODUCTO_BAJA_TITULO "BAJA DE PRODUCTO"
#define PRODUCTO_LISTADO_TITULO "LISTADO DE PRODUCTOS"

/**************************** MENSAJES INPUT *****************************************************/
#define PRODUCTO_MSJ_INGRESE_ID "\n\nIngrese el ID de Producto: \0"
#define PRODUCTO_MSJ_INGRESE_DESCRIPCION "\nIngrese Descripcion y Apellido: \0"
#define PRODUCTO_MSJ_INGRESE_CANTIDAD "\nIngrese cantidad: \0"
#define PRODUCTO_MSJ_INGRESE_TARJETA "\nIngrese numero de tarjeta: \0"
#define PRODUCTO_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Producto?"

/**************************** MENSAJES ERROR *****************************************************/
#define PRODUCTO_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define PRODUCTO_MSJ_ID_NO_EXISTE "\nEl ID de Producto ingresado no existe"
#define PRODUCTO_MSJ_LISTA_VACIA "\n\nLa lista de Productos esta vacia"
#define PRODUCTO_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Producto"
#define PRODUCTO_MSJ_REINGRESE_DESCRIPCION "\nDescripcion muy largo. Reingrese por favor: \0"
#define PRODUCTO_MSJ_REINGRESE_CANTIDAD "\nCantidad muy larga. Reingrese por favor: \0"
#define PRODUCTO_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define PRODUCTO_MSJ_ALTA_OK "\nEl Producto se dio de alta"
#define PRODUCTO_MSJ_BAJA_OK "\nEl Producto se dio de baja"
#define PRODUCTO_MSJ_MODIFICACION_OK "\nEl Producto se modifico"
#define PRODUCTO_MSJ_REGISTRO_ACTUAL "\n\nProducto actual: "
#define PRODUCTO_MSJ_REGISTRO_MODIFICADO "\n\nProducto modificado: "

/**************************** LISTADOS ***********************************************************/
#define PRODUCTO_MOSTRAR_UNO_MASCARA "\n%d \t %-10s \t %d"
#define PRODUCTO_MOSTRAR_UNO_CABECERA "\nID \t DESCRIPCION \t\t CANTIDAD\n-- \t ---- \t\t -----"
#define PRODUCTO_MOSTRAR_UNO_PAGINADO 20

/**************************** ORDENAMIENTO *******************************************************/
#define PRODUCTO_ORDEN_DESCRIPCION "descripcionAsc"
#define PRODUCTO_ORDEN_ID "idAsc"

#endif // PRODUCTO_H_INCLUDED
