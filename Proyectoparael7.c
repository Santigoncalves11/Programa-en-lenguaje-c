// Proyecto: cuadro de texto con borde de arterisco. listo
// Corrección ortográfica
// Corrección con click (Programar cursor). no listo          
// Corrección en rojo. no listo                              
// Corrección incluye          
// Justificación del texto.  listo
// Debe crear una hoja con un máximo de 22 línea en el compilador 22 líneas al llegar a las linea 22 crear otra hoja, hasta un máximo de 4. Casi listo.
// Mayúscula después de un punto y seguido.
// Al darle enter, que baje a la siguiente línea. listo 


#include <stdio.h> 
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h> // Para el cursor
#include <stdnoreturn.h>
#include <unistd.h> // Valores por linea


#define MAX_LINEAS 22
#define JUSTIFICACION_TEXTO
#define ESPACIO 32
#define ENTER 13
#define BORRAR 8 
#define ESP 27 
#define __HYPHEN_H__
#define MAX_NAME 20
#define MAX_CHARS 100
#define __NCURSES_H
#define CURSES 1
#define CURSES_H 1
#undef	NCURSES_COLOR_T
#undef	NCURSES_SIZE_T
#define	NCURSES_COLOR_T short
#define	NCURSES_SIZE_T short
#define COLOR_RED 1
#define COLOR_WHITE 7 

// Aquí es donde va toda la entrada a la ventana.
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	
	switch (Message){
	
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}

		default:
		return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX clase; // Estructura de propiedades de la ventana.
	HWND hwnd; // Un 'HANDLE', de ahí la H, o un puntero a nuestra ventana.
	MSG msg; // Ubicación temporal para todos los mensajes.

	memset(&clase,0,sizeof(clase));

	clase.cbSize		 = sizeof(WNDCLASSEX);
	clase.lpfnWndProc	 = WndProc; // Aquí es donde enviaremos los mensajes
	clase.hInstance	     = hInstance;
	clase.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	// Blanco, COLOR_WINDOW es solo un #definir para un color del sistema, intente Ctrl+Hacer clic en él
	clase.hbrBackground  = (HBRUSH)(COLOR_MENU);
	clase.lpszClassName  = "Windoclaselass";
	clase.hIcon		     = LoadIcon(NULL, IDI_APPLICATION); //  Cargar un icono estándar
	clase.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); //  Use el nombre "A" para usar el ícono del proyecto

	if(!RegisterClassEx(&clase)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"Windoclaselass"," Word de santi",WS_VISIBLE|WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
	CreateWindowEx(0,"EDIT","",ES_LEFT|WS_CHILD|ES_MULTILINE|ES_WANTRETURN|WS_VISIBLE,150,20,300,400,hwnd,NULL, hInstance,NULL);
	SendMessage(hwnd, EM_SETLIMITTEXT, 22 * 80, 0); // Limita el número de líneas a 22. 
	ShowWindow (hwnd, nCmdShow);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
 
	while(GetMessage(&msg, NULL, 0, 0) > 0) { // Si no se recibe ningún error...
		TranslateMessage(&msg); // Traducir códigos clave a caracteres si están presentes.
		DispatchMessage(&msg); // Envíalo a WndProc.
	}
	return msg.wParam;
	
	// Función que divide un texto en líneas de un ancho máximo dado y las justifica.
    void justificar_texto(char* texto, int ancho_maximo) {
    char linea[ancho_maximo + 1]; // Buffer para almacenar cada línea.
    int i = 0; // Índice para recorrer el texto.
    int j = 0; // Índice para recorrer la línea.
    int k = 0; // Índice para guardar la posición del último espacio.
    while (texto[i] != '\0') { // Mientras no se llegue al final del texto.
    if (texto[i] == ' ') { // Si se encuentra un espacio.
      k = j; // Se guarda la posición del espacio en la línea.
    }
    linea[j] = texto[i]; // Se copia el carácter del texto a la línea.
    j++; // Se incrementa el índice de la línea.
    i++; // Se incrementa el índice del texto.
    if (j == ancho_maximo) { // Si se llega al ancho máximo de la línea.
      linea[j] = '\0'; // Se termina la línea con el carácter nulo.
      if (texto[i] != ' ' && k > 0) { // Si el siguiente carácter no es un espacio y hay un espacio anterior.
        i -= (j - k - 1); // Se retrocede el índice del texto hasta el espacio.
        linea[k] = '\0'; // Se termina la línea en el espacio.
      }
      printf("%-80s\n", linea); // Se imprime la línea justificada.
      j = 0; // Se reinicia el índice de la línea.
    }
  }
  if (j > 0) { // Si quedan caracteres en la línea.
    linea[j] = '\0'; // Se termina la línea con el carácter nulo.
    printf("%-80s\n", linea); // Se imprime la última linea justificada.
  }
}

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX clase; // Estructura de propiedades de la ventana.
	HWND hwnd; // Un 'HANDLE', de ahí la H, o un puntero a nuestra ventana.
	MSG msg; // Ubicación temporal para todos los mensajes.

	memset(&clase,0,sizeof(clase));

	clase.cbSize		 = sizeof(WNDCLASSEX);
	clase.lpfnWndProc	 = WndProc; // Para enviar el mensaje. 
	clase.cbWndExtra     = 0;
	clase.cbClsExtra     = 0;
	clase.hInstance	     = hInstance;
	clase.hCursor		 = LoadCursor(NULL,IDC_ARROW);
	clase.hIcon          = LoadIcon(NULL,IDI_APPLICATION);
	
	// Blanco, COLOR_WINDOWS es solo un #definir para un color del sistema, intente Ctrl+Hacer clic en el.
	clase.hbrBackground  = (HBRUSH)(COLOR_MENU);
	clase.lpszClassName  = "WindowsWord";
    clase.hIcon		     = LoadIcon(NULL, IDI_APPLICATION);  // Cargar un icono estandar.
	clase.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); // Usar el nombre "A" para usar el icono del proyecto.

	if(!RegisterClassEx(&clase)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
}
	// Función que imprime el texto en el control EDIT de la ventana.
void imprimir_texto(HWND hwnd, char* texto) {
  // Obtiene el identificador del control EDIT.
  HWND hEdit = GetDlgItem(hwnd, 0);
  // Borra el contenido actual del control.
  SetWindowText(hEdit, "");
  // Imprime el texto en el control.
  SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)texto);
}

// Entrada a la ventana.
LRESULT CALLBACK WndProc(HWND hwnd, UINT Mensaje, WPARAM wParam, LPARAM lParam) {
	
	switch (Mensaje){
	
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		case WM_COMMAND: {
			if (LOWORD(wParam) == 1) { // Si se presiona el botón de justificar.
				// Obtiene el texto desde el control EDIT.
				char* texto = obtener_texto(hwnd);
				// Justifica el texto.
				justificar_texto(texto, 80);
				// Imprime el texto en el control EDIT.
				imprimir_texto(hwnd, texto);
				// Libera la memoria del texto.
				free(texto);
			}
			break;
		}

		default:
		return DefWindowProc(hwnd, Mensaje, wParam, lParam);
	}
	return 0;
}
}


