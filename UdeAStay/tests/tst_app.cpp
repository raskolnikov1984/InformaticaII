#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../app/app.h"

using namespace testing;
using namespace std;


class AppTest : public ::testing::Test {
public:
    App* app;

    void SetUp() override {
        app = new App();
    }

    void TearDown()override {
        delete app;
    }
};


TEST_F(AppTest, ValidarLoginUsuario){
    EXPECT_TRUE(app->validate_user("test", "test"));
}
