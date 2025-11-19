#include QMK_KEYBOARD_H
#include "drivers/sensors/navigator_trackball.h"

const pointing_device_driver_t pointing_device_driver = {
    .init = navigator_trackball_device_init,
    .get_report = navigator_trackball_get_report,
    .get_cpi = navigator_trackball_get_cpi,
    .set_cpi = navigator_trackball_set_cpi
};
