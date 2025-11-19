#pragma once

// Pointing device configuration
#define POINTING_DEVICE_DRIVER navigator_trackball

// I2C Configuration for STM32F303 (Planck Rev7)
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4

// Navigator trackball settings
#define NAVIGATOR_TRACKBALL_ADDRESS 0x50
#define NAVIGATOR_TRACKBALL_TIMEOUT 100

// Enable debug output
#define POINTING_DEVICE_DEBUG

// Mouse key settings
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64
