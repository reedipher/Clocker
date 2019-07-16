#include "Clocker.hpp"

#include <iostream>
#include <fstream>

// Constructor
Clocker::Clocker(std::string name)
{
    start = std::chrono::high_resolution_clock::now();

    clockName = name;
}

void Clocker::log(std::string eventInfo) 
{
    tmpEvent.absTime  = std::chrono::high_resolution_clock::now();
    tmpEvent.duration = tmpEvent.absTime - start;
    tmpEvent.dTime    = tmpEvent.duration.count();
    tmpEvent.info     = eventInfo;

    logData.push_back(tmpEvent);

    if (print) {
        std::cout << eventInfo << ": " << tmpEvent.dTime << '\n';
    }
}

void Clocker::writeData(std::string filename) {
    std::ofstream output;
    output.open(filename);
    output << "Clocker Name: " << clockName << '\n';
    output << "Event, Time\n";
    for(uint32_t i = 0; i < logData.size(); i++) {
        output << logData[i].info << ", " << logData[i].dTime << '\n';
    }
    output.close();
}

// Destructor
Clocker::~Clocker()
{
    end = std::chrono::high_resolution_clock::now();
    duration = end-start;

    float ms = duration.count()*1000.0;
    std::cout << clockName << " took: " << duration.count() << "s,\t" << ms << "ms\n";
}
