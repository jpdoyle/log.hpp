#include "log.hpp"

int main() {
    logger loggers[] = {
        {logger::DEBUG},  {logger::DEBUG,  true},
        {logger::INFO},   {logger::INFO,   true},
        {logger::WARNING},{logger::WARNING,true},
        {logger::ERROR},  {logger::ERROR,  true}
    };

    for(auto& log:loggers) {
        log.d("Doing a thing ",3," ",4.5)
           .i(2,": Thing is being done")
           .w("Thing was done scarily!")
           .e("Thing was done badly!");
    }

    return 0;
}
