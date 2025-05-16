#ifndef CONNECTION_H
#define CONNECTION_H

#include "esp_event.h"

void initialize_mqtt(void);
void mqtt_app_start(void);
void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);
void log_error_if_nonzero(const char *message, int error_code);
void manda_mensagem(void);
void manda_mensagem_comando1(void);
void manda_mensagem_comando2(void);

#endif // CONNECTION_H
