//
//  main.cpp
//  Книга
//
//  Created by Станислав Егоров on 10.01.2024.
//

#include <iostream>
#include <string>
using namespace std;

enum TypeOfBinding {
    leather,
    paper,
    cardboard
};

struct Book {
    string name ="";
    int pages = 0;
    int year = 0;
    TypeOfBinding binding;
    
    string toString() {
        string bindingStr;
        switch (binding) {
            case leather: bindingStr = "кожа"; break;
            case paper: bindingStr = "бумага"; break;
            case cardboard: bindingStr = "картон"; break;
            default: bindingStr = "неизвестно";
        }
        
        return "Название: " + name + ", Страниц: " + to_string(pages) + ", Год издания: " + to_string(year) + ", Переплет: " + bindingStr;
    }
};

int main() {
    Book book1, book2{"Name2", 1000, 2002, cardboard};
    book1.name = "Name1";
    book1.pages = 1600;
    book1.year = 1918;
    book1.binding = paper;
    
    cout << book1.toString() << endl;
    cout << book2.toString() << endl;
    
    return 0;
}
