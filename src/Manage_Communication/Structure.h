struct Datas {
  uint8_t humidity;
  float temperature; 
  char message[20];
};

union U_Datas {
    struct Datas datas;
    uint8_t data8[sizeof(struct Datas)];
};

// #define EMITTER
#define RECIEVER