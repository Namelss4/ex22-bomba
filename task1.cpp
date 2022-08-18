#include <Arduino.h>
#include "task1.h"

static void changeVar(uint32_t *pdata)
{
    *pdata = 10;
}

static void printVar(uint32_t value)
{
    Serial.print("var content: ");
    Serial.print(value);
    Serial.print("\n");
    //printf("var content: %d\n", value);
}

void task1()
{
    enum class Task1States
    {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(9600);
        task1State = Task1States::WAIT_DATA;
        Serial.println("To WAIT_DATA state");
        break;
    }

    case Task1States::WAIT_DATA:
    {
        // evento 1:
        // Ha llegado al menos un dato por el puerto serial?
        if (Serial.available() > 0)
        {
            Serial.read();
            Serial.println("Data from serial");
            uint32_t var = 0;
            uint32_t *pvar = &var;
            printVar(*pvar);
            changeVar(pvar);
            printVar(var);
        }
        break;
    }

    default:
    {
        break;
    }
    }
}