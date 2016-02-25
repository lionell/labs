//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_3_IOLIB_H_
#define _LAB_3_IOLIB_H_

#include "share.h"

double try_read_double();
double read_double();

double try_read_positive_double();
double read_positive_double();

int try_read_integer();
int read_integer();

int try_read_positive_integer();
int read_positive_integer();

void print_relative_position(Position position);
void print_relative_distance(double distance, Position position);


#endif //_LAB_3_IOLIB_H_
