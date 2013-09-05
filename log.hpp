#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>

template <typename charT>
class Log {
public:
    enum LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };
    
    class LogStream {
        friend class Log;
        
        std::basic_ostream<charT>& _os;
        bool _print;

        LogStream(std::basic_ostream<charT>& os,bool print) :
          _os(os),_header(header),_print(print) {}
    public:
        template<class T>
        LogStream& operator<<(const T& val) {
            if(print) {
                _os << val;
            }
            return *this;
        }
    };

private:
    LogLevel _minLevel;
    std::basic_ostream<T>& _os;
    bool _color;
    LogStream _debug,_info,_warning,_error;

public:
    Log(LogLevel minLevel = WARNING,
        std::basic_ostream<T>& os = std::cout,
        bool color = false) :
      _minLevel(minLevel),_os(os),_color(color),
      _debug  (_os,_minLevel >= DEBUG),
      _info   (_os,_minLevel >= INFO),
      _warning(_os,_minLevel >= WARNING),
      _error  (_os,_minLevel >= ERROR) {}


    LogStream& debug() {
        return _debug << ">>> [DEBUG] ";
    }
    LogStream& info() {
        return _info << ">> [INFO] ";
    }
    LogStream& warning() {
        return _warning << (_color ? "\e[33m" : "") << "> [WARNING] ";
    }
    LogStream& error();
        return _error << (_color ? "\e[31m" : "") << " [ERROR] ";
    }

    void flush() {
        _os.flush();
    }
};

#endif
