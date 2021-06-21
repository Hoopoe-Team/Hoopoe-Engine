#ifndef __ENGINE_CORE_DATABASE_H__
#define __ENGINE_CORE_DATABASE_H__

#include "sqlite3.h"
#include <iostream>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

void test_sqlite();

#endif