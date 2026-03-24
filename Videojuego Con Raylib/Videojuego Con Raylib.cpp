#include <iostream>
#include <raylib.h>
#include <string>

using namespace std;

const int filas = 36;
const int columnas = 28;
int maze[filas][columnas] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

float blockSize = 20;
Rectangle block{ 0, 0, blockSize, blockSize };
bool isCollidingWall = false;
bool isCollidingEnemy = false;
bool isCollindingWallEnemy = false;

Color backgroundColor = { 20, 16, 75, 255 };
int windowWidth = 560;
int windowHeight = 850;

class Player {
protected:
    Vector2 position;
    Vector2 oldPosition;
    Vector2 size;
    float speed;

public:
    Player(Vector2 position, Vector2 size, float speed) {
        this->position = position;
        this->oldPosition = position;
        this->size = size;
        this->speed = speed;
    }

    Vector2 getPosition() { return position; }
    Vector2 getSize() { return size; }
    float   getSpeed() { return speed; }

    void movimiento() {
        float deltaTime = GetFrameTime();
        oldPosition = position;

        if (IsKeyDown(KEY_RIGHT)) position.x += speed * deltaTime;
        if (IsKeyDown(KEY_LEFT))  position.x -= speed * deltaTime;
        if (IsKeyDown(KEY_UP))    position.y -= speed * deltaTime;
        if (IsKeyDown(KEY_DOWN))  position.y += speed * deltaTime;

        windowWidth = GetScreenWidth();
        windowHeight = GetScreenHeight();

        if (position.x - size.x < 0)           position.x = size.x;
        if (position.x + size.x > windowWidth)  position.x = windowWidth - size.x;
        if (position.y - size.y < 0)            position.y = size.y;
        if (position.y + size.y > windowHeight) position.y = windowHeight - size.y;
    }

    void revertX() { position.x = oldPosition.x; }
    void revertY() { position.y = oldPosition.y; }

    void dibujar() {
        DrawRectangleV(position, size, GRAY);
    }

    Rectangle GetRect() {
        return Rectangle{ position.x, position.y, size.x, size.y };
    }

    void DrawHitbox(bool colisionando) {
        if (colisionando)
            DrawRectangleLinesEx(GetRect(), 4, RED);
    }

    void checkWallCollision(Rectangle block) {
        isCollidingWall = isCollidingWall || CheckCollisionRecs(GetRect(), block); // Acumula el valor bool, despues lo resetea
        if (isCollidingWall) {
            revertX();
            if (CheckCollisionRecs(GetRect(), block)) {
                revertY();
            }
        }
    }
};

class Enemy : public Player {
private:
    Color color;
    float timer = 0.0f;
    bool  moverEnX = true;

public:
    Enemy(Vector2 position, Vector2 size, float speed, Color color)
        : Player(position, size, speed) {
        this->color = color;
    }

    Rectangle GetRect() {
        return Rectangle{ position.x, position.y, size.x, size.y };
    }

    void dibujar() {
        DrawRectangleV(position, size, color);
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
            if (playerPos.y > position.y) position.y += speed * deltaTime;
            if (playerPos.y < position.y) position.y -= speed * deltaTime;
        }

        windowWidth = GetScreenWidth();
        windowHeight = GetScreenHeight();

        if (position.x - size.x < 0)           position.x = size.x;
        if (position.x + size.x > windowWidth)  position.x = windowWidth - size.x;
        if (position.y - size.y < 0)            position.y = size.y;
        if (position.y + size.y > windowHeight) position.y = windowHeight - size.y;
    }
};

class Item {
private:
    Vector2 position;
    Vector2 size;
    int points;
    Color color;
    bool collected;
public:
    Item(Vector2 position, Vector2 size, int points, Color color) {
        this->position = position;
        this->size = size;
        this->points = points;
        this->color =  color;
        this->collected = false;
    } 

    Vector2 getPosition() { return position; }

    int getPoints() { return points; }

    bool isCollected() { return collected; } //getter

    Rectangle GetRect() { 
        return Rectangle{ position.x,position.y,size.x,size.y }; 
    }

    bool checkCollision(Rectangle playerRect) {
        if (CheckCollisionRecs(playerRect, GetRect())) {
            collected = true;
        }
        return collected;
    }

    void dibujar() {
        if (!collected) {
            DrawCircleV({ position.x,position.y }, size.x, color);
        }
    }
};

class GameManager {
private:
    Player* player;
    Enemy* enemy;
    Item* arrayItems[30];
    int totalPoints;
    int totalTime;
public:
    GameManager(Player* player, Enemy* enemy) {
        this->player = player;
        this->enemy = enemy;
        this->totalPoints = 0;
        this->totalTime = 0;
    }

    void acuPoints(Item& item) {
        bool colisiono = item.checkCollision(player->GetRect());
        if (colisiono) {
            totalPoints += item.getPoints();
        }
    }

    int getTotalPoints() { return totalPoints; }
};

//Estructura lista
struct estructuraNodo {
    Player* valor;
    estructuraNodo* siguiente;
};

typedef estructuraNodo* nodo;

void insertar(Enemy* npcInsertar, nodo& lista) {
    if (lista == NULL) {
        nodo nuevo = new estructuraNodo();
        nuevo->valor = npcInsertar;
        nuevo->siguiente = NULL;
        lista = nuevo;
    }
    else {
        insertar(npcInsertar, lista->siguiente);
    }
}

void listarElementos(nodo lista) {
    if (lista != NULL) {
        cout << lista->valor->getSpeed() << ", ";
        listarElementos(lista->siguiente);
    }
}

bool buscarRecursividad(int datoBuscar, nodo lista) {
    if (lista != NULL) {
        if (lista->valor->getSpeed() == datoBuscar) return true;
        return buscarRecursividad(datoBuscar, lista->siguiente);
    }
    return false;
}

void printArray2D(Player& player, Item& item, Enemy& enemy) {
    isCollidingWall = false;
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            if (maze[y][x] == 1) {
                block.x = x * blockSize;
                block.y = y * blockSize;

                DrawRectangleRec(block, RED);
                DrawRectangleLinesEx(block, 5, BLUE);
                player.checkWallCollision(block);
            }
        }
    }
    item.dibujar();

    isCollidingEnemy = CheckCollisionRecs(player.GetRect(), enemy.GetRect());
    if (isCollidingEnemy)
        DrawText("GameOver", 200, 360, 25, ORANGE);
}


int main() {
    nodo lista = NULL;

    Player p1({ 130, 370 }, { 20, 20 }, 200.0f);
    Enemy  e1({ 40,  40 }, { 20, 20 }, 100.0f, ORANGE);
    Item cookie({ 50,370 }, { 10,10 }, 35, WHITE);
    
    GameManager gm(&p1, &e1);

    insertar(&e1, lista);

    InitWindow(windowWidth, windowHeight, "MazeRunner");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(backgroundColor);

        p1.movimiento();
        e1.moverAutomatico(p1.getPosition());
        cookie.checkCollision(p1.GetRect());

        gm.acuPoints(cookie);

        printArray2D(p1, cookie, e1);

        DrawText(("Points: " + to_string(gm.getTotalPoints())).c_str(), 10, 800, 20 ,RED);

        p1.dibujar();
        e1.dibujar();

        p1.DrawHitbox(isCollidingWall);
        e1.DrawHitbox(isCollidingEnemy);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}