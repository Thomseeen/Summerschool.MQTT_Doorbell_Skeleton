/*****************************************
 * Includes
 *****************************************/
// Generic
#include <string.h>
#include <time.h>
// FreeRTOS
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
// ESP32 APIs and functions
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_event_loop.h"
// Get lower level log messages
// - #define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
// SNTP
#include "lwip/apps/sntp.h"
#include "lwip/err.h"
// Camera
#include "esp_camera.h"
// MQTT
#include "esp_mqtt.h"
// Configs
#include "comconfig.h"
#include "exlibconfig.h"

/*****************************************
 * Local defines/settings
 *****************************************/
// clang-format off
// GPIO pins
#define PIN_STATUSLED   2
#define PIN_PUSHBUTTON  33

// MQTT Client-ID
#define ROOM "010"
#define CLIENTID_MQTT   "ESP32Doorbell" ROOM
#define TOPIC_MQTT_PIC  "hska/office"   ROOM "/doorbell/picture"
#define TOPIC_MQTT_TS   "hska/office"   ROOM "/doorbell/timestamp"

// TAG for the esp_log macros
#define TAG "MQTT_Doorbell"

// Expected max. size of frame - used for the send-buffer to optimize heap usage
// (camera often allocates a larger framebuffer than actually necessary)
#define MAXSIZE_OF_FRAME 27000  // bytes

// clang-format on

/*****************************************
 * Main
 *****************************************/
void app_main() {
    ESP_LOGI(TAG, "Hello World from Team-No. %s", ROOM);
}