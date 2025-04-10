#include "Color.h"

Color::Color(int r, int g, int b) {
    this->red = (r >= 0 && r <= 255) ? r : 0;
    this->green = (g >= 0 && g <= 255) ? g : 0;
    this->blue = (b >= 0 && b <= 255) ? b : 0;
}

int Color::getRed() const {
    return this->red;
}

int Color::getGreen() const {
    return this->green;
}

int Color::getBlue() const {
    return this->blue;
}

void Color::setRed(int r) {
    this->red = (r >= 0 && r <= 255) ? r : 0;
}

void Color::setGreen(int g) {
    this->green = (g >= 0 && g <= 255) ? g : 0;
}

void Color::setBlue(int b) {
    this->blue = (b >= 0 && b <= 255) ? b : 0;
}