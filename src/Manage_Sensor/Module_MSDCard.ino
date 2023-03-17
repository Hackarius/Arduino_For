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
     * @def ist all file at root on sdcard
     * @param void
     * @return void
    */
    void getFilesOnRoot(void)
    {
        root.ls(LS_R | LS_DATE | LS_SIZE);
    }

    /**
     * @def Init and verify SD Card board is activate
     * @param void
     * @return void
    */
    void setupCardReader(void) 
    {
        Serial.println("Setup SDCard module");

        if (!card.init(SPI_HALF_SPEED, SD_CS)) {
            Serial.println("Error to initialize SD Card Reader");
            return;
        } else {
            Serial.println("SD Card Reader is initialize !");
        }

        getSDCardType();

        if (volume.init(card)) {
            Serial.println("Read list of files in SD Card > ");
            root.openRoot(volume);
            getFilesOnRoot();
        }

        if (!SD.begin(4)) {
            Serial.println("SD Card init error to read and write files !");
            return;
        }
    }

    /**
     * @def Function to return on Serial data in file
     * @param char (*nameFile) Name of file to read
     * @return void
    */
    void readFile(char* nameFile) 
    {
        if (SD.exists(nameFile)) {
            file = SD.open(nameFile);
            
            Serial.print(" - ");
            Serial.print(nameFile);
            Serial.println(" : Data > ");

            while (file.available()) {
                Serial.write(file.read());
            }

            file.close();
        } else {
            Serial.println("Error file doesn't exist");
        }
    }

    /**
     * @def Write on data on specific file
     * @param char (*nameFile) Name of the file to write
     * @param char (*textFile) Text to write into the file
     * @return void
    */
    void writeFile(char* nameFile, char* textFile)
    {
        file = SD.open(nameFile, FILE_WRITE);
        file.println(textFile);
        file.close();
    }

    /**
     * @def Create new empty file 
     * @param char (*nameFile) Name of the empty file to create
     * @return void
    */
    void clearFile(char* nameFile)
    {
        if (SD.exists(nameFile)) {
            SD.remove(nameFile);
        }

        file = SD.open(nameFile, FILE_WRITE);
        file.write("");
        file.close();
    }
#endif