//
//  main.cpp
//  Парсинг СВТ
//
//  Created by Станислав Егоров on 25.10.2023.
//

#include <iostream> // Библиотека для ввода и вывода
#include <string> // Библиотека для работы со строками
#include <curl/curl.h> // Библиотека cURL для отправки HTTP-запросов

// Функция обратного вызова для записи ответа
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp)
{
    userp->append((char*)contents, size * nmemb); // Добавляем полученные данные в нашу строку
    return size * nmemb; // Возвращаем количество обработанных данных
}

int main()
{
    CURL* curl; // Объект для работы с cURL
    CURLcode res; // Код ответа cURL
    std::string readBuffer; // Строка для хранения ответа
    
    curl_global_init(CURL_GLOBAL_DEFAULT); // Инициализируем cURL
    curl = curl_easy_init(); // Создаем объект cURL
    
    if(curl) { // Если объект создан успешно
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.svt.spb.ru"); // Устанавливаем URL, на который отправляем запрос
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // Устанавливаем функцию обратного вызова для записи ответа
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer); // Устанавливаем строку, в которую будет записан ответ
        
        res = curl_easy_perform(curl); // Выполняем HTTP-запрос
        
        if(res != CURLE_OK) // Если произошла ошибка
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res)); // Выводим сообщение об ошибке
        else
            std::cout << readBuffer << std::endl; // Выводим полученную HTML-страницу
        
        curl_easy_cleanup(curl); // Очищаем ресурсы, занятые cURL
    }
    
    curl_global_cleanup(); // Очищаем все глобальные ресурсы, занятые cURL
    
    return 0; // Завершаем программу
}
