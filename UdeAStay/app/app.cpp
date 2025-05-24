#include "app.h"
#include "../db/db.h"

App::App(){
    db_app = new DB();
    db_app->inicializarBaseDeDatos();
}

App::~App(){
    delete db_app;
}

bool App::validate_user(const string& usaurio, const string& password){
    return true;
}
