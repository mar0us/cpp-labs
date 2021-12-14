#include "log.h"
#include <stdio.h>

namespace logging
{
    #ifdef NDEBUG

    void info(const char* mess){}
    void error(const char* mess){}
    void warn(const char* mess){}
    void critical(const char* mess){}

    #else
    
    void info(const char* mess)
    {
        printf("[INFO] %s\n", mess);
    }
    void error(const char* mess)
    {
        printf("[ERROR] %s\n", mess);
    }
    void warn(const char* mess)
    {
        printf("[WARN] %s\n", mess);
    }
    void critical(const char* mess)
    {
        printf("[CRITICAL] %s\n", mess);
    }
    

    #endif

}