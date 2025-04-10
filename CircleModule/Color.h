#ifndef COLOR_H
#define COLOR_H

class Color {
private:
    int red = 0;
    int green = 0;
    int blue = 0;

public:
    Color(int r = 0, int g = 0, int b = 0); // 构造函数声明
    int getRed() const;                     // 获取红色分量
    int getGreen() const;                   // 获取绿色分量
    int getBlue() const;                    // 获取蓝色分量
    void setRed(int r);                     // 设置红色分量
    void setGreen(int g);                   // 设置绿色分量
    void setBlue(int b);                    // 设置蓝色分量
};

#endif // COLOR_H