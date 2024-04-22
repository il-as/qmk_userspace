# ECPGPP qwerty lafayette
This is a close implementation of the Qwerty-Lafayette keymap, a keymap made for french developers qui veulent écrire bien français oui monsieur.
Made for the keychron Q11.
The original keychron layers are kept in their original place, but slightly modified.

## How to use
It's made to be used with a US international layout on the OS side.
The main objective is ease of setup when using the keyboard on multiple systems.

When developers work, they might need to log in a distant server, or log into containers, or use multiple physical computers.
This firmware makes it so the only step needed is to switch to the us international keymap

on linux with X server, this can be done like this:
    > ```setxkbmap -layout us -variant intl```
## Changes on the original keychron layers
### MAC_BASE
MAC_BASE was changed to make it less inconvenient to use on other systems:
+ The function row was changed from Mac specific keycodes to standard F1 to F12
+ Right command was changed to a new layer One Shot Key (ALT_GR)
+ the collon key was changed to a new layer One Shot Key (DK1)

### MAC_FN
The function row was changed from standard F1 to F12 to mac specific keycodes

### WIN_BASE
+ Right Alt was changed to a new layer One Shot Key (ALT_GR)
+ the collon key was changed to a new layer One Shot Key (DK1)

## The keymap
    > characters positioned to the right of the keys are shifted characters.
### Ascii representation
#### MAC_BASE layer
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
    │ O │ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │ O │
    └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
    │M1 │ │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │        │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │ │PGU│
    ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
    │M2 │ │Tab  │ Q │ W │ E │ R │ T │        │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │PGD│
    ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
    │M3 │ │Caps  │ A │ S │ D │ F │ G │        │ H │ J │ K │ L │DK2│ ' │    Ent │ │HOM│
    ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
    │M4 │ │Sft     │ Z │ X │ C │ V │ B │        │ N │ M │ , │ . │ / │Shift │ │Up │
    ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
    │M5 │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │Alt│Fn1│Ctr│ │Lft│Dwn│Rig│
    └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘

#### MAC_FN (RGB and media control)
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
    │RGB│ │Esc│BR-│BR+│MCL│LPD│LD-│LD+│        │MU-│MUS│MU+│DEF│Vo-│Vo+│   │   │ │RGB│
    └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
    │   │ │   │   │   │   │   │   │   │        │   │   │   │   │   │   │       │ │   │
    ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
    │   │ │RGBtg│mod│VA+│HU+│SA+│SP+│        │   │   │   │   │   │   │   │     │ │   │
    ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
    │   │ │      │Rmd│VA-│HU-│SA-│SP-│        │Lft│Dwn│Up │Rgt│   │   │        │ │   │
    ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
    │   │ │        │   │   │   │   │   │        │NKt│   │   │   │   │      │ │   │
    ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
    │   │ │    │    │    │    │        │        │          │   │   │   │ │   │   │   │
    └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘

#### Dead Key 1 (most usual accents, rigorous typing chars)
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
    │MUT│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │MUT│
    └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
    │M1 │ │   │   │“’ │”’ │ ¢ │ £ │ ¥ │        │ ¤ │ § │ ¶ │ ° │   │ =±│Bkspc  │ │PGU│
    ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
    │M2 │ │Tab  │ Æ │ É │ è │ Ë │ - │        │ Ü │ ù │ Ï │ Œ │   │   │   │     │ │PGD│
    ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
    │M3 │ │Caps  │ à │ ß │ Ê │ - │   │        │ Ŷ │ Û │ Î │ Ô │DK2│ ' │    Ent │ │HOM│
    ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
    │M4 │ │Sft     │ Â │ × │ Ç │ _ │   │        │ Ñ │ µ │ · │   │ ÷¿│Shift │ │Up │
    ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
    │M5 │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │Cmd│Fn1│Ctr│ │Lft│Dwn│Rig│
    └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
    Note: For now, capitalised versions of è à ù need to be done with caps lock.
     
#### Dead Key 2 (umlaut accent)
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
    │MUT│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │MUT│
    └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
    │   │ │   │   │   │   │   │   │   │        │   │   │   │   │   │   │Bkspc  │ │PGU│
    ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
    │   │ │Tab  │   │ Ẅ │ Ë │   │ ẗ │        │ Ÿ │ Ü │ Ï │ Ö │   │   │   │  \  │ │PGD│
    ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
    │   │ │Caps  │ Ä │   │   │   │   │        │ Ḧ │   │   │   │ ; │   │    Ent │ │HOM│
    ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
    │   │ │Sft     │   │ Ẍ │   │   │   │        │   │   │   │   │   │Shift │ │Up │
    ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
    │   │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │Cmd│Fn1│Ctr│ │Lft│Dwn│Rig│
    └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
    Note: S(ẗ) does't work, it doesn't exist in the us intl keymap

#### WIN_BASE layer
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
    │ O │ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │ O │
    └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
    │M1 │ │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │        │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │ │PGU│
    ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
    │M2 │ │Tab  │ Q │ W │ E │ R │ T │        │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │PGD│
    ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
    │M3 │ │Caps  │ A │ S │ D │ F │ G │        │ H │ J │ K │ L │DK1│ ' │    Ent │ │HOM│
    ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
    │M4 │ │Sft     │ Z │ X │ C │ V │ B │        │ N │ M │ , │ . │ / │Shift │ │Up │
    ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
    │M5 │ │Ctrl│Win │ALT │ FN │Space   │        │Bkspc Del │ALG│Fn1│Ctr│ │Lft│Dwn│Rig│
    └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
     
#### WIN_FN (RGB and media control)
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
    │RGB│ │   │BR-│BR+│TSK│FXP│VA-│VA+│        │MU-│MUS│MU+│MUT│VO+│VO-│   │   │ │RGB│
    └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
    │   │ │   │   │   │   │   │   │   │        │   │   │   │   │   │   │       │ │   │
    ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
    │   │ │RGBtg│Mod│VA+│HU+│SA+│SP+│        │   │   │   │   │   │   │   │     │ │   │
    ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
    │   │ │      │Rmd│VA-│HU-│SA-│SP-│        │Lft│Dwn│Up │Rgt│   │   │        │ │   │
    ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
    │   │ │        │   │   │   │   │   │        │NKt│   │   │   │   │      │ │   │
    ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
    │   │ │    │    │    │    │        │        │          │   │   │   │ │   │   │   │
    └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘

#### INFO : ALT_GR (dev special chars)
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
    │ O │ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│Ins│Del│ │ O │
    └───┘ └───┴───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┴───┴───┘ └───┘
    ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
    │   │ │   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │        │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │ │PGU│
    ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘      ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤
    │   │ │Tab  │ @ │ < │ > │ $ │ % │        │ ^ │ & │ *×│ ' │ ` │   │   │     │ │PGD│
    ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐       └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
    │   │ │Caps  │ { │ ( │ ) │ } │ = │        │ \ │ +±│ - │ /÷│ " │   │    Ent │ │HOM│
    ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐      └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬─┬─┴─┼───┘
    │   │ │Sft     │ ~ │ [ │ ] │ _ │ # │        │ |¦│ ! │ ; │ : │ ? │Shift │ │Up │
    ├───┤ ├────┬───┴┬──┴─┬─┴──┬┴───┴───┤        ├───┴───┴──┬┴──┬┴──┬┴──┬─┬─┴─┼───┼───┐
    │   │ │Ctrl│GUI │CMD │ FN │Space   │        │Bkspc Del │ALT│Fn1│Ctr│ │Lft│Dwn│Rig│
    └───┘ └────┴────┴────┴────┴────────┘        └──────────┴───┴───┴───┘ └───┴───┴───┘
### Optimisations

Plans are made to evolve the keymap to use the split keyboard layout better
#### Done
+ There is no End key so a shortcut was added `Ctrl + Home` : `End`
+ Right space was replaced with Backspace
+ `Shift` + `backspace` : `Del`
+ in Fn layers, `left, down, up, right` is added on `h, j, k, l` location
#### Planned
+ make `shift + Space` output a non breaking space
+ add unicode inputs for chars not present in the us international keymap
## Currently known bugs
### exclamation on dead key
Using shift with the dead key doesn't currently supress the deadkey behavior (should type an exclamation mark as per the qwerty lafayette layout)
### Shifted grave accents
Using shift while typing grave accents gived out the wrong characters:
    - shifted `è` produces `Ẽ` instead of `È` 
    - shifted `ù` produces `Ũ` instead of `Ù`
    - shifted `à` produces `Ã` instead of `À`
    > it is still possible to type the correct character by using `Caps Lock` instead of `Shift`

