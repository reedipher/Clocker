#include <iostream>
#include <unistd.h>
#include <chrono>
#include <vector>
#include <fstream>

struct logEvent {
    std::string info;
    std::chrono::high_resolution_clock::time_point absTime;
    std::chrono::duration<double> duration;
    double dTime;
};

class Clocker {
    public:
        std::chrono::high_resolution_clock::time_point start, end;
        std::chrono::duration<double> duration;

        std::vector<struct logEvent> logData;

        // Constructor
        Clocker(std::string name = "Process");

        void log(std::string eventInfo = "Event");
        void writeData(std::string filename = "/tmp/clockData.csv");

        // Destructor
        ~Clocker();

        bool print = false;
    private:
        std::string clockName;
        logEvent    tmpEvent;
};

