#include <iostream>
#include <thread>
#include <mutex> // to prevent data races
#include <condition_variable>

std::mutex mu;

void print(const std::string &msg, const int &i) {
    std::lock_guard<std::mutex> locker{mu};
    std::cout << msg << i << "\n";
}

void myFunc() {
    for (int i{0}; i > -10; --i)
    {
        print("t1 thread: ", i);
    }
}

// std::unique_lock<std::mutex>

int main(int argc, char *argv[]) {
    std::thread t1(myFunc); // start running new thread
    // t1.detach();            // once thread is detached, it can't be joined again, it runs independently, becomes daemon process
    // if (t1.joinable())
    //     t1.join(); // main thread wait for other thread,
    // std::cout << "Main thread finished!";
    for (int i{0}; i < 10; ++i)
    {
        print("Main thread: ", i);
    }

    t1.join();
    return 0;
}

// int main()
// {
//     std::thread t1{myFunc};
//     std::cout << std::this_thread::get_id();
//     std::cout << "\n";
//     std::cout << "Number of threads that can run concurrently: " << std::thread::hardware_concurrency() << "\n";
//     // if main thread throws an error, t1 will not be able to join,.... so do operations in try-catch block and join the thread before throwing
//     // otherwise
//     try
//     {
//         for (int i{0}; i < 10; ++i)
//         {
//             std::cout << "Main thread: " << i << "\n";
//         }
//     }
//     catch (...)
//     { // catch any exception
//         t1.join();
//         throw;
//     }
//     t1.join();
//     return 0;
// }