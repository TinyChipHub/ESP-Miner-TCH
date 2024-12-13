#ifndef TPS546_H_
#define TPS546_H_

#define TPS546_I2CADDR         0x24  //< TPS546 i2c address
#define TPS546_MANUFACTURER_ID 0xFE  //< Manufacturer ID
#define TPS546_REVISION        0xFF  //< Chip revision

/*-------------------------*/
/* These are the inital values for the voltage regulator configuration */
/* when the config revision stored in the TPS546 doesn't match, these values are used */


#define TPS546_INIT_ON_OFF_CONFIG 0x18 /* use ON_OFF command to control power */
#define OPERATION_OFF 0x00
#define OPERATION_ON  0x80

#define TPS546_INIT_FREQUENCY 650  /* KHz */

typedef struct
{
  const char* PROFILE;
  /* vin voltage */
  const float TPS546_INIT_VIN_ON;  /* V */
  const float TPS546_INIT_VIN_OFF; /* V */
  const float TPS546_INIT_VIN_UV_WARN_LIMIT; /* V */
  const float TPS546_INIT_VIN_OV_FAULT_LIMIT; /* V */
  const uint8_t TPS546_INIT_VIN_OV_FAULT_RESPONSE; /* retry 6 times */

  /* vout voltage */
  const float TPS546_INIT_SCALE_LOOP; /* Voltage Scale factor */
  const float TPS546_INIT_VOUT_MAX;/* V */
  const float TPS546_INIT_VOUT_OV_FAULT_LIMIT;/* %/100 above VOUT_COMMAND */
  const float TPS546_INIT_VOUT_OV_WARN_LIMIT; /* %/100 above VOUT_COMMAND */
  const float TPS546_INIT_VOUT_MARGIN_HIGH; /* %/100 above VOUT */
  const float TPS546_INIT_VOUT_COMMAND;  /* V absolute value */
  const float TPS546_INIT_VOUT_MARGIN_LOW; /* %/100 below VOUT */
  const float TPS546_INIT_VOUT_UV_WARN_LIMIT;  /* %/100 below VOUT_COMMAND */
  const float TPS546_INIT_VOUT_UV_FAULT_LIMIT; /* %/100 below VOUT_COMMAND */
  const float TPS546_INIT_VOUT_MIN; /* v */

   /* iout current */
  const float TPS546_INIT_IOUT_OC_WARN_LIMIT;  /* A */
  const float TPS546_INIT_IOUT_OC_FAULT_LIMIT; /* A */

  /* SW Ferq */
  const int TPS546_INIT_SW_FREQ;

} TPS546_CONFIG;

static TPS546_CONFIG ZYBER_CONFIG = {
  .PROFILE = "TPS546 profile for ZyberOcto",
  /* vin voltage */
  .TPS546_INIT_VIN_ON=11.5f,
  .TPS546_INIT_VIN_OFF=11.0f,
  .TPS546_INIT_VIN_UV_WARN_LIMIT=11.0f,
  .TPS546_INIT_VIN_OV_FAULT_LIMIT=13.0f,
  .TPS546_INIT_VIN_OV_FAULT_RESPONSE=0xB7,
  
  /* vout voltage */
  .TPS546_INIT_SCALE_LOOP=0.125f,
  .TPS546_INIT_VOUT_MAX=5.5f,
  .TPS546_INIT_VOUT_OV_FAULT_LIMIT=1.25f,
  .TPS546_INIT_VOUT_OV_WARN_LIMIT=1.1f,
  .TPS546_INIT_VOUT_MARGIN_HIGH=1.1f,
  .TPS546_INIT_VOUT_COMMAND=4.80f,
  .TPS546_INIT_VOUT_MARGIN_LOW=0.9f,
  .TPS546_INIT_VOUT_UV_WARN_LIMIT=0.9f,
  .TPS546_INIT_VOUT_UV_FAULT_LIMIT=0.75f,
  .TPS546_INIT_VOUT_MIN=2.5f,

  /* iout current */
  .TPS546_INIT_IOUT_OC_WARN_LIMIT=50,
  .TPS546_INIT_IOUT_OC_FAULT_LIMIT=52,

  /* SW Ferq */
  .TPS546_INIT_SW_FREQ=750,

};

/* vin voltage */
// #define TPS546_INIT_VIN_ON  4.8  /* V */
// #define TPS546_INIT_VIN_OFF 4.5  /* V */
// #define TPS546_INIT_VIN_UV_WARN_LIMIT 5.8 /* V */
// #define TPS546_INIT_VIN_OV_FAULT_LIMIT 6.0 /* V */
// #define TPS546_INIT_VIN_OV_FAULT_RESPONSE 0xB7  /* retry 6 times */

  /* vout voltage */
// #define TPS546_INIT_SCALE_LOOP 0.25  /* Voltage Scale factor */
// #define TPS546_INIT_VOUT_MAX 3 /* V */
// #define TPS546_INIT_VOUT_OV_FAULT_LIMIT 1.25 /* %/100 above VOUT_COMMAND */
// #define TPS546_INIT_VOUT_OV_WARN_LIMIT  1.1 /* %/100 above VOUT_COMMAND */
// #define TPS546_INIT_VOUT_MARGIN_HIGH 1.1 /* %/100 above VOUT */
// #define TPS546_INIT_VOUT_COMMAND 1.2  /* V absolute value */
// #define TPS546_INIT_VOUT_MARGIN_LOW 0.90 /* %/100 below VOUT */
// #define TPS546_INIT_VOUT_UV_WARN_LIMIT 0.90  /* %/100 below VOUT_COMMAND */
// #define TPS546_INIT_VOUT_UV_FAULT_LIMIT 0.75 /* %/100 below VOUT_COMMAND */
// #define TPS546_INIT_VOUT_MIN 1 /* v */

  /* iout current */
//#define TPS546_INIT_IOUT_OC_WARN_LIMIT  25.00 /* A */
//#define TPS546_INIT_IOUT_OC_FAULT_LIMIT 30.00 /* A */
#define TPS546_INIT_IOUT_OC_FAULT_RESPONSE 0xC0  /* shut down, no retries */

  /* temperature */
// It is better to set the temperature warn limit for TPS546 more higher than Ultra 
#define TPS546_INIT_OT_WARN_LIMIT  135 /* degrees C */
#define TPS546_INIT_OT_FAULT_LIMIT 145 /* degrees C */
#define TPS546_INIT_OT_FAULT_RESPONSE 0xFF /* wait for cooling, and retry */

  /* timing */
#define TPS546_INIT_TON_DELAY 0
#define TPS546_INIT_TON_RISE 3
#define TPS546_INIT_TON_MAX_FAULT_LIMIT 0
#define TPS546_INIT_TON_MAX_FAULT_RESPONSE 0x3B
#define TPS546_INIT_TOFF_DELAY 0
#define TPS546_INIT_TOFF_FALL 0

#define INIT_STACK_CONFIG 0x0000
#define INIT_SYNC_CONFIG 0x0010
#define INIT_PIN_DETECT_OVERRIDE 0x0000

/*-------------------------*/

/* PMBUS_ON_OFF_CONFIG initialization values */
#define ON_OFF_CONFIG_PU 0x10   // turn on PU bit
#define ON_OFF_CONFIG_CMD 0x08  // turn on CMD bit
#define ON_OFF_CONFIG_CP 0x00   // turn off CP bit
#define ON_OFF_CONFIG_POLARITY 0x00 // turn off POLARITY bit
#define ON_OFF_CONFIG_DELAY 0x00 // turn off DELAY bit


/* Bit masks for status faults */
#define PMBUS_FAULT_SECONDARY 0x0001 /* need to check STATUS_WORD */
#define PMBUS_FAULT_CML       0x0002 /* need to check STATUS_CML */
#define PMBUS_FAULT_TEMP      0x0004 /* need to check STATUS_TEMP */
#define PMBUS_FAULT_VIN_UV    0x0008
#define PMBUS_FAULT_IOUT_OC   0x0010
#define PMBUS_FAULT_VOUT_OV   0x0020
#define PMBUS_FAULT_OFF       0x0040
#define PMBUS_FAULT_BUSY      0x0080
/* NOT SUPPORTED              0x0100 */
#define PMBUS_FAULT_OTHER     0x0200 /* need to check STATUS_OTHER */
/* NOT SUPPORTED              0x0400 */
#define PMBUS_FAULT_PGOOD     0x0800
#define PMBUS_FAULT_MFR       0x1000 /* need to check STATUS_MFR */
#define PMBUS_FAULT_INPUT     0x2000 /* need to check STATUS_INPUT */
#define PMBUS_FAULT_IOUT      0x4000 /* need to check STATUS_IOUT  */
#define PMBUS_FAULT_VOUT      0x8000 /* need to check STATUS_VOUT  */

#define PMBUS_SYNC_CONFIG_ZYBER 0xD0  //enable auto detect sync
#define PMBUS_STACK_CONFIG_ZYBER 0x0001  //One-Slave,2-phase
// #define 


/* public functions */
int TPS546_init(TPS546_CONFIG);
void TPS546_read_mfr_info(uint8_t *);
void TPS546_set_mfr_info(void);
void TPS546_write_entire_config(void);
int TPS546_get_frequency(void);
void TPS546_set_frequency(int);
int TPS546_get_temperature(void);
float TPS546_get_vin(void);
float TPS546_get_iout(void);
float TPS546_get_vout(void);
void TPS546_set_vout(float volts);
void TPS546_show_voltage_settings(void);
void TPS546_print_status(void);
void TPS546_check_status(void);

#endif /* TPS546_H_ */
