#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"

#define SLAVE_ADDR          0x32
#define MASTER_PORT         I2C_NUM_0
#define MASTER_SDA          21
#define MASTER_SCL          22
#define MASTER_FREQ_HZ      100000

void i2c_master_init() {
    i2c_config_t i2c_master_config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = MASTER_SDA,
        .scl_io_num = MASTER_SCL,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = MASTER_FREQ_HZ,
    };
    ESP_ERROR_CHECK(i2c_param_config(MASTER_PORT, &i2c_master_config));
    ESP_ERROR_CHECK(i2c_driver_install(MASTER_PORT, i2c_master_config.mode, 0, 0, 0));
}

void app_main() {
    i2c_master_init();

    
    const char * trama = "S,1,0,1,E";

    const uint8_t data[3] = {1, 0, 1};
    
    while(1) {
        if(ESP_ERR_TIMEOUT == i2c_master_write_to_device(MASTER_PORT, SLAVE_ADDR, data, sizeof(data), 100/portTICK_PERIOD_MS))
            continue;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
