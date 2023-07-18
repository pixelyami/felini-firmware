
#include <cstdlib>
#include <thread>
#include <iostream>

#include "porting/lv_porting.h"
#include "lvgl.h"

#include "App/App.h"
#include "HAL/HAL.h"

#ifdef CONFIG_IDF_TARGET_ESP32S3
    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "esp_freertos_hooks.h"
    #include "freertos/semphr.h"
    #include "esp_system.h"
    #include "driver/gpio.h"
    #include "driver/uart.h"
    #include "axp173.h"
#endif

extern "C"
{

#ifdef CONFIG_IDF_TARGET_ESP32S3
    void app_main(void)
    {
                // extern int dap_main(void);
        // dap_main();
        axp_init();
#else
    int main(int argc, char *argv[])
    {
#endif
    
        lv_porting_init();

        // lv_obj_t *label = lv_label_create(lv_scr_act());
        // lv_label_set_text(label, "obit tesla!!!!!!");
        // lv_obj_center(label);
        HAL::HAL_Init();
        App_Init();

#ifdef CONFIG_IDF_TARGET_ESP32S3



    float vbus, bat, charge_current, discharge_current, temp, ts;

    // while(1)
    // {
        axp_read_adc_data(DATA_VBUS_VOLT, &vbus);
        axp_read_adc_data(DATA_BAT_VOLT, &bat);
        axp_read_adc_data(DATA_BAT_CHARGE_CURRENT, &charge_current);
        axp_read_adc_data(DATA_BAT_DISCHARGE_CURRENT, &discharge_current);
        axp_read_adc_data(DATA_INTEL_TEMP, &temp);
        axp_read_adc_data(DATA_TS_ADC, &ts);
        printf( "VBUS volt: %.2f | BAT volt: %.2f | Charge_current: %.2f | Discharge_current: %.2f | temp: %.2f | ts: %.2f\r\n", vbus, bat, charge_current, discharge_current, temp, ts);

        // axp_read_columb_data(&columb);
        // ESP_LOGI(TAG, "Columb %.5f", columb);

    //     vTaskDelay(pdMS_TO_TICKS(500));
    // }
#else
        while (1)
        {            
                lv_timer_handler();
                lv_porting_delay();
        }
#endif
    }
}