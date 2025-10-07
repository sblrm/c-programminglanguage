// Membuat game tic tac toe dengan bahasa C
// Menggunakan library Windows.h untuk input/output console
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Mendefinisikan ukuran layar dan batas permainan
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define GAME_WIDTH 10
#define GAME_HEIGHT 20
#define GAME_LEFT 35
#define GAME_TOP 3

// Mendefinisikan karakter untuk menggambar elemen permainan
#define WALL_CHAR '#'
#define EMPTY_CHAR ' '
#define BLOCK_CHAR '*'

// Mendefinisikan warna untuk elemen permainan
#define WALL_COLOR 15
#define EMPTY_COLOR 0
#define BLOCK_COLOR 14

// Mendefinisikan bentuk dan warna blok tic tac toe
// Ada 2 jenis blok, yaitu X dan O
// Setiap blok direpresentasikan dengan array 3x3
const int blocks[2][3][3] = {
    // Bentuk X
    {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    },
    // Bentuk O
    {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    }
};

const int block_colors[2] = {12, 9};

// Mendefinisikan struktur data untuk menyimpan informasi blok yang sedang dimainkan
typedef struct {
    int x; // posisi x
    int y; // posisi y
    int shape; // bentuk (0 atau 1)
} Block;

// Mendefinisikan variabel global untuk menyimpan papan permainan dan blok yang sedang dimainkan
char board[GAME_HEIGHT][GAME_WIDTH]; // array 2D untuk menyimpan karakter permainan
Block current_block; // variabel untuk menyimpan blok yang sedang dimainkan
int turn; // variabel untuk menyimpan giliran pemain (0 atau 1)
int score[2]; // array untuk menyimpan skor pemain (0 untuk X, 1 untuk O)
int game_over; // variabel untuk menyimpan status permainan (0 untuk berjalan, 1 untuk selesai)

// Mendefinisikan fungsi-fungsi yang dibutuhkan untuk permainan
void init_game(); // fungsi untuk menginisialisasi permainan
void draw_screen(); // fungsi untuk menggambar layar permainan
void draw_board(); // fungsi untuk menggambar papan permainan
void draw_block(Block b); // fungsi untuk menggambar blok
void erase_block(Block b); // fungsi untuk menghapus blok
void move_block(int dx, int dy); // fungsi untuk memindahkan blok
void rotate_block(); // fungsi untuk merotasi blok
void drop_block(); // fungsi untuk menjatuhkan blok
void new_block(); // fungsi untuk membuat blok baru
int is_valid(int x, int y, int shape); // fungsi untuk mengecek apakah posisi blok valid
int is_full(); // fungsi untuk mengecek apakah papan permainan penuh
int is_line(int y); // fungsi untuk mengecek apakah baris tertentu penuh
void remove_line(int y); // fungsi untuk menghapus baris tertentu
void check_lines(); // fungsi untuk mengecek dan menghapus baris-baris yang penuh
int is_game_over(); // fungsi untuk mengecek apakah permainan selesai
void update_score(); // fungsi untuk mengupdate skor pemain
void change_turn(); // fungsi untuk mengganti giliran pemain
void input_key(); // fungsi untuk menerima input dari pemain

// Fungsi utama
int main()
{
    // Menginisialisasi permainan
    init_game();

    // Mengulangi permainan sampai selesai
    while (!game_over)
    {
        // Menggambar layar permainan
        draw_screen();

        // Menerima input dari pemain
        input_key();

        // Mengecek dan menghapus baris-baris yang penuh
        check_lines();

        // Mengupdate skor pemain
        update_score();

        // Mengganti giliran pemain
        change_turn();

        // Mengecek apakah permainan selesai
        game_over = is_game_over();
    }

    // Menggambar layar permainan terakhir
    draw_screen();

    // Menampilkan pesan permainan selesai
    printf("\nGame Over!\n");
    printf("Skor X: %d\n", score[0]);
    printf("Skor O: %d\n", score[1]);
    if (score[0] > score[1])
        printf("Pemenang: X\n");
    else if (score[0] < score[1])
        printf("Pemenang: O\n");
    else
        printf("Hasil: Seri\n");

    // Mengembalikan nilai 0
    return 0;
}

// Fungsi untuk menginisialisasi permainan
void init_game()
{
    // Mengosongkan papan permainan
    for (int i = 0; i < GAME_HEIGHT; i++)
    {
        for (int j = 0; j < GAME_WIDTH; j++)
        {
            board[i][j] = EMPTY_CHAR;
        }
    }

    // Mengatur giliran pemain secara acak
    srand(time(NULL));
    turn = rand() % 2;

    // Mengatur skor pemain menjadi 0
    score[0] = 0;
    score[1] = 0;

    // Mengatur status permainan menjadi berjalan
    game_over = 0;

    // Membuat blok baru
    new_block();
}

// Fungsi untuk menggambar layar permainan
void draw_screen()
{
    // Membersihkan layar
    system("cls");

    // Mengatur warna teks
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    // Menampilkan judul permainan
    printf("Tic Tac Toe Game\n\n");

    // Menampilkan skor pemain
    printf("Skor X: %d\n", score[0]);
    printf("Skor O: %d\n", score[1]);

    // Menampilkan giliran pemain
    if (turn == 0)
        printf("Giliran: X\n");
    else
        printf("Giliran: O\n");

    // Menggambar papan permainan
    draw_board();
}

// Fungsi untuk menggambar papan permainan
void draw_board()
{
    // Mengatur posisi kursor
    COORD coord;
    coord.X = GAME_LEFT;
    coord.Y = GAME_TOP;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // Mengatur warna teks
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WALL_COLOR);

    // Menggambar dinding atas
    for (int i = 0; i < GAME_WIDTH + 2; i++)
    {
        printf("%c", WALL_CHAR);
    }
    printf("\n");

    // Menggambar dinding kiri dan kanan
    for (int i = 0; i < GAME_HEIGHT; i++)
    {
        coord.X = GAME_LEFT;
        coord.Y = GAME_TOP + 1 + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("%c", WALL_CHAR); // dinding kiri
        coord.X = GAME_LEFT + GAME_WIDTH + 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("%c", WALL_CHAR); // dinding kanan
    }
    printf("\n");

    // Menggambar dinding bawah
    coord.X = GAME_LEFT;
    coord.Y = GAME_TOP + 1 + GAME_HEIGHT;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i < GAME_WIDTH + 2; i++)
    {
        printf("%c", WALL_CHAR);

