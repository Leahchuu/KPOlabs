#include <iostream>
#include <string>
#include <fstream> 
#include <list>
#include <set>
using namespace std;

const int start = 1;
const int load = 2;
const int settings = 3;
const int about = 4;
const int exitMenu = 5;

const int setSpecialty = 1;
const int setName = 2;
const int setSubjects = 3;
const int setBack = 4;

// функция для сохранения настроек в файл 
void saveSettings(const string& specialty, const string& studentName, int subjectsCount) { 
    ofstream outFile("settings.txt"); 
    if (outFile.is_open()) { 
        outFile << specialty << endl; 
        outFile << studentName << endl; 
        outFile << subjectsCount << endl; 
        outFile.close();
    } 
}

// функция для загрузки настроек из файла
void loadSettings(string& specialty, string& studentName, int& subjectsCount) { 
    ifstream inFile("settings.txt"); 
    if (inFile.is_open()) { 
        getline(inFile, specialty); 
        getline(inFile, studentName);
        inFile >> subjectsCount; 
        inFile.close();
    } else {
    // если файла нет, записываем значения по умолчанию
        specialty = "Программная инженерия"; 
        studentName = "Кабачук Лия"; 
        subjectsCount = 5; 
        saveSettings(specialty, studentName, subjectsCount);
    } 
}

int main() {
    setlocale(LC_ALL, "RU");
    string specialty;
    string studentName;
    int subjectsCount;

    loadSettings(specialty, studentName, subjectsCount);

    list<string> studentNamesHistory;
    set<string> availableSpecialties = { "Программная инженерия", "Искусственный интеллект", "Компьютерная инженерия" }; // множество Set

    // Добавим текущее имя в список
    studentNamesHistory.push_back(studentName);

    int menuChoice = 0;
    while (menuChoice != exitMenu) {
        cout << endl;
        cout << "--- Моя жизнь в университете ---" << endl;
        cout << "1. Начать игру" << endl;
        cout << "2. Загрузить игру" << endl;
        cout << "3. Настройки" << endl;
        cout << "4. О программе" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите пункт меню: ";
        cin >> menuChoice;

        switch (menuChoice) {
            case start: {
                cout << endl;
                cout << "Игра началась! Добро пожаловать в университет, " << studentName << endl;
                cout << "[Нажмите Enter, чтобы вернуться в главное меню]" << endl;
                cin.ignore(); cin.get();
                break;
            }
            case load: {
                cout << endl;
                cout << "Эта функция сейчас недоступна. Появится в ближайших обновлениях" << endl;
                cout << "[Нажмите Enter, чтобы вернуться в главное меню]" << endl;
                cin.ignore(); cin.get();
                break;
            }
            case settings: {
                int settingsChoice = 0;
                while (settingsChoice != setBack) {
                    cout << endl;
                    cout << "--- Настройки игры ---" << endl;
                    cout << "Специальность: " << specialty << endl;
                    cout << "Имя студента: " << studentName << endl;
                    cout << "Количество предметов: " << subjectsCount << endl;
                    cout << "----------------------" << endl;
                    cout << "1. Изменить специальность" << endl;
                    cout << "2. Изменить имя студента" << endl;
                    cout << "3. Изменить количество предметов" << endl;
                    cout << "4. Назад в главное меню" << endl;
                    cout << "Выберите параметр для изменения: ";
                    cin >> settingsChoice;

                    if (settingsChoice == setSpecialty) {
                        cout << "Введите новую специальность: ";
                        cin.ignore(); 
                        getline(cin, specialty);
                        // добавляем в множество
                        availableSpecialties.insert(specialty);
                        // сохраняем в файл
                        saveSettings(specialty, studentName, subjectsCount);
                        cout << "Специальность успешно изменена и сохранена в файл" << endl;
                    } 
                    else if (settingsChoice == setName) {
                        cout << "Введите имя студента: ";
                        cin.ignore(); 
                        getline(cin, studentName);
                        // добавляем в список
                        studentNamesHistory.push_back(studentName);
                        // сохраняем в файл
                        saveSettings(specialty, studentName, subjectsCount);
                        cout << "Имя успешно изменено и сохранено в файл" << endl;
                    }
                    else if (settingsChoice == setSubjects) {
                        cout << "Введите количество предметов: ";
                        cin.ignore();
                        cin >> subjectsCount;
                        // сохраняем в файл
                        saveSettings(specialty, studentName, subjectsCount);
                        cout << "Количество предметов изменено и сохранено в файл" << endl;
                    }
                    else if (settingsChoice == setBack) {
                        cout << "Возврат в главное меню" << endl;
                    } else {
                        cout << "Неверный пункт. Попробуйте снова" << endl;
                    }
                }
                break;
            }
            case about: {
                cout << endl;
                cout << "--- О программе ---" << endl;
                cout << "Версия: 2.0" << endl;
                cout << "Разработчик: Кабачук Лия" << endl;
                cout << "--------------------" << endl;
                cout << "[Нажмите Enter, чтобы вернуться в главное меню]" << endl;
                cin.ignore(); cin.get();
                break;
            }
            case exitMenu: {
                cout << endl;
                cout << "Выход из программы" << endl;
                break;
            }
            default: {
                cout << endl;
                cout << "Неверный ввод. Выберите пункт от 1 до 5" << endl;
                break;
            }
        }
    }
    return 0;
}