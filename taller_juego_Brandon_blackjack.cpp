#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

        int mazo[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

        class Jugador {

        private:
            string nombre;
            int puntos;
        public:
            Jugador(string n) {
            nombre = n;
            puntos = 0;
        }
            string getNombre() { return nombre; }
            int getPuntos() { return puntos; }
            void sumarPuntos(int carta) {
                puntos += carta;
            }
            void mostrar() {
            cout << nombre << " tiene: " << puntos << " puntos" << endl;
        }
    };

    int main() {
        srand(time(0));
            string nombre;
            cout << "Ingrese su nombre: ";
            cin >> nombre;

        Jugador jugador(nombre);

        int carta1 = mazo[rand() % 13];
        int carta2 = mazo[rand() % 13];
            jugador.sumarPuntos(carta1);
            jugador.sumarPuntos(carta2);
        cout << "Cartas iniciales: " << carta1 << " y " << carta2 << endl;

            char opcion;
                while (true) {
                jugador.mostrar();
            if (jugador.getPuntos() > 21) {
                cout << "Te pasaste de 21. Perdiste!" << endl;
                break;
            }
            cout << "Pedir carta (p) o plantarse (s): ";
            cin >> opcion;
            if (opcion == 'p') {
                    int nueva = mazo[rand() % 13];
                cout << "Nueva carta: " << nueva << endl;
            jugador.sumarPuntos(nueva);
            }
                else if (opcion == 's') {
                    cout << "Te plantaste con " << jugador.getPuntos() << "!" << endl;
                break;
            }
                else {
                cout << "Opcion invalida" << endl;
            }
        }
        return 0;
    }
