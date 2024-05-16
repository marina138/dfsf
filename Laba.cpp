#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <sys/stat.h>
#include <pthread.h>
#include <filesystem>
#include <future>
#include <math.h>
#include <conio.h>
#include <signal.h>
#include <iomanip>
using namespace std;

////Task6
//void sleepSort(const string& word) {
//    this_thread::sleep_for(chrono::milliseconds(word.length() * 100)); // Adjust multiplier for sleep time
//    std::cout << word << endl;
//}
//
//void main() {
//    vector<string> words;
//    cout << "Enter the number of valid lines: ";
//    int a;
//    cin >> a;
//    // Читаем пользовательский ввод
//    for (int i = 0; i < a; i++) {
//        string word;
//        cin >> word;
//        words.push_back(word);
//    }
//
//    // Создаём vector кладём потоки для сортировки
//    vector<thread> threads;
//    for (const string& word : words) {
//        threads.emplace_back(sleepSort, word);
//    }
//
//    // Ждём, пока все потоки закончат выполняться
//    for (thread& th : threads) {
//        th.join();
//    }
//}
// 

////Task8
//
//long double calculate_pi(int start, int end)
//{
//    long double sum = 0;
//    for (int i = start; i <= end; i++) {
//        sum += ((pow(-1, i)) / (2 * i + 1));
//    }
//    return sum;
//}
//
//void Calculation()
//{
//    cout << "Enter the number of threads : ";
//    int kol;//число потоков
//    cin >> kol;
//    int iteration = 1000000000 / kol;
//    long double pi = 0;
//    // Create a vector to store futures
//    std::vector<std::future<long double>> futures(kol); //асинхронное выполнение в будущем
//    // Launch threads and store their futures
//    for (int i = 0; i < kol; i++) {
//        int start = i * iteration;
//        int end = (i == kol - 1) ? 1000000000 - 1 : start + iteration - 1;
//        futures[i] = std::async(std::launch::async, calculate_pi, start, end);//он используется c future
//    }
//    // Wait for all threads to finish and accumulate results
//    for (auto& future : futures) {
//        long double result = future.get();
//        pi = pi + result;
//    }
//    pi = pi * 4;
//    std::cout << setprecision(10) << pi << endl;
//}
//
//void main() 
//{
//    Calculation();
//}
// 

////Task9
//long double calculate_pi(const int THREAD_NUMBER, const int NUM_THREADS, bool* isFinishedExecuting) {
//    long double sum = 0;
//    long long n = THREAD_NUMBER;
//    for (long long i = 0; true; n += NUM_THREADS, i++) {
//        sum += ((pow(-1, n)) / (2 * n + 1));
//
//        if (i % 1000000000 == 0 && *isFinishedExecuting == true) {
//            break;
//        }
//    }
//
//    return sum;
//}
//
//bool* isFinishedExecuting = new bool(false);
//
//void cancel_program(int num) {
//    cout << "Cancullation started!!!!!!!!!!" << endl;
//    *isFinishedExecuting = true;
//}
//
//void main() {
//    signal(SIGINT, cancel_program);//сигнал прерывания
//    const int NUM_THREADS = 5;
//    long double pi = 0;
//    // Create a vector to store futures
//    std::vector<std::future<long double>> futures(NUM_THREADS);
//
//    // Launch threads and store their futures
//    for (int i = 0; i < NUM_THREADS; i++) {
//        futures[i] = std::async(std::launch::async, calculate_pi, i, NUM_THREADS, isFinishedExecuting);
//    }
//
//    // Wait for all threads to finish and accumulate results
//    for (auto& future : futures) {
//        long double result = future.get();
//        pi = pi + result;
//    }
//
//    pi = pi * 4;
//
//    std::cout << setprecision(10) << pi << endl;
//    delete isFinishedExecuting;
//}
// 

////Task10
////
//void main() {
//    const int number_of_philosophers = 5;
//
//    struct Forks//вилки
//    {
//    public:
//        Forks() { ; }
//        std::mutex mu;
//    };
//
//    auto eat = [](Forks& left_fork, Forks& right_fork, int philosopher_number) {
//        std::unique_lock<std::mutex> llock(left_fork.mu);//левая вилка 
//        std::unique_lock<std::mutex> rlock(right_fork.mu);//правая вилка
//
//        cout << "Filosof " << philosopher_number << " eat..." << endl;
//
//        std::chrono::milliseconds timeout(1500);
//        std::this_thread::sleep_for(timeout);
//
//        cout << "Filosof " << philosopher_number << " finished eating and thinking..." << endl;
//        };
//
//    // Создаём вилки и философов
//    Forks forks[number_of_philosophers];
//    std::thread philosopher[number_of_philosophers];
//
//    // Философы начитают думать
//    for (int i = 0; i < number_of_philosophers; ++i) {
//        auto philosopher_number = i + 1;
//        cout << "Filosof " << philosopher_number << " thinks.." << endl;
//        auto previous_fork_index = (number_of_philosophers + (i - 1)) % number_of_philosophers;
//        philosopher[i] = std::thread(eat, std::ref(forks[i]), std::ref(forks[previous_fork_index]), philosopher_number);
//    }
//
//    for (auto& ph : philosopher) {
//        ph.join();
//    }
//}
// 

//// -------------TASK 11------------------------
//mutex mu;
//
//void print() {
//    lock_guard<mutex> guard(mu);//При построении объект mutex блокируется вызывающим потоком, а при разрушении — разблокируется.
//    cout << std::this_thread::get_id() << ": Print text..." << endl;
//}
//void threadPrint() {
//    for (int i = 0; i < 10; ++i) {
//        print();
//        chrono::milliseconds timeout(50);
//        this_thread::sleep_for(timeout);
//    }
//}
//int main() {
//    setlocale(LC_ALL, "Ru");
//
//    thread childThread(threadPrint);
//
//    threadPrint();
//
//    childThread.join();
//    return 0;
//}
//

//// -------------TASK 12------------------------
//
//    Прооблемы с 2-мя мьютексами заключаются в том, что 2 мьютекса могут быть получены в разном порядке
//    таким образом может возникнуть DEADLOCK. Также 2 мьютекса не гарантируют, в каком порядке потоки получат
//    доступ к секции кода.
//

//// -------------TASK 13------------------------
//mutex mu;
//condition_variable cv; //условная переменная, которая используется для уведомления ожидающих потоков о изменении состояния
//bool isChildTurn = false;//указывает, чей сейчас ход: дочернего или родительского потока.
//
//void print(const string& text, bool isChild) {
//    unique_lock<mutex> lock(mu);
//    cv.wait(lock, [isChild] { return isChild == isChildTurn; }); // условие проверяет, принадлежит ли текущий поток дочернему или родительскому, и сравнивает с флагом isChildTurn
//    cout << text << endl;
//    isChildTurn = !isChildTurn; //переключатель
//    cv.notify_one();
//}
//
//void threadPrint() {
//    for (int i = 0; i < 10; ++i) {
//        print("Дочерний поток: потомок", true);
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//
//    thread childThread(threadPrint);
//
//    for (int i = 0; i < 10; ++i) {
//        print("Родительский поток: родитель", false);
//    }
//
//    childThread.join();
//    return 0;
//}
// 

//// -------------TASK 14------------------------
//mutex mu;
//atomic<int> parentSemaphore(1);//Объявление двух атомарных переменных типа int, которые используются в качестве семафоров для синхронизации между потоками. 
//atomic<int> childSemaphore(0);
//
//void print(const string& text, atomic<int>& semaphore1, atomic<int>& semaphore2) {
//    while (true) {
//        unique_lock<mutex> lock(mu);// Захват мьютекса перед доступом к общим данным.
//        if (semaphore1) { //Проверка значения атомарной переменной semaphore1. Если значение равно 1 (истина), то это означает, что текущий поток имеет право печати.
//            cout << text << endl;
//            semaphore1 = 0;
//            semaphore2 = 1;
//            break;
//        }
//    }
//}
//
//void threadPrint() {
//    for (int i = 0; i < 10; ++i) {
//        print("Дочерний поток: пример...", childSemaphore, parentSemaphore);
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//
//    thread childThread(threadPrint);
//
//    for (int i = 0; i < 10; ++i) {
//        print("Родительский поток: пример...", parentSemaphore, childSemaphore);
//    }
//
//    childThread.join();
//    return 0;
//}
//

//// -------------TASK 15------------------------
//
//    Хоть проблема с дедлоком в случае с семаформами остаётся возможной,
//    однако с помощью семафоров можно управлять порядком выполнения программы,
//    в отличии от ситуации с мьютеками, можно контролировать порядок.


//// -------------TASK 17------------------------
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
using namespace std;

struct Node {
    string data;
    Node* next; //указатель на след эл
    Node(const string& data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    mutex mtx;

public:
    LinkedList() : head(nullptr) {}

    void insert(const string& data) {
        lock_guard<mutex> lock(mtx);
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        lock_guard<mutex> lock(mtx);
        Node* current = head;
        while (current != nullptr) {//пока текущ эл не равен пустоте
            cout << current->data << endl;
            current = current->next;
        }
    }

    void bubbleSort() {//44 20 33->20 30 44
        lock_guard<mutex> lock(mtx);
        if (!head) return;///конец сорт
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
};

void sortingThread(LinkedList& list) {
    while (true) {
        this_thread::sleep_for(chrono::seconds(5));
        list.bubbleSort();
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    LinkedList list;
    thread sorting(sortingThread, ref(list));
    while (true) {
        string input;
        getline(cin, input);
        if (input.empty()) {
            cout << "Текущее состояние списка:" << endl;
            list.print();
        }
        else {
            if (input.length() > 80) {
                for (size_t i = 0; i < input.length(); i += 80) {
                    string substr = input.substr(i, 80);
                    list.insert(substr);
                }
            }
            else {
                list.insert(input);
            }
        }
    }
    sorting.join();
    return 0;
}
//

//// -------------TASK 18------------------------
//
//struct Node {
//    string data;
//    Node* next;
//    mutex mtx;
//
//    Node(const string& data) : data(data), next(nullptr) {}
//};
//
//class LinkedList {
//private:
//    Node* head;
//    mutex headMtx;
//
//public:
//    LinkedList() : head(nullptr) {}
//
//    void insert(const string& data) {
//        Node* newNode = new Node(data);
//        lock_guard<mutex> lock(headMtx);
//        newNode->next = head;
//        head = newNode;
//    }
//
//    void print() {
//        lock_guard<mutex> lock(headMtx);
//        Node* current = head;
//        while (current != nullptr) {
//            lock_guard<mutex> nodeLock(current->mtx);
//            cout << current->data << endl;
//            current = current->next;
//        }
//    }
//
//    void bubbleSort() {
//        if (!head) return;
//        bool swapped;
//        Node* ptr1;
//        Node* lptr = nullptr;
//        do {
//            swapped = false;
//            lock_guard<mutex> lock(headMtx);
//            ptr1 = head;
//            Node* prev = nullptr;
//            while (ptr1->next != lptr) {
//                lock_guard<mutex> lock1(ptr1->mtx);
//                lock_guard<mutex> lock2(ptr1->next->mtx);
//                if (ptr1->data > ptr1->next->data) {
//                    swap(ptr1->data, ptr1->next->data);
//                    swapped = true;
//                }
//                prev = ptr1;
//                ptr1 = ptr1->next;
//            }
//            lptr = ptr1;
//        } while (swapped);
//    }
//};
//
//void sortingThread(LinkedList& list, int interval) {
//    while (true) {
//        this_thread::sleep_for(chrono::seconds(interval));
//        list.bubbleSort();
//    }
//}
//
//int main() {
//    LinkedList list;
//    vector<thread> sortingThreads;
//    int numThreads = 2;
//    int intervalSeconds = 5;
//
//    for (int i = 0; i < numThreads; ++i) {
//        sortingThreads.emplace_back(sortingThread, ref(list), intervalSeconds);
//    }
//
//    while (true) {
//        string input;
//        getline(cin, input);
//        if (input.empty()) {
//            cout << "Текущее состояние списка:" << endl;
//            list.print();
//        } else {
//            if (input.length() > 80) {
//                for (size_t i = 0; i < input.length(); i += 80) {
//                    string substr = input.substr(i, 80);
//                    list.insert(substr);
//                }
//            } else {
//                list.insert(input);
//            }
//        }
//    }
//
//    for (auto& thread : sortingThreads) {
//        thread.join();
//    }
//    return 0;
//}
//

//// -------------TASK 19------------------------
//
//#include <windows.h>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//
//bool isSorted = true;
//bool xxx = false;
//struct Node {
//    string data;
//    Node* next;
//    mutex mtx;
//
//    Node(const string& data) : data(data), next(nullptr) {}
//};
//
//class LinkedList {
//private:
//    Node* head;
//    mutex headMtx;
//
//public:
//    LinkedList() : head(nullptr) {}
//
//    void insert(const string& data) {
//        Node* newNode = new Node(data);
//        lock_guard<mutex> lock(headMtx);
//        newNode->next = head;
//        head = newNode;
//        isSorted = false;
//    }
//
//    void print() {
//        lock_guard<mutex> lock(headMtx);
//        Node* current = head;
//        while (current != nullptr) {
//            lock_guard<mutex> nodeLock(current->mtx);
//            cout << current->data << endl;
//            current = current->next;
//        }
//    }
//
//    void bubbleSortStep() {
//        if (!head) return;
//        bool swapped;
//        Node* ptr1;
//        Node* lptr = nullptr;
//        do {
//            cout << "Текущее состояние списка:" << endl;
//            this->print();
//            cout << endl;
//            swapped = false;
//            lock_guard<mutex> lock(headMtx);
//            ptr1 = head;
//            Node* prev = nullptr;
//            while (ptr1->next != lptr) {
//                lock_guard<mutex> lock1(ptr1->mtx);
//                lock_guard<mutex> lock2(ptr1->next->mtx);
//                if (ptr1->data > ptr1->next->data) {
//                    swap(ptr1->data, ptr1->next->data);
//                    swapped = true;
//                }
//                prev = ptr1;
//                ptr1 = ptr1->next;
//            }
//            lptr = ptr1;
//            this_thread::sleep_for(chrono::seconds(1));
//        } while (swapped);
//        isSorted = true;
//        xxx = false;
//    }
//
//    void bubbleSortStepWithDelay() {
//        bubbleSortStep();
//        this_thread::sleep_for(chrono::seconds(1)); // Пауза между шагами сортировки
//    }
//};
//
//void sortingThread(LinkedList& list) {
//    while (true) {
//        if (!isSorted && xxx) {
//            list.bubbleSortStepWithDelay();
//        }
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    LinkedList list;
//    thread sorting(sortingThread, ref(list));
//
//    while (true) {
//        string input;
//        getline(cin, input);
//        if (input.empty()) {
//            if (isSorted) {
//                cout << "Текущее состояние списка:" << endl;
//                list.print();
//            }
//            else {
//
//                xxx = true;
//            }
//
//        }
//        else {
//            if (input.length() > 80) {
//                for (size_t i = 0; i < input.length(); i += 80) {
//                    string substr = input.substr(i, 80);
//                    list.insert(substr);
//                }
//            }
//            else {
//                list.insert(input);
//            }
//        }
//    }
//
//    sorting.join();
//    return 0;
//}
//

//// -------------TASK 20------------------------
//
//#include <string>
//#include <thread>
//#include <shared_mutex>
//#include <chrono>
//#include <algorithm>
//struct Node {
//    string data;
//    Node* next;
//    mutable shared_mutex mtx; //  shared_mutex вместо mutex 
//
//    Node(const string& data) : data(data), next(nullptr) {}
//};
//
//class LinkedList {
//private:
//    Node* head;
//    mutable shared_mutex headMtx; //  shared_mutex вместо mutex 
//
//public:
//    LinkedList() : head(nullptr) {}
//
//    void insert(const string& data) {
//        Node* newNode = new Node(data);
//        unique_lock<shared_mutex> lock(headMtx, defer_lock);
//        lock.lock();
//        newNode->next = head;
//        head = newNode;
//    }
//
//    void print() {
//        shared_lock<shared_mutex> lock(headMtx);
//        Node* current = head;
//        while (current != nullptr) {
//            shared_lock<shared_mutex> nodeLock(current->mtx);
//            cout << current->data << endl;
//            current = current->next;
//        }
//    }
//
//    void bubbleSort() {
//        if (!head) return;
//        bool swapped;
//        Node* ptr1;
//        Node* lptr = nullptr;
//        do {
//            swapped = false;
//            shared_lock<shared_mutex> lock(headMtx);
//            ptr1 = head;
//            Node* prev = nullptr;
//            while (ptr1->next != lptr) {
//                unique_lock<shared_mutex> lock1(ptr1->mtx, defer_lock);
//                unique_lock<shared_mutex> lock2(ptr1->next->mtx, defer_lock);
//                std::lock(lock1, lock2);
//
//                if (ptr1->data > ptr1->next->data) {
//                    swap(ptr1->data, ptr1->next->data);
//                    swapped = true;
//                }
//                prev = ptr1;
//                ptr1 = ptr1->next;
//            }
//            lptr = ptr1;
//        } while (swapped);
//    }
//};
//
//void sortingThread(LinkedList& list, int interval) {
//    while (true) {
//        this_thread::sleep_for(chrono::seconds(interval));
//        list.bubbleSort();
//    }
//}
//
//int main() {
//
//    LinkedList list;
//    vector<thread> sortingThreads;
//    int numThreads = 2;
//    int intervalSeconds = 5;
//
//    for (int i = 0; i < numThreads; ++i) {
//        sortingThreads.emplace_back(sortingThread, ref(list), intervalSeconds);
//    }
//
//    while (true) {
//        string input;
//        getline(cin, input);
//        if (input.empty()) {
//            cout << "Текущее состояние списка:" << endl;
//            list.print();
//        }
//        else {
//            if (input.length() > 80) {
//                for (size_t i = 0; i < input.length(); i += 80) {
//                    string substr = input.substr(i, 80);
//                    list.insert(substr);
//                }
//            }
//            else {
//                list.insert(input);
//            }
//        }
//    }
//
//    for (auto& thread : sortingThreads) {
//        thread.join();
//    }
//    return 0;
//}
//

//// -------------TASK 21------------------------
//#include <string>
//#include <thread>
//#include <shared_mutex>
//#include <chrono>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//bool isSorted = true;
//bool xxx = false;
//struct Node {
//    string data;
//    Node* next;
//    mutable shared_mutex mtx; // Заменим mutex на shared_mutex
//
//    Node(const string& data) : data(data), next(nullptr) {}
//};
//
//class LinkedList {
//private:
//    Node* head;
//    mutable shared_mutex headMtx; // Заменим mutex на shared_mutex
//
//public:
//    LinkedList() : head(nullptr) {}
//
//    void insert(const string& data) {
//        Node* newNode = new Node(data);
//        unique_lock<shared_mutex> lock(headMtx);
//        newNode->next = head;
//        head = newNode;
//        isSorted = false;
//    }
//
//    void print() {
//        shared_lock<shared_mutex> lock(headMtx);
//        Node* current = head;
//        while (current != nullptr) {
//            shared_lock<shared_mutex> nodeLock(current->mtx);
//            cout << current->data << endl;
//            current = current->next;
//        }
//    }
//
//    void bubbleSortStep() {
//        if (!head) return;
//        bool swapped;
//        Node* ptr1;
//        Node* lptr = nullptr;
//        do {
//            cout << "Текущее состояние списка:" << endl;
//            this->print();
//            cout << endl;
//            swapped = false;
//            unique_lock<shared_mutex> lock(headMtx);
//            ptr1 = head;
//            Node* prev = nullptr;
//            while (ptr1->next != lptr) {
//                unique_lock<shared_mutex> lock1(ptr1->mtx);
//                unique_lock<shared_mutex> lock2(ptr1->next->mtx);
//                if (ptr1->data > ptr1->next->data) {
//                    swap(ptr1->data, ptr1->next->data);
//                    swapped = true;
//                }
//                prev = ptr1;
//                ptr1 = ptr1->next;
//            }
//            lptr = ptr1;
//            this_thread::sleep_for(chrono::seconds(1));
//        } while (swapped);
//        isSorted = true;
//        xxx = false;
//    }
//
//    void bubbleSortStepWithDelay() {
//        bubbleSortStep();
//        this_thread::sleep_for(chrono::seconds(1)); // Пауза между шагами сортировки
//    }
//};
//
//void sortingThread(LinkedList& list) {
//    while (true) {
//        if (!isSorted && xxx) {
//            list.bubbleSortStepWithDelay();
//        }
//    }
//}
//
//int main() {
//
//    LinkedList list;
//    thread sorting(sortingThread, ref(list));
//
//    while (true) {
//        string input;
//        getline(cin, input);
//        if (input.empty()) {
//            if (isSorted) {
//                cout << "Текущее состояние списка:" << endl;
//                list.print();
//            }
//            else {
//
//                xxx = true;
//            }
//
//        }
//        else {
//            if (input.length() > 80) {
//                for (size_t i = 0; i < input.length(); i += 80) {
//                    string substr = input.substr(i, 80);
//                    list.insert(substr);
//                }
//            }
//            else {
//                list.insert(input);
//            }
//        }
//    }
//
//    sorting.join();
//    return 0;
//}


//// -------------TASK 22------------------------
//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <limits>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <fstream>
//#include <sys/stat.h>
//#include <pthread.h>
//#include <chrono>
////#include <future>
////#include <math.h>
////#include <conio.h>
//#include <signal.h>
//#include <condition_variable>
//using namespace std;
//
//mutex printM;
//void print(string str) {
//    printM.lock();
//
//    cout << str << endl;
//
//    printM.unlock();
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    string text;
//    const int number_of_philosophers = 5;
//
//    struct Forks {
//    public:
//        Forks() : is_left_available(true), is_right_available(true) {}
//        std::mutex mu;
//        std::condition_variable left_cond, right_cond;
//        bool is_left_available;
//        bool is_right_available;
//    };
//
//    auto eat = [](Forks& left_fork, Forks& right_fork, int philosopher_number) {
//        std::unique_lock<std::mutex> lock(left_fork.mu);
//
//        left_fork.left_cond.wait(lock, [&] { return left_fork.is_left_available; });
//
//        int right_fork_index = (number_of_philosophers + (philosopher_number - 1)) % number_of_philosophers;
//        {
//            std::unique_lock<std::mutex> right_lock(right_fork.mu);
//            right_fork.left_cond.wait(lock, [&] { return right_fork.is_right_available; });
//
//            print("Философ " + std::to_string(philosopher_number) + " ест...");
//
//            std::chrono::milliseconds timeout(1500);
//            std::this_thread::sleep_for(timeout);
//            print("Философ " + std::to_string(philosopher_number) + " закончил есть и думает...");
//
//            left_fork.is_left_available = true;
//            left_fork.left_cond.notify_one();
//
//            right_fork.is_right_available = true;
//            right_fork.right_cond.notify_one();
//        }
//        };
//
//
//    Forks forks[number_of_philosophers];
//    std::thread philosopher[number_of_philosophers];
//
//    for (int i = 0; i < number_of_philosophers; ++i) {
//        auto philosopher_number = i + 1;
//        print("Философ " + std::to_string(philosopher_number) + " думает...");
//
//        int previous_fork_index = (number_of_philosophers + (i - 1)) % number_of_philosophers;
//        philosopher[i] = std::thread(eat, std::ref(forks[i]), std::ref(forks[previous_fork_index]), philosopher_number);
//    }
//
//    for (auto& ph : philosopher) {
//        ph.join();
//    }
//
//    return 0;
//}


//// -------------TASK 23------------------------
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <thread>
//#include <chrono>
//#include <mutex>
//using namespace std;
//
//mutex listMutex;
//
//struct Node {
//    string data;
//    Node* next;
//    Node(const string& str) : data(str), next(nullptr) {}
//};
//
//Node* head = nullptr;
//
//void AddToList(const string& str) {
//    Node* newNode = new Node(str);
//    lock_guard<mutex> lock(listMutex);
//    if (!head) {
//        head = newNode;
//        return;
//    }
//    Node* current = head;
//    while (current->next) {
//        current = current->next;
//    }
//    current->next = newNode;
//}
//
//void sleepSort(const string& str) {
//    int sleepTime = str.length() * 100 + 1000;
//    this_thread::sleep_for(chrono::milliseconds(sleepTime));
//    AddToList(str);
//}
//
//void PrintList() {
//    Node* current = head;
//    while (current) {
//        cout << current->data << endl;
//        current = current->next;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//
//    ifstream inputFile("input.txt");
//    if (!inputFile) {
//        cerr << "Ошибка открытия файла" << endl;
//        return 1;
//    }
//
//    vector<string> strings;
//
//    string input;
//    while (getline(inputFile, input)) {
//        strings.push_back(input);
//    }
//
//    inputFile.close();
//
//    vector<thread> threads;
//    for (const auto& str : strings) {
//        threads.push_back(thread(sleepSort, str));
//    }
//
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    PrintList();
//
//    Node* current = head;
//    while (current) {
//        Node* temp = current;
//        current = current->next;
//        delete temp;
//    }
//
//    return 0;
//}


//// -------------TASK 24------------------------
//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <chrono>
//
//using namespace std;
//
//mutex mtxA;
//mutex mtxB;
//mutex mtxC;
//mutex mtxBolt;
//condition_variable cv;
//
//int A_count = 0;
//int B_count = 0;
//int C_count = 0;
//
//const int MAX_PRODUCTS = 5;
//
//struct Bolt {
//    bool isAReady;
//    bool isBReady;
//    bool isCReady;
//    bool isProduced;
//};
//
//vector<Bolt> initBoltsVector() {
//    vector<Bolt> bolts(MAX_PRODUCTS);
//    return bolts;
//}
//
//void makeA(vector<Bolt>& bolts) {
//    for (int i = 0; i < MAX_PRODUCTS; ++i) {
//        this_thread::sleep_for(chrono::seconds(1));
//        {
//            lock_guard<mutex> lck(mtxA);
//            A_count++;
//            bolts[i].isAReady = true;
//            cout << "Деталь A изготовлена. Всего произведено: " << A_count << endl;
//        }
//        cv.notify_all();
//    }
//}
//
//void makeB(vector<Bolt>& bolts) {
//    for (int i = 0; i < MAX_PRODUCTS; ++i) {
//        this_thread::sleep_for(chrono::seconds(2));
//        {
//            lock_guard<mutex> lck(mtxB);
//            B_count++;
//            bolts[i].isBReady = true;
//            cout << "Деталь B изготовлена. Всего произведено: " << B_count << endl;
//        }
//        cv.notify_all();
//    }
//}
//
//void makeC(vector<Bolt>& bolts) {
//    for (int i = 0; i < MAX_PRODUCTS; ++i) {
//        this_thread::sleep_for(chrono::seconds(3));
//        {
//            lock_guard<mutex> lck(mtxC);
//            C_count++;
//            bolts[i].isCReady = true;
//            cout << "Деталь C изготовлена. Всего произведено: " << C_count << endl;
//        }
//        cv.notify_all();
//    }
//}
//
//void makeBolt(vector<Bolt>& bolts) {
//    for (int i = 0; i < MAX_PRODUCTS; ++i) {
//        unique_lock<mutex> lck(mtxBolt);
//        cv.wait(lck, [&bolts, i] {
//            return (bolts[i].isAReady && bolts[i].isBReady && bolts[i].isCReady) && !bolts[i].isProduced;
//            });
//        bolts[i].isProduced = true;
//        cout << "Винтик готов!" << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//
//    vector<Bolt> boltsVector = initBoltsVector();
//
//    thread threadA(makeA, ref(boltsVector));
//    thread threadB(makeB, ref(boltsVector));
//    thread threadC(makeC, ref(boltsVector));
//    thread boltThread(makeBolt, ref(boltsVector));
//
//    threadA.join();
//    threadB.join();
//    threadC.join();
//    boltThread.join();
//
//    return 0;
//}

//// -------------TASK 25------------------------
//#include <iostream>
//#include <queue>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <chrono>
//using namespace std;
//
//
//mutex mPrint;
//void print(string str) {
//    mPrint.lock();
//
//    cout << str << endl;
//
//    mPrint.unlock();
//}
//
//class MessageQueue {
//private:
//    queue<string> queue_;
//    mutex mutex_;
//    condition_variable notEmpty_;
//    condition_variable notFull_;
//    const size_t maxSize_ = 10;
//
//public:
//    void put(const string& msg) {
//        unique_lock<mutex> lock(mutex_);
//        notFull_.wait(lock, [this] { return queue_.size() < maxSize_; });
//        queue_.push(msg.substr(0, 80)); // обрезаем до 80 символов
//        lock.unlock();
//        notEmpty_.notify_one();
//    }
//
//    string get() {
//        unique_lock<mutex> lock(mutex_);
//        notEmpty_.wait(lock, [this] { return !queue_.empty(); });
//        string msg = queue_.front();
//        queue_.pop();
//        lock.unlock();
//        notFull_.notify_one();
//        return msg;
//    }
//
//    void drop() {
//        lock_guard<mutex> lock(mutex_);
//        notEmpty_.notify_all();
//        notFull_.notify_all();
//    }
//};
//
//void producer(MessageQueue& queue, int id) {
//    for (int i = 0; i < 10; ++i) {
//        string msg = "Сообщение от производителя " + to_string(id) + ", номер " + to_string(i);
//        queue.put(msg);
//        this_thread::sleep_for(chrono::milliseconds(100)); // simulate some work
//    }
//}
//
//void consumer(MessageQueue& queue, int id) {
//    for (int i = 0; i < 10; ++i) {
//        string msg = queue.get();
//        print("Потребитель " + std::to_string(id) + " получил: " + msg);
//        // cout << "Потребитель " << id << " получил: " << msg << endl;
//        this_thread::sleep_for(chrono::milliseconds(500)); // simulate some work
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//
//    MessageQueue queue;
//
//    thread producer1(producer, ref(queue), 1);
//    thread producer2(producer, ref(queue), 2);
//    thread consumer1(consumer, ref(queue), 1);
//    thread consumer2(consumer, ref(queue), 2);
//
//    producer1.join();
//    producer2.join();
//    consumer1.join();
//    consumer2.join();
//
//    return 0;
//}


//// -------------TASK 26------------------------
//#include <iostream>
//#include <queue>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <chrono>
//using namespace std;
//
//mutex mPrint;
//void print(string str) {
//    mPrint.lock();
//
//    cout << str << endl;
//
//    mPrint.unlock();
//}
//
//class MessageQueue {
//private:
//    queue<string> queue_;
//    mutex mutex_;
//    condition_variable messageAvailable_;
//    const size_t maxSize_ = 10;
//
//public:
//    void put(const string& msg) {
//        unique_lock<mutex> lock(mutex_);
//        messageAvailable_.wait(lock, [this] { return queue_.size() < maxSize_; });
//        queue_.push(msg.substr(0, 80)); // обрезаем до 80 символов
//        lock.unlock();
//        messageAvailable_.notify_one();
//    }
//
//    string get() {
//        unique_lock<mutex> lock(mutex_);
//        messageAvailable_.wait(lock, [this] { return !queue_.empty(); });
//        string msg = queue_.front();
//        queue_.pop();
//        lock.unlock();
//        return msg;
//    }
//
//    void drop() {
//        lock_guard<mutex> lock(mutex_);
//        messageAvailable_.notify_all();
//    }
//};
//
//void producer(MessageQueue& queue, int id) {
//    for (int i = 0; i < 5; ++i) {
//        string msg = "Сообщение от производителя " + to_string(id) + ", номер " + to_string(i);
//        queue.put(msg);
//        this_thread::sleep_for(chrono::milliseconds(100)); // simulate some work
//    }
//}
//
//void consumer(MessageQueue& queue, int id) {
//    for (int i = 0; i < 5; ++i) {
//        string msg = queue.get();
//        print("Потребитель " + std::to_string(id) + " получил: " + msg);
//        this_thread::sleep_for(chrono::milliseconds(500)); // simulate some work
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//
//    MessageQueue queue;
//
//    thread producer1(producer, ref(queue), 1);
//    thread producer2(producer, ref(queue), 2);
//    thread consumer1(consumer, ref(queue), 1);
//    thread consumer2(consumer, ref(queue), 2);
//
//    producer1.join();
//    producer2.join();
//    consumer1.join();
//    consumer2.join();
//
//    return 0;
//}