#include <windows.h>
#include <iostream>
#include <direct.h>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
// Оценка -> ID студента, ID предмета, основание, значение.
// За посещение (0), контрольные (1), творчество (2), экзамены (3).
class grade {
public:
    short int sID{}, dID{}, type{};
    double nume{};
    string date{};
    grade(short int sID, short int dID, short int type, double nume, string date) : sID(sID), dID(dID), type(type), nume(nume), date(date) {};
};
// Студент -> ID студента, ID группы, имя.
class student {
public:
    short int sID{}, gID{};
    string name{};
    student(short int sID, short int gID, string name) : sID(sID), gID(gID), name(name) {};
};
// Предмет -> ID предмета, название.
class discipline {
public:
    short int dID{};
    string name{};
    discipline(short int dID, string name) : dID(dID), name(name) {};
};
// Группа -> ID группы, название.
class group {
public:
    short int gID{};
    string name{}; // В имени группы: университет, факультет, направление, имя группы, дата поступления, уровень обучения.
    group(short int gID, string name) : gID(gID), name(name) {};
};
// Направление -> ID направления, название.
class programme {
public:
    short int pID{};
    string name{};
    programme(short int pID, string name) : pID(pID), name(name) {};
};
// Факультет -> ID факультета, название.
class faculty {
public:
    short int fID{};
    string name{};
    faculty(short int fID, string name) : fID(fID), name(name) {};
};
// Университет (или филиал) -> ID университета, название.
class university {
public:
    short int uID{};
    string name{};
    university(short int uID, string name) : uID(uID), name(name) {};
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    // В перспективе создать базу данных.
    vector <grade> grades = {
        grade(0, 0, 0, 0.5, "1.1.3000"), grade(1, 0, 0, 0.5, "1.1.3000"), grade(2, 0, 0, 0.5, "1.1.3000"),
        grade(2, 0, 3, 10, "2.2.3000"), grade(1, 0, 3, 5, "2.2.3000"), grade(0, 0, 3, 0, "2.2.3000")
    };
    vector <student> students = { student(0, 0, "Первый"), student(1, 0, "Второй"), student(2, 0, "Третий") };
    vector <discipline> disciplines = { discipline(0, "Математика"), discipline(1, "Экономика") };
    vector <string> degrees = { "Бакалавр", "Специалист", "Магистр" };
    vector <university> universities = { university(0, "Университет Омега"), university(1, "Университет Сигма") };

    ofstream fout;
    cout << "Создать папки университетов: " << endl;
    for (int i = 0; i < universities.size(); i++) {
        cout << "Для ID " << universities[i].uID << " - ";
        if (!_mkdir((to_string(universities[i].uID)).c_str())) {
            cout << "\x1b[92mУспешно\x1b[0m";
            fout.open((to_string(universities[i].uID)).c_str() + string("/students.txt")); fout.close();
            fout.open((to_string(universities[i].uID)).c_str() + string("/grades.txt")); fout.close();
        }
        else cout << "\x1b[91mСуществует\x1b[0m";
        cout << endl;
    }

    //cout << "Оценки студента №: "; int snume; cin >> snume;
    //for (int i = 0; i < grades.size(); i++) {
    //    if (grades[i].sID == snume) cout << grades[i].sID << " " << grades[i].dID << " " << grades[i].type << " " << grades[i].nume << " " << grades[i].date << endl;
    //}

    return 0;
}
