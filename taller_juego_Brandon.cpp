#include <iostream>
#include <string>
using namespace std;

    char tablero[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

        class Jugador {
        private:

    string nombre;
    char simbolo;

    public:
        Jugador(string n, char s) {
            nombre = n;
            simbolo = s;
        }

        string getNombre() { return nombre; }
        char getSimbolo() { return simbolo; }

        int pedirCasilla() {
            int casilla;
            cout << nombre << " elige casilla (1-9): ";
            cin >> casilla;
            return casilla;
        }
};
    void mostrarTablero() {
        cout << " " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
        cout << "---|---|---" << endl;
        cout << " " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;
}

            bool hayGanador(char s) {
                return (tablero[0]==s && tablero[1]==s && tablero[2]==s) ||
                            (tablero[3]==s && tablero[4]==s && tablero[5]==s) ||
                            (tablero[6]==s && tablero[7]==s && tablero[8]==s) ||
                            (tablero[0]==s && tablero[3]==s && tablero[6]==s) ||
                            (tablero[1]==s && tablero[4]==s && tablero[7]==s) ||
                            (tablero[2]==s && tablero[5]==s && tablero[8]==s) ||
                            (tablero[0]==s && tablero[4]==s && tablero[8]==s) ||
                            (tablero[2]==s && tablero[4]==s && tablero[6]==s);
}
        int main() {
                    string n1, n2;
                    cout << "Nombre jugador 1: ";
                    cin >> n1;
                    cout << "Nombre jugador 2: ";
                    cin >> n2;

                        Jugador j1(n1, 'X');
                        Jugador j2(n2, 'O');

            int turno = 0;
            int jugadas = 0;

                    while (jugadas < 9) {
                                mostrarTablero();

                            Jugador actual = (turno == 0) ? j1 : j2;
                                int casilla = actual.pedirCasilla();

                                if (casilla < 1 || casilla > 9 || tablero[casilla-1] != ' ') {
                                                    cout << "Casilla invalida, intenta de nuevo." << endl;
                                                            continue;
                                }

                    tablero[casilla-1] = actual.getSimbolo();
                    jugadas++;

                                if (hayGanador(actual.getSimbolo())) {
                                mostrarTablero();
                                    cout << actual.getNombre() << " gano!" << endl;
                    return 0;
                }

                turno = (turno == 0) ? 1 : 0;
            }

            mostrarTablero();
            cout << "Empate!" << endl;
            return 0;
}


