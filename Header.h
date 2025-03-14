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

    //Конструктор по умолчанию
    Lightning();
    //Конструктор c параметрами
    Lightning(string idLight, int lenLight, int powerLight, int distantToLight, double timeLight, string surname);
    //Конструктор копирования
    Lightning(const Lightning& myLight);

    //Деструктор
    ~Lightning();
 
    //Сеттеры
    void setIdLight(string idLight);
    void setLenLight(int lenLight);
    void setPowerLight(int powerLight);
    void setDistantToLight(int distantToLight);
    void setTimeLight(double timeLight);
    void setSurname(string surname);

    //Геттеры
    string getIdLight();
    int getLenLight();
    int getPowerLight();
    int getDistantToLight();
    double getTimeLight();
    string getSurname();

    //Отобразить всю информацию о молнии
    void showInfoAboutLight();
};

//Вывод информации о списке молний
void printAllList(vector<Lightning>& A);

//Добавление молний
void addElement(vector<Lightning>& A);

//Удаление молнии
void delElement(vector<Lightning>& A);

//Изменение параметра молнии
void editElement(vector<Lightning>& A);

//Решение задания 1
void taskOne(vector<Lightning>& A);

//Решение задания 2
void taskTwo(vector<Lightning>& A);

//Запуск программы
void menu();
