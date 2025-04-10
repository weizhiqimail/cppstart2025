#include "Cube.h"

// 设置长度
void Cube::setLength(int l) {
    this->length = l;
}

// 设置宽度
void Cube::setWidth(int w) {
    this->width = w;
}

// 设置高度
void Cube::setHeight(int h) {
    this->height = h;
}

// 获取长度
double Cube::getLength() {
    return this->length;
}

// 获取宽度
double Cube::getWidth() {
    return this->width;
}

// 获取高度
double Cube::getHeight() {
    return this->height;
}

// 计算体积
double Cube::getVolume() {
    return this->length * this->width * this->height;
}