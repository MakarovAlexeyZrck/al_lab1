// laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;


// Используемые структуры данных
struct trumpet
{
    int id;
    float length;
    float diam;
    bool repaired = 0;
};

struct ks
{
    int id;
    char name[100];
    int number;
    int numberOfAvailable;
    float efficiency;
};


// Глобальный вектор для информации о трубах
vector <trumpet> trumpets_data;

// Глобальный вектор для информации о КС
vector <ks> kss_data;


// Проверяем, чтоб было введено натуральное число
int is_invalidinput(string msg) {

    int user_input;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0 || user_input > 7);

    return user_input;
}


// Проверяем, чтоб было введена переменная типа float
float is_float(string msg) {

    float user_input;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0);

    return user_input;
}


// Ввод целого неотрицательного числа от пользователя
int is_integer(string msg) {

    int user_input;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0);

    return user_input;
}


// Ввод булевого значения
bool is_bool(string msg) {

    bool user_input = 1;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0 || user_input > 2);

    return user_input;

}


// Функция по добавлению трубы
void new_trumpet() {

    /*
        *  В этой функции мы создаем новую трубу и добавлем ее в простаранство всех труб
    */

    // Создаем трубу
    trumpet current_trumpet;


    // Получаем идентификатор трубы от пользователя
    current_trumpet.id = is_integer("Введите идентификатор трубы:   ");

    // Пользователь заполняет остальную информацию о трубе
    current_trumpet.length = is_float("Введите длину трубы:   ");

    // Добавляем диаметр трубы
    current_trumpet.diam = is_float("Введите диаметр трубы:   ");

    // Добавляем признак в работе или нет
    current_trumpet.repaired = is_bool("Труба в работе? (1 - да, 0 - нет):  ");


    cout << "\nДобавлена новая труба: " << endl;
    cout << "Идентификатор: " << current_trumpet.id << endl;
    cout << "Длина: " << current_trumpet.length << endl;
    cout << "Диаметр трубы: " << current_trumpet.diam << endl;
    cout << (current_trumpet.repaired ? "Труба в ремонте" : "Труба работает") << endl;

}


// Добавляем новую КС
void new_ks() {

    /*
        *  В этой функции мы создаем новую компрессорную станцию и добавляем ее в пространство всех кс
    */

    // Создаем трубу
    ks current_ks;


    // Получаем идентификатор КС от пользователя
    current_ks.id = is_integer("Введите идентификатор КС:   ");

    // Пользователь заполняет имя КС
    cout << "Введите наименование КС:   ";
    cin >> current_ks.name;

    // Пользователь вводит количество цехов
    current_ks.number = is_integer("Введите количество цехов в КС:   ");

    // Пользователь вводит количество цехов в работе
    current_ks.numberOfAvailable = is_integer("Введите количество цехов КС в работе:   ");

    // Цехов в работе должно быть меньше, чем цехов всего
    if (current_ks.numberOfAvailable > current_ks.number){
        while (current_ks.numberOfAvailable >= current_ks.number){
            current_ks.numberOfAvailable = is_integer("Введенное число цехов в работе превышает число всех цехов:   ");
        }
    }

    // Введите показатель эфективности КС
    current_ks.efficiency = is_float("Введите показатель эффекти́вности:     ");


    cout << "\nДобавлена новая КС: " << endl;
    cout << "Идентификатор: " << current_ks.id << endl;
    cout << "Наименованиие: " << current_ks.name << endl;
    cout << "Кол-во цехов всего: " << current_ks.number << endl;
    cout << "Кол-во цехов в работе: " << current_ks.numberOfAvailable << endl;
    cout << "Эффективность КС: " << current_ks.efficiency << endl;

}


// Функция с вводом и проверкой начальной комманды первоначальной команды
int main_menu()
{

    // Меню пользователя по выбору функции программы
    cout << "1. Добавить трубу" << endl <<
            "2. Добавить КС" << endl <<
            "3. Просмотр всех объектов" << endl <<
            "4. Редактировать трубу" << endl <<
            "5. Редактировать КС" << endl <<
            "6. Сохранить" << endl <<
            "7. Загрузить" << endl <<
            "0. Выход" << endl;

    // Ввода пользователя (защита от текстового ввода, отр. чисел, чисел > кол-ва пунктов в меню
    int user_input_main;
    user_input_main = is_invalidinput("Выберите необходимую функцию или задайте ее снова(1-7):  ");

    // Запуск функционала программы
    switch (user_input_main)
    {
    case 1:
    {
        cout << endl << " --- Создание новой трубы --- " << endl;
        new_trumpet();
        break;
    }

    case 2:
    {
        cout << endl << " --- Создание новой КС --- " << endl;
        new_ks();
        break;
    }

    case 3:
    {
        cout << "Отобразить все элементы";
        break;
    }

    case 4:
    {
        cout << "Исправить трубу";
        break;
    }

    case 5:
    {
        cout << "Исправить КС";
        break;
    }

    case 6:
    {
        cout << "Выполняем чтение из файла";
        break;
    }

    case 7:
    {
        cout << "Сохраним все данные в файл";
        break;
    }

    case 0:
    {
        return 0;
    }

    }

    cout << "\n\n";

}

int main()
{
    // Делаем отображение русского текста в консоли
    setlocale(LC_ALL, "Russian");

    // Переменная, обозначающая пользовательский ввод
    int user_point = 1;

    // До тех пор, пока пользователь не введет нуль из главного меню - программа выполняется
    while (user_point != 0) {
        user_point = main_menu();
    }

    cout << "\n\nПрограмма завершила работу!!! \n\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.