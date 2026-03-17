#include <iostream>
#include <raylib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

//GetRandomValue(0,1) es como usar rand() %

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
Rectangle block{ 0,0,blockSize,blockSize };
bool isCollidingWall;
bool isCollidingEnemy;
bool isCollidingWallEnemy;

//Window default
Color backgroundColor = { 20,16,75,255 };
int windowWidth = 950;
int windowHeight = 1400;

class Node {
public:
    int x, y;           // posicion en el grid (celdas, no pixeles)
    float g, h, f;      // costos A*
    bool esPared;
    bool enAbierta;
    bool enCerrada;
    Node* padre;
    Rectangle rect;     // rectangulo en pixeles para dibujar y colisionar

    Node() {
        x = 0; y = 0;
        g = 0; h = 0; f = 0;
        esPared = false;
        enAbierta = false;
        enCerrada = false;
        padre = nullptr;
        rect = { 0, 0, blockSize, blockSize };
    }

    // Resetea solo los datos A* sin tocar esPared ni rect
    void resetAStar() {
        g = 0; h = 0; f = 0;
        enAbierta = false;
        enCerrada = false;
        padre = nullptr;
    }
};

// Grid global
Node grid[filas][columnas];

// Convierte el maze[][] en Nodes reales
void inicializarGrid() {
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            grid[y][x].x = x;
            grid[y][x].y = y;
            grid[y][x].esPared = (maze[y][x] == 1);
            grid[y][x].rect = {
                (float)(x * blockSize),
                (float)(y * blockSize),
                blockSize,
                blockSize
            };
        }
    }
}

struct CompararNodo {
    bool operator()(Node* a, Node* b) { return a->f > b->f; }
};

vector<Node*> encontrarCamino(int startPx, int startPy, int endPx, int endPy) {
    // Convertir pixeles a celdas
    int startX = max(0, min((int)(startPx / blockSize), columnas - 1));
    int startY = max(0, min((int)(startPy / blockSize), filas - 1));
    int endX = max(0, min((int)(endPx / blockSize), columnas - 1));
    int endY = max(0, min((int)(endPy / blockSize), filas - 1));

    // Si inicio o fin son pared, buscar celda libre cercana
    auto buscarLibre = [](int& cx, int& cy) {
        if (!grid[cy][cx].esPared) return;
        for (int r = 1; r < 5; r++) {
            for (int dy = -r; dy <= r; dy++) {
                for (int dx = -r; dx <= r; dx++) {
                    int ny = cy + dy;
                    int nx = cx + dx;
                    if (ny >= 0 && ny < filas && nx >= 0 && nx < columnas
                        && !grid[ny][nx].esPared) {
                        cx = nx; cy = ny; return;
                    }
                }
            }
        }
        };

    buscarLibre(startX, startY);
    buscarLibre(endX, endY);

    // Resetear datos A* de todo el grid
    for (int y = 0; y < filas; y++)
        for (int x = 0; x < columnas; x++)
            grid[y][x].resetAStar();

    priority_queue<Node*, vector<Node*>, CompararNodo> abiertos;

    // Nodo inicial
    grid[startY][startX].g = 0;
    grid[startY][startX].h = (float)(abs(endX - startX) + abs(endY - startY));
    grid[startY][startX].f = grid[startY][startX].h;
    grid[startY][startX].enAbierta = true;
    abiertos.push(&grid[startY][startX]);

    int dx[] = { 0,  0, 1, -1 };
    int dy[] = { 1, -1, 0,  0 };

    while (!abiertos.empty()) {
        Node* actual = abiertos.top();
        abiertos.pop();

        // Llegamos al destino
        if (actual->x == endX && actual->y == endY) {
            vector<Node*> camino;
            while (actual != nullptr) {
                camino.push_back(actual);
                actual = actual->padre;
            }
            reverse(camino.begin(), camino.end());
            return camino;
        }

        actual->enCerrada = true;

        // Explorar los 4 vecinos
        for (int i = 0; i < 4; i++) {
            int nx = actual->x + dx[i];
            int ny = actual->y + dy[i];

            if (nx < 0 || ny < 0 || nx >= columnas || ny >= filas) continue;
            if (grid[ny][nx].esPared)   continue;
            if (grid[ny][nx].enCerrada) continue;

            float nuevoG = actual->g + 1;
            float h = (float)(abs(endX - nx) + abs(endY - ny));

            if (!grid[ny][nx].enAbierta || nuevoG < grid[ny][nx].g) {
                grid[ny][nx].g = nuevoG;
                grid[ny][nx].h = h;
                grid[ny][nx].f = nuevoG + h;
                grid[ny][nx].padre = actual;
                grid[ny][nx].enAbierta = true;
                abiertos.push(&grid[ny][nx]);
            }
        }
    }
    return {}; // sin camino
}

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

        //5 seg
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
        if ((position.x - size.x) < 0) position.x = 0 + size.x;
        if (position.x + size.x > windowWidth) position.x = windowWidth - size.x;
        if (position.y - size.x < 0) position.y = 0 + size.x;
        if (position.y + size.x > windowHeight) position.y = windowHeight - size.x;
    }
};

void printArray2D(Player& player, Enemy& enemy) {
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            if (grid[y][x].esPared) {
                DrawRectangleRec(grid[y][x].rect, RED);
                DrawRectangleLinesEx(grid[y][x].rect, 5, BLUE);

                // Colision player con pared
                isCollidingWall = CheckCollisionRecs(player.GetRect(), grid[y][x].rect);
                if (isCollidingWall) {
                    player.revertX();
                    if (CheckCollisionRecs(player.GetRect(), grid[y][x].rect))
                        player.revertY();
                }
            }
        }
    }

    isCollidingEnemy = CheckCollisionRecs(player.GetRect(), enemy.GetRect());
    if (isCollidingEnemy)
        DrawText("GameOver", 200, 360, 25, ORANGE);
}

int main() {
    inicializarGrid();
    Player p1({ 130, 370 }, { 20, 20 }, 200.0f);
    Enemy  e1({ 40,  40 }, { 20, 20 }, 100.0f, ORANGE);

    InitWindow(windowHeight, windowWidth, "MazeRunner");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(backgroundColor);

        p1.movimiento();
        e1.moverAutomatico(p1.getPosition());

        printArray2D(p1, e1);

        p1.dibujar();
        e1.dibujar();

        p1.DrawHitbox(isCollidingWall);
        e1.DrawHitbox(isCollidingEnemy);

        EndDrawing();
    }
    CloseWindow();
}