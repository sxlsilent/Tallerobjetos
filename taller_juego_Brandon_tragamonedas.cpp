#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

        char simbolos[4] = {'@','#','$','%'};

        class Jugador {
    private:
        string nombre;
        int monedas;
    public:
        Jugador(string n) {
            nombre = n;
            monedas = 100;
        }
        string getNombre() { return nombre; }
        int getMonedas() { return monedas; }
        void apostar(int cantidad) {
            monedas -= cantidad;
        }
        void ganar(int premio) {
                monedas += premio;
        }
    void mostrarSaldo() {
        cout << nombre << " tiene: " << monedas << " monedas" << endl;
    }
};

    int main() {
            srand(time(0));
                string nombre;
            cout << "Como te llamas: ";
            cin >> nombre;

        Jugador jugador(nombre);
        char opcion;

        while (true) {
            jugador.mostrarSaldo();
            if (jugador.getMonedas() < 10) {
                cout << "No tienes monedas. Fin del juego!" << endl;
                break;
            }
                cout << "Tirar? (s/n): ";
                cin >> opcion;
            if (opcion == 'n') {
                cout << "Gracias por jugar!" << endl;
                break;
            }
                jugador.apostar(10);
                    char r1 = simbolos[rand() % 4];
                    char r2 = simbolos[rand() % 4];
                    char r3 = simbolos[rand() % 4];
            cout << "[ " << r1 << " ] [ " << r2 << " ] [ " << r3 << " ]" << endl;
                if (r1==r2 && r2==r3) {
                    cout << "3 iguales Ganaste 50 monedas!" << endl;
                jugador.ganar(50);
            }
                else if (r1==r2 || r2==r3 || r1==r3) {
                cout << "2 iguales Ganaste 20 monedas!" << endl;
                jugador.ganar(20);
            }
                else {
                cout << "No hay premio." << endl;
            }
        }
        return 0;
    }

