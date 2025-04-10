#ifndef COLOR_H
#define COLOR_H

class Color {
private:
    int red = 0;
    int green = 0;
    int blue = 0;

public:
    Color(int r = 0, int g = 0, int b = 0); // ���캯������
    int getRed() const;                     // ��ȡ��ɫ����
    int getGreen() const;                   // ��ȡ��ɫ����
    int getBlue() const;                    // ��ȡ��ɫ����
    void setRed(int r);                     // ���ú�ɫ����
    void setGreen(int g);                   // ������ɫ����
    void setBlue(int b);                    // ������ɫ����
};

#endif // COLOR_H