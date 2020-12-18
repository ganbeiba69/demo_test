#include "demo.h"

typedef struct tDataList
{
    unsigned char u8FailureValue;
    unsigned char u8MaxValidValue;
} sDataList;

int dataGlobal = 0;
int const constVar = 200;

// test case for basic simple test
// test case for ranged value
unsigned char demo_ranged(unsigned char checker1, unsigned char checker2)
{
    unsigned char checkOutput = checker1 + checker2;
    return checkOutput;
}

// test case for Coverage By Analysis (CBA)
int demo_CBA(unsigned char condition)
{
    int cba = 0;
    if (condition > 255u)
    {
        cba = condition;
    }
    if (condition < 10u)
    {
        cba = 0xFFFF;
    }
    return cba;
}

// test case for pointer input output
void demo_pointer(sDataList *ioDataList)
{
    if (0 != ioDataList)
    {
        if (235 > ioDataList->u8FailureValue)
        {
            ioDataList->u8MaxValidValue = ioDataList->u8FailureValue+20;
        }
        else
        {
            ioDataList->u8MaxValidValue = ioDataList->u8FailureValue;
        }
    }
}

int demo_stubs_test(void)
{
    int stubsValue = demo_stubs_if();
    return stubsValue;
}

int demo_sbf_test(unsigned char checker1, unsigned char checker2)
{
    int sbfValue = demo_ranged(checker1, checker2) + 33;
    return sbfValue;
}

int demo_division(int devidend, int divisor)
{
    int resultValue = devidend / divisor;
    return resultValue;    
}

int demo_const()
{
    int returnValue = 0xFF;
    if (100 > constVar)
    {
        returnValue = 100;
    }
    return returnValue;
}