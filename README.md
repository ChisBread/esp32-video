[简体中文](./README.zh.md)

# ESP32-Video
ESP32-Video is the esp-idf component ported from the [esp_8_bit](https://github.com/ChisBread/esp_8_bit) project.

# Usage
Suppose your project directory looks like this
```
- YourProject
  - components/
  - main/
  - CMakeLists.txt
  - sdkconfig
```
1. Add the library as a new component to your project.
```
git submodule add https://github.com/ChisBread/esp32-video components/esp32-video
```
2. Compilation optimization set to O2 and default CPU frequency set to 240MHz.(required)
```
idf.py menuconfig
```
3. Combining esp32-video with an existing graphics library

# Examples
[composite_video_lvgl_benchmark](https://github.com/ChisBread/esp32-codelab/tree/master/composite_video_lvgl)
## LVGL
Initialize esp32-video
```C
#include "capi_video.h"
//....
void app_main(void) {
    esp32_video_start(0);// PAL
    //esp32_video_start(1);// NTSC
    // do something...
    esp32_video_stop(); // Video output can be turned off and started at runtime
}
```
LVGL driver
```C
#include "capi_video.h"
//....
static void  lvgl_esp32_video_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p) {
    // esp32_video_sync(); // Display is more stable, but more stuttering
    // Set colors one by one
    for(int y = area->y1; y <= area->y2; ++y) {
        for(int x = area->x1; x <= area->x2; ++x) {
            esp32_video_set_color(x, y, lv_color_to8(*color_p));
            ++color_p;
        }
    }
}
```