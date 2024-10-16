//
//  main.cpp
//  Стек
//
//  Created by Станислав Егоров on 26.02.2024.
//

#include <iostream>

using namespace std;

/*

Stack » LIFO | Last In First Out

FIFO » | Firt In First Out

*/

class Stack {
    //Нижняя и верхняя границы стека
    enum { EMPTY = -1, FULL = 3 };

    //Массив для хранения данных
    char st[FULL + 1];

    // указатель на вершину
    int top;

public:
    // ctor
    Stack();
    // push
    void Push(char c);
    // pop
    char Pop();
    // clear
    void Clear();
    // is full
    bool IsFull();
    // is empty
    bool IsEmpty();
    // get count
    int GetCount();
};

Stack::Stack() {
    top = EMPTY;
}

bool Stack::IsFull() {
    return top == FULL;
}

bool Stack::IsEmpty() {
    return top == EMPTY;
}

int Stack::GetCount() {
    return top + 1;
}

void Stack::Push(char c) {
    if (!IsFull())
        st[++top] = c;

    /*

    top++ >> возвращение top >> увеличение top на 1
    ++top >> увеличение на 1 >> возвращение

    */
}

char Stack::Pop() {
    return IsEmpty() ? 0 : st[top--];
}

void Stack::Clear() {
    top = EMPTY;
}

int main()
{
    srand(time(0));
    Stack ST;
    char c;

    //пока стек не заполнится
    cout << "Pushed: ";
    while (!ST.IsFull()) {
        c = rand() % 4 + 2;
        ST.Push(c);
        cout << c << " ";
        cout.flush();
    }

    //пока стек не освободится
    cout << "\nPopped: ";
    while (c = ST.Pop()) {
        cout << c << " ";
        cout.flush();
    }
    cout << "\n\n";
}
