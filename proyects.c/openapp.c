#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// PROYECTO: Lanzador de aplicaciones en segundo plano mediante atajos globales
int main()
{
    // ==========================================
    // 1. CONTROL Y OCULTACIÓN DE LA VENTANA
    // ==========================================
    
    // Crea una variable especial para almacenar el identificador único (ID) de una ventana
    HWND ventana;
    
    // Asegura que el sistema operativo le asigne una consola activa a este programa
    AllocConsole();
    
    // Busca la consola del programa por su tipo ("ConsoleWindowClass"). 
    // NULL indica que no nos importa el título de la ventana. El ID encontrado se asigna a "ventana".
    ventana = FindWindowA("ConsoleWindowClass", NULL);
    
    // Modifica el estado visual de la ventana usando su ID (0 = Ocultar por completo, 1 = Mostrar)
    ShowWindow(ventana, 0);


    // ==========================================
    // 2. REGISTRO DEL ATAJO DE TECLADO (HOTKEY)
    // ==========================================
    
    // Registra un atajo global (Ctrl + Shift + C) asignándole el identificador numérico 10.
    // Si la función devuelve 0, significa que el atajo está ocupado por otra app y el programa se cierra (return 1).
    if (RegisterHotKey(NULL, 10, MOD_CONTROL | MOD_SHIFT, 'C') == 0) {
        return 1;
    }


    // ==========================================
    // 3. ESTRUCTURA Y BUCLE DE EVENTOS (MENSAJES)
    // ==========================================
    
    // Crea una estructura compuesta (ficha con sub-variables) y la inicializa en 0 para limpiar la basura de la memoria
    MSG mensaje = {0};
    
    // Bucle inteligente: 'GetMessage' recibe la dirección de memoria (&mensaje) para rellenarla con datos del evento.
    // Si no hay actividad, "duerme" el programa (0% CPU). Al presionar el atajo, despierta y devuelve un valor distinto de 0.
    while (GetMessage(&mensaje, NULL, 0, 0) != 0) {
        
        // FILTRO 1: Evalúa si la acción general que ocurrió en el sistema operativo fue activar un atajo global (WM_HOTKEY)
        if (mensaje.message == WM_HOTKEY) {
            
            // FILTRO 2: Accede al dato específico (wParam) para verificar si el atajo presionado fue el nuestro (ID 10)
            if (mensaje.wParam == 10) {
                // Invoca a la terminal de Windows para ejecutar el comando que lanza Google Chrome
                system("start chrome");
            }
        }
        // Tras ejecutar la acción, el ciclo vuelve al inicio y el programa se duerme nuevamente esperando otro atajo
    }

    return 0;
}