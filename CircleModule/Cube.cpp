#include "Cube.h"

// ���ó���
void Cube::setLength(int l) {
    this->length = l;
}

// ���ÿ��
void Cube::setWidth(int w) {
    this->width = w;
}

// ���ø߶�
void Cube::setHeight(int h) {
    this->height = h;
}

// ��ȡ����
double Cube::getLength() {
    return this->length;
}

// ��ȡ���
double Cube::getWidth() {
    return this->width;
}

// ��ȡ�߶�
double Cube::getHeight() {
    return this->height;
}

// �������
double Cube::getVolume() {
    return this->length * this->width * this->height;
}