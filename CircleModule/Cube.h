#ifndef CUBE_H
#define CUBE_H

class Cube {
private:
    double length = 0;  // ����
    double width = 0;   // ���
    double height = 0;  // �߶�

public:
    // ��Ա��������
    void setLength(int l);    // ���ó���
    void setWidth(int w);     // ���ÿ��
    void setHeight(int h);    // ���ø߶�
    double getLength();       // ��ȡ����
    double getWidth();        // ��ȡ���
    double getHeight();       // ��ȡ�߶�
    double getVolume();       // �������
};

#endif // CUBE_H