#include "Config.h"

#ifdef MODULE_MSDCARD_READER
    #include <SPI.h>
    #include <SD.h>

    #define SD_CS 4

    Sd2Card card;
    SdVolume volume;
    SdFile root;
    File file;

    /**
     * @def Get type of SD Card
     * @param void
     * @return void
    */
    void getSDCardType(void) {
        Serial.print("Card type > ");

        switch (card.type()) {
            case SD_CARD_TYPE_SD1:
                Serial.println("SD1");
                break;
            case SD_CARD_TYPE_SD2:
                Serial.println("SD2");
                break;
            case SD_CARD_TYPE_SDHC:
                Serial.println("SDHC");
                break;
            default:
                Serial.println("Unknown");
        }
    }

    /**
     * @def Init and verify SD Card board is activate
     * @param void
     * @return void
    */
    void setupCardReader(void) 
    {
        if (!card.init(SPI_HALF_SPEED, SD_CS)) {
            Serial.println("Error to initialize SD Card Reader");
            return;
        } else {
            Serial.println("SD Card Reader is initialize !");
        }

        getSDCardType();

        if (volume.init(card)) {
            Serial.println("SD Card volume can be analyze !");
        }

        if (!SD.begin(4)) {
            Serial.println("SD Card init error to read and write files !");
            return;
        }
    }

    void readFile(char* nameFile) 
    {
        file = SD.open(nameFile);
    }

    /**
     * @def Write on data on specific file
     * @param char (*nameFile) Name of the file to write
     * @param char (*textFile) Text to write into the file
    */
    void writeFile(char* nameFile, char* textFile)
    {
        file = SD.open(nameFile, FILE_WRITE);
        file.println(textFile);
        file.close();
    }
    

    
#endif