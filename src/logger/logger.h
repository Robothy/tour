#ifndef LOGGER_H
#define LOGGER_H

#include <time.h>

/** ��ȡ��ǰʱ�䣬��ȷ���� **/
char* get_time_stamp();



void warn(char*);

void error(char*);

void info(char*);

#endif // LOGGER_H
