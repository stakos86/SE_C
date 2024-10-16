//
//  main.cpp
//  6
//
//  Created by Станислав Егоров on 08.04.2024.
//

#include <iostream>
#include <queue>
using namespace std;

// Шаблон класса очереди
template <typename T>
class Queue {
private:
    std::queue<T> queueData;

public:
    // Добавление элемента в конец очереди
    void enqueue(T value) {
        queueData.push(value);
    }

    // Удаление элемента из начала очереди
    void dequeue() {
        if (!queueData.empty()) {
            queueData.pop();
        } else {
            std::cout << "Очередь пуста, нельзя выполнить dequeue" << std::endl;
        }
    }

    // Проверка, пуста ли очередь
    bool isEmpty() const {
        return queueData.empty();
    }

    // Возвращает первый элемент очереди
    T front() const {
        if (!queueData.empty()) {
            return queueData.front();
        } else {
            throw std::runtime_error("Очередь пуста");
        }
    }

    // Удаляет первый элемент очереди
    void pop() {
        if (!queueData.empty()) {
            queueData.pop();
        } else {
            std::cout << "Очередь пуста, нельзя выполнить pop" << std::endl;
        }
    }
};

int main() {
    // Создание очереди целых чисел
    Queue<int> intQueue;
    intQueue.enqueue(748756);
    try {
        cout << intQueue.front() << " ";
        intQueue.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
