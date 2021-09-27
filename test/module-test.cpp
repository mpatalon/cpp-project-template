#include <gtest/gtest.h>
#include <cpp-project-template/module/module.h>


TEST(module_test, TestModuleFunction) {
  ASSERT_EQ(0, module::module_function(common::Common{}));
}
