////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÓN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colección de subprogramas útiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÓDIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarINTRO (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void descartarEntrada (void)
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////


void descartarEntrada (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro código ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacío
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void borrarPantalla (void)
//
//  USO:
//
//    Programa que sirve para borrar el contenido de la pantalla al volver a iniciar un programa para no ocupar más espacio
//
//  DETALLES:
//
//    Es un envoltorio de la función limpiarPantalla(), a la cual delega todo el
//    trabajo. sirve para crear "sinonimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//
//    NO RECIBE VALORES DE ENTRADA.
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//  void  limpiarPantalla(void)
////////////////////////////////////////////////////////////////////////////////

void borrarPantalla (void)
{
  limpiarPantalla();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void limpiarPantalla (void)
//
//
//  USO:
//
//    Programa que sirve para borrar el contenido de la pantalla al volver a iniciar un programa para no ocupar más espacio
//
//  DETALLES:
//
//    Es un envoltorio de la función system(BORRAR), a la cual delega todo el
//    trabajo. Sirve para crear "Sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//
//    NO RECIBE VALORES DE ENTRADA.
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//  system(BORRAR)
////////////////////////////////////////////////////////////////////////////////

void limpiarPantalla (void)
{
  system(BORRAR);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    Crea tantas líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n' ó 0x10.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)
{
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
    
    nlineas--;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void abajo (int nfils)
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de líneas que bajar que envía al programa bajar(nfils), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void abajo (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void saltar (int nfils)
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de líneas que bajar que envía al programa bajar(nfils), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void saltar (int nfils)
{
  bajar(nfils);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarFils (int nfils)
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de líneas que bajar que envía al programa bajar(nfils), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void desplazarFils (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarV (int nfils)
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de líneas que bajar que envía al programa bajar(nfils), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void desplazarV (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarY (int nfils)
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de líneas que bajar que envía al programa bajar(nfils), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void desplazarY (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void indentar (int ncolumnas)
//
//  USO:
//
//    Permite desplazar el cursor en la pantalla hacia la derecha, tantas columnas como se le indique.
//
//  DETALLES:
//
//    Crea tantos espacios en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con un espacio en blanco.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//
//      Variable entera que recibirá del exterior el número de espacios en blanco
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void derecha (int ncols)
//
//  USO:
//
//    Permite desplazar el cursor en la pantalla hacia la derecha, tantas columnas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de espacios que desplazar que envía al programa indentar(ncols), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de espacios en blanco
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void derecha (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void tabular (int ncols)
//
//  USO:
//
//    Permite desplazar el cursor en la pantalla hacia la derecha, tantas columnas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de espacios que desplazar que envía al programa indentar(ncols), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de espacios en blanco
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void tabular (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarCols (int ncols)
//
//  USO:
//
//    Permite desplazar el cursor en la pantalla hacia la derecha, tantas columnas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de espacios que desplazar que envía al programa indentar(ncols), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de espacios en blanco
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void desplazarCols (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarX (int ncols)
//
//  USO:
//
//    Permite desplazar el cursor en la pantalla hacia la derecha, tantas columnas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de espacios que desplazar que envía al programa indentar(ncols), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de espacios en blanco
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void desplazarX (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarH (int ncols)
//
//  USO:
//
//    Permite desplazar el cursor en la pantalla hacia la derecha, tantas columnas como se le indique.
//
//  DETALLES:
//
//    La función recibe un valor de espacios que desplazar que envía al programa indentar(ncols), al que delega todo el trabajo, esto sirve
//	  para crear "sinonimos" de acciones, es decir distintos programas que realizan la misma accion	
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de espacios en blanco
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols);
//		
//    programa creado anteriormente al que se delega todo el trabajo
//
//
////////////////////////////////////////////////////////////////////////////////

void desplazarH (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void posicionar (int nfils, int ncols)
//
//  USO:
//
//    Programa que desplaza el cursor en la pantalla hacia abajo y hacia la derecha el número de veces que le sea indicado
//
//  DETALLES:
//
//    Programa que llama tanto a bajar(nfils) y a tabular(ncols) a las que delega todo el trabajo despues de recibir 2 parámetros,ç
//	  uno para cada programa	
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que sirve para indicar el número de lineas en blanco que se desplazará el cursor
//
//    ncols
//
//		Variable de tipo entero que sirve para indicar el número de espacios en blanco que se desplazará el cursor      
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//    PROGRAMAS DE LOS QUE DEPENDE
//
//    bajar(nfils)
//
//      Recibe la variable de lineas en blanco que va a bajar y se ejecuta bajando el múmero de lineas
//
//    tabular(ncols)
//
//      Recibe la variable de espacios en blanco que va a desplazarse y se ejecuta desplazando el cursor hacia la derecha
//
////////////////////////////////////////////////////////////////////////////////

void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazar (int nfils, int ncols)
//
//  USO:
//
//    Programa que desplaza el cursor de la pantalla hacia la derecha y hacia abajo segun el número que se indique
//
//  DETALLES:
//
//    Recibe dos variables, una que indica las lineas que se desean bajar y otra que indica las columnas que se quieren desplazar,
//	  seguidamente las manda al programa posicionar(nfils, ncols) al que delega todo el trabajo, esto con el fin de crear 
//    "sinonimos" de acciones, es decir distintos programas que realizan la misma accion.	 
//    	
//    
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que sirve para indicar el número de lineas en blanco que se desplazará el cursor
//
//    ncols
//
//		Variable de tipo entero que sirve para indicar el número de espacios en blanco que se desplazará el cursor      
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar(nfils, ncols);
//
//    recibe las variables de columnas y lineas que se quieren desplazar y se pone en marcha desplazando el cursor tantas veces como se
//    haya indicado
//   
//
////////////////////////////////////////////////////////////////////////////////

void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazar (int nfils, int ncols)
//
//  USO:
//
//    Programa que desplaza el cursor de la pantalla hacia la derecha y hacia abajo segun el número que se indique
//
//  DETALLES:
//
//    Recibe dos variables, una que indica las lineas que se desean bajar y otra que indica las columnas que se quieren desplazar,
//	  seguidamente las manda al programa posicionar(nfils, ncols) al que delega todo el trabajo, esto con el fin de crear 
//    "sinonimos" de acciones, es decir distintos programas que realizan la misma accion.	 
//    	
//    
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que sirve para indicar el número de lineas en blanco que se desplazará el cursor
//
//    ncols
//
//		Variable de tipo entero que sirve para indicar el número de espacios en blanco que se desplazará el cursor      
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar(nfils, ncols);
//
//    recibe las variables de columnas y lineas que se quieren desplazar y se pone en marcha desplazando el cursor tantas veces como se
//    haya indicado
//   
//
////////////////////////////////////////////////////////////////////////////////

void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//	  void retardoSegundos (int segundosmax)	    
//
//  USO:
//
//    Crea un retardo en el ordenador del tiempo que se le indique
//
//  DETALLES:
//
//    Crea una serie de bucles "for" anidados que se repetiran de forma que en
//	  el primer bucle de los 4 que hay se de una vuelta cada segundo hasta alcanzar el valor que se 
//    haya introducido como variable
//    
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//
//      variable de tipo entero que servirá para dictaminar el tiempo de duración
//      del retardo
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    for()
//
//      Crea los bucles que darán el retraso al programa
//
//   
//
////////////////////////////////////////////////////////////////////////////////

void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en función de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//	  void retardoMilisegundos (int milisegundosmax)	    
//
//  USO:
//
//    Crea un retardo en el ordenador del tiempo que se le indique
//
//  DETALLES:
//
//    Crea una serie de bucles "for" anidados que se repetiran de forma que en
//	  el primer bucle de los 4 que hay se de una vuelta cada milisegundo hasta alcanzar el valor que se 
//    haya introducido como variable
//    
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//
//      variable de tipo entero que servirá para dictaminar el tiempo de duración
//      del retardo
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    for()
//
//      Crea los bucles que darán el retraso al programa
//
//   
//
////////////////////////////////////////////////////////////////////////////////

void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//	  void retrasoMilisegundos (int milisegundos)
//
//  USO:
//
//    Crea un retardo en el ordenador del tiempo que se le indique
//
//  DETALLES:
//
//    Usa la función de clock_t y un bucle hecho con un do{}while para crear un bucle que durará
//    el tiempo que haya sido indicado como variable
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      variable de tipo entero que servirá para dictaminar el tiempo de duración
//      del retardo
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    do{}while
//
//      Crea el bucle que dará el retraso al programa
//
//   
//
////////////////////////////////////////////////////////////////////////////////

void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarSegundos (int segundos)
//
//  USO:
//
//    Función que crea un retardo en el programa
//
//  DETALLES:
//
//   La función usa el programa prefabricado de sleep(), al que le será enviado     
//   el valor de segundos que dictaminarán la duracoón del retardo, también se 
//   ayuda de un #ifdef para alterar el bucle
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//
//     Variable de tipo entero que sirve para dictaminar el tiempo en segundos
//     del retardo
//
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep()
//    
//    función que crea el retraso en el programa usando la variable introducida
//
//
////////////////////////////////////////////////////////////////////////////////

void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarMiliegundos (int milisegundos)
//
//  USO:
//
//    Función que crea un retardo en el programa
//
//  DETALLES:
//
//   La función usa el programa prefabricado de sleep(), al que le será enviado     
//   el valor de milisegundos que dictaminarán la duracoón del retardo, también se 
//   ayuda de un #ifdef para alterar el bucle
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//     Variable de tipo entero que sirve para dictaminar el tiempo en milisegundos
//     del retardo
//
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep()
//    
//    función que crea el retraso en el programa usando la variable introducida
//
//
////////////////////////////////////////////////////////////////////////////////

void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausa (void)
//
//  USO:
//
//    Pausa el programa hasta que se pulse la tecla "intro"
//
//  DETALLES:
//
//    El programa al ponerse en marcha delega todo el trabajo a pausaEstandar(), es una forma
//    de generar "sinonimos" de funciones, es decir, dos funciones que hagan exactamente
//    lo mismo.
//
//    NO RECIBE VALORES DE ENTRADA.
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaEstandar()
//
//      Se delega en esta todo el trabajo.
//
//
////////////////////////////////////////////////////////////////////////////////

void pausa (void)
{
  pausaEstandar(1, 2);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaEstandar (int nfils, int ncols)
//
//  USO:
//
//    Crea una pausa hasta que se pulse la tecla "intro" del teclado, generando un mensaje y también desplaza el mensaje
//    ciertas columnas y filas
//
//  DETALLES:
//
//    Recibe dos variables que dictaminan el desplazamiento del mensaje, estas son
//    enviadas al programa pausaGenerica() al que se delega toda la acción, es una forma
//    de generar "sinonimos" de funciones, es decir, dos funciones que hagan exactamente
//    lo mismo. 
//
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable de tipo entero que dictamina el número de líneas en blanco
//      que se va a desplazar el mensaje
//
//    ncols
//
//      Variable de tipo entero que dictamina el número de espacios en blanco
//      que se va a desplazar el mensaje
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaGenerica()
//
//      se le pasan al programa las variables y se le delega todo el trabajo
////////////////////////////////////////////////////////////////////////////////

void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
//
//  USO:
//
//    Crea un mensaje que desplaza ciertas filas y ciertas columnas y no para hasta que se pulse la tecla "intro"
//
//  DETALLES:
//
//      el programa recibe un mensaje, un numero de filas y un numero de columnas
//      que se llevan a mensaje_x_y() al que se delega todo el trabajo, para crear "sinonimos" de 
//      acciones, es dedcir, dos acciones que hacen lo mismo y luego se espera a que se pulse intro con el programa
//      esperarINTRO()
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      variable de tipo char que muestra un mensaje a la pantalla
//      
//
//    nfils
//
//     Variable de tipo entero que sirve para dictaminar el número
//     de líneas en blanco que se desplaza el mensaje
//
//    ncols
//
//     Variable de tipo entero que sirve para dictaminar el número de 
//     espacios en blanco que se desplazará el mensaje
//
//    nuevalinea
//    
//    variable del tipo boolean
//
//    
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Se le llevan todas las variables y se delega toda la accion
//
//	  esperarINTRO
//   
//     Finaliza el programa cuando se pulsa intro
//
////////////////////////////////////////////////////////////////////////////////

void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);a

  esperarINTRO(); 
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void texto()
//
//  USO:
//
//    Crea un mensaje que se mostrará al usuario
//
//  DETALLES:
//
//    Recibe un mensaje que enviará al programa puts(); al que se delegará toda la acción
//    esto para crear "sinónimos" de acciones, es decir, acciones diferentes que hacen lo mismo
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      variable de tipo char que dictamina el mensaje que se va a mostrar
//      
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    puts()
//
//      Se le lleva el mensaje que se va a mostrar y se delega en el toda la acción
//
////////////////////////////////////////////////////////////////////////////////

void texto (char msjtxt[])
{
  puts(msjtxt);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void separar()
//
//  USO:
//
//    programa que genera un cambio de línea
//
//  DETALLES:
//
//    El programa llama a mostrar() que genera un cambio de línea
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//    mostrar()
//
//      Se pone en marcha el programa realizando un cambio de línea \n
//
////////////////////////////////////////////////////////////////////////////////

void separar()
{
  mostrar("\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void nuevaLinea (void)   
//
//  USO:
//
//    Desplaza el cursor una línea hacia abajo
//
//  DETALLES:
//
//    El programa llama a saltar(1) y se desplaza una línea hacia abajo
//    
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//     se pone en marcha el programa bajando una línea
//
//
////////////////////////////////////////////////////////////////////////////////

void nuevaLinea (void)
{
  saltar(1);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar (char msjtxt[])
//
//  USO:
//
//    Se muestra un mensaje sin desplazarlo nada
//
//  DETALLES:
//
//    Se recibe un mensaje de texto que se le manda a mensaje_x_y() y se le delega toda la acción
//
//  PARÁMETROS DE ENTRADA:
//
//    char msjtxt[]
//    
//   Variabled de tipo char que dicta el mensaje que se va a mostrar
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//    mostrar_x_y()
//
//    Recibe el mensaje que se va a mostrar y se pone en marcha
//
////////////////////////////////////////////////////////////////////////////////

void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra un mensaje que desplaza un numero determinado de columnas y filas
//
//  DETALLES:
//
//    Recibe un mensaje y un número de columnas y filas que desplazarlo, luego se los
//    llevará a mostrar_x_y() al que le delegará toda la acción, esto para crear "sinónimos" de acciones
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      variable de tipo char que dictamina el mensaje que se mostrará 
//      
//
//    nfils
//
//      Variable de tipo entero que dictamina el número de filas que se desplaza el mensaje
//     
//    ncols
//
//      Variable de tipo entero que dictamina el número de columnas que se desplaza el mensaje
//
// 
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     mensaje_x_y()
//
//      Se le da a este el mensaje que se va a mostrar así como el número de columnas y filas que se desplaza
//      
//
////////////////////////////////////////////////////////////////////////////////

void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir (char msjtxt[])
//
//  USO:
//
//    Muestra un mensaje que se muestra sin desplazarse
//
//  DETALLES:
//
//    Recibe un mensaje, luego se lo llevará a escribir_x_y() al que le delegará toda la acción, esto para crear "sinónimos" de acciones
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      variable de tipo char que dictamina el mensaje que se mostrará 
//
// 
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     escribir_x_y()
//
//      Se le da a este el mensaje que se va a mostrar 
//      
//
////////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir_x_y(char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra un mensaje que desplaza un numero determinado de columnas y filas
//
//  DETALLES:
//
//    Recibe un mensaje y un número de columnas y filas que desplazarlo, luego se los
//    llevará a mensaje_x_y() al que le delegará toda la acción, esto para crear "sinónimos" de acciones
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      variable de tipo char que dictamina el mensaje que se mostrará 
//      
//
//    nfils
//
//      Variable de tipo entero que dictamina el número de filas que se desplaza el mensaje
//     
//    ncols
//
//      Variable de tipo entero que dictamina el número de columnas que se desplaza el mensaje
//
// 
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     mensaje_x_y()
//
//      Se le da a este el mensaje que se va a mostrar así como el número de columnas y filas que se desplaza
//      
//
////////////////////////////////////////////////////////////////////////////////

void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir(char msjtxt[])
//
//  USO:
//
//    Recibe un mensaje que se muestra sin desplazarse
//
//  DETALLES:
//
//    Recibe un mensaje, luego se lo llevará a imprimir_x_y() al que le delegará toda la acción, esto para crear "sinónimos" de acciones
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      variable de tipo char que dictamina el mensaje que se mostrará 
//
// 
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     imprimir_x_y()
//
//      Se le da a este el mensaje que se va a mostrar 
//      
//
////////////////////////////////////////////////////////////////////////////////

void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir_x_y(char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra un mensaje que desplaza un numero determinado de columnas y filas
//
//  DETALLES:
//
//    Recibe un mensaje y un número de columnas y filas que desplazarlo, luego se los
//    llevará a mensaje_x_y() al que le delegará toda la acción, esto para crear "sinónimos" de acciones
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      variable de tipo char que dictamina el mensaje que se mostrará 
//      
//
//    nfils
//
//      Variable de tipo entero que dictamina el número de filas que se desplaza el mensaje
//     
//    ncols
//
//      Variable de tipo entero que dictamina el número de columnas que se desplaza el mensaje
//
// 
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     mensaje_x_y()
//
//      Se le da a este el mensaje que se va a mostrar así como el número de columnas y filas que se desplaza
//      
//
////////////////////////////////////////////////////////////////////////////////

void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje(char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra un mensaje que desplaza un numero determinado de columnas y filas
//
//  DETALLES:
//
//    Recibe un mensaje y un número de columnas y filas que desplazarlo, luego se los
//    llevará a mensaje_x_y() al que le delegará toda la acción, esto para crear "sinónimos" de acciones
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//
//      variable de tipo char que dictamina el mensaje que se mostrará 
//      
//
//    nfils
//
//      Variable de tipo entero que dictamina el número de filas que se desplaza el mensaje
//     
//    ncols
//
//      Variable de tipo entero que dictamina el número de columnas que se desplaza el mensaje
//
// 
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//     mensaje_x_y()
//
//      Se le da a este el mensaje que se va a mostrar así como el número de columnas y filas que se desplaza
//      
//
////////////////////////////////////////////////////////////////////////////////

void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
//
//  USO:
//
//    Muestra un mensaje en pantalla que mostrará desplazando ciertas filas y columnas
//
//  DETALLES:
//
//    Usa saltar() y tabular() para desplazar un mensaje que mostrará llamando a printf()
//    y luego, dependiendo de la variable nuevalinea, hará un cambio de linea
//    
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//     Variable del tipo char que dictamina el mensaje que se mostrará      
//
//
//    nfils
//
//      Variable del tipo entero que dictamina el numero de lineas en blanco que se desplazará el mensaje     
// 
//    ncols
//
//      Variable del tipo entero que dictamina el numero de espacios en blanco que se desplazará el mensaje
//
//    nuevalinea
//
//      Variable del tipo boolean que sirve para dictaminar su hay o no salto de linea
//
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Se le entrega el número de líneas en blanco que se va a desplazar y se pone en marcha
//
//    tabular()
//
//      Se le entrega el número de espacios en blanco que se va a desplazar y se pone en marcha
//
//    printf()
//
//      Función predeterminada para mostrar texto
//
////////////////////////////////////////////////////////////////////////////////

void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void iniciaAleatorizador (void)
//
//  USO:
//
//    Función que inicia un programa aleatorizador
//
//  DETALLES:
//
//    pone en marcha la función srand()
//
//
//    NO RECIBE VALORES DE ENTRADA.
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    srand()
//
//      Se le delega toda la acción
//
//
////////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int generaAleatorioEntero (int limite)
//
//  USO:
//
//    Genera un número aleatorio entre 0 y el límite
//
//  DETALLES:
//
//   se introduce un número que hará de límite y el programa rand() generará un valor aleatorio y lo devolverá
//
//  PARÁMETROS DE ENTRADA:
//
//    limite
//
//      Variable de tipo entero que dictamina el valor máximo que puede tener el número que generamos  
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa un número aleatorio
//
//
//    return()
//
//      Devuelve un valor
//
//    rand()
//   
//      Genera un vaslor aleatorio
//
////////////////////////////////////////////////////////////////////////////////

int generaAleatorioEntero (int limite)
{
  // Generará un número entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    Sustitución mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La función scanf() no retira el código ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras después de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra función creada en esta librería,
//    vaciarBuffer() para ello. No muestra ningún mensaje por pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//  Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la función scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerCaracterASCII()
//
//  USO:
//
//    Obtiene una letra 
//
//  DETALLES:
//
//    El programa delega toda la acción a obtenerLetra(), creando "sinónimos" de acciones,
//    es decir, dos acciones que realizan la misma acción
//
//
//    NO RECIBE VALORES DE ENTRADA.
//
//    VALORES DE SALIDA
//    
//    Devuelve una letra que se obtiene de obtenerLetra
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra();
//
//      Se le delega toda la acción 
//
//
////////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerLetra (void)
//
//  USO:
//
//    Programa que sirve para pedir una letra y devolverla al usuario
//
//  DETALLES:
//
//    Utiliza un getchar para obtener una letra (sólo ASCII válido) y controlará
//    los valores mediante un if(), se retornará la letra elegida al usuario
//    
//
//  PARÁMETROS DE ENTRADA:
//
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra que se haya elegido al usuario
//    
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    return
//
//      Devuelve la letra al finalizar el programa
//
//    getchar()
//
//      Sirve para recojer la letra que se quiera
//
//    vaciarBuffer()
//    
//    espera que el usuario pulse teclas a la espera de INTRO.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerLetra (void)   // Sólo ASCII VÁLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÓDIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de múltiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un número de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() más un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. También impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    función obtenerEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibirá el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibirá del exterior el número de espacios en
//      blanco a añadir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    función ha recibido desde la función obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para añadir en pantalla un texto adicional después del mensaje.
//
//    obtenerEntero()
//
//      Es la función que se encarga en la práctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero positivo al usuario.
//
//  DETALLES:
//
//    Usa un bucle do-while para entrampar al usuario hasta que introduzca un
//    número que sea mayor o igual a cero.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto del mensaje a mostrar.
//
//    ncols
//
//      Entero que indica los espacios en blanco a añadir antes del mensaje.
//
//    mostrarerror
//
//      Booleano que indica si se debe mostrar un mensaje de error si falla.
//
//  VALOR DE SALIDA:
//
//    Devuelve el número entero positivo introducido por el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//      Muestra el texto con margen.
//
//    mostrar()
//      Imprime texto en pantalla.
//
//    obtenerEntero()
//      Lee el número del teclado.
//
//    nuevaLinea()
//      Realiza un salto de línea.
//
//    mensaje_x_y()
//      Muestra el error en coordenadas concretas.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < 0);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
//
//  USO:
//
//    Pide al usuario un número entero que esté dentro de un rango específico.
//
//  DETALLES:
//
//    Usa un do-while para obligar al usuario a introducir un valor que esté
//    entre los límites pasados como parámetros.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto del mensaje a mostrar.
//
//    ncols
//
//      Entero que indica los espacios de margen izquierdo del mensaje.
//
//    mostrarerror
//
//      Indica si se muestra o no un mensaje de error si se sale del límite.
//
//    min
//
//      Indica el valor mínimo permitido en el intervalo.
//
//    max
// 
//      Indica el valor máximo permitido en el intervalo.
//
//  VALOR DE SALIDA:
//
//    Devuelve el número válido que haya introducido el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//      Muestra el texto con margen.
//
//    obtenerEntero()
//      Lee el número del teclado.
//
//    nuevaLinea()
//      Realiza un salto de línea.
//
//    mensaje_x_y()
//      Muestra el error en coordenadas concretas.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
//
//  USO:
//
//    Obliga al usuario a introducir una letra concreta por teclado.
//
//  DETALLES:
//
//    Convierte las letras a mayúsculas para hacer la comparación. Atrapa al 
//    usuario en un bucle hasta que pulse la letra exacta requerida.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto a mostrar antes de pedir la letra.
//
//    ncols
//
//      Número de espacios a desplazar desde la izquierda.
//
//    mostrarerror
//
//      Booleano para activar el mensaje de fallo si se equivoca.
//
//    letra
//
//      Carácter exacto que se espera que el usuario pulse.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra introducida por el usuario, convertida en mayúscula.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//      Pasa la letra a mayúscula (Librería estándar).
//
//    mensaje()
//      Muestra el texto en pantalla.
//
//    mostrar()
//      Imprime texto simple.
//
//    obtenerLetra()
//      Captura el carácter del teclado.
//
//    nuevaLinea()
//      Salto de línea.
//
//    mensaje_x_y()
//      Impresión de error posicionado.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
//
//  USO:
//
//    Pide al usuario que confirme una acción respondiendo Sí o No.
//
//  DETALLES:
//
//    Compara la entrada con las constantes 'SI' y 'NO'. Trabaja siempre con
//    mayúsculas para evitar problemas y usa un bucle de repetición.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto de la pregunta a mostrar al usuario.
//
//    ncols
//
//      Espacios de margen para el mensaje.
//
//    mostrarerror
//
//      Indica si saltará error visual si la respuesta es incorrecta.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra (SI o NO) pulsada por el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//      Despliega la pregunta.
//
//    obtenerLetra()
//      Captura lo que se pulsa.
//
//    toupper()
//      Transforma la entrada en mayúscula.
//
//    nuevaLinea()
//      Da espacio tras intentar responder.
//
//    mensaje_x_y()
//      Se encarga de imprimir el error si lo hay.
//
////////////////////////////////////////////////////////////////////////////////

int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
//
//  USO:
//
//    Comprueba si dos caracteres dados son iguales.
//
//  DETALLES:
//
//    Permite configurar si la comprobación distingue o no entre mayúsculas
//    y minúsculas (case sensitive).
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//
//      Primer carácter a comparar (la referencia).
//
//    dada
//
//      Segundo carácter a comparar (la entrada).
//
//    sensibleamayusculas
//
//      Si es FALSE, convierte ambas a mayúsculas antes de comparar.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si las letras coinciden, FALSE si son diferentes.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//      Iguala el formato de letras si se ignora el tipo de caja.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
//
//  USO:
//
//    Verifica si una letra se encuentra dentro de un grupo de letras válido.
//
//  DETALLES:
//
//    Recorre la cadena de opciones posibles y compara el carácter dado con 
//    cada una de ellas hasta encontrar una coincidencia.
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//
//      Carácter que queremos buscar.
//
//    seleccion
//
//      Cadena de texto con todas las opciones válidas.
//
//    sensibleamayusculas
//
//      Booleano para tener en cuenta si hay diferencias entre mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si la letra está en el conjunto, FALSE si no la encuentra.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//      Para saber la longitud de la cadena de opciones.
//
//    validarLetraUnica()
//      Para comparar uno a uno los caracteres del conjunto.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char *cadenaOpcionesDisponibles (char entrada[])
//
//  USO:
//
//    Toma una cadena de opciones ("ABC") y la formatea con barras ("A/B/C").
//
//  DETALLES:
//
//    Usa memoria dinámica (malloc) para crear una nueva cadena con el doble
//    de tamaño, por lo que requerirá usar un free() posteriormente para liberarla.
//
//  PARÁMETROS DE ENTRADA:
//
//    entrada
//
//      Cadena de caracteres original sin separación.
//
//  VALOR DE SALIDA:
//
//    Devuelve un puntero a la nueva cadena de caracteres con el formato "X/Y/Z".
//    Si la entrada es nula, devuelve NULL.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//      Para medir el tamaño de la cadena de entrada.
//
//    malloc()
//      Para reservar memoria suficiente para la cadena final.
//
////////////////////////////////////////////////////////////////////////////////

char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas máximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacía, así que generamos vacía. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la última '/' por un '\0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
//
//  USO:
//
//    Pide al usuario pulsar una letra que esté dentro de un menú de opciones.
//
//  DETALLES:
//
//    Muestra el menú de letras válidas separadas por barras. Encierra al 
//    usuario en un bucle hasta que dé una letra que exista en el conjunto.
//    Se encarga de liberar la memoria de la cadena formateada temporal.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto a mostrar pidiendo la selección.
//
//    ncols
//
//      Márgenes de la izquierda para imprimir.
//
//    mostrarerror
//
//      Si es TRUE avisa al usuario visualmente de que la tecla no es válida.
//
//    seleccion
//
//      Cadena con todas las letras permitidas.
//
//    sensibleamayusculas
//
//      Decide si exige coincidencia estricta de mayúsculas/minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra correcta elegida por el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    cadenaOpcionesDisponibles()
//      Formatea visualmente las opciones.
//
//    mensaje(), mostrar(), printf(), nuevaLinea(), mensaje_x_y()
//      Para mostrar interfaz y errores por pantalla.
//
//    obtenerLetra()
//      Captura lo que se teclea.
//
//    validarLetraConjunto()
//      Comprueba si la letra está entre las válidas.
//
//    free()
//      Libera la memoria dinámica usada para el formato visual.
//
//    toupper()
//      Estandariza a mayúsculas si corresponde.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con «seleccion» a valor NULL.
  
  // Usar «cadenaOpcionesDisponibles()» implica luego liberar memoria con «free()».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayúsculas, siempre la devolvemos mayúscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}

#ifdef SO_WINDOWS

#include <conio.h>

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerTeclaInteractiva(void)
//
//  USO:
//
//    Lee una tecla directamente del usuario en sistemas Windows.
//
//  DETALLES:
//
//    Captura la tecla al instante sin esperar a que se pulse Enter. Traduce 
//    teclas especiale a códigos unificados.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve un carácter que representa la tecla pulsada o el código de la 
//    tecla especial mapeada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    _getch()
//      Función nativa de <conio.h> en Windows para leer caracteres bloqueando.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo código. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // Normalización de teclas conflictivas no estándar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}

#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerTeclaInteractiva(void)
//
//  USO:
//
//    Lee una tecla directamente del usuario en sistemas basados en UNIX/Linux.
//
//  DETALLES:
//
//    Altera la configuración de la consola para leer la pulsación sin esperar
//    a que se pulse Enter y ocultando lo que se ha escrito. Descifra las secuencias 
//    de escape enviadas por flechas.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve el código de la tecla estándar o especial pulsada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    tcgetattr() y tcsetattr()
//      Para obtener y aplicar configuraciones a la terminal.
//
//    getchar()
//      Para leer los caracteres de entrada estándar de C.
//
//    fcntl()
//      Para activar temporalmente la lectura no bloqueante.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuración actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canónico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquí hasta recibir un carácter.
  // Las flechas envían una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // ¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer código de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era sólo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuración original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
