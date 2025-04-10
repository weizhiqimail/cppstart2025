#ifndef CUBE_H
#define CUBE_H

class Cube {
private:
    double length = 0;  // 长度
    double width = 0;   // 宽度
    double height = 0;  // 高度

public:
    // 成员函数声明
    void setLength(int l);    // 设置长度
    void setWidth(int w);     // 设置宽度
    void setHeight(int h);    // 设置高度
    double getLength();       // 获取长度
    double getWidth();        // 获取宽度
    double getHeight();       // 获取高度
    double getVolume();       // 计算体积
};

#endif // CUBE_H