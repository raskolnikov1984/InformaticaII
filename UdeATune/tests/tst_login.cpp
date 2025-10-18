#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>

#include "../login.h"

using namespace std;
using namespace testing;

TEST(Login, LoginSuccess)
{
  Login login;
  EXPECT_EQ(login.getArchvio(), "login.csv");

  string usuario = "admin";
  string password = "123";
  string usuarioActual;

  EXPECT_TRUE(login.esAutorizado(usuario, password, usuarioActual));
  EXPECT_EQ(usuario, usuarioActual);
}

TEST(Login, LoginFailed)
{
  Login login;
  EXPECT_EQ(login.getArchvio(), "login.csv");

  string usuario = "admin";
  string password = "1234";
  string usuarioActual;

  EXPECT_FALSE(login.esAutorizado(usuario, password, usuarioActual));
  EXPECT_EQ(usuarioActual, "");
}
