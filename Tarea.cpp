#include <iostream>
#include <string.h>
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

/*
@name: lineas
@description: funcion para imprimir lineas delimitantes en el programa
*/
void lineas() {
    cout << "***********************************************************************************************************************\n" << endl;
}
/*
@name: mensaje_inicial
@description: funcion para imprimir lineas de mensaje inicial del programa
*/
void mensaje_inicial() {
    lineas();
    cout << "\t\t\t\tCalculo de Sueldo final de Empleado\n" << endl;
    lineas();
}

/*
@name: mover_cursor
@description: mueve el cursor en las coordenadas indicadas
*/
void mover_cursor(int x, int y) {
  HANDLE variable_handle;
  CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  variable_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(variable_handle, &csbiInfo);
  csbiInfo.dwCursorPosition.X=x;
  csbiInfo.dwCursorPosition.Y=y;
  SetConsoleCursorPosition(variable_handle, csbiInfo.dwCursorPosition);
}

/*
@name: mensaje_salario
@description: funcion que muestra la interfaz de menu del salario calculado
*/
void mensaje_salario(string nombres, string apellidos, string cargo) {
    cout << "\t\t\tEmpleado:\t" << nombres << ", " << apellidos <<  "\n" << endl;
    cout << "\t\t\tCargo:\t\t" << cargo <<  "\n" << endl;
}

/*
@name: imprimir_salario
@description: funcion que imprime el salario final
*/
void imprimir_salario(double salario_bruto, double renta, double isss, double salario_neto, double SEGURO_VIDA) {
    cout << "\t\t\tSueldo inicial : \t$ " << fixed << setprecision(2) << salario_bruto << endl;
    cout << "\t\t\t(descuentos de ley)" << endl;
    cout << "\t\t\tRenta : \t\t$ " << fixed << setprecision(2) << renta << endl;
    cout << "\t\t\tISSS : \t\t\t$ " << fixed << setprecision(2) << isss << endl;
    cout << "\t\t\tSeguro Vida : \t\t$ " << SEGURO_VIDA << endl;
    cout << "\t\t\t\t\t\t___________" << endl;
    cout << "\t\t\tSueldo a pagar : \t$ " << fixed << setprecision(2) << salario_neto << endl;
    cout << "\n\n" << endl;
}

/*
@name: calculo_salario
@description: funcion para realizar calculo de salario e imprimir resultados
*/
void calculo_salario(double costo_hora, double horas_laborales) {
    /*CONSTANTES*/
    const double SEGURO_VIDA = 12.00;
    const double PORCENTAJE_RENTA = 0.075;
    const double PORCENTAJE_ISSS = 0.054;
    /*VARIABLES*/
    double salario_bruto = costo_hora*horas_laborales;
    double renta = salario_bruto*PORCENTAJE_RENTA;
    double isss = salario_bruto*PORCENTAJE_ISSS;
    double salario_neto = salario_bruto - renta - isss - SEGURO_VIDA;

    imprimir_salario(salario_bruto, renta, isss, salario_neto, SEGURO_VIDA);
}

/*
@name: menu_salario
@description: funcion de "implementacion" que muestra la interfaz de menu del salario calculado
*/
void menu_salario(string nombres, string apellidos, string cargo, double costo_hora, double horas_laborales) {
    lineas();
    mensaje_salario(nombres, apellidos, cargo);
    lineas();
    calculo_salario(costo_hora, horas_laborales);
}

/*
@name: ingresar_datos
@description: funcion para imprimir el menu inicial del programa, e ingresar datos iniciales.
*/
void ingresar_datos() {
    /*Variables*/
    string nombres;
    string apellidos;
    double costo_hora;
    double horas_laborales;
    string cargo;
    /*Llamado de funcion de mensaje_inicial*/
    mensaje_inicial();
    /*Se imprime menu de ingreso de datos*/
    string menu_display = "1. Nombres: __________________\t4. Costo hora: $________________\n\n2. Apellidos:_________________\t5. Horas laborales: ____________ horas\n\n3. Cargo:_____________________\n";
    //cout << menu_display.size() << endl; /*Mide el tamaño del string*/

    cout << "Ingrese la siguiente informacion laboral: \n\n" << endl;
    cout << menu_display << endl;

    /*Ingreso Primer Input*/
    mover_cursor(13,9);
    getline(cin, nombres);
    /*Ingreso Segundo Input*/
    mover_cursor(14,11);
    getline(cin, apellidos);
    /*Ingreso Tercer Input*/
    mover_cursor(10,13);
    getline(cin, cargo);
    /*Ingreso Cuarto Input*/
    mover_cursor(50,9);
    cin >> costo_hora;
    /*Ingreso Quinto Input*/
    mover_cursor(54,11);
    cin >> horas_laborales;

    /*Borrar Pantalla de Consola*/
    system("CLS");
    /*Ejecutar funcion para menu de salario*/
    menu_salario(nombres, apellidos, cargo, costo_hora, horas_laborales);
}

/*
@name: main
@description: funcion principal del programa
*/
int main()
{
    ingresar_datos();
    return 0;
}
