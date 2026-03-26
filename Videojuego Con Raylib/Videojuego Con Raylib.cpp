#include <iostream>
#include <raylib.h>
#include <string>


using namespace std;

Color backgroundColor = { 20, 16, 75, 255 };
int windowWidth = 560;
int windowHeight = 850;

float blockSize = 20;
Rectangle block{ 0, 0, blockSize, blockSize };

const int filas = 37;
const int columnas = 28;
int maze[filas][columnas] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
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
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int inicializarComida() {
    int contador = 0;
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            if (maze[y][x] == 0) {
                maze[y][x] = 2;
                contador++;
            }
        }
    }
    return contador;
}

bool isCollidingWall = false;
bool isCollidingEnemy = false;

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

class GameManager {
private:
    Player* player;
    Enemy* enemy;
    int totalPoints;
    float totalTime;
    bool gameOver;
    int totalCookies;
    int points;
public:
    GameManager(Player* player, Enemy* enemy) {
        this->player = player;
        this->enemy = enemy;
        this->totalPoints = 0;
        this->totalTime = 0.0f;
        this->gameOver = false;
        this->totalCookies = 0;
        this->points = 35;
    }

    void acuPoints() {
        totalPoints += points;
    }

    int getTotalPoints() { return totalPoints; }

    void actualizarTiempo() {
        totalTime += GetFrameTime();
    }

    float getTotalTime() { return totalTime; }

    void setGameOver() { gameOver = true; }

    bool getGameOver() { return gameOver; }

    void setTotalCookies(int cookies){
        totalCookies += cookies;
    }

    bool isVictory() {
        if (totalPoints == (totalCookies * points)) { //O algun puntaje a eleccion
            return true;
        }
        return false;
    }

    int getTotalCookies() { return totalCookies; }
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

void printArray2D(Player& player, Enemy& enemy, GameManager& gameManager) {
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
            if (maze[y][x] == 2) {
                DrawCircleV({ x * blockSize + blockSize/2, y * blockSize + blockSize/2 }, 2.0f, WHITE);
                int celdaX = (player.getPosition().x + player.getSize().x / 2) / blockSize;
                int celdaY = (player.getPosition().y + player.getSize().y / 2) / blockSize;

                if (celdaX == x && celdaY == y) {
                    maze[y][x] = 0;
                    gameManager.acuPoints();
                }
            }
        }
    }

    isCollidingEnemy = CheckCollisionRecs(player.GetRect(), enemy.GetRect());
    if (isCollidingEnemy)
        gameManager.setGameOver();
}


int main() {
    //Declaraciones
    int totalCookies = inicializarComida();

    nodo lista = NULL;

    Player p1({ 130, 370 }, { 20, 20 }, 200.0f);
    Enemy  e1({ 40,  40 }, { 20, 20 }, 100.0f, ORANGE);
    
    GameManager gm(&p1, &e1);
    gm.setTotalCookies(totalCookies);

    insertar(&e1, lista);

    InitWindow(windowWidth, windowHeight, "MazeRunner");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(backgroundColor);

        if (!gm.getGameOver() && !gm.isVictory()) {
            //Logica de la partida
            p1.movimiento();
            //5e1.moverAutomatico(p1.getPosition());

            printArray2D(p1, e1, gm);

            DrawText(("Points: " + to_string(gm.getTotalPoints())).c_str(), 10, 800, 20 ,RED);
        
            gm.actualizarTiempo();
            char tiempoTexto[20];
            snprintf(tiempoTexto, sizeof(tiempoTexto), "Time: %.2f", gm.getTotalTime());
            DrawText(tiempoTexto, 10, 775, 20, RED);

            p1.dibujar();
            e1.dibujar();

            p1.DrawHitbox(isCollidingWall);
            e1.DrawHitbox(isCollidingEnemy);

        }
        else if (gm.isVictory()) {
            DrawText("YOU WIN!", 170, 350, 40, GREEN);
            DrawText(("Points: " + to_string(gm.getTotalPoints())).c_str(), 180, 400, 20, WHITE);
        }
        else {
            DrawText("GAME OVER", 150, 350, 40, RED);
            DrawText(("Points: " + to_string(gm.getTotalPoints())).c_str(), 180, 400, 20, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}