#include <stdlib.h>
#include <string.h>
#include "coap-engine.h"

static void res_get_handler(coap_message_t *request, coap_message_t *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);
static void res_post_handler(coap_message_t *request, coap_message_t *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);

RESOURCE(res_info,
        "title=\"Board info: CC2650\";rt=\"Text\"",
        res_get_handler,
        res_post_handler,
        NULL,
        NULL);

static void res_get_handler(coap_message_t *request, coap_message_t *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
        const char *len = NULL; 
        // char const *const message = "Node B - IP: fe80::212:4b00:f8e:2300";
        char const *const message = "Node C - IP: fe80::212:4b00:f82:8380";
        int length = 36;

        if (coap_get_query_variable(request, "len", &len)) {
                length = atoi(len);
                if(length < 0) {
                        length = 0;
                }
                if(length > REST_MAX_CHUNK_SIZE) {
                        length = REST_MAX_CHUNK_SIZE;
                }
                memcpy(buffer, message, length);
        } else {
                memcpy(buffer, message, length);
        }

        coap_set_header_content_format(response, TEXT_PLAIN);
        coap_set_header_etag(response, (uint8_t *)&length, 1);
        coap_set_payload(response, buffer, length);
}
