//
//  main.cpp
//  Интерфейс для управления автомобилем
//
//  Created by Станислав Егоров on 20.03.2024.
//

class ICarControl {
public:
    virtual void goForward() = 0;
    virtual void goBackward() = 0;
    virtual void stop() = 0;
    virtual void turnRight() = 0;
    virtual void turnLeft() = 0;
    virtual ~ICarControl() {}
};


//Описание реализации интерфейса для легкового автомобиля:

class SedanCar : public ICarControl {
public:
    void goForward() override {
        // Код для движения вперед для легкового автомобиля
    }

    void goBackward() override {
        // Код для движения назад для легкового автомобиля
    }

    void stop() override {
        // Код для остановки движения для легкового автомобиля
    }

    void turnRight() override {
        // Код для поворота вправо для легкового автомобиля
    }

    void turnLeft() override {
        // Код для поворота влево для легкового автомобиля
    }
};


//Описание реализации интерфейса для трактора:


class Tractor : public ICarControl {
public:
    void goForward() override {
        // Код для движения вперед для трактора
    }

    void goBackward() override {
        // Код для движения назад для трактора
    }

    void stop() override {
        // Код для остановки движения для трактора
    }

    void turnRight() override {
        // Код для поворота вправо для трактора
    }

    void turnLeft() override {
        // Код для поворота влево для трактора
    }
};
