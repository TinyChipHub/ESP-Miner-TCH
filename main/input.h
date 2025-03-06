#ifndef INPUT_H_
#define INPUT_H_

esp_err_t input_init(void (*button_short_clicked_cb)(void), void (*button_long_pressed_cb)(void));
esp_err_t display_input_init(void (*display_button_short_clicked_cb)(void), void (*display_button_long_pressed_cb)(void));

#endif /* INPUT_H_ */
