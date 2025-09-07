// данный файл нужен для решения различных задач и реализации структур данных и алгоритмов
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template<typename T>
class List {

private:

    template<typename T2>
    class Node {
    public:
        Node *pNext; // указатель на следующий элемент
        T2 data; // хранение информации любого типа

        Node(T2 data=T2(), Node *pNext=nullptr) { // устанавливаем значения по умолчанию, чтобы не было мусора
            this->data = data;
            this->pNext = pNext;
        }
    };

    int SIZE;
    Node<T> *head;

public:
    // объявляем методы
    List();
    ~List();

    void clear_list();
    void pop_front();
    void push_back(T data);
    int GetSize();
    void pop_back();
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);
    void PrintList();


    T& operator[](const int index);

};

// конструктор по умолчанию
template<typename T>
List<T>::List() {
    SIZE = 0;
    head = nullptr;
}

// деструктор для освобождения памяти
template<typename T>
List<T>::~List() {
    cout << "Deleting List..." << endl;
    clear_list();
}

// метод нужен для добавления элементов в конец списка
template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        this->head = new Node<T>(data);
    }
    else {
        Node<T> *curr = head;
        while (curr->pNext != nullptr) {
            curr = curr->pNext;
        }

        curr->pNext = new Node<T>(data);
    }

    SIZE++;
}

// метод для удаления первого элемента
template<typename T>
void List<T>::pop_front() {
    Node<T> *temp = head; // храним адрес head
    head = head->pNext;

    delete temp;

    SIZE--;
}

// геттер
template<typename T>
int List<T>::GetSize() {
    return SIZE;
}

// тип данных, ссылка, класс(его тип данных), обращение к оператору(или методу), какой оператор перегружаем, индекс
template<typename T>
T & List<T>::operator[](const int index) {
    int counter = 0;
    Node<T> *curr = head;
    while (curr != nullptr) {
        if (counter == index) {
            return curr->data;
        }
        curr = curr->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::clear_list() {
    while (SIZE) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    SIZE++;
}

template<typename T>
void List<T>::insert(T data, int index) {

    if (index == 0) {
        push_front(data);
    }
    else {
        Node<T> *prev = this->head;

        for (int i = 0; i < (index - 1); i++) {
            prev = prev->pNext;
        }
        Node<T> *newNode = new Node<T>(data, prev->pNext);
        prev->pNext = newNode;

        SIZE++;
    }
}

template<typename T>
void List<T>::removeAt(int index) {

    if (index == 0) {
        pop_front();
    }
    else {
        Node<T> *prev = this->head;
        for (int i = 0; i < (index - 1); i++) {
            prev = prev->pNext;
        }
        Node<T> *temp = prev->pNext;
        prev->pNext = temp->pNext;
        temp->pNext = nullptr;
        delete temp;
        SIZE--;
    }
}

template<typename T>
void List<T>::pop_back() {
    removeAt(SIZE - 1);
}



template<typename T>
void List<T>::PrintList() {
    Node<T> *curr = head;
    cout << curr->data;
    curr = curr->pNext;
    while (curr != nullptr) {
        cout << "->";
        cout << curr->data;
        curr = curr->pNext;
    }
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "Rus");

    List<int> lst;
    lst.push_back(1488);
    lst.push_back(228);
    lst.push_back(337);

    lst.insert(666, 2);

    lst.PrintList();

    lst.removeAt(1);

    lst.PrintList();

    lst.pop_back();

    lst.PrintList();

    return 0;
}


