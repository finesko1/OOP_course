#pragma once
#include <string>
#include <vector>
using namespace std;


class Lightning
{
private:
    string idLight, surname;
    int lenLight, powerLight, distantToLight;
    double timeLight;

    //����������� �� ���������
    Lightning();
    //����������� c �����������
    Lightning(string idLight, int lenLight, int powerLight, int distantToLight, double timeLight, string surname);
    //����������� �����������
    Lightning(const Lightning& myLight);

    //����������
    ~Lightning();
 
    //�������
    void setIdLight(string idLight);
    void setLenLight(int lenLight);
    void setPowerLight(int powerLight);
    void setDistantToLight(int distantToLight);
    void setTimeLight(double timeLight);
    void setSurname(string surname);

    //�������
    string getIdLight();
    int getLenLight();
    int getPowerLight();
    int getDistantToLight();
    double getTimeLight();
    string getSurname();

    //���������� ��� ���������� � ������
    void showInfoAboutLight();
};

//����� ���������� � ������ ������
void printAllList(vector<Lightning>& A);

//���������� ������
void addElement(vector<Lightning>& A);

//�������� ������
void delElement(vector<Lightning>& A);

//��������� ��������� ������
void editElement(vector<Lightning>& A);

//������� ������� 1
void taskOne(vector<Lightning>& A);

//������� ������� 2
void taskTwo(vector<Lightning>& A);

//������ ���������
void menu();
