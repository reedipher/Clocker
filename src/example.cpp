#include "Clocker.hpp"

void Function() {
    Clocker clock("in scope");
    sleep(1);
}

int main() {
    Function();

    // in line
    Clocker* clocky = new Clocker("Test example");
    clocky->print = true;

    sleep(1);
    for (uint8_t i = 0; i < 100; i++) {
        clocky->log("receive");
        usleep(1000);
    }

    clocky->writeData("testFile.csv");

    delete clocky;

    return 0;

}
