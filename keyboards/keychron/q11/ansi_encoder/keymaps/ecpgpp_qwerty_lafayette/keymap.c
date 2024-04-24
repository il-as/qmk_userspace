/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

# include "keymap_us_international_linux.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    DK1,
    DK2,
    WIN_BASE,
    WIN_FN,
    ALT_GR,
};

#undef US_CIRC
enum custom_keycodes {
    US_YACU = SAFE_RANGE,
    US_EGRV, // è
    US_UGRV, // ù
    US_AGRV, // à

    US_CEGV, // È
    US_CUGV, // Ù
    US_CAGV, // À


    US_ECFX, // ê
    US_YCFX, // ŷ
    US_UCFX, // û
    US_ICFX, // î
    US_OCFX, // ô
    US_ACFX, // â

    US_WDIA, // ẅ
    US_TDIA, // ẗ
    US_YDIA, // ÿ
    US_HDIA, // ḧ
    US_XDIA, // ẍ
    US_FLIP,
    US_IDIA = ALGR(KC_J), // ï
    US_EDIA = ALGR(KC_F), // ë

    US_CIRC = S(ALGR(KC_6)), // ^
    US_PLMN = S(ALGR(KC_M)), // ±
    US_ITPT = ALGR(KC_X)     // ·
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// ucis
const ucis_symbol_t ucis_symbol_table[] = {
    UCIS_SYM("flip", 0x0028, 0x256F, 0x00B0, 0x25A1, 0x00B0, 0x0029, 0x256F, 0xFE35, 0x0020, 0x253B, 0x2501, 0x253B)
};


// dead key conversion from us intl multi deadkey setup to lafayette's single dead key
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case US_EGRV: // è
            if(record->event.pressed) {
                tap_code(US_DGRV);
                tap_code(US_E);
            }
            break;
        case US_UGRV: // ù
            if(record->event.pressed) {
                tap_code(US_DGRV);
                tap_code(US_U);
            }
            break;
        case US_AGRV: // à
            if(record->event.pressed) {
                tap_code(US_DGRV);
                tap_code(US_A);
            }
            break;

        case US_CEGV: // È BUG: not working
            if(record->event.pressed) {
                tap_code(US_DGRV);
                tap_code16(S(US_E));
            }
            break;
        case US_CUGV: // Ù BUG: not working
            if(record->event.pressed) {
                tap_code(US_DGRV);
                tap_code16(S(US_U));
            }
            break;
        case US_CAGV: // À BUG: not working
            if(record->event.pressed) {
                tap_code(US_DGRV);
                tap_code16(S(US_A));
            }
            break;

        case US_ECFX: // ê
            if(record->event.pressed) {
                tap_code16(US_DCIR);
                tap_code(US_E);
            }
            break;
        case US_YCFX: // ŷ
            if(record->event.pressed) {
                tap_code16(US_DCIR);
                tap_code(US_Y);
            }
            break;
        case US_UCFX: // û
            if(record->event.pressed) {
                tap_code16(US_DCIR);
                tap_code(US_U);
            }
            break;
        case US_ICFX: // î
            if(record->event.pressed) {
                tap_code16(US_DCIR);
                tap_code(US_I);
            }
            break;
        case US_OCFX: // ô
            if(record->event.pressed) {
                tap_code16(US_DCIR);
                tap_code(US_O);
            }
            break;
        case US_ACFX: // â
            if(record->event.pressed) {
                tap_code16(US_DCIR);
                tap_code(US_A);
            }
            break;

        case US_WDIA: // ẅ
            if(record->event.pressed) {
                tap_code16(US_DIAE);
                tap_code(US_W);
            }
            break;
        case US_TDIA: // ẗ
            if(record->event.pressed) {
                tap_code16(US_DIAE);
                tap_code(US_T);
            }
            break;
        case US_YDIA: // ÿ
            if(record->event.pressed) {
                tap_code16(US_DIAE);
                tap_code(US_Y);
            }
            break;
        case US_HDIA: // ḧ
            if(record->event.pressed) {
                tap_code16(US_DIAE);
                tap_code(US_H);
            }
            break;
        case US_XDIA: // ẍ
            if(record->event.pressed) {
                tap_code16(US_DIAE);
                tap_code(US_X);
            }
            break;
        case US_FLIP:
            if(record->event.pressed) {
                //SEND_STRING("(╯°□°)╯︵ ┻━┻");
                ucis_start();
                send_unicode_string("flip");
                for (int i = 0; i < strlen("flip"); i++) {
                    tap_code(KC_BSPC);
                }
                tap_code(KC_SPC);
            }
            break;
    }
    return true;
};

// Key override for shifted keys in ALT_GR layer
const key_override_t US_BRKP_key_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_PIPE, US_BRKP, 1<<ALT_GR); // ¦
const key_override_t US_MUL_key_override    = ko_make_with_layers(MOD_MASK_SHIFT, KC_PAST, US_MUL,  1<<ALT_GR); // ×
const key_override_t US_GRPLMN_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_PLUS, US_PLMN, 1<<ALT_GR); // ±
const key_override_t US_NOT_key_override    = ko_make_with_layers(MOD_MASK_SHIFT, KC_PMNS, US_NOT,  1<<ALT_GR); // ¬
const key_override_t US_DIV_key_override    = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, US_DIV,  1<<ALT_GR); // ÷

// Key override for shifted keys in DK1 layer
const key_override_t US_LSQU_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_LDQU, US_LSQU, 1<<DK1); // ‘
const key_override_t US_RSQU_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_RDQU, US_RSQU, 1<<DK1); // ’
const key_override_t US_PLMN_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL,  US_PLMN, 1<<DK1); // ±
const key_override_t US_IQUE_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_DIV,  US_IQUE, 1<<DK1); // ¿
const key_override_t US_CEGV_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_EGRV, US_CEGV, 1<<DK1); // È BUG:
const key_override_t US_CUGV_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_EGRV, US_CUGV, 1<<DK1); // Ù BUG: no workey
const key_override_t US_CAGV_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_AGRV, US_CAGV, 1<<DK1); // À BUG:

// Key override for shifted keys in BASE layer
const key_override_t US_DQUO_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_QUOT, US_DQUO, 1<<MAC_BASE | 1<<WIN_BASE); // " // might break the dead key macros
const key_override_t US_TILD_key_override = ko_make_with_layers(MOD_MASK_SHIFT, US_DTIL, US_TILD, 1<<MAC_BASE | 1<<WIN_BASE); // BUG: doesn't work / useless (last flash solved it, but might be because KC_GRV was replaced with US_GRV)
const key_override_t US_LDAQ_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_9,    US_LDAQ, 1<<MAC_BASE | 1<<WIN_BASE); // «
const key_override_t US_RDAQ_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_0,    US_RDAQ, 1<<MAC_BASE | 1<<WIN_BASE); // »
const key_override_t US_EXLM_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, US_EXLM, 1<<MAC_BASE | 1<<WIN_BASE); // BUG: doesn't work

// Key override for shifted keys in ALL layers
const key_override_t US_END_key_override = ko_make_basic(MOD_MASK_CTRL, KC_HOME, KC_END);
const key_override_t US_DEL_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]) {
    &US_BRKP_key_override,
    &US_MUL_key_override,
    &US_GRPLMN_key_override,
    &US_NOT_key_override,
    &US_DIV_key_override,

    &US_LSQU_key_override,
    &US_RSQU_key_override,
    &US_PLMN_key_override,
    &US_IQUE_key_override,
    &US_CEGV_key_override,
    &US_CUGV_key_override,
    &US_CAGV_key_override,

    &US_DQUO_key_override,
    &US_TILD_key_override,
    &US_LDAQ_key_override,
    &US_RDAQ_key_override,
    &US_EXLM_key_override,

    &US_END_key_override,
    &US_DEL_key_override,
    NULL // Null terminate the array of overrides!
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        US_FLIP,  US_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     OSL(DK1), US_QUOT,              KC_ENT,             KC_HOME,
     MO(ALT_GR),  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LOPT,  KC_LCMD,  MO(MAC_FN),         KC_SPC,                        KC_BSPC,          MO(ALT_GR), MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    /* NOTE: MAC_BASE layer
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
     * │MUT│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │MUT│
     * └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
     * │M1 │ │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │        │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │ │PGU│
     * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
     * │M2 │ │Tab  │ Q │ W │ E │ R │ T │        │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │PGD│
     * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
     * │M3 │ │Caps  │ A │ S │ D │ F │ G │        │ H │ J │ K │ L │DK2│ ' │    Ent │ │HOM│
     * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
     * │AlG│ │Sft     │ Z │ X │ C │ V │ B │        │ N │ M │ , │ . │ / │Shift │ │Up │
     * ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
     * │M5 │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │AlG│Fn1│Ctr│ │Lft│Dwn│Rig│
     * └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
     */

    [MAC_FN] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
     /* NOTE: MAC_FN layer
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
     * │RGB│ │Esc│BR-│BR+│MCL│LPD│LD-│LD+│        │MU-│MUS│MU+│DEF│Vo-│Vo+│   │   │ │RGB│
     * └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
     * │   │ │   │   │   │   │   │   │   │        │   │   │   │   │   │   │       │ │   │
     * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
     * │   │ │RGBtg│mod│VA+│HU+│SA+│SP+│        │   │   │   │   │   │   │   │     │ │   │
     * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
     * │   │ │      │Rmd│VA-│HU-│SA-│SP-│        │Lft│Dwn│Up │Rgt│   │   │        │ │   │
     * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
     * │   │ │        │   │   │   │   │   │        │NKt│   │   │   │   │      │ │   │
     * ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
     * │   │ │    │    │    │    │        │        │          │   │   │   │ │   │   │   │
     * └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
     */

    [DK1] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        US_FLIP,  KC_NO,    KC_NO,    US_LDQU,  US_RDQU,  US_CENT,  US_PND,    US_YEN,   US_CURR,  US_SECT,  US_PILC,  US_DEG,   KC_NO,      KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   US_AE,    US_EACU,  US_EGRV,  US_EDIA,  US_MINS,   US_UDIA,  US_UGRV,  US_IDIA,  US_OE,    KC_NO,    KC_NO,      KC_NO,    KC_NO,              KC_PGDN,
        _______,  KC_CAPS,  US_AGRV,  US_SS,    US_ECFX,  US_MINS,  KC_NO,     US_YCFX,  US_UCFX,  US_ICFX,  US_OCFX,  OSL(DK2), KC_NO,                KC_ENT,             KC_HOME,
     MO(ALT_GR),  KC_LSFT,            US_ACFX,  US_MUL,   US_CCED,  US_UNDS,   KC_NO,    US_NTIL,  US_MICR,  US_ITPT,  KC_NO,    US_DIV,               KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LOPT,  KC_LCMD,  MO(MAC_FN),         KC_SPC,                        KC_BSPC,            KC_RALT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    /* NOTE: Dead Key 1 layer
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
     * │MUT│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │MUT│
     * └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
     * │M1 │ │   │   │“’ │”’ │ ¢ │ £ │ ¥ │        │ ¤ │ § │ ¶ │ ° │   │ =±│Bkspc  │ │PGU│
     * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
     * │M2 │ │Tab  │ Æ │ É │ è │ Ë │ - │        │ Ü │ ù │ Ï │ Œ │   │   │   │     │ │PGD│
     * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
     * │M3 │ │Caps  │ à │ ß │ Ê │ - │   │        │ Ŷ │ Û │ Î │ Ô │DK2│ ' │    Ent │ │HOM│
     * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
     * │AlG│ │Sft     │ Â │ × │ Ç │ _ │   │        │ Ñ │ µ │ · │   │ ÷¿│Shift │ │Up │
     * ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
     * │M5 │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │Alt│Fn1│Ctr│ │Lft│Dwn│Rig│
     * └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
     * For now, capitalised versions of è à ù need to be done with caps lock.
     */

    [DK2] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_NO,    US_WDIA,  US_EDIA,  KC_NO,    US_TDIA,   US_YDIA,  US_UDIA,  US_IDIA,  US_ODIA,  KC_NO,    KC_NO,      KC_NO,    KC_NO,              KC_PGDN,
        _______,  KC_CAPS,  US_ADIA,  KC_NO,    KC_NO,    KC_NO,    KC_NO,     US_HDIA,  KC_NO,    KC_NO,    KC_NO,    KC_SCLN,  KC_NO,                KC_ENT,             KC_HOME,
     MO(ALT_GR),  KC_LSFT,            KC_NO,    US_XDIA,  KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LOPT,  KC_LCMD,  MO(MAC_FN),         KC_SPC,                        KC_BSPC,            KC_RALT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    /* INFO: Dead Key 2 layer
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
     * │MUT│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │MUT│
     * └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
     * │   │ │   │   │   │   │   │   │   │        │   │   │   │   │   │   │Bkspc  │ │PGU│
     * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
     * │   │ │Tab  │   │ Ẅ │ Ë │   │ ẗ │        │ Ÿ │ Ü │ Ï │ Ö │   │   │   │  \  │ │PGD│
     * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
     * │   │ │Caps  │ Ä │   │   │   │   │        │ Ḧ │   │   │   │ ; │   │    Ent │ │HOM│
     * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
     * │   │ │Sft     │   │ Ẍ │   │   │   │        │   │   │   │   │   │Shift │ │Up │
     * ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
     * │   │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │Cmd│Fn1│Ctr│ │Lft│Dwn│Rig│
     * └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
     * S(ẗ) does't work, it doesn't exist in the us intl keymap
     */


    [WIN_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        US_FLIP,  US_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     OSL(DK1), US_QUOT,              KC_ENT,             KC_HOME,
     MO(ALT_GR),  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,  KC_LALT,  MO(WIN_FN),         KC_SPC,                        KC_BSPC,          MO(ALT_GR), MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    /* INFO: WIN_BASE layer
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
     * │MUT│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │MUT│
     * └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
     * │M1 │ │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │        │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │ │PGU│
     * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
     * │M2 │ │Tab  │ Q │ W │ E │ R │ T │        │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │PGD│
     * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
     * │M3 │ │Caps  │ A │ S │ D │ F │ G │        │ H │ J │ K │ L │DK1│ ' │    Ent │ │HOM│
     * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
     * │M4 │ │Sft     │ Z │ X │ C │ V │ B │        │ N │ M │ , │ . │ / │Shift │ │Up │
     * ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
     * │M5 │ │Ctrl│Win │ALT │ FN │Space   │        │Bkspc Del │ALG│Fn1│Ctr│ │Lft│Dwn│Rig│
     * └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
     */

    [WIN_FN] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
    /* INFO: WIN_FN layer (RGB and media control)
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
     * │RGB│ │   │BR-│BR+│TSK│FXP│VA-│VA+│        │MU-│MUS│MU+│MUT│VO+│VO-│   │   │ │RGB│
     * └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
     * │   │ │   │   │   │   │   │   │   │        │   │   │   │   │   │   │       │ │   │
     * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
     * │   │ │RGBtg│Mod│VA+│HU+│SA+│SP+│        │   │   │   │   │   │   │   │     │ │   │
     * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
     * │   │ │      │Rmd│VA-│HU-│SA-│SP-│        │Lft│Dwn│Up │Rig│   │   │        │ │   │
     * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
     * │   │ │        │   │   │   │   │   │        │NKt│   │   │   │   │      │ │   │
     * ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
     * │   │ │    │    │    │    │        │        │          │   │   │   │ │   │   │   │
     * └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
     */

    [ALT_GR] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        US_PLUS,  KC_NO,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_PMNS,  KC_TAB,   KC_AT,    KC_LT,    KC_GT,    KC_DLR,   KC_PERC,   US_CIRC,  KC_AMPR,  KC_PAST,  US_QUOT,  US_GRV,   KC_NO,      KC_NO,    KC_NO,              KC_PGDN,
        KC_PAST,  KC_CAPS,  KC_LCBR,  KC_LPRN,  KC_RPRN,  KC_RCBR,  KC_EQL,    KC_BSLS,  US_PLUS,  KC_PMNS,  KC_SLSH,  US_DQUO,  KC_NO,                KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            US_TILD,  KC_LBRC,  KC_RBRC,  KC_UNDS,  KC_HASH,   KC_PIPE,  KC_EXLM,  US_SCLN,  US_COLN,  US_QUES,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LGUI,  KC_LCMD,  MO(MAC_FN),         KC_SPC,                        KC_BSPC,            KC_RALT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
     /* INFO : ALT_GR (dev special chars) layer
      * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
      * │MUT│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │MUT│
      * └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
      * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
      * │ + │ │   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │        │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │ │PGU│
      * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
      * │ - │ │Tab  │ @ │ < │ > │ $ │ % │        │ ^ │ & │ *×│ ' │ ` │   │   │     │ │PGD│
      * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
      * │ * │ │Caps  │ { │ ( │ ) │ } │ = │        │ \ │ +±│ - │ /÷│ " │   │    Ent │ │HOM│
      * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
      * │   │ │Sft     │ ~ │ [ │ ] │ _ │ # │        │ |¦│ ! │ ; │ : │ ? │Shift │ │Up │
      * ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
      * │   │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │ALT│Fn1│Ctr│ │Lft│Dwn│Rig│
      * └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
      */
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [DK1]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [DK2]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [ALT_GR]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_MAP_ENABLE
