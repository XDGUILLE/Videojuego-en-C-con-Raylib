// Videojuego Con Raylib.cpp
#include <iostream>
#include <raylib.h>

using namespace std;

int blockSize = 30;
int maze[50][75];
Rectangle block = Rectangle{500,500,80,80}; // .x, .y, .width, .height

//Window default
Color backgroundColor = { 20,16,75,255 };
int windowWidth = 950;
int windowHeight = 1500;

//Player
class Player {
private:
    Vector2 position;
    Vector2 size;
    float speed;
public:
    Player(Vector2 position, Vector2 size, float speed) {
        this->position = position;
        this->size = size;
        this->speed = speed;//Constructor
    }
    void movimiento() {
        float deltaTime = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT)) position.x += speed * deltaTime;
        if (IsKeyDown(KEY_LEFT))  position.x -= speed * deltaTime;
        if (IsKeyDown(KEY_UP))    position.y -= speed * deltaTime;
        if (IsKeyDown(KEY_DOWN))  position.y += speed * deltaTime;

        //Limite Window
        windowWidth = GetScreenWidth();
        windowHeight = GetScreenHeight();

        if ((position.x - size.x) < 0) position.x = 0 + size.x;
        if (position.x + size.x > windowWidth) position.x = windowWidth - size.x;
        if (position.y - size.x < 0) position.y = 0 + size.x;
        if (position.y + size.x > windowHeight) position.y = windowHeight - size.x;
    }
    int dibujarP1() {
        DrawRectangleV(position, size, GRAY);
        return 0;
    }
    Rectangle GetRect() {
        return Rectangle{ position.x, position.y, size.x, size.y };
    }
    void DrawHitbox(bool isColliding) {
        if (isColliding) {
            DrawRectangleLinesEx(GetRect(), 3, RED);
        }   
    }
};

void array2D() {

    for (int y = 0; y < blockSize; y++) {
        for (int x = 0; x < blockSize; x++) {
            // Bordes
            if (y == 0 || y == blockSize - 1 || x == 0 || x == blockSize - 1) {
                maze[y][x] = 1;
            }
            // Paredes Aleatorias

            else if (x % 4 == 0 && y % 4 == 0) {
                maze[y][x] = 1;
            }
        }
    }
}

void printArray2D() {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 50; x++) {
            if (maze[y][x] == 1) {
                // Posicion * tamano
                DrawRectangle(x * blockSize, y * blockSize, blockSize, blockSize, RED);
                // Bordes
                DrawRectangleLines(x * blockSize, y * blockSize, blockSize, blockSize, BLUE);
            }
        }
    }
}

/*
int mapa() {
    DrawRectangleLinesEx(block, 15,GREEN);
    array2D();
    printArray2D();
    return 0;
}
*/

int main(){

    Player p1 = Player({ 400,225 }, { 20,20 }, 200.0f);

    InitWindow(windowHeight, windowWidth, "MazeRunner");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(backgroundColor);

        bool isColliding = CheckCollisionRecs(p1.GetRect(), block);
        p1.movimiento();
        DrawRectangleLinesEx(block, 15, GREEN);
        p1.dibujarP1();
        p1.DrawHitbox(isColliding);

        array2D();
        printArray2D();
        
        

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