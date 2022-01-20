/**
 * @file mof_test.h
 * @author Mazen Osama (you@domain.com)
 * @brief simple test macro to prepare tests
 * @version 0.1
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _MOF_TEST_H
#define _MOF_TEST_H


typedef void (*test_func_t)(void);

static unsigned int test_idx = 0;


#define TEST(funcname)   void TEST_##funcname (void)
#define TEST_SUBSCRIBE(funcname)  \
{  \
   test_functions[test_idx++] = TEST_##funcname ;   \
}    
  
#ifndef TEST_COUNT
#define TEST_COUNT      1
#endif

test_func_t test_functions[TEST_COUNT] ; 

#define TEST_RUNALL() \
{   \
  for (int i = 0; i < test_idx; i++)  \
  {                \
      test_functions[i]() ;   \
  }           \
    \
}



#endif