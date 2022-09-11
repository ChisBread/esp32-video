# ESP32-Video
esp32-video 是从项目 [esp_8_bit](https://github.com/ChisBread/esp_8_bit) 移植的esp32-idf组件

# Usage
假设你的项目目录如下所示
```
- YourProject
  - components/
  - main/
  - CMakeLists.txt
  - sdkconfig
```
1. 将esp32-video添加到你项目的components文件夹中
```
git submodule add https://github.com/ChisBread/esp32-video components/esp32-video
```
2. 设置编译优化选项为O2、 默认CPU 频率为240MHz (必要)
```
idf.py menuconfig
```
3. 和你现有的图形库(如LVGL)结合使用

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