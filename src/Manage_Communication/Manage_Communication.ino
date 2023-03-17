#include "Structure.h"
struct Datas sdata;

void setup() {
    Serial.begin(9600);

    #ifdef EMITTER
        setupValues();
    #endif
}

void loop() {
    #ifdef EMITTER
        emit();
    #endif

    #ifdef RECIEVER
        recieve();
    #endif
}

#ifdef EMITTER
    void setupValues() 
    {
        sdata.humidity = 30;
        sdata.temperature = 22.87F;
        sdata.message = "Hello Mister";
    }

    void emit() 
    {
        U_Datas ud;
        ud.datas = sdata;

        for (int i = 0; i < sizeof(struct Datas); i++) {
            Serial.write(ud.data8[i]);
        }
    }
#endif

#ifdef RECIEVER
    void recieve()
    {
        
    }
#endif