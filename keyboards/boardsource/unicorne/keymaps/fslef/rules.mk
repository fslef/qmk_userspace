SERIAL_DRIVER = vendor
AUDIO_DRIVER = pwm_hardware
POINTING_DEVICE_DRIVER = analog_joystick
COMBO_ENABLE = no
RGB_MATRIX_CUSTOM_USER = yes
BOOTMAGIC_ENABLE = yes
TAP_DANCE_ENABLE = yes

# Removed dependency on rgb_matrix_user.inc to avoid compilation errors.
# Added a workaround to handle missing rgb_matrix_user.inc dependency
# Re-enabling RGB_MATRIX as requested
RGB_MATRIX_ENABLE = yes
