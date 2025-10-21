#include <iostream>
#include "app.h"

using namespace std;

int main() {
  App *app = new App("/home/aserrador/Desktop/04-UdeA/InformaticaII/UdeATune");
  app->run();
  return 0;
}
