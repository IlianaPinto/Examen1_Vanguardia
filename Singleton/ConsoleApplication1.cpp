#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Buscaminas {
    static Buscaminas* _instance;
    char tablero[5][5];
public:
    static Buscaminas* getInstance() {
        if (_instance == NULL) {
            _instance = new Buscaminas();
        }
        return _instance;
    }

    void llenarTablero() {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                tablero[i][j] = '.';
            }
        }
        int pos1 = rand() % 4 + 0;
        int pos2 = rand() % 4 + 0;
        tablero[pos1][pos2] = '1';
        //cout << "La mina esta en: " << pos1 << " " << pos2<<endl;
        
    }

    bool verificar(int x, int y) {
        if (x > 4 || y > 4) {
            cout << "Posicion incorrecta" << endl;
            return false;
        }
        if (tablero[x][y] == '1') {
            tablero[x][y] = 'X';
            cout << "Mina encontrada" << endl;
            return true;
        }
        else if (tablero[x][y] == 'X') {
            cout << "La posicion ya fue ingresada" << endl;
            return false;
        }else {
            tablero[x][y] = '0';
            return false;
        }
    }

    void imprimir() {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (tablero[i][j] == '1') {
                    cout << " . ";
                }
                else {
                    cout <<" "<<tablero[i][j]<<" ";
                }
            }
            cout << endl;
        }
    }
};

Buscaminas * Buscaminas::_instance;

int main()
{
    int x, y;
    Buscaminas* minas = Buscaminas::getInstance();
    minas->llenarTablero();
    bool salir = true;
    do
    {
        cout << "Mini - Buscaminas" << endl;
        cout << endl;
        minas->imprimir();
        cout << "Ingrese posicion en x (0-4): ";
        cin >> x;
        cout << "Ingrese posicion en y (0-4): ";
        cin >> y;
        cout << endl;
        salir = !(minas->verificar(x, y));
        cout << endl;
    } while (salir);
    minas->imprimir(); delete minas;
    return 0;
}