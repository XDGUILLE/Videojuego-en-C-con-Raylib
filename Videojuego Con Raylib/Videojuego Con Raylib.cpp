
#include <iostream>
#include <raylib.h>

//GetRandomValue(0,1) es como usar rand() %

using namespace std;

const int filas = 40;
const int columnas = 50;
int maze[filas][columnas] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    // fila central
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

float blockSize = 20;
Rectangle block{ 0,0,blockSize,blockSize };
bool isCollidingWall;
bool isCollidingEnemy;
bool isCollidingWallEnemy;

//Window default
Color backgroundColor = { 20,16,75,255 };
int windowWidth = 950;
int windowHeight = 1400;

//Player
class Player {
protected:
    Vector2 position;
    Vector2 size;
    float speed;
    Vector2 oldPosition;
public:
    Player(Vector2 position, Vector2 size, float speed) {//Constructor
        this->position = position;
        this->size = size;
        this->speed = speed;
    }

    Vector2 getPosition() { return position; }
    Vector2 getSize() { return size; }
    float getSpeed() { return speed; } //Getters

    void movimiento() {
        float deltaTime = GetFrameTime();
        oldPosition = position; //Guardo la ultima posicion por si hay colision

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

    //Regresar a la posicion anterior pero por ejes separados
    void revertX() { position.x = oldPosition.x; }
    void revertY() { position.y = oldPosition.y; }

    int dibujar() {
        DrawRectangleV(position, size, GRAY);
        return 0;
    }
    Rectangle GetRect() {  //Esto es una funcion propia
        return Rectangle{ position.x, position.y, size.x, size.y };
    }
    void DrawHitbox(bool isCollidingWall) {
        if (isCollidingWall) {
            DrawRectangleLinesEx(GetRect(), 4, RED);
        }
    }
};

class Enemy : public Player {
private:
    Color color;
    float timer = 0.0f;
    int direccion = 0;
    bool moverEnX = true;

public:
    Enemy(Vector2 position, Vector2 size, float speed, Color color)
        : Player(position, size, speed) {
        this->color = color;
    }

    Rectangle GetRect() {  //Esto es una funcion propia
        return Rectangle{ position.x, position.y, size.x, size.y };
    }

    void dibujar() {
        DrawRectangleV(getPosition(), getSize(), color);
    }

    void moverAutomatico(Vector2 playerPos) {
        oldPosition = position;
        float deltaTime = GetFrameTime();
        timer += deltaTime;

        if (timer > 0.3f) {
            moverEnX = !moverEnX;
            timer = 0.0f;

        }
        
        if (moverEnX) {
            if (playerPos.x > position.x) position.x += speed * deltaTime;
            if (playerPos.x < position.x) position.x -= speed * deltaTime;
        }
        else {
            if (playerPos.y > position.y) position.y -= speed * deltaTime;
            if (playerPos.y < position.y) position.y += speed * deltaTime;
        }
        

        windowWidth = GetScreenWidth();
        windowHeight = GetScreenHeight();

        if ((position.x - size.x) < 0) position.x = 0 + size.x;
        if (position.x + size.x > windowWidth) position.x = windowWidth - size.x;
        if (position.y - size.x < 0) position.y = 0 + size.x;
        if (position.y + size.x > windowHeight) position.y = windowHeight - size.x;
    }

    void forzarCambioEje() {
        moverEnX = !moverEnX;
        timer = 0.0f;
    }

};

void printArray2D(Player& player, Enemy& enemy) {//Refencia de player
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            if (maze[y][x] == 1) {

                block.x = x * block.width;
                block.y = y * block.height;
                // Posicion * tamano
                DrawRectangleRec(block, RED);
                // Bordes
                DrawRectangleLinesEx(block, 5, BLUE);

                isCollidingWall = CheckCollisionRecs(player.GetRect(), block);
                if (isCollidingWall) {
                    //Solo revierte x
                    player.revertX();
                    if (CheckCollisionRecs(player.GetRect(), block)) {
                        //Sino revierte y tambien
                        player.revertY();
                    }
                }

                isCollidingWallEnemy = CheckCollisionRecs(enemy.GetRect(), block);
                if (isCollidingWallEnemy) {
                    enemy.revertX();
                    if (CheckCollisionRecs(enemy.GetRect(), block)) {
                        //Sino revierte y tambien
                        enemy.revertY();
                        enemy.forzarCambioEje();
                    }
                    enemy.forzarCambioEje();

                    isCollidingEnemy = CheckCollisionRecs(player.GetRect(), enemy.GetRect());
                    if (isCollidingEnemy) {
                        DrawText("GameOver", 475, 700, 25, ORANGE);
                    }

                }
            }
        }
    }
}

int main() {

    Player p1 = Player({ 450,450 }, { 20,20 }, 200.0f);
    Enemy e1 = Enemy({ 45,45 }, { 20,20 }, 250.0f, RED);

    //array2D();

    InitWindow(windowHeight, windowWidth, "MazeRunner");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(backgroundColor);

        p1.movimiento();
        e1.moverAutomatico(p1.getPosition());

        printArray2D(p1,e1);

        p1.dibujar();
        e1.dibujar();

        p1.DrawHitbox(isCollidingWall);
        e1.DrawHitbox(isCollidingEnemy);  

        EndDrawing();
    }
    CloseWindow();
}