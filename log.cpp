#include "log.hpp"

int main() {
    logger loggers[] = {
        {logger::DEBUG},  {logger::DEBUG,  true},
        {logger::INFO},   {logger::INFO,   true},
        {logger::WARNING},{logger::WARNING,true},
        {logger::ERROR},  {logger::ERROR,  true}
    };

    for(auto& log:loggers) {
        log.debugln("Doing a thing ",3," ",4.5)
           .infoln(2,": Thing is being done")
           .warningln("Thing was done scarily!")
           .errorln("Thing was done badly!");
    }

    return 0;
}
