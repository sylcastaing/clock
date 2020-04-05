#include <LEDMatrixDriver.hpp>

const uint8_t LEDMATRIX_CS_PIN = 2;

const int LEDMATRIX_SEGMENTS = 4;
LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);

const int empty[8][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
};

const int font[][8][5] = {
        {
                {0, 1, 1, 1, 0},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 0}
        },
        {
                {0, 0, 1, 0, 0},
                {0, 1, 1, 0, 0},
                {1, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {1, 1, 1, 1, 1}
        },
        {
                {0, 1, 1, 1, 0},
                {1, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 0, 0, 0},
                {1, 1, 1, 1, 1}
        },
        {
                {0, 1, 1, 1, 0},
                {1, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {0, 0, 1, 1, 1},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 0}
        },
        {
                {0, 0, 0, 1, 0},
                {0, 0, 1, 1, 0},
                {0, 1, 0, 1, 0},
                {1, 0, 0, 1, 0},
                {1, 1, 1, 1, 1},
                {0, 0, 0, 1, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 0, 1, 0}
        },
        {
                {1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 1, 1, 1, 0},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 0}
        },
        {
                {0, 0, 0, 1, 1},
                {0, 0, 1, 0, 0},
                {0, 1, 0, 0, 0},
                {1, 1, 1, 1, 0},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 0}
        },
        {
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0}
        },
        {
                {0, 1, 1, 1, 0},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 0},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 0}
        },
        {
                {0, 1, 1, 1, 0},
                {1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 1},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {1, 0, 0, 0, 1},
                {0, 1, 1, 1, 0}
        }
};

void initDisplay() {
  lmd.setEnabled(true);
  lmd.setIntensity(0);
  lmd.clear();
  lmd.display();
}


void display1(int value) {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (x > 1 && x < 7) {
        lmd.setPixel(x, y, (value > 0 ? font[value] : empty)[y][x - 2]);
      } else {
        lmd.setPixel(x, y, false);
      }
    }
  }
}

void display2(int value) {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (x < 5) {
        lmd.setPixel(x + 8, y, font[value][y][x]);
      } else {
        lmd.setPixel(x + 8, y, x == 7 && (y == 1 || y == 2 || y == 5 || y == 6));
      }
    }
  }
}

void display3(int value) {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (x > 2) {
        lmd.setPixel(x + 16, y, font[value][y][x - 3]);
      } else {
        lmd.setPixel(x + 16, y, x == 0 && (y == 1 || y == 2 || y == 5 || y == 6));
      }
    }
  }
}

void display4(int value) {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (x > 0 && x < 6) {
        lmd.setPixel(x + 24, y, font[value][y][x - 1]);
      } else {
        lmd.setPixel(x + 24, y, false);
      }
    }
  }
}

void displayTime(int hours, int minutes) {
  display1(hours / 10);
  display2( hours % 10);
  display3(minutes / 10);
  display4(minutes % 10);
  lmd.display();
}