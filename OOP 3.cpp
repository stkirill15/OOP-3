#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

template <typename T> class Stack
{
public:
    Stack() : root(nullptr), size(0) {} // По умолчанию стек пуст
    Stack <T>(Stack const& a) : root(nullptr), size(0) // Конструктор копирования
    {
        Node* copy = nullptr;
        for (Node* n = a.root; n != nullptr; n = n->next) {
            Node* item = new Node();
            item->data = n->data;
            if (!root)
                root = item;
            else
                copy->next = item;
            copy = item;
            ++size;
        }
    }
    ~Stack() // Деструктор
    {
        while (!empty()) {
            pop();
        }
    }
    Stack <T>& operator =(Stack const& a) // Оператор присваивания
    {
        while (!empty())
            pop();
        size = 0;
        Node* copy = nullptr;
        for (Node* n = a.root; n != nullptr; n = n->next) {
            Node* item = new Node();
            item->data = n->data;
            if (!root)
                root = item;
            else
                copy->next = item;
            copy = item;
            ++size;
        }
        return *this;
    }
    void push(const T& x) // Добавление в стек
    {
        cout << "push() => " << x << endl;
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = root;
        root = newnode;
        size++;
    }
    bool empty() const // Проверка на пустоту
    {
        printf("empty() => ");
        if (root == nullptr)
            printf("yes ");
        else
            printf("no ");
        return root == nullptr;
    }
    const T& top() const // Вывод вершины стека
    {
        cout << "top() => ";
        if (empty())
        {
            return NULL;
        }
        cout << root->data << endl;
        return root->data;
    }
    void pop() { // Удаление вершины стека
        cout << "pop() => ";
        if (empty())
        {
            printf("\n");
            return;
        }
        cout << "=> " << root->data << endl;
        Node* delnode = root;
        root = delnode->next;
        size--;
        delete delnode;
    }
    int get_size() { // Вывести размер стека 
        return size;
    }
    void clear() { // Очистка стека
        while (!empty()) {
            pop();
        }
    }
    void show() const { // Вывод элементов стека
        for (Node* n = root; n != nullptr; n = n->next)
            cout << n->data << ' ';
        printf("\n");
    }
private:
    struct Node // Узел стека
    {
        T data; // Поле с данными
        Node* next; // Указатель на следующий узел
    };
    int size;
    Node* root; // Верхний элемент стека
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    while (1) {
        system("cls");
        Stack <int> s;
        clock_t start = clock();
        srand(std::time(NULL));
        for (int i = 0; i < 10000; i++) {
            int choice = rand() % 6;
            if (choice >= 0 && choice <= 2) {
                int a = rand() % 10000;
                s.push(a);
            }
            else if (choice == 3) {
                s.pop();
            }
            else if (choice == 4) {
                s.empty();
                printf("\n");
            }
            else if (choice == 5) {
                s.top();
            }
        }
        clock_t end = clock();
        printf("\n\n");
        s.show();
        printf("\n\n");
        long double time = (long double)(end - start) / CLOCKS_PER_SEC;
        cout << "\nПрограмма работала " << time << " секунд.\n Количество элементов - " << s.get_size() << endl;
        _getch();
    }
    return 0;
}