#include<iostream> 
#include<Windows.h> 
#include<cmath> 
#include<string> 
#include<iomanip> 


//Аккаунты 
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin","user" };
std::string* passArr = new std::string[userCount]{ "admin","user" };

//Касса
double cash = 50000;
double cashMoney{};
double webMoney{};

//чек
int checkSize = 1;
std::string* nameCheckArr = new std::string[checkSize];
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];


//Cклад 
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

void Start();
bool Login();
bool IsNumber(std::string string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
void Getline(std::string& stringname);
int Getid(int mode = 0);
void RefillProduct();
void RemoveProduct();
void ChangePrice();
void ChangeStorage();
void AddNewProduct();
void EditProduct();
void DeleteProduct();

void ChangeEmployee();
void AddNewEmployee();
void EditEmployee();
void DeleteEmployee();

void Selling();
void AddNewCheckSize();

//свой склад
template<typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize)
{
    for (int i = 0; i < staticSize; i++)
    {
        dynamicArr[i] = staticArr[i];
    }
}
//sss
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Start();
    delete[]loginArr;
    delete[]passArr;
    delete[]idArr;
    delete[]nameArr;
    delete[]countArr;
    delete[]priceArr;
    return 0;
}

void RefillProduct()

{
    std::string choose, chooseCount;
    int id = 0, count;

    while (true)
    {
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод:";
        Getline(choose);
        if (choose == "1")
        {
            ShowStorage(1);
            id = Getid();
            while (true)
            {
                std::cout << "Введите кол-во товара для пополнения: ";
                Getline(chooseCount);
                if (IsNumber(chooseCount))
                {
                    count = std::stoi(chooseCount);

                    if (count >= 0 && count <= 1000)
                    {

                    }
                    else
                    {
                        std::cout << "\nОшибка ввода\n";
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }

            }
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}
template<typename Arr>
void FillStorage(Arr stasticArr[], Arr dynamicArr[], int staticSize);


void Start() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "\t\tКисточки\n\n";
    if (Login() == true) {
        if (isAdmin == true) {
            std::string choose;
            loginArr->size();

            while (true)
            {

                std::cout << "\n1 - Использовать готовый склад\n2 - Создать склад\nВвод: ";
                std::getline(std::cin, choose, '\n');
                if (choose == "1") {
                    //готовый склад 
                    CreateStaticStorage();
                    break;
                }
                else if (choose == "2")
                {
                    //динамический склад 
                    break;
                }
                else
                {
                    std::cout << "\n\nОшибка ввода\n\n";
                }
            }
            ShowAdminMenu();
        }
        else
        {
            CreateStaticStorage();
            ShowAdminMenu();
            //загрузка юзерского меню
        }
    }
    else
    {
        std::cerr << "LoginErr\n";
    }
}
bool Login() {
    std::string login, pass;
    while (true)
    {
        std::cout << "Введите логин:";
        Getline(login);
        std::cout << "Введите пароль:";
        Getline(pass);
        if (login == loginArr[0] && pass == passArr[0])
        {
            std::cout << "Авторизация пользователя:" << loginArr[0] << '\n\n';
            isAdmin = true;
            return true;
        }

        for (int i = 1; i < userCount; i++) {
            if (login == loginArr[i] && pass == passArr[i])
            {
                std::cout << "Авторизация пользователя: " << loginArr[i] << "\n\n";
                isAdmin = false;
                return true;
            }

        }
        system("cls");
        std::cout << "Неверный логин или пароль\n\n";
    }
}


bool IsNumber(std::string string)
{
    for (int i = 0; i < string.size(); i++)
    {
        if (!std::isdigit(string[i]))
        {
            return false;
        }
    }
    return true;
}


void CreateStaticStorage()
{
    const int tempSize = 10;
    int tempId[tempSize]{ 1,2,3,4,5,6,7,8,9,10 };
    std::string tempName[tempSize]
    {
     "Кровавые пилочки",
     "Жестяные кусачки",
     "Режущие фрезы",
     "МандаИриновые палочки",
     "Железные типсы",
     "Пенопластовый штамп",
     "Ультракислотный праймер",
     "Бумажные ножнички",
     "Прозрачный глиттер",
     "Карамельный лак"
    };
    int tempCount[tempSize]{ 300,12,25,500,450,50,40,60,15,30 };
    double tempPrice[tempSize]{ 90.0,450.0,250.0,15.0,350.0,200.0,150.0,400.0,180.0,290.0 };
    FillStorage(tempId, idArr, tempSize);
    FillStorage(tempName, nameArr, tempSize);
    FillStorage(tempCount, countArr, tempSize);
    FillStorage(tempPrice, priceArr, tempSize);
}

void ShowAdminMenu()
{
    std::string choose;
    while (true)
    {
        system("cls");
        std::cout << "1 - Начать продажу\n";
        std::cout << "2 - Показать склад\n";
        std::cout << "3 - Пополнить склад\n";
        std::cout << "4 - Списать со склада\n";
        std::cout << "5 - Изменить цену\n";
        std::cout << "6 - Изменить склад\n";
        std::cout << "7 - Изменить сотрудников\n";
        std::cout << "8 - Отчёт о прибыли\n";
        std::cout << "0 - Закрыть смену\n\n";
        std::cout << "Ввод: ";
        Getline(choose);
        if (choose == "1")
        {
            Selling();
        }
        else if (choose == "2")
        {
            ShowStorage();

        }
        else if (choose == "3")
        {
            RefillProduct();
        }
        else if (choose == "4")
        {
            RemoveProduct();
        }
        else if (choose == "5")
        {
            ChangePrice();
        }
        else if (choose == "6")
        {
            ChangeStorage();
        }
        else if (choose == "7")
        {
            ChangeEmployee();
        }
        else if (choose == "8")
        {

        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
            Sleep(500);
        }

    }
}

void ShowUserMenu()
{
    std::string choose;
    while (true)
    {
        system("cls");
        std::cout << "1 - Начать продажу\n";
        std::cout << "2 - Показать склад\n";
        std::cout << "3 - Пополнить склад\n";
        std::cout << "4 - Списать со склада\n";
        std::cout << "5 - Отчёт о прибыли\n";
        std::cout << "0 - Закрыть смену\n\n";
        std::cout << "Ввод: ";
        std::getline(std::cin, choose, '\n');
        if (choose == "1")
        {

        }
        else if (choose == "2")
        {
            ShowStorage();
        }
        else if (choose == "3")
        {
            RefillProduct();
        }
        else if (choose == "4")
        {
            RemoveProduct();
        }
        else if (choose == "5")
        {

        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
            Sleep(500);
        }

    }
}


void ShowStorage(int mode)
{
    system("cls");
    if (mode == 0)
    {
        std::cout << "ID" << "название\t\t\t" << "кол-во\t" << "цена\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
        }
        system("pause");
    }
    else if (mode == 1)//склад без цены
    {
        std::cout << "ID" << "название\t\t\t" << "кол-во\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\n";
        }
    }
    else if (mode == 2)//склад без кол-во 
    {
        std::cout << "ID" << "название\t\t\t" << "цена\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << priceArr[i] << "\n";
        }
    }
    else if (mode == 3)//склад названий
    {
        std::cout << "ID" << "название\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\n";
        }
    }
    else
    {
        std::cerr << "\nMenuModeError\n";
    }
}



void Getline(std::string& stringName)
{
    std::getline(std::cin, stringName, '\n');
}
int Getid(int mode)
{
    std::string stringId;
    int result{};
    int currentSize = 0;
    if (mode == 1)
    {
        currentSize = userCount;
    }
    else if (mode == 0)
    {
        currentSize = size;
    }
    while (true)
    {
        std::cout << "Введите ID товара: ";
        Getline(stringId);
        if (IsNumber(stringId))
        {
            result = std::stoi(stringId);
            if (result > 0 && result <= size)
            {
                return result;
            }
            else
            {
                std::cout << "\nНеккоректное ID\n";
            }
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
    return 0;
}

void RefillProduct()
{
    std::string choose, chooseCount;
    int id = 0, count;
    while (true) {
        system("cls");        
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод:";
        Getline(choose);        
        if (choose == "1")
        {
            ShowStorage(1);
            id = Getid();           
            while (true)
            {
                std::cout << "Введите кол-во товара для пополнения: ";
                Getline(chooseCount);                
                if (IsNumber(chooseCount))
                {
                    count = std::stoi(chooseCount);
                    if (count >= 0 && count <= 1000)
                    {
                        countArr[id - 1] += count;
                        std::cout << "\n\nТовар успешно пополнен\n\n";                        Sleep(800);
                        break;
                    }
                    else {
                        std::cout << "\nОшибка ввода\n";
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }
        }
        else if (choose == "0") 
        {
            break;
        }
        else 
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}
void RemoveProduct()
{
    std::string choose, chooseCount; 
    int id = 0, count;
    while (true)
    {
        system("cls");
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод:";   
        Getline(choose);
        if (choose == "1") 
        {
            ShowStorage(1);        
            id = Getid();
            while (true)
            {
                std::cout << "Введите кол-во товара для списания: ";
                Getline(chooseCount);           
                if (IsNumber(chooseCount))
                {
                    count = std::stoi(chooseCount);
                    if (count >= 0 && count <= countArr[id - 1])
                    {
                        countArr[id - 1] -= count;
                        std::cout << "\n\nТовар успешно списан\n\n";                    Sleep(800);
                        break;
                    }
                    else 
                    {
                        std::cout << "\nОшибка ввода\n";
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }
        }
        else if (choose == "0") 
        {
            break;
        }
        else 
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}
void ChangePrice()
{
    std::string choose, choosePrice;      
    int id = 0;
    double price{};
    while (true) 
    {
        system("cls");            
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод:";
        Getline(choose);            
        if (choose == "1")
        {
            ShowStorage(2);
            id = Getid();               
            while (true)
            {
                std::cout << "Введите новую цену: ";
                Getline(choosePrice);                    
                if (IsNumber(choosePrice))
                {
                    price = std::stod(choosePrice);
                    if (price >= 0 && price <= 50000.0)
                    {
                        priceArr[id - 1] = price;
                        std::cout << "\n\nЦена успешно изменена\n\n";                           
                        Sleep(800);
                        break;
                    }
                    else 
                    {
                        std::cout << "\nОшибка ввода\n";
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }
        }
        else if (choose == "0") 
        {
            break;
        }
        else 
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}
void ChangeStorage()
{
    std::string choose;
    while (true)
    {
        system("cls");
        std::cout << "Изменение склада\n\n";
        std::cout << "1 - Добавление нового товара\n2 - редактирование назавания\n3 - Удаление товара\n0 - Отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            AddNewProduct();
        }
        else if (choose == "2")
        {
            EditProduct();
        }
        else if (choose == "3")
        {
            DeleteProduct();
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}

void AddNewProduct()
{
    std::string choose, nameStr, priceStr, countStr;
    while (true)
    {
        system("cls");
        std::cout << "Добавление нового товара\n\n";
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
        Getline(choose);

        if (choose == "1")
        {
            int* tempId = new int[size];
            int* tempCount = new int[size];
            double* tempPrice = new double[size];
            std::string* tempName = new std::string[size];

            for (int i = 0; i < size; i++)
            {
                tempId[i] = idArr[i];
                tempCount[i] = countArr[i];
                tempPrice[i] = priceArr[i];
                tempName[i] = nameArr[i];
            }

            delete[]idArr;
            delete[]nameArr;
            delete[]countArr;
            delete[]priceArr;

            size++;

            idArr = new int[size];
            countArr = new int[size];
            priceArr = new double[size];
            nameArr = new std::string[size];

            for (int i = 0; i < size - 1; i++)
            {
                idArr[i] = tempId[i];
                countArr[i] = tempCount[i];
                priceArr[i] = tempPrice[i];
                nameArr[i] = tempName[i];
            }

            while (true)
            {
                std::cout << "Введите название нового товара:";
                Getline(nameStr);
                if (nameStr.size() <= 60 && nameStr.size() > 1)
                {
                    nameArr[size - 1] = nameStr;
                    break;
                }
                std::cout << "\nОшибка ввода. От 2 до 60 символов\n";
            }

            while (true)
            {
                std::cout << "Введите кол-во нового товара:";
                Getline(countStr);
                if (IsNumber(countStr))
                {
                    if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000)
                    {
                        countArr[size - 1] = std::stoi(countStr);
                        break;
                    }
                    else
                    {
                        std::cout << "\nОшибка ввода\n";
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            while (true)
            {
                std::cout << "Введите цену нового товара:";
                Getline(priceStr);
                if (IsNumber(priceStr))
                {
                    if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 50000.0)
                    {
                        priceArr[size - 1] = std::stod(priceStr);
                        break;
                    }
                    else
                    {
                        std::cout << "\nОшибка ввода\n";
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            idArr[size - 1] = size;

            std::cout << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1]
                << "\t" << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";
            std::cout << "Новый товар успешно добавлен\n";

            delete[]tempId;
            delete[]tempCount;
            delete[]tempPrice;
            delete[]tempName;

            Sleep(2000);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}
void EditProduct()
{
    std::string choose, newName;
    int id{};
    while (true)
    {
        system("cls");
        std::cout << "Редактирование товара\n\n";
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            ShowStorage(3);
            id = Getid();
            while (true)
            {
                std::cout << "Введите новое название товара";
                Getline(newName);
                if (newName.size() <= 60 && newName.size() > 1)
                {
                    nameArr[id - 1] = newName;
                    break;
                }
                std::cout << "\nОшибка ввода. От 2 до 60 символов\n";
            }
            std::cout << "Название изменено\n";
            Sleep(2000);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
            Sleep(800);
        }
    }
}
void DeleteProduct()
{
    std::string choose;
    int id{};
    while (true)
    {
        system("cls");
        std::cout << "Удаление товара\n\n";
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
        Getline(choose);

        if (choose == "1")
        {
            ShowStorage(3);
            int* tempId = new int[size];
            int* tempCount = new int[size];
            double* tempPrice = new double[size];
            std::string* tempName = new std::string[size];

            for (int i = 0; i < size; i++)
            {
                tempId[i] = idArr[i];
                tempCount[i] = countArr[i];
                tempPrice[i] = priceArr[i];
                tempName[i] = nameArr[i];
            }

            delete[]idArr;
            delete[]nameArr;
            delete[]countArr;
            delete[]priceArr;

            size--;

            idArr = new int[size];
            countArr = new int[size];
            priceArr = new double[size];
            nameArr = new std::string[size];

            id = Getid();

            for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
            {
                if (j == id - 1)
                {
                    if (id == size + 1)
                    {
                        break;
                    }
                    j++;
                    idArr[i] = tempId[i];
                    countArr[i] = tempCount[j];
                    priceArr[i] = tempPrice[j];
                    nameArr[i] = tempName[j];
                }
                else
                {
                    idArr[i] = tempId[i];
                    countArr[i] = tempCount[j];
                    priceArr[i] = tempPrice[j];
                    nameArr[i] = tempName[j];
                }

            }
            std::cout << "Товар успешно удален\n";

            delete[]tempId;
            delete[]tempCount;
            delete[]tempPrice;
            delete[]tempName;

            Sleep(2000);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
            Sleep(800);
        }
    }
}

void ChangeEmployee()
{
    std::string choose;
    while (true)
    {
        system("cls");
        std::cout << "Изменение сотрудников\n\n";
        std::cout << "1 - Добавление нового сотрудника\n2 - редактирование логина, пороля\n3 - Удаление сотрудника\n0 - Отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            AddNewEmployee();
        }
        else if (choose == "2")
        {
            EditEmployee();
        }
        else if (choose == "3")
        {
            if (userCount > 1)
            {
                DeleteEmployee();
            }
            else
            {
                std::cout << "Нет пользователя для удаления\n";
                Sleep(500);
            }
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
            Sleep(800);
        }
    }
}
void AddNewEmployee()
{
    std::string choose, newLogin, newPass;
    int  id = 0;

    while (true)
    {
        system("cls");
        std::cout << "Добавление нового сотрудника\n\n";
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
        Getline(choose);

        if (choose == "1")
        {
            std::string* tempLogin = new std::string[userCount];
            std::string* tempPass = new std::string[userCount];


            for (int i = 0; i < userCount; i++)
            {
                tempLogin[i] = loginArr[i];
                tempPass[i] = passArr[i];
            }

            delete[]loginArr;
            delete[]passArr;


            userCount++;

            loginArr = new std::string[userCount];
            passArr = new std::string[userCount];

            for (int i = 0; i < userCount - 1; i++)
            {
                loginArr[i] = tempLogin[i];
                passArr[i] = tempPass[i];
            }

            while (true)
            {
                std::cout << "Введите логин нового пользователя:";
                Getline(newLogin);
                if (newLogin.size() <= 15 && newLogin.size() >= 4)
                {
                    loginArr[userCount - 1] = newLogin;
                    break;
                }
                std::cout << "\nОшибка ввода. От 4 до 15 символов\n";
            }

            while (true)
            {
                std::cout << "Введите пароль нового пользователя:";
                Getline(newPass);
                if (newPass.size() <= 15 && newPass.size() >= 4)
                {
                    passArr[userCount - 1] = newPass;
                    break;
                }
                std::cout << "\nОшибка ввода. От 4 до 15 символов\n";
            }
            std::cout << "Новый пользователь успешно добавлен\n";

            delete[]tempPass;
            delete[]tempLogin;
            Sleep(2000);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}
void EditEmployee()
{
    std::string choose, currentPass, newPass;
    int id = 0;
    while (true)
    {
        system("cls");
        std::cout << "Редактирование даннных сотрудника\n\n";
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            id = Getid(1);
            while (true)
            {
                std::cout << "Введите текущий пароль пользователя: " << loginArr[id - 1] << "\n0 - Выход\nВывод: ";
                Getline(currentPass);
                if (currentPass == passArr[id - 1])
                {
                    while (true)
                    {
                        std::cout << "Введите новый пароль пользователя:" << loginArr[id - 1] << ": ";
                        Getline(newPass);
                        if (newPass.size() <= 15 && newPass.size() >= 4)
                        {
                            passArr[id - 1] = newPass;
                            std::cout << "Пароль успешно изменен\n";
                            break;
                        }
                        std::cout << "\nОшибка ввода. От 4 до 15 символов\n";
                    }
                }
                else if (currentPass == "0")
                {
                    break;
                }
                else
                {
                    std::cout << "\nНеверные данные\n";
                }
            }
        }
        else if (choose == "0")
        {

        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}
void DeleteEmployee()
{
    std::string choose;
    int id{};
    while (true)
    {
        system("cls");
        std::cout << "Удаление сотрудника\n\n";
        std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
        Getline(choose);
        if (userCount <= 1)
        {
            std::cout << "Пользователей больше нет\n";
            Sleep(1000);
            break;
        }

        if (choose == "1")
        {
            for (int i = 1; i < userCount; i++)
            {
                std::cout << i << " " << loginArr[i] << "\n";
            }
            std::cout << "\n";

            std::string* tempLogin = new std::string[userCount];
            std::string* tempPass = new std::string[userCount];


            for (int i = 0; i < userCount; i++)
            {
                tempLogin[i] = loginArr[i];
                tempPass[i] = passArr[i];
            }

            delete[]loginArr;
            delete[]passArr;

            userCount--;

            loginArr = new std::string[userCount];
            passArr = new std::string[userCount];

            id = Getid(1);

            loginArr[0] = tempLogin[0];
            passArr[0] = tempPass[0];



            for (int i = 1, j = 1; i < userCount, j < userCount + 1; i++, j++)
            {
                if (j == id)
                {
                    if (id == userCount)
                    {
                        break;
                    }
                    j++;
                    loginArr[i] = tempLogin[j];
                    passArr[i] = tempPass[j];
                }
                else
                {
                    loginArr[i] = tempLogin[j];
                    passArr[i] = tempPass[j];
                }

            }
            std::cout << "Пользователь успешно удален\n";

            delete[]tempLogin;
            delete[]tempPass;

            Sleep(2000);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
            Sleep(800);
        }
    }
}

void Selling()
{
    std::string choose, chooseID, chooseCount;
    bool isFirst = true;
    int id{}, count{};
    while (true)
    {
        system("cls");
        std::cout << "1 - Начать новую продажу\n0 - Отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            isFirst = true;
            delete[]totalPriceCheckArr;
            delete[]countCheckArr;
            delete[]countCheckArr;
            delete[]priceCheckArr;

            checkSize = 1;

            totalPriceCheckArr = new double[size];
            countCheckArr = new int[size];
            priceCheckArr = new double[size];
            nameCheckArr = new std::string[size];

            while (true)
            {
                system("cls");
                ShowStorage();
                std::cout << "Введите ID товара или\"exit\" для завершения покупок\n\nВвод: ";
                Getline(chooseID);
                if (chooseID == "exit")
                {
                    break;
                }
                else if (IsNumber(chooseID))
                {
                    id = std::stoi(chooseID);
                    if (id > 0 && id <= size)
                    {
                        std::cout << "Введите кол-во " << nameArr[id - 1] << " для покупки: ";
                        Getline(chooseCount);
                        if (IsNumber(chooseCount))
                        {
                            count = std::stoi(chooseCount);
                            if (count >= 0 && count <= countArr[id - 1])
                            {
                                if (isFirst)
                                {
                                    nameCheckArr[checkSize - 1] = nameArr[id - 1];
                                    countCheckArr[checkSize - 1] = count;
                                    priceCheckArr[checkSize - 1] = priceArr[id - 1];
                                    totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
                                    isFirst = false;
                                    //удаление склада
                                }
                                else
                                {
                                    AddNewCheckSize();
                                    nameCheckArr[checkSize - 1] = nameArr[id - 1];
                                    countCheckArr[checkSize - 1] = count;
                                    priceCheckArr[checkSize - 1] = priceArr[id - 1];
                                    totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
                                }
                            }
                            else
                            {
                                std::cout << "\nОшибка кол-во\n";
                                Sleep(1000);
                            }
                        }
                        else
                        {
                            std::cout << "\nОшибка ввода\n";
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        std::cout << "\nОшибка ID\n";
                        Sleep(1000);
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                    Sleep(1000);
                }
            }
            if (!isFirst)
            {
                
            }
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
            Sleep(800);
        }
    }
}

void AddNewCheckSize()
{
    std::string choose;
    int* tempCount = new int[checkSize];
    double* tempTotalPrice = new double[checkSize];
    double* tempPrice = new double[checkSize];
    std::string* tempName = new std::string[checkSize];

    for (int i = 0; i < size; i++)
    {
        tempTotalPrice[i] = totalPriceCheckArr[i];
        tempCount[i] = countCheckArr[i];
        tempPrice[i] = priceCheckArr[i];
        tempName[i] = nameCheckArr[i];
    }

    delete[]totalPriceCheckArr;
    delete[]countCheckArr;
    delete[]countCheckArr;
    delete[]priceCheckArr;

    checkSize++;

    totalPriceCheckArr = new double[size];
    countCheckArr = new int[size];
    priceCheckArr = new double[size];
    nameCheckArr = new std::string[size];

    for (int i = 0; i < checkSize - 1; i++)
    {
        totalPriceCheckArr[i] = tempTotalPrice[i];
        countCheckArr[i] = tempCount[i];
        priceCheckArr[i] = tempPrice[i];
        nameCheckArr[i] = tempName[i];
    }

    delete[]tempTotalPrice;
    delete[]tempCount;
    delete[]tempPrice;
    delete[]tempName;
}


