#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "esp_attr.h"
    void IRAM_ATTR esp32_video_set_color(int x_pos, int y_pos, uint8_t c);
    void esp32_video_start(bool ntsc);
    void esp32_video_stop();
    void IRAM_ATTR esp32_video_sync();
#ifdef __cplusplus
}
#endif