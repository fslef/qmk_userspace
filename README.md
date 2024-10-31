# Guide to Setting Up and Compiling Custom QMK Firmware

## Prepare the Dev Environment
1. Run `qmk setup -H ~/gitrepos/fslef/qmk-firmware/` to set up the QMK environment (see [QMK Docs](https://docs.qmk.fm/#/newbs) for details).
2. Accept to clone the QMK_Firmware repo

## Build the Firmware
1. Run `qmk compile -kb boardsource/unicorne -km fslef`

## Flash the Firmware
1. Run `qmk flash -kb boardsource/unicorne -km fslef`
2. Put the keyboard in bootloader mode (check device-specific instructions) to proceed with flashing.

## Extra Info
Any commit to the repo triggers a GitHub Action that builds the firmware and pushes it to Releases.

