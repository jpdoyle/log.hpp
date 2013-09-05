log.hpp
=======

Dead simple logger using C++11.

Usage
=====

If your compiler supports C++11 (you may need to add the -std=c++0x or 
-std=c++11 flag), just include the header and use it (see log.cpp for another
example).

    #include "log.hpp"
    int main() {
        // You can choose minimum log level for output, whether to color output,
        // and what output stream to use.
        logger log{logger::DEBUG,true,std::cout};
        // Or you can just go with the defaults.
        logger log2;

        log(logger::INFO,"You can specify the log level as a parameter,\n");
        log.warning("Or use a specialized function.\n");
        log.errorln("logger::<level>ln() automatically adds that pesky \\n.");

        log.infoln ("All ",8," functions can output anything that has an")
           .infoln ("operator<< overload, and you can chain functions,")
           .debugln("even of different levels.");
        return 0;
    }

