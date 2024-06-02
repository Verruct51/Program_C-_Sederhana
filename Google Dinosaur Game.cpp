#include <iostream>
#include <Windows.h>
#include <conio.h>

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

using namespace std;

void AturTampilanKonsol() {
    system("mode con:cols=100 lines=25");
    system("title Dinosaurs. By KELOMPOK 11 ");
}

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int DapatkanTombolDitekan() {
    if (_kbhit() != 0) {
        return _getch();
    }
    return 0;
}

void GambarDino(int dinoY) {
    GotoXY(0, dinoY);
    static bool kakiDepan = true;
    cout << "        $$$$$$$ " << endl;
    cout << "       $$ $$$$$$" << endl;
    cout << "       $$$$$$$$$" << endl;
    cout << "$      $$$      " << endl;
    cout << "$$     $$$$$$$  " << endl;
    cout << "$$$   $$$$$     " << endl;
    cout << " $$  $$$$$$$$$$ " << endl;
    cout << " $$$$$$$$$$$    " << endl;
    cout << "  $$$$$$$$$$    " << endl;
    cout << "    $$$$$$$$    " << endl;
    cout << "     $$$$$$     " << endl;
    if (kakiDepan) {
        cout << "     $    $$$    " << endl;
        cout << "     $$          ";
        kakiDepan = false;
    } else {
        cout << "     $$$    $    " << endl;
        cout << "          $$     ";
        kakiDepan = true;
    }
}

void GambarPohon(int treeX) {
    GotoXY(treeX, TREE_BOTTOM_Y);
    cout << "$$$$";
    GotoXY(treeX, TREE_BOTTOM_Y + 1);
    cout << " $$ ";
    GotoXY(treeX, TREE_BOTTOM_Y + 2);
    cout << " $$ ";
    GotoXY(treeX, TREE_BOTTOM_Y + 3);
    cout << " $$ ";
    GotoXY(treeX, TREE_BOTTOM_Y + 4);
    cout << " $$ ";
}

bool PeriksaTabrakan(int dinoY, int treeX) {
    return (treeX <= 2 && treeX >= 0 && dinoY >= DINO_BOTTOM_Y - 2);
}

bool MulaiPermainan() {
    bool sedangMelompat = false;
    bool diDasar = true;
    const int gravitasi = 3;
    const int tinggiLompatan = 8;

    int dinoY = DINO_BOTTOM_Y;
    int treeX = TREE_BOTTOM_X;

    while (true) {
        if (DapatkanTombolDitekan() == 'z' && diDasar) {
            sedangMelompat = true;
            diDasar = false;
        }

        if (sedangMelompat) {
            dinoY -= gravitasi;
            if (dinoY <= DINO_BOTTOM_Y - tinggiLompatan) {
                sedangMelompat = false;
            }
        } else {
            dinoY += gravitasi;
            if (dinoY >= DINO_BOTTOM_Y) {
                dinoY = DINO_BOTTOM_Y;
                diDasar = true;
            }
        }

        treeX -= 2;
        if (treeX <= 0) {
            treeX = TREE_BOTTOM_X;
        }

        if (PeriksaTabrakan(dinoY, treeX)) {
            GotoXY(32, DINO_BOTTOM_Y + 2);
            cout << "GAME OVER!";
            GotoXY(32, DINO_BOTTOM_Y + 7);
            cout << "Try Again [Y]";
            GotoXY(32, DINO_BOTTOM_Y + 9);
            cout << "Exit [X]";
            break;
        }

        GambarDino(dinoY);
        GambarPohon(treeX);
        Sleep(80);
        system("cls");
    }

    char pilihan = getch();
    return (pilihan == 'y' || pilihan == 'Y');
}

void TampilkanLoading() {
    const int loadingBarWidth = 30;

    for (int i = 0; i <= loadingBarWidth; i++) {
        GotoXY(28, 11);
        cout << "--------------------";
        GotoXY(28, 12);
        cout << "L O A D I N G  " << (i * 100) / loadingBarWidth << "%";
        GotoXY(28, 13);
        cout << "--------------------";
        GotoXY(25, 15);
        cout << "[";
        for (int j = 0; j < i; j++) {
            cout << "#";
        }
        for (int j = i; j < loadingBarWidth; j++) {
            cout << " ";
        }
        cout << "]";
        Sleep(100); // Adjust the speed of loading animation here
    }

    Sleep(500); // Pause before clearing the screen
    system("cls");
}

void TampilkanLayarPlay() {
    system("cls");
    GotoXY(32, 14);
    cout << "PLAY GAME" << endl;
    GotoXY(25, 16);
    cout << "(Klik enter untuk memulai permainan!!)";
    getch();
    system("cls");
}

int main() {
    AturTampilanKonsol();

    while (true) {
        TampilkanLayarPlay();
        TampilkanLoading();
        if (!MulaiPermainan()) {
            break;
        }
    }

    return 0;
}
