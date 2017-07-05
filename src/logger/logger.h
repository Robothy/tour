#ifndef LOGGER_H
#define LOGGER_H

#include <time.h>

/** 获取当前时间，精确到秒 **/
char* get_time_stamp();



void warn(char*);

void error(char*);

void info(char*);

#endif // LOGGER_H
