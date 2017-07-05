#include "logger.h"

/** 获取当前时间，精确到秒 **/
char* get_time_stamp(){
    time_t t;
    struct tm *timeinfo;
    time(&t);
    timeinfo = localetime(&t);

    char time_stamp___[22];   //yyyy-mm-dd hh:MM:ss
    sprintf(time_stamp__,"%d-%d-%d %d:%d:%d %d ",
            timinfo->tm_year + 1900,
            timeinfo->tm_mon + 1,
            timeinfo->tm_mday,
            timeinfo->tm_hour,
            timeinfo->tm_min,
            timeinfo->tm_sec)
    return time_stamp___;
}

void info(char*msg){
    ;
}

void warn(char*msg){
    ;
}

void error(char*msg){
    ;
}

