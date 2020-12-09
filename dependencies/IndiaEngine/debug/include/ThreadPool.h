#pragma once
#include "Core.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <chrono>

namespace India {

    class India_EXPORT ThreadPool
    {
    public:
        ThreadPool(int threads);
        ~ThreadPool();
        /**
        Runs a job on a separate thread than the main.
        */
        void Run(std::function <void(void)> func);
    protected:
        /**
        All assigned threads run this function. The first thread that detects a job, gets to execute it.
        */
        void ThreadEntry(int i);
        std::mutex _lock;
        std::condition_variable _cond_var;
        bool _shutdown;
        std::queue <std::function <void(void)>> _jobs;
        std::vector <std::thread> _threads;
    };

}