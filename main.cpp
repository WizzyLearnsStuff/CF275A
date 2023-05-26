#include<iostream>

using namespace std;

void legal_access(int c, int r, bool arr[]) {
    if (c < 0 || r < 0 || c > 2 || r > 2) return;
    arr[r * 3 + c] = !arr[r * 3 + c];
}

int main() {
    bool arr[9];
    int mapr[] = {-1, 0, 1,  0, 0};
    int mapc[] = { 0, 0, 0, -1, 1};
    bool toggle[9];

    for (int i = 0; i < 9; i++) {
        arr[i] = 1;
        toggle[i] = 1;
    }

    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        toggle[i] = tmp % 2;
    }

    for (int i = 0; i < 9; i++) {
        if (toggle[i]) {

            for (int j = 0; j < 5; j++) {
                legal_access((i % 3) + mapc[j], (i / 3) + mapr[j], arr);
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        cout << arr[i];
        if (i == 2 || i == 5) cout << '\n';
    }
}
