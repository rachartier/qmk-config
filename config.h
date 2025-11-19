#pragma once

// Pointing device configuration
#define POINTING_DEVICE_DRIVER navigator_trackball

// I2C Configuration for STM32F303 (Planck Rev7)
// Note: B6/B7 are audio pins on standard Planck
// Using them for I2C requires disabling audio
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4

// Navigator trackball I2C address
// The driver expects 7-bit address shifted left
#define NAVIGATOR_TRACKBALL_ADDRESS (0x28 << 1)
#define NAVIGATOR_TRACKBALL_TIMEOUT 100
#define NAVIGATOR_TRACKBALL_CPI 40

// Enable debug output
#define POINTING_DEVICE_DEBUG
#define DEBUG_ENABLE
#define DEBUG_MATRIX

// Disable audio to free up B6/B7 for I2C
#define NO_AUDIO_ENABLE

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
