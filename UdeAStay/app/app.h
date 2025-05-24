#ifndef APP_H
#define APP_H

#include "../db/db.h"
#include <string>

using namespace std;

class App
{
public:
    DB* db_app;

    App();
    ~App();

    bool validate_user(const string& usuario, const string& password);
};

#endif // APP_H
