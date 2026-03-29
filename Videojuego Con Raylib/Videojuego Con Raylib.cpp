#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>
#include <queue>


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


class Node {
public:
    int x, y;
    float g, h, f;
    bool esPared;
    bool enCerrada;
    bool enAbierta;
    Node* padre;

    Node() {
        x = 0; y = 0;
        g = 0.0f; h = 0.0f; f = 0.0f;
        esPared = false;
        enCerrada = false;
        enAbierta = false;
        padre = nullptr;
    }

    void reset() {
        g = 0.0f; h = 0.0f; f = 0.0f;
        enCerrada = false;
        enAbierta = false;
        padre = nullptr;
    }
};

Node grid[filas][columnas];

void inicializarGrid() {
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            grid[y][x].x = x;
            grid[y][x].y = y;
            grid[y][x].esPared = (maze[y][x] == 1);
        }
    }
}

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


struct CompararNodo {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

vector<Node*> encontrarCamino(int startPx, int startPy, int endPx, int endPy) {
    int startX = startPx / blockSize;
    int startY = startPy / blockSize;
    int endX = endPx / blockSize;
    int endY = endPy / blockSize;

    startX = max(0, min(startX, columnas - 1));
    startY = max(0, min(startY, filas - 1));
    endX = max(0, min(endX, columnas - 1));
    endY = max(0, min(endY, filas - 1));

    if (grid[startY][startX].esPared) {
        for (int r = 1; r < 5; r++) {
            bool found = false;
            for (int dy2 = -r; dy2 <= r && !found; dy2++) {
                for (int dx2 = -r; dx2 <= r && !found; dx2++) {
                    int ny = startY + dy2;
                    int nx = startX + dx2;
                    if (ny >= 0 && ny < filas && nx >= 0 && nx < columnas
                        && !grid[ny][nx].esPared) {
                        startX = nx; startY = ny;
                        found = true;
                    }
                }
            }
            if (found) break;
        }
    }

    for (int y = 0; y < filas; y++)
        for (int x = 0; x < columnas; x++)
            grid[y][x].reset();

    grid[startY][startX].g = 0;
    grid[startY][startX].h = abs(endX - startX) + abs(endY - startY);
    grid[startY][startX].f = grid[startY][startX].h;

    priority_queue<Node*, vector<Node*>, CompararNodo> abiertos;
    abiertos.push(&grid[startY][startX]);

    int dx[] = { 0,  0, 1, -1 };
    int dy[] = { 1, -1, 0,  0 };

    while (!abiertos.empty()) {
        Node* actual = abiertos.top();
        abiertos.pop();

        if (actual->x == endX && actual->y == endY) {
            vector<Node*> camino;
            Node* nodo = actual;
            while (nodo != nullptr) {
                camino.push_back(nodo);
                nodo = nodo->padre;
            }
            reverse(camino.begin(), camino.end());
            return camino;
        }

        actual->enCerrada = true;

        for (int i = 0; i < 4; i++) {
            int nx = actual->x + dx[i];
            int ny = actual->y + dy[i];

            if (nx < 0 || ny < 0 || nx >= columnas || ny >= filas) continue;
            if (grid[ny][nx].esPared) continue;
            if (grid[ny][nx].enCerrada) continue;
        
            float nuevoG = actual->g + 1;
            float h = abs(endX - nx) + abs(endY - ny);
            float f = nuevoG + h;

            if (!grid[ny][nx].enAbierta || nuevoG < grid[ny][nx].g) {
                grid[ny][nx].g = nuevoG;
                grid[ny][nx].h = h;
                grid[ny][nx].f = f;
                grid[ny][nx].padre = actual;
                grid[ny][nx].enAbierta = true;
                abiertos.push(&grid[ny][nx]);
            }
        }
    }
    return {};
}


bool isCollidingEnemy = false;

class Player {
protected:
    Vector2 position;
    Vector2 oldPosition;
    Vector2 size;
    float speed;
    bool isCollidingWall = false;
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

    bool getIsCollidingWall() { return isCollidingWall; }

    void resetCollision() {
        isCollidingWall = false;
    }
};

class Enemy : public Player {
private:
    Color color;
    float timer = 0.0f;
    bool  moverEnX = true;
    vector<Node*> camino;
    int indiceCamino = 0;
    Vector2 ultimaPosPlayer = { 40.0f, 40.0f };  
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

        int celdaPlayerX = playerPos.x / blockSize;
        int celdaPlayerY = playerPos.y / blockSize;
        int ultimaX = ultimaPosPlayer.x / blockSize;
        int ultimaY = ultimaPosPlayer.y / blockSize;

        if (celdaPlayerX != ultimaX || celdaPlayerY != ultimaY || camino.empty() || indiceCamino >= (int)camino.size()) {
            camino = encontrarCamino(
                (int)(position.x / blockSize) * blockSize,
                (int)(position.y / blockSize) * blockSize,
                playerPos.x, playerPos.y
            );
            indiceCamino = 1;
            ultimaPosPlayer = playerPos;
        }

        if (!camino.empty() && indiceCamino < (int)camino.size()) {
            float targetX = camino[indiceCamino]->x * blockSize;
            float targetY = camino[indiceCamino]->y * blockSize;

            float dx = targetX - position.x;
            float dy = targetY - position.y;

            if (abs(dx) > 1.0f) position.x += (dx > 0 ? 1.0f : -1.0f) * speed * deltaTime;
            if (abs(dy) > 1.0f) position.y += (dy > 0 ? 1.0f : -1.0f) * speed * deltaTime;

            if (abs(dx) < 2.0f && abs(dy) < 2.0f)
                indiceCamino++;
        }
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

//Estructura lista elazada simple
struct estructuraNodo {
    Enemy* valor;
    float distancia;
    estructuraNodo* siguiente;
};

typedef estructuraNodo* nodo;

void insertar(Enemy* npcInsertar, nodo& lista) {

    distancia = sqrt(pow(ex - px, 2) + pow(ey - py, 2));

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
    player.resetCollision();
    enemy.resetCollision();
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            if (maze[y][x] == 1) {   
                block.x = x * blockSize;
                block.y = y * blockSize;

                DrawRectangleRec(block, RED);
                DrawRectangleLinesEx(block, 5, BLUE);
                player.checkWallCollision(block);
                //enemy.checkWallCollision(block);
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
    inicializarGrid();

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
            e1.moverAutomatico(p1.getPosition());

            printArray2D(p1, e1, gm);

            DrawText(("Points: " + to_string(gm.getTotalPoints())).c_str(), 10, 800, 20 ,RED);
        
            gm.actualizarTiempo();
            char tiempoTexto[20];
            snprintf(tiempoTexto, sizeof(tiempoTexto), "Time: %.2f", gm.getTotalTime());
            DrawText(tiempoTexto, 10, 775, 20, RED);

            p1.dibujar();
            e1.dibujar();

            p1.DrawHitbox(p1.getIsCollidingWall());
            e1.DrawHitbox(e1.getIsCollidingWall());

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