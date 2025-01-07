#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <X11/keysym.h>

#define MAP_WIDTH  10
#define MAP_HEIGHT 10
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600



int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

double castRay(double playerX, double playerY, double playerAngle) {
    double rayX = playerX;
    double rayY = playerY;
    double rayDist = 0.0;
    double stepSize = 0.05;

    while (1) {
        rayX += cos(playerAngle) * stepSize;
        rayY += sin(playerAngle) * stepSize;
        rayDist += stepSize;

        int mapX = (int)rayX;
        int mapY = (int)rayY;

        if (mapX >= 0 && mapX < MAP_WIDTH && mapY >= 0 && mapY < MAP_HEIGHT) {
            if (worldMap[mapX][mapY] == 1) {
                return rayDist;
            }
        } else {
            return rayDist;
        }
    }
}

void render3D(Display *display, Window window, GC gc, double playerX, double playerY, double playerAngle) {
    int screenWidth = WINDOW_WIDTH;
    int screenHeight = WINDOW_HEIGHT;

    for (int x = 0; x < screenWidth; x++) {
        double rayAngle = playerAngle + (x - screenWidth / 2) * 0.002;

        double dist = castRay(playerX, playerY, rayAngle);

        int lineHeight = (int)(screenHeight / dist);
        int lineStart = screenHeight / 2 - lineHeight / 2;
        int lineEnd = screenHeight / 2 + lineHeight / 2;

        XDrawLine(display, window, gc, x, lineStart, x, lineEnd);
    }
}

int main() {
    Display *display;
    Window window;
    GC gc;
    int screen;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Não foi possível abrir o display.\n");
        exit(1);
    }

    screen = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, WINDOW_WIDTH, WINDOW_HEIGHT, 1,
                                 BlackPixel(display, screen), WhitePixel(display, screen));

    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    gc = XCreateGC(display, window, 0, NULL);

    double playerX = 5.0;
    double playerY = 5.0;
    double playerAngle = M_PI / 4;

    while (1) {
        XEvent event;
        if (XPending(display)) {
            XNextEvent(display, &event);
            if (event.type == KeyPress) {
                KeySym key = XLookupKeysym(&event.xkey, 0);
                if (key == XK_w) {
                    playerX += cos(playerAngle) * 0.5;
                    playerY += sin(playerAngle) * 0.5;
                } else if (key == XK_s) {
                    playerX -= cos(playerAngle) * 0.5;
                    playerY -= sin(playerAngle) * 0.5;
                } else if (key == XK_a) {
                    playerAngle -= 0.5;
                } else if (key == XK_d) {
                    playerAngle += 0.5;
                } else if (key == XK_Escape) {
                    break;
                }
            }
        }

        // Limpar tela
        XClearWindow(display, window);

        // Renderizar cena 3D
        render3D(display, window, gc, playerX, playerY, playerAngle);

        //usleep(10000);  // Delay
    }

    XCloseDisplay(display);
    return 0;
}
