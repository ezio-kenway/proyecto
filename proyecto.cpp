#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

size_t mayor;
char aux[100];
vector<string> lineas;

//Muestra el texto leído en la consola
void mostrar()
{
    for (auto e : lineas)
    {
        cout << e << endl;
    }
    cout << "\n\n\n\n";
}

//elimina los espacios al principio y al final de cada línea
void espacios()
{

    bool ajustar = false;
    //recorre toda las lineas y elimina los espacios de fin y inicio
    for (auto& e : lineas)
    {
        int aux = 0, i = 0;
        while (true)
        {
            if (e[0] != ' ' && e[0] != '\t')
            {
                break;
            }
            e.erase(0, 1);
        }

        size_t contador = size(e);
        while (true)
        {
            if (e[contador] != ' ' && e[contador] != '\t')
            {
                break;
            }
            contador--;
        }
        e.erase(contador);
    }
}

//crea un vector con todas las líneas del archivo
void abrir()
{
    //abre el archivo
    string auxiliar;
    int i = 0;
    ifstream archivo("C:/Users/Julio/Desktop/proyectopoo1/prueba.txt");
    while(!archivo.eof())
    {
        lineas.resize(i+1);
        getline(archivo,auxiliar);
        lineas[i] = auxiliar;
        i++;
    }
}
//alinea a la izquierda
void izquierda()
{
    espacios();
    bool ajustar = false;
    for (auto& e : lineas)
    {
        int aux = 0, i = 0;
        while (true)
        {
            if (e[aux] != ' ' && e[aux] != '\t')
            {
                break;
            }
            aux++;
            ajustar = true;
        }
        if(ajustar)
            while(aux<size(e)+1)
            {
                e[i] = e[aux];
                aux++, i++;
            }
    }
}

//alinea a la derecha
void derecha() {
    espacios();
    mayor = size(lineas[1]);
    size_t dif;
    for (auto& e : lineas) {
        if (size(e) > mayor) {
            mayor = size(e);
        }
    }

    for (auto& e : lineas) {
        dif = mayor - size(e);
        for (int i = 0; i < dif; i++) {
            e = " " + e;
        }
    }
}

//centra el texto
void centrar() {
    espacios();
    mostrar();
    for (auto& e : lineas) {
        auto start = (mayor - size(e)) / 2;
        for (int i = 0; i < start; i++) {
            e = " " + e;
        }
    }
}

//Aquí metes el menú y todo
int main() {
    int a;
    string ruta = "C:/Users/Julio/Desktop/proyectopoo1/prueba.txt";
    do {
        cout << "1. Leer Archivo" << endl;
        cout << "2. Guardar Archivo" << endl;
        cout << "3. Justificación" << endl;
        cout << "4. Alinear el texto a la izquierda" << endl;
        cout << "5. Alinear el texto a la derecha" << endl;
        cout << "6. Alinear el texto al centro" << endl;
        cin >> a;
        switch (a) {
            case 1:
                cout << "Direccion añadida" << endl;
                abrir();
                mostrar();
                break;
            case 2:
                cout << ruta << endl;
                break;
            case 3:
                cout << "Justificado correctamente" << endl;
                break;
            case 4:
                mostrar();
                izquierda();
                break;
            case 5:
                derecha();
                mostrar();
                break;
            case 6:
                centrar();
                mostrar();
        }
    }
    while (a != 7);
    system("pause");
}
