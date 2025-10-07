// Membuat Game Snake dengan Bahasa C (Windows Console) - Meramu Koding
// https://www.meramukoding.com/membuat-game-snake-dengan-bahasa-c-array/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Konstanta untuk ukuran layar
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Konstanta untuk arah gerak ular
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Konstanta untuk karakter yang digunakan
#define SNAKE_BODY '#'
#define SNAKE_FOOD '@'
#define WALL '*'
#define BLANK ' '

// Struktur untuk menyimpan posisi x dan y
typedef struct {
    int x;
    int y;
} Position;

// Variabel global untuk menyimpan posisi ular dan makanan
Position snake[SCREEN_WIDTH * SCREEN_HEIGHT];
Position food;

// Variabel global untuk menyimpan panjang ular, arah gerak, skor, dan status permainan
int snake_length;
int snake_direction;
int score;
int game_over;

// Fungsi untuk menginisialisasi variabel-variabel awal
void init() {
    // Mengatur ukuran layar sesuai konstanta
    system("mode con: cols=80 lines=25");

    // Menyembunyikan kursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    // Mengatur seed untuk fungsi random
    srand(time(NULL));

    // Mengatur panjang ular awal menjadi 3
    snake_length = 3;

    // Mengatur posisi ular awal di tengah layar
    snake[0].x = SCREEN_WIDTH / 2;
    snake[0].y = SCREEN_HEIGHT / 2;
    snake[1].x = snake[0].x - 1;
    snake[1].y = snake[0].y;
    snake[2].x = snake[1].x - 1;
    snake[2].y = snake[1].y;

    // Mengatur arah gerak ular awal ke kanan
    snake_direction = RIGHT;

    // Mengatur posisi makanan awal secara random
    food.x = rand() % (SCREEN_WIDTH - 2) + 1;
    food.y = rand() % (SCREEN_HEIGHT - 2) + 1;

    // Mengatur skor awal menjadi 0
    score = 0;

    // Mengatur status permainan menjadi belum selesai
    game_over = 0;
}

// Fungsi untuk mengambil input keyboard tanpa menunggu enter
int getch_noblock() {
    if (_kbhit())
        return _getch();
    else
        return -1;
}

// Fungsi untuk mengubah arah gerak ular sesuai input keyboard
void change_direction() {
    int ch = getch_noblock();
    if (ch != -1) {
        switch (ch) {
            case 'w':
            case 'W':
                if (snake_direction != DOWN)
                    snake_direction = UP;
                break;
            case 's':
            case 'S':
                if (snake_direction != UP)
                    snake_direction = DOWN;
                break;
            case 'a':
            case 'A':
                if (snake_direction != RIGHT)
                    snake_direction = LEFT;
                break;
            case 'd':
            case 'D':
                if (snake_direction != LEFT)
                    snake_direction = RIGHT;
                break;
        }
    }
}

// Fungsi untuk memindahkan posisi ular sesuai arah gerak
void move_snake() {
    // Menyimpan posisi kepala ular sebelum bergerak
    Position head = snake[0];

    // Mengubah posisi kepala ular sesuai arah gerak
    switch (snake_direction) {
        case UP:
            snake[0].y--;
            break;
        case DOWN:
            snake[0].y++;
            break;
        case LEFT:
            snake[0].x--;
            break;
        case RIGHT:
            snake[0].x++;
            break;
    }

    // Memindahkan posisi setiap segmen ular ke posisi segmen di depannya
    for (int i = snake_length - 1; i > 1; i--) {
        snake[i] = snake[i - 1];
    }

    // Mengembalikan posisi kepala ular ke posisi semula
    snake[0] = head;
}

// Fungsi untuk mengecek apakah ular memakan makanannya
void check_food() {
    // Jika posisi kepala ular sama dengan posisi makanan
    if (snake[0].x == food.x && snake[0].y == food.y) {
        // Membuat makanan baru di posisi random yang tidak sama dengan tubuh ular
        int valid = 0;
        while (!valid) {
            valid = 1;
            food.x = rand() % (SCREEN_WIDTH - 2) + 1;
            food.y = rand() % (SCREEN_HEIGHT - 2) + 1;
            for (int i = 0; i < snake_length; i++) {
                if (snake[i].x == food.x && snake[i].y == food.y) {
                    valid = 0;
                    break;
                }
            }
        }

        // Menambah panjang ular dengan menambahkan segmen baru di ekor
        snake_length++;
        snake[snake_length - 1].x = snake[snake_length - 2].x;
        snake[snake_length - 1].y = snake[snake_length - 2].y;

        // Menambah skor
        score += 10;
    }
}

// Fungsi untuk mengecek apakah ular menabrak tembok atau tubuhnya sendiri
void check_collision() {
    // Jika posisi kepala ular berada di luar batas layar
    if (snake[0].x <= 0 || snake[0].x >= SCREEN_WIDTH - 1 || snake[0].y <= 0 || snake[0].y >= SCREEN_HEIGHT - 1) {
        // Mengubah status permainan menjadi selesai
        game_over = 1;
    }

    // Jika posisi kepala ular sama dengan posisi salah satu segmen tubuhnya
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            // Mengubah status permainan menjadi selesai
            game_over = 1;
            break;
        }
    }
}

// Fungsi untuk menggambar layar permainan
void draw_screen() {
    // Membersihkan layar
    system("cls");

    // Membuat buffer untuk menyimpan karakter-karakter yang akan digambar
    char buffer[SCREEN_WIDTH][SCREEN_HEIGHT];

    // Mengisi buffer dengan karakter spasi
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            buffer[x][y] = BLANK;
        }
    }

    // Mengisi buffer dengan karakter pagar di tepi layar untuk membuat tembok
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        buffer[x][0] = WALL;
        buffer[x][SCREEN_HEIGHT - 1] = WALL;
    }
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        buffer[0][y] = WALL;
        buffer[SCREEN_WIDTH - 1][y] = WALL;
    }

    // Mengisi buffer dengan karakter ular di posisi-posisi segmen tubuh ular
    for (int i = 0; i < snake_length; i++) {
        buffer[snake[i].x][snake[i].y] = SNAKE_BODY;
    }

    // Mengisi buffer dengan karakter makanan di posisi makanan
    buffer[food.x][food.y] = SNAKE_FOOD;

    // Menampilkan isi buffer ke layar
    for (int y = 0; y < SCREEN_HEIGHT;
