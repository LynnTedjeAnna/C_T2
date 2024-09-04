#include "unity_test_module.h"

/* As an alternative for header files we can declare that
 * the following methos are available 'extern'ally.
 */
extern void run_encode_tests();
extern void run_channel_tests();
extern void run_decode_tests();
/*
 * You can add here additional run_XXX_tests modules, if needed. Can be handy when you have 
 * code that can be used by the encoder as well as the decoder.
 * Then you need to add additional files!
 * 
 */


int main (int argc, char * argv[])
{
  UnityTestModule allModules[] = { { "encode", run_encode_tests},
                                   { "channel", run_channel_tests},
                                   { "decode", run_decode_tests}  
                                 };

  size_t number_of_modules = sizeof(allModules)/sizeof(allModules[0]);

  return UnityTestModuleRun(argc, argv, allModules, number_of_modules);
}
