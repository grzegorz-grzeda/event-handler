/**
 * MIT License
 * Copyright (c) 2023 Grzegorz Grzęda
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "event_handler.h"
#include <stddef.h>

#ifndef EVENT_HANDLERS_MAX_HANDLERS_COUNT
#error "EVENT_HANDLERS_MAX_HANDLERS_COUNT not defined!"
#define EVENT_HANDLERS_MAX_HANDLERS_COUNT (0)
#endif

struct handler {
    event_handler_t handler;
    void *context;
    uint16_t id;
} handlers[EVENT_HANDLERS_MAX_HANDLERS_COUNT];

static size_t handlers_count = 0;

void register_event_handler(uint16_t id, void *context, event_handler_t handler)
{
    if (!handler || (handlers_count >= EVENT_HANDLERS_MAX_HANDLERS_COUNT)) {
        return;
    }
    handlers[handlers_count].handler = handler;
    handlers[handlers_count].context = context;
    handlers[handlers_count].id = id;
    handlers_count++;
}

void send_event_to_handlers(uint16_t id, void *payload)
{
    for (size_t i = 0; i < handlers_count; i++) {
        if (id == handlers[i].id) {
            handlers[i].handler(id, handlers[i].context, payload);
        }
    }
}