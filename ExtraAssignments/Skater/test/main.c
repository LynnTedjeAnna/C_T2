#include "unity_test_module.h"

/* As an alternative for header files we can declare that
 * the following methos are available 'extern'ally.
 */
extern void run_skater_tests();

int main (int argc, char * argv[])
{
  UnityTestModule allModules[] = { { "skater", run_skater_tests}
                                 };

  size_t number_of_modules = sizeof(allModules)/sizeof(allModules[0]);

  return UnityTestModuleRun(argc, argv, allModules, number_of_modules);
}
