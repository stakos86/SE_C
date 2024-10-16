////
////  main.cpp
////  Работа в классе 01.06.24
////
////  Created by Станислав Егоров on 01.07.2024.
////
//
////#include <iostream>
////#include <iomanip>
////#include <ctime>
////using namespace std;
////
////class Counter {
////int attempts;
////public:
////Counter(int s=0) : attempts(s) {};
////
////void Run() { attempts++; }
////void getString() { cout << "attempts: " << attempts << " "; }
////};
////
////class ProbableCounter {
////int odds=1;
////int total=3;
////int attempts;
////int result=0;
////public:
////ProbableCounter(int o, int t, int a) : odds(o), total(t), attempts(a) {};
////
////bool Run() {
////attempts++;
////
////if (rand() % total < odds) {
////result++;
////cout << "[" << odds << "/" << total << "]:увеличился result, теперь: "
//// << result << "\n";
////}
////return result == true ? result++ : result;
////}
////
////void getString() { cout << "attempts: " << attempts << " result: " << result <<
////", odds: " << odds << ", total: " << total; }
////};
////
////class Point {
////double point;
////public:
////Point(double p) { p >= 100 ? point = 0.001 : point = 0.00001; }
////double GetPoint() { return point; }
////};
////
////int main()
////{
////srand(time(0));
////Point p1(186.345), p2(1.08755);
////cout << "Point для 186.345 " << p1.GetPoint();
////cout << "\nPoint для 1.08755 " << fixed << setprecision(5) << p2.GetPoint();
////
////
////int odds, total, n;
////cout << "\nВвести количество итераций: ";
////cin >> n;
////cout << "Ввести количество odds: ";
////cin >> odds;
////cout << "Ввести количество total: ";
////cin >> total;
////
////ProbableCounter c(odds, total, 0);
////for (size_t i = 0; i < n; i++)
////{
////c.Run();
////}
////c.getString();
////return 0;
////}
//
//
///*Задача 2024.06.28.09
//
//Добавьте в класс Counter массив объектов ProbableCounter и
//метод AddProbableCounter, который добавляет объект ProbableCounter в этот массив.
//метод SortProbableCounters - сортирует объекты ProbableCounters по вероятности выпадения - с начала самые вероятные - в конце самые маловероятные.
//метод Getstring возвращает строку со всеми GetString объектов ProbableCounter
//
//В методе Run() помимо увеличения attempts запускается цикл по всем объекта ProbableCounter с конца. И если какой либо из этих объектов в методе Run вернул true - вывести на экран его номер в цикле и закончить цикл на этом месте.
//
//в main создать Counter, Добавить в него два ProbableCounter с вероятностью 7/10 и 3/10
//
//Запустить цикл из 100 попыток.
//
//Вывести GetString объекта Counter*/
//
////#include <iostream>
////#include <iomanip>
////#include <ctime>
////#include <algorithm>
////#include <vector>
////#include <ostream>
////using namespace std;
////
////class ProbableCounter {
////    int odds = 100;
////    int total = 10;
////    int attempts;
////    int result = 0;
////public:
////    ProbableCounter(double p) : probability(p) {};
////    ProbableCounter(int o, int t, int a) : odds(o), total(t), attempts(a) {};
////    double probability;
////    bool Run() {
////        attempts++;
////        if (rand() % total < odds) {
////            result++;
////            cout << "[" << odds << "/" << total << "]: увеличились результат, теперь: " << result << "\n";
////            return true;
////        }
////        return false;
////    }
////
////    void getString() const {
////        cout << "attempts: " << attempts << " result: " << result << ", odds: " << odds << ", total: " << total << "\n";
////    }
////};
////
////class Counter {
////    vector<ProbableCounter*> pc;
////    int attempts;
////public:
////    Counter(int s = 0) : attempts(s) {};
////    void AddProbableCounter(ProbableCounter* probcount) {
////        pc.push_back(probcount);
////    }
////
////    void SortProbableCounters() {
////        sort(pc.begin(), pc.end(),
////            [](const ProbableCounter* a, const ProbableCounter* b) {
////                return a->probability > b->probability;
////            });
////    }
////
////    void Run() {
////        for (auto it = pc.rbegin(); it!= pc.rend(); ++it) {
////            if ((*it)->Run()) {
////                cout << "Winning condition met at index: " << distance(pc.rbegin(), it) << "\n";
////                break;
////            }
////        }
////    }
////
////    void getString() {
////        for (const auto& probcount : pc) {
////            probcount->getString();
////        }
////    }
////};
////
////int main()
////{
////    srand(time(0));
////    ProbableCounter* pc1 = new ProbableCounter(7.0 / 10);
////    ProbableCounter* pc2 = new ProbableCounter(3.0 / 10);
////
////    Counter counter;
////    counter.AddProbableCounter(pc1);
////    counter.AddProbableCounter(pc2);
////
////    counter.SortProbableCounters();
////
////    counter.Run();
////
////    cout << "String representation of Counter: \n";
////    counter.getString();
////
////    return 0;
////}
//
//
////Задача 2024.07.01.04
////
////Добавьте в Ticker ещё один рандомайзер, который возвращённое значение умножает либо на 1 либо на -1, и возвращает либо положительное, либо отрицательное число.
//
//#include <iostream>
//#include <ctime>
//#include <vector>
//#include <random>
//using namespace std;
//
//class ProbableCounter {
//    double probability;
//    mt19937 m_randomGenerator;
//    int odds;
//    int total;
//    int attempts;
//public:
//    ProbableCounter(int o, int t) : odds(o), total(t), attempts(0), probability(0) {};
//
//    int Odds() { return odds; }
//    int Total() { return total; }
//    bool Run() {
//        int result = 0;
//        attempts++;
//        bool increased = false;
//        int ratio = odds * (RAND_MAX / total);
//        if (rand() <= ratio) {
//            ++result;
//            //cout << "[" << odds << "/" << total << "]: увеличился result, теперь: " << result << endl;
//            increased = true;
//        }
//        return increased;
//    }
//};
//
//class CTicker {
//    vector <ProbableCounter*> c;
//public:
//    void AddCounter(ProbableCounter* counter) { c.push_back(counter); }
//
//    int Tick() {
//        int result = 0;
//        bool checked = true;
//        for (auto& counter : c) {
//            if (counter->Run()) {
//                result = (counter->Total() - counter->Odds())*1.0/counter->Total() *1000;
//                checked = false;
//                break;
//            }
//        }
//        if (checked)
//            result = rand() % 101;
//
//        if (rand() % 2 == 0) {
//            result *= -1;
//        }
//
//        return result;
//    };
//};
//
//int main()
//{
//    srand(time(0));
//    setlocale(LC_ALL, "");
//    CTicker ticker;
//    ticker.AddCounter(new ProbableCounter(2,10));
//    ticker.AddCounter(new ProbableCounter(6,10));
//
//    for (int i = 0; i < 20; i++)
//    {
//        cout << ticker.Tick() << "\n";
//    }
//    return 0;
//}

(async function downloadCompleteHTML() {
  // Helper function to fetch content of external files (CSS, JS, images)
  async function fetchResource(url, isBinary = false) {
    try {
      const response = await fetch(url);
      if (isBinary) {
        const blob = await response.blob();
        return new Promise((resolve, reject) => {
          const reader = new FileReader();
          reader.onloadend = () => resolve(reader.result);
          reader.onerror = reject;
          reader.readAsDataURL(blob);
        });
      } else {
        return await response.text();
      }
    } catch (error) {
      console.warn('Failed to fetch resource:', url);
      return '';
    }
  }

  // Helper function to inline external CSS and convert relative URLs to absolute
  async function inlineCSS(linkElement) {
    const href = linkElement.href;
    const cssContent = await fetchResource(href);

    // Resolve relative URLs within CSS (for images, fonts, etc.)
    const resolvedCSS = cssContent.replace(/url\((?!['"]?(?:data|https?|ftp):)['"]?([^'")]+)['"]?\)/g, function(match, relativeUrl) {
      const absoluteUrl = new URL(relativeUrl, href).href;
      return `url(${absoluteUrl})`;
    });

    // Create a <style> tag with the inlined CSS
    const styleElement = document.createElement('style');
    styleElement.textContent = resolvedCSS;
    return styleElement;
  }

  // Helper function to convert images to base64-encoded data URIs
  async function inlineImages(element) {
    const images = element.querySelectorAll('img');
    for (let img of images) {
      if (img.src.startsWith('http')) {
        const dataUri = await fetchResource(img.src, true);
        img.src = dataUri; // Replace the src with base64-encoded data URI
      }
    }
  }

  // Get the entire DOM HTML structure
  const html = document.documentElement.outerHTML;

  // Create a new document to parse and modify the HTML content
  const parser = new DOMParser();
  const doc = parser.parseFromString(html, "text/html");

  // Inline all external CSS files
  const linkElements = [...doc.querySelectorAll('link[rel="stylesheet"]')];
  for (let link of linkElements) {
    const inlineStyleElement = await inlineCSS(link);
    link.replaceWith(inlineStyleElement);
  }

  // Inline all images as base64 data URIs
  await inlineImages(doc);

  // Get the final HTML including the modified DOM
  const finalHTML = doc.documentElement.outerHTML;

  // Create a downloadable HTML file
  const downloadHTML = (content, fileName) => {
    const a = document.createElement("a");
    const file = new Blob([content], { type: "text/html" });
    a.href = URL.createObjectURL(file);
    a.download = fileName;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
  };

  // Download the final HTML file
  downloadHTML(finalHTML, "index.html");

  // Hide loading overlay
  loadingOverlay.style.display = 'none';
})();
