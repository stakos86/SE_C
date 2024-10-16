//
//  main.cpp
//  Очередь
//
//  Created by Станислав Егоров on 27.02.2024.
//

#include <iostream>
#include <queue>

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

    // Получение первого элемента из очереди
    T front() const {
        if (!queueData.empty()) {
            return queueData.front();
        } else {
            std::cout << "Очередь пуста, нельзя выполнить front" << std::endl;
            return T(); // Возвращаем пустой объект типа T
        }
    }

    // Проверка, пуста ли очередь
    bool isEmpty() const {
        return queueData.empty();
    }

    // Получение размера очереди
    size_t size() const {
        return queueData.size();
    }
};

int main() {
    // Создание очереди целых чисел
    Queue<int> intQueue;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    std::cout << "Размер очереди intQueue: " << intQueue.size() << std::endl;

    // Создание очереди строк
    Queue<std::string> stringQueue;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    std::cout << "Размер очереди stringQueue: " << stringQueue.size() << std::endl;

    return  0;
}
