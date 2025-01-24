#ifndef SCREEN_H_
#define SCREEN_H_

typedef enum {
    SCR_SELF_TEST,
    SCR_OVERHEAT,
    SCR_SETUP,
    SCR_LOGO,
    SCR_MINING_STAT,
    SCR_DEVICE_INFO,
    SCR_NETWORK,
    MAX_SCREENS,
} screen_t;

#define SCR_CAROUSEL_START SCR_MINING_STAT
#define SCR_CAROUSEL_END SCR_NETWORK

esp_err_t screen_start(void * pvParameters);
void screen_next(void);

#endif /* SCREEN_H_ */
