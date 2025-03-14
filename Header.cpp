#include <string>
#include <vector>
#include <iostream>
#include "Header.h"
using namespace std;

class Lightning
{
private:
    string idLight, surname;
    int lenLight, powerLight, distantToLight;
    double timeLight;

public:
    //Конструктор по умолчанию
    Lightning()
    {
        idLight = "";
        surname = "";
        lenLight = 0;
        powerLight = 0;
        distantToLight = 0;
        timeLight = 0;
    }

    //Конструктор с параметрами
    Lightning(string idLight, int lenLight, int powerLight, int distantToLight, double timeLight, string surname)
    {
        this->idLight = idLight;
        this->lenLight = lenLight;
        this->powerLight = powerLight;
        this->distantToLight = distantToLight;
        this->timeLight = timeLight;
        this->surname = surname;
    }

    //Конструктор копирования
    Lightning(const Lightning& myLight)
    {
        idLight = myLight.idLight;
        lenLight = myLight.lenLight;
        powerLight = myLight.powerLight;
        distantToLight = myLight.distantToLight;
        timeLight = myLight.timeLight;
        surname = myLight.surname;
    }

    //Деструктор
    ~Lightning() {}

    //Сеттеры
    void setIdLight(string idLight) { this->idLight = idLight; }
    void setLenLight(int lenLight) { this->lenLight = lenLight; }
    void setPowerLight(int powerLight) { this->powerLight = powerLight; }
    void setDistantToLight(int distantToLight) { this->distantToLight = distantToLight; }
    void setTimeLight(double timeLight) { this->timeLight = timeLight; }
    void setSurname(string surname) { this->surname = surname; }

    //Геттеры
    string getIdLight() { return idLight; }
    int getLenLight() { return lenLight; }
    int getPowerLight() { return powerLight; }
    int getDistantToLight() { return distantToLight; }
    double getTimeLight() { return timeLight; }
    string getSurname() { return surname; }
    //Отобразить всю информацию о молнии
    void showInfoAboutLight()
    {
        cout << "Id lightning: " << idLight;
        cout << "\nLength lightning: " << lenLight;
        cout << "\nPower lightning: " << powerLight;
        cout << "\nDistant to lightning: " << distantToLight;
        cout << "\nFlash time: " << timeLight;
        cout << "\nSurname spectator: " << surname << endl;
    }
};

//Вывод информации о списке молний
void printAllList(vector<Lightning>& A)
{
    for (Lightning i : A)
    {
        i.showInfoAboutLight();
        cout << endl << endl;
    }
}

//Добавление молний
void addElement(vector<Lightning>& A)
{
    //Запрос на количество добавлений
    int count;
    cout << "How many lightnings do you want to add? - ";
    cin >> count;
    //Запрос списка параметров молнии
    for (int i = 0; i < count; i++)
    {
        string idLightX, surnameX;
        int lenLightX, powerLightX, distantToLightX, timeLightX;

        cout << "Enter id lightning " << i + 1 << ": ";
        cin >> idLightX;

        cout << "Enter length lightning " << i + 1 << ": ";
        cin >> lenLightX;

        cout << "Enter power lightning " << i + 1 << ": ";
        cin >> powerLightX;

        cout << "Enter distant to lightning " << i + 1 << ": ";
        cin >> distantToLightX;

        cout << "Enter flash time lightning " << i + 1 << ": ";
        cin >> timeLightX;

        cout << "Enter surname spectator " << i + 1 << ": ";
        cin >> surnameX;

        //Добавление молнии в список
        A.push_back(Lightning(idLightX, lenLightX, powerLightX, distantToLightX, timeLightX, surnameX));
        cout << "!!!  Lightning number " << i + 1 << " is added in your list!!!  \n\n";
    }
}

//Удаление молнии
void delElement(vector<Lightning>& A)
{
    /*Параметры, по которым отобразить список молний
            1 - по идентефикатору
            2 - по длине
            3 - по мощности
            4 - по дистанции до молнии
            5 - по времени вспышки
            6 - по фамилии наблюдателя*/
    cout << "Enter parametr lightnings:\n";
    cout << "1 - identificator\n";
    cout << "2 - length\n";
    cout << "3 - power\n";
    cout << "4 - distant to lightning\n";
    cout << "5 - flash time\n";
    cout << "6 - surname spectator\n";
    //Запрос номера действия
    char numAct;
    cout << "Your action: ";
    cin >> numAct;
    cout << endl;

    cout << "Number\t\tparametr\n";
    switch (numAct)
    {
    case'1':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getIdLight() << endl;
        }
        break;
    }
    case'2':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getLenLight() << endl;
        }
        break;
    }
    case'3':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getPowerLight() << endl;
        }
        break;
    }
    case'4':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getDistantToLight() << endl;
        }
        break;
    }
    case'5':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getTimeLight() << endl;
        }
        break;
    }
    case'6':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getSurname() << endl;
        }
        break;
    }
    }

    char typeDel;
    string delParametr;
    cout << "Enter value parameter: ";
    cin >> delParametr;
    cout << endl;

    cout << "Deleting an element\n";
    cout << "1 - everything related to this value\n";
    cout << "2 - defined number\n";
    cout << "Type of deletion: ";
    cin >> typeDel;
    cout << endl;

    switch (typeDel)
    {
    case'1':
    {
        //Удаление по параметру всех элементов
        switch (numAct)
        {
        case'1':
        {
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getIdLight() == delParametr)
                {
                    A.erase(A.begin() + i);
                }
            }
            break;
        }
        case'2':
        {
            int k = stoi(delParametr);
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getLenLight() == k)
                {
                    A.erase(A.begin() + i);
                }
            }
            break;
        }
        case'3':
        {
            int k = stoi(delParametr);
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getPowerLight() == k)
                {
                    A.erase(A.begin() + i);
                }
            }
            break;
        }
        case'4':
        {
            int k = stoi(delParametr);
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getDistantToLight() == k)
                {
                    A.erase(A.begin() + i);
                }
            }
            break;
        }
        case'5':
        {
            int k = stoi(delParametr);
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getTimeLight() == k)
                {
                    A.erase(A.begin() + i);
                }
            }
            break;
        }
        case'6':
        {
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getSurname() == delParametr)
                {
                    A.erase(A.begin() + i);
                }
            }
            break;
        }
        default:
        {
            cout << "Error in the parameter\n";
        }
        }
        break;
    }
    case'2':
    {
        int numLight = 0;
        cout << "Enter num lightning - ";
        cin >> numLight;
        A.erase(A.begin() + numLight - 1);
        break;
    }
    default:
    {
        cout << "The type of deletion is not defined";
    }
    }
}

//Изменение параметра молнии
void editElement(vector<Lightning>& A)
{
    /*Параметры, по которым отобразить список молний
                       1 - по идентефикатору
                       2 - по длине
                       3 - по мощности
                       4 - по дистанции до молнии
                       5 - по времени вспышки
                       6 - по фамилии наблюдателя*/
    cout << "Enter the change parameter:\n";
    cout << "1 - identificator\n";
    cout << "2 - length\n";
    cout << "3 - power\n";
    cout << "4 - distant to lightning\n";
    cout << "5 - flash time\n";
    cout << "6 - surname spectator\n";
    //Запрос номера действия
    char numAct;
    cout << "Your action: ";
    cin >> numAct;
    cout << endl;

    cout << "Number\t\tparametr\n";
    switch (numAct)
    {
    case'1':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getIdLight() << endl;
        }
        break;
    }
    case'2':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getLenLight() << endl;
        }
        break;
    }
    case'3':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getPowerLight() << endl;
        }
        break;
    }
    case'4':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getDistantToLight() << endl;
        }
        break;
    }
    case'5':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getTimeLight() << endl;
        }
        break;
    }
    case'6':
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << i + 1 << "\t\t" << A[i].getSurname() << endl;
        }
        break;
    }
    }

    int numLight;
    string edParametr;
    cout << "Enter num lightning: ";
    cin >> numLight;
    cout << "Enter new value parameter: ";
    cin >> edParametr;
    cout << endl;

    //cout << "Number\t\tparametr\n";
    switch (numAct)
    {
    case'1':
    {
        A[numLight - 1].setIdLight(edParametr);
        break;
    }
    case'2':
    {
        A[numLight - 1].setLenLight(stoi(edParametr));
        break;
    }
    case'3':
    {
        A[numLight - 1].setPowerLight(stoi(edParametr));
        break;
    }
    case'4':
    {
        A[numLight - 1].setDistantToLight(stoi(edParametr));
        break;
    }
    case'5':
    {
        A[numLight - 1].setTimeLight(stoi(edParametr));
        break;
    }
    case'6':
    {
        A[numLight - 1].setSurname(edParametr);
        break;
    }
    }
}

//Решение задания 1
void taskOne(vector<Lightning>& A)
{
    string surnameX;
    cout << "Enter surname spectator: ";
    cin >> surnameX;
    int distantToLightX;
    cout << "Enter distant to lightning: ";
    cin >> distantToLightX;

    for (Lightning i : A)
    {
        if (i.getSurname() == surnameX)
        {
            if (i.getDistantToLight() > distantToLightX)
            {
                i.showInfoAboutLight();
                cout << endl << endl;
            }
        }
    }
}

//Решение задания 2
void taskTwo(vector<Lightning>& A)
{
    int timeLightX;
    cout << "Enter flash time: ";
    cin >> timeLightX;
    int lenLightX;
    cout << "Enter lenght lightning: ";
    cin >> lenLightX;

    for (Lightning i : A)
    {
        if (i.getTimeLight() == timeLightX)
        {
            if (i.getLenLight() > lenLightX)
            {
                i.showInfoAboutLight();
                cout << endl << endl;
            }
        }
    }
}

//Запуск программы
void menu()
{
    //Создание начального списка молний 
    //Параметры молнии: идентификатор, длина, мощность, удаленность, длительность, фамилия наблюдателя
    vector<Lightning> vecLightning;
    vecLightning.push_back(Lightning("A", 1750, 15000, 1000, 1, "Fedorov"));
    vecLightning.push_back(Lightning("B", 1300, 18000, 1500, 0.75, "Ivanov"));
    vecLightning.push_back(Lightning("C", 1200, 20000, 200, 1.1, "Komarov"));
    vecLightning.push_back(Lightning("D", 1250, 22500, 1355, 0.83, "Mikhailov"));
    vecLightning.push_back(Lightning("B", 1250, 17500, 270, 1.1, "Denisov"));
    vecLightning.push_back(Lightning("C", 1800, 16500, 1200, 0.85, "Fedorov"));

    while (true)
    {
        /*Варианты действий со списком молний
        1 - добавить молнию
        2 - удалить молнию
        3 - изменить параметр молнии
        4 - выполнение задания один
        5 - выполнение задания два
        6 - вывыод информации о молниях*/
        cout << "Table of actions\n";
        cout << "1 - add lightning\n";
        cout << "2 - delete lightning\n";
        cout << "3 - edit info about lightning\n";
        cout << "4 - task one\n";
        cout << "5 - task two\n";
        cout << "6 - info about list\n\n";

        //Запрос номера действия
        char numAct;
        cout << "Enter an action: ";
        cin >> numAct;
        cout << endl;


        switch (numAct)
        {
        case '1':
        {
            addElement(vecLightning);
            break;
        }
        case '2':
        {
            delElement(vecLightning);
            break;
        }
        case '3':
        {
            editElement(vecLightning);
            break;
        }
        case '4':
        {
            taskOne(vecLightning);
            break;
        }
        case '5':
        {
            taskTwo(vecLightning);
            break;
        }
        case '6':
        {
            printAllList(vecLightning);
            break;
        }
        default:
        {
            cout << "The end of the program\n";
            break;
        }
        }
    }

}