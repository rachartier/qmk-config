// Per-key glow: a key stays lit at full brightness while held, then fades to black
// once released. No background layer.
// Tune here: fade length, colour, peak brightness.
#define FADE_DURATION_MS 200
#define GLOW_COLOR_R 128
#define GLOW_COLOR_G 0
#define GLOW_COLOR_B 255
#define MAX_BRIGHTNESS 255

RGB_MATRIX_EFFECT(PRESS_GLOW)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Only safe inside this guard: the other two passes include this file inside an enum
// body and a switch body, where a #include would not compile.
#include "matrix.h"

static uint16_t press_glow_start[RGB_MATRIX_LED_COUNT];
static bool     press_glow_lit[RGB_MATRIX_LED_COUNT];

bool PRESS_GLOW(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // iter 0 is the first chunk of a frame, so this runs once per frame.
    // A held key has its start time pushed forward every frame, which pins it at full
    // brightness; the fade only begins on the frame after the key stops being held.
    if (params->iter == 0) {
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            matrix_row_t bits = matrix_get_row(row);
            for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                if (!(bits & ((matrix_row_t)1 << col))) continue;
                uint8_t led = g_led_config.matrix_co[row][col];
                if (led == NO_LED) continue;
                press_glow_start[led] = timer_read();
                press_glow_lit[led]   = true;
            }
        }
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        uint16_t elapsed = timer_elapsed(press_glow_start[i]);
        if (!press_glow_lit[i] || elapsed >= FADE_DURATION_MS) {
            press_glow_lit[i] = false;
            rgb_matrix_set_color(i, 0, 0, 0);
            continue;
        }

        // Linear ramp from MAX_BRIGHTNESS down to 0. For ease-out, add: level = scale8(level, level);
        uint8_t level = MAX_BRIGHTNESS - (uint32_t)MAX_BRIGHTNESS * elapsed / FADE_DURATION_MS;
        rgb_matrix_set_color(i, scale8(GLOW_COLOR_R, level), scale8(GLOW_COLOR_G, level), scale8(GLOW_COLOR_B, level));
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
