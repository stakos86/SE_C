//
//  main.cpp
//  Экзамен. Виселица
//
//  Created by Станислав Егоров on 06.03.2024.
//
/*
 Создайте консольную версию игры «Виселица».
 Важно:
 ■ Слово выбирается компьютером из списка слов.
 ■ Список слов находится в файле в зашифрованном виде.
 ■ По завершении игры на экран выводится статистика игры:
 • количество времени;
 • количество попыток;
 • искомое слово;
 • буквы игрока
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

const int MAX_TRIES = 6; // максимальное количество попыток

std::string selectRandomWord() {
    std::ifstream wordFile("words.txt");
    std::vector<std::string> words;

    std::string word;
    while (wordFile >> word) {
        words.push_back(word);
    }

    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void printGameStats(int tries, const std::string& word, const std::vector<char>& guessedLetters) {
    std::cout << "Игра окончена!" << std::endl;
    std::cout << "Количество попыток: " << tries << std::endl;
    std::cout << "Искомое слово: " << word << std::endl;
    std::cout << "Буквы игрока: ";
    for (char letter : guessedLetters) {
        std::cout << letter << " ";
    }
    std::cout << std::endl;
}

char readGuess() {
    std::cout << "Угадайте букву: ";
    char guess;
    std::cin >> guess;
    return guess;
}

bool hasLetter(const std::string& word, char letter) {
    for (char c : word) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

void updateGame(std::string& currentWord, const std::string& word, char letter) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            currentWord[i] = letter;
        }
    }
}

bool isGameFinished(const std::string& currentWord, const std::string& word, int tries) {
    if (currentWord == word) {
        std::cout << "Вы угадали слово: " << word << std::endl;
        return true;
    } else if (tries == 0) {
        std::cout << "Вы использовали все попытки. Загаданное слово: " << word << std::endl;
        return true;
    }
    return false;
}

int main() {
    std::srand(std::time(nullptr));

    std::string word = selectRandomWord();
    std::string currentWord(word.length(), '_');
    int tries = MAX_TRIES;
    std::vector<char> guessedLetters;

    std::cout << "Добро пожаловать в игру Виселица!" << std::endl;

    while (true) {
        std::cout << "Загаданное слово: " << currentWord << std::endl;
        std::cout << "Оставшиеся попытки: " << tries << std::endl;

        char guess = readGuess();
        guessedLetters.push_back(guess);

        if (hasLetter(word, guess)) {
            updateGame(currentWord, word, guess);
        } else {
            tries--;
        }

        if (isGameFinished(currentWord, word, tries)) {
            break;
        }
    }

    printGameStats(MAX_TRIES - tries, word, guessedLetters);

    return 0;
}
