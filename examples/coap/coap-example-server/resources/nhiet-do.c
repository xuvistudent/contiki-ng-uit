/** 
 * \file
 *      Example of Posting resource.
 * \author
 *      Hoang Xuan Viet <hxv1305@gmail.com>
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coap-engine.h"

static void nhiet_do_post_handler(coap_message_t *request, coap_message_t *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);

RESOURCE(nhiet_do,
        "Title=\"Nhiet do cua phong khach\"",
        NULL,
        nhiet_do_post_handler,
        NULL,
        NULL);

static void nhiet_do_post_handler(coap_message_t *request, coap_message_t *reponse, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
    const uint8_t *nhiet_do = NULL;
    coap_get_payload(request, &nhiet_do);
    printf("\nNhiet do: %s", nhiet_do);
}