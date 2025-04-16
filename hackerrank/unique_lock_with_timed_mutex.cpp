#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex tmtx;

void worker(int id) {
    std::unique_lock<std::timed_mutex> lock(tmtx, std::defer_lock);  // std::defer_lock tells unique_lock not to lock immediately

    if (lock.try_lock_for(std::chrono::milliseconds(500))) {
        std::cout << "Worker " << id << " acquired the lock.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } else {
        std::cout << "Worker " << id << " timed out trying to acquire the lock.\n";
    }
}

int main() {
    std::thread t1(worker, 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread t2(worker, 2);

    t1.join();
    t2.join();
    return 0;
}
