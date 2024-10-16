//
//  main.cpp
//  Каталог текстов песен
//
//  Created by Станислав Егоров on 12.12.2023.
//
/*
 Приложение должно иметь следующие возможности:
 ■ Добавление текста песни:
 • Текст песни:
 может быть введен с клавиатуры;
 загружен из файла.
 • Для каждой песни нужно указывать название песни, автора текста и
 год создания песни (если он известен).
 ■ Удаление текста песни.
 ■ Изменение текста песни.
 ■ Отображение текста песни на экран.
 ■ Сохранение текста песни в файл.
 ■ Поиск и отображение всех песен одного автора.
 ■ Поиск и отображение всех песен, содержащих слово, указанное пользователем
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Структура для хранения информации о песне
struct Song {
    std::string title;
    std::string author;
    int year;
    std::string lyrics;
};

// Функция для добавления песни в каталог
void addSong(std::vector<Song>& catalog) {
    Song newSong;

    std::cout << "Введите название песни: ";
    std::getline(std::cin >> std::ws, newSong.title);

    std::cout << "Введите автора песни: ";
    std::getline(std::cin >> std::ws, newSong.author);

    std::cout << "Введите год создания песни (если известен): ";
    std::cin >> newSong.year;

    std::cout << "Введите текст песни: ";
    std::getline(std::cin >> std::ws, newSong.lyrics);

    catalog.push_back(newSong);
    std::cout << "Песня успешно добавлена в каталог!" << std::endl;
}

// Функция для удаления песни из каталога
void deleteSong(std::vector<Song>& catalog) {
    std::string titleToDelete;
    std::cout << "Введите название песни, которую необходимо удалить: ";
    std::getline(std::cin >> std::ws, titleToDelete);

    bool songFound = false;
    for (auto it = catalog.begin(); it != catalog.end(); ++it) {
        if (it->title == titleToDelete) {
            catalog.erase(it);
            songFound = true;
            break;
        }
    }

    if (songFound) {
        std::cout << "Песня успешно удалена!" << std::endl;
    } else {
        std::cout << "Песня с указанным названием не найдена." << std::endl;
    }
}

// Функция для изменения текста песни
void editSong(std::vector<Song>& catalog) {
    std::string titleToEdit;
    std::cout << "Введите название песни, текст которой нужно изменить: ";
    std::getline(std::cin >> std::ws, titleToEdit);

    bool songFound = false;
    for (auto& song : catalog) {
        if (song.title == titleToEdit) {
            std::cout << "Введите новый текст песни: ";
            std::getline(std::cin >> std::ws, song.lyrics);
            songFound = true;
            break;
        }
    }

    if (songFound) {
        std::cout << "Текст песни успешно изменен!" << std::endl;
    } else {
        std::cout << "Песня с указанным названием не найдена." << std::endl;
    }
}

// Функция для отображения текста песни на экран
void displaySong(const Song& song) {
    std::cout << "Название песни: " << song.title << std::endl;
    std::cout << "Автор текста: " << song.author << std::endl;
    std::cout << "Год создания: " << song.year << std::endl;
    std::cout << "Текст песни:\n" << song.lyrics << std::endl;
}

// Функция для сохранения каталога песен в файл
void saveCatalog(const std::vector<Song>& catalog, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& song : catalog) {
            file << "Название песни: " << song.title << std::endl;
            file << "Автор текста: " << song.author << std::endl;
            file << "Год создания: " << song.year << std::endl;
            file << "Текст песни:\n" << song.lyrics << std::endl;
            file << std::endl;
        }
        file.close();
        std::cout << "Каталог песен сохранен в файл: " << filename << std::endl;
    } else {
        std::cout << "Не удалось сохранить каталог песен. Проверьте правильность имени файла." << std::endl;
    }
}

// Функция для поиска и отображения всех песен одного автора
void searchByAuthor(const std::vector<Song>& catalog, const std::string& author) {
    std::cout << "Песни автора " << author << ":" << std::endl;

    bool songsFound = false;
    for (const auto& song : catalog) {
        if (song.author == author) {
            displaySong(song);
            std::cout << std::endl;
            songsFound = true;
        }
    }

    if (!songsFound) {
        std::cout << "Песни указанного автора не найдены." << std::endl;
    }
}

// Функция для поиска и отображения всех песен, содержащих указанное слово
void searchByKeyword(const std::vector<Song>& catalog, const std::string& keyword) {
    std::cout << "Песни, содержащие слово \"" << keyword << "\":" << std::endl;

    bool songsFound = false;
    for (const auto& song : catalog) {
        if (song.lyrics.find(keyword) != std::string::npos) {
            displaySong(song);
            std::cout << std::endl;
            songsFound = true;
        }
    }

    if (!songsFound) {
        std::cout << "Песни с указанным словом не найдены." << std::endl;
    }
}

int main() {
    std::vector<Song> catalog;
    std::string filename = "catalog.txt";

    int choice;
    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить текст песни" << std::endl;
        std::cout << "2. Удалить текст песни" << std::endl;
        std::cout << "3. Изменить текст песни" << std::endl;
        std::cout << "4. Отобразить текст песни" << std::endl;
        std::cout << "5. Сохранить каталог в файл" << std::endl;
        std::cout << "6. Поиск песен одного автора" << std::endl;
        std::cout << "7. Поиск песен по ключевому слову" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addSong(catalog);
                break;
            case 2:
                deleteSong(catalog);
                break;
            case 3:
                editSong(catalog);
                break;
            case 4:
                if (catalog.empty()) {
                    std::cout << "Каталог песен пуст." << std::endl;
                } else {
                    std::string titleToDisplay;
                    std::cout << "Введите название песни, которую необходимо отобразить: ";
                    std::getline(std::cin >> std::ws, titleToDisplay);

                    bool songFound = false;
                    for (const auto& song : catalog) {
                        if (song.title == titleToDisplay) {
                            displaySong(song);
                            songFound = true;
                            break;
                        }
                    }

                    if (!songFound) {
                        std::cout << "Песня с указанным названием не найдена." << std::endl;
                    }
                }
                break;
            case 5:
                saveCatalog(catalog, filename);
                break;
            case 6: {
                std::string authorToSearch;
                std::cout << "Введите имя автора для поиска: ";
                std::getline(std::cin >> std::ws, authorToSearch);
                searchByAuthor(catalog, authorToSearch);
                break;
            }
            case 7: {
                std::string keywordToSearch;
                std::cout << "Введите ключевое слово для поиска: ";
                std::getline(std::cin >> std::ws, keywordToSearch);
                searchByKeyword(catalog, keywordToSearch);
                break;
            }
            case 0:
                std::cout << "До свидания!" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}
