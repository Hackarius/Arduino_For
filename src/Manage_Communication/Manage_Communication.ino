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
        strcpy(sdata.message, "Hello Mister");
    }

    void emit() 
    {
        while (!Serial.available()) { delay(50); }
        char c = Serial.read();

        if (c == 'o') {
            U_Datas ud;
            ud.datas = sdata;

            for (int i = 0; i < sizeof(struct Datas); i++) {
                Serial.write(ud.data8[i]);
            }

            delay(1000);
        }

        Serial.flush();
    }
#endif

#ifdef RECIEVER
    void recieve()
    {
        // while(Serial.available()) { Serial.read(); }
        // delay(1000);

        Serial.write('o');

        uint8_t i = 0;
        U_Datas ud;
        while(Serial.available() && i < sizeof(struct Datas)) {
            ud.data8[i] = Serial.read();
            i++;
        }

        Serial.print("Humidity > ");
        Serial.println(ud.datas.humidity);

        Serial.print("Temperature > ");
        Serial.println(ud.datas.temperature);

        Serial.print("Message > ");
        Serial.println(ud.datas.message);
    }
#endif