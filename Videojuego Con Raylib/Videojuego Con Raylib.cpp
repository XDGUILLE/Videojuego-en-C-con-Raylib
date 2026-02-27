// Videojuego Con Raylib.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <raylib.h>
using namespace std;

//Window default
Color backgroundColor = { 20,16,75,255 };
int windowWidth = 800;
int windowHeight = 500;

//Player default

struct Player{
    Vector2 position;
    Vector2 size;
    float speed;
};
Player player1 = { 
                    {400,225},
                    {40,40}, 
                    5.0f
                };

void movimiento() {
    float deltaTime = GetFrameTime();

    if (IsKeyDown(KEY_RIGHT)) player1.position.x += player1.speed ;
    if (IsKeyDown(KEY_LEFT))  player1.position.x -= player1.speed ;
    if (IsKeyDown(KEY_UP))    player1.position.y -= player1.speed ;
    if (IsKeyDown(KEY_DOWN))  player1.position.y += player1.speed ;

}

int dibujar() {
    DrawRectangleV(player1.position, player1.size, WHITE);
    return 0;
}

int ventana() {
    InitWindow(windowHeight, windowWidth, "MazeRunner");
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(backgroundColor);
        DrawText("Ventana Videojuego!", 200, 200, 30, LIGHTGRAY);

        
        dibujar();
        movimiento();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

int mapa() {
    int laberinto[25][25];
    return 0;
}


int main()
{
    ventana();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
