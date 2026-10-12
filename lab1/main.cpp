#include <iostream>
#include <string>
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

int main() {
    setlocale(LC_ALL, "RU");
    string specialty = "Программная инженерия";
    string studentName = "Кабачук Лия";
    int subjectsCount = 5;
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
                cout << "Игра началась! Добро пожаловать в университет" << endl;
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
                    cout << "Спеицальность: " << specialty << endl;
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
                        cin.ignore(); getline(cin, specialty);
                    } 
                    else if (settingsChoice == setName) {
                        cout << "Введите имя студента: ";
                        cin.ignore(); getline(cin, studentName);
                    } 
                    else if (settingsChoice == setSubjects) {
                        cout << "Введите количество предметов: ";
                        cin >> subjectsCount;
                    }
                    else if (settingsChoice == setBack) {
                        cout << "Возврат в главное меню" << endl;
                    }
                    else {
                        cout << "Неверный пункт. Попробуйте снова" << endl;
                    }
                }
                break;
            }
            case about: {
                cout << endl;
                cout << "--- О программе ---" << endl;
                cout << "Версия: 1.0" << endl;
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