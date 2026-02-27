// Videojuego Con Raylib.cpp
#include <iostream>
#include <raylib.h>


using namespace std;

//Window default
Color backgroundColor = { 20,16,75,255 };
int windowWidth = 900;
int windowHeight = 1000;

//Player
class Player{
private:
    Vector2 position;
    Vector2 size;
    float speed;
public:
    Player(Vector2, Vector2,float);//Constructor
    void movimiento();
    int dibujar();
};

Player::Player(Vector2 _position, Vector2 _size, float _speed) {
    position = _position;
    size = _size;
    speed = _speed;
}

void Player::movimiento() {
    float deltaTime = GetFrameTime();

    if (IsKeyDown(KEY_RIGHT)) position.x += speed * deltaTime;
    if (IsKeyDown(KEY_LEFT))  position.x -= speed * deltaTime;
    if (IsKeyDown(KEY_UP))    position.y -= speed * deltaTime;
    if (IsKeyDown(KEY_DOWN))  position.y += speed * deltaTime;
}

int Player::dibujar() {
    DrawRectangleV(position, size, GRAY);
    return 0;
}

//Block
class Block {
private:
    Vector2 position;
    Vector2 size;
    Color color;
public:
    Block(Vector2, Vector2, Color);//Constructor
    int mapa();
};

int Block::mapa() {
    int laberinto[25][25];


    return 0;
}


int main(){
    Player p1 = Player({ 400,225 }, { 40,40 }, 200.0f);
    InitWindow(windowHeight, windowWidth, "MazeRunner");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(backgroundColor);
        DrawText("Ventana Videojuego!", 200, 200, 30, LIGHTGRAY);


        p1.dibujar();
        p1.movimiento();

        EndDrawing();
    }
    CloseWindow();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
