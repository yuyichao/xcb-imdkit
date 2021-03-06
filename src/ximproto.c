#include <string.h>
#include "ximproto.h"

void ximattr_fr_read(ximattr_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->attribute_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->type_of_the_value, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_im_attribute, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->im_attribute, frame->length_of_im_attribute, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* ximattr_fr_write(ximattr_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->attribute_ID, data, swap);
    data = uint16_t_write(&frame->type_of_the_value, data, swap);
    data = uint16_t_write(&frame->length_of_im_attribute, data, swap);
    data = bytearray_write(&frame->im_attribute, frame->length_of_im_attribute, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t ximattr_fr_size(ximattr_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += frame->length_of_im_attribute;
    size = align_to_4(size, size, NULL);
    return size;
}

void ximattr_fr_free(ximattr_fr *frame)
{
    free(frame->im_attribute);
}

void xicattr_fr_read(xicattr_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->attribute_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->type_of_the_value, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_ic_attribute, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->ic_attribute, frame->length_of_ic_attribute, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* xicattr_fr_write(xicattr_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->attribute_ID, data, swap);
    data = uint16_t_write(&frame->type_of_the_value, data, swap);
    data = uint16_t_write(&frame->length_of_ic_attribute, data, swap);
    data = bytearray_write(&frame->ic_attribute, frame->length_of_ic_attribute, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t xicattr_fr_size(xicattr_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += frame->length_of_ic_attribute;
    size = align_to_4(size, size, NULL);
    return size;
}

void xicattr_fr_free(xicattr_fr *frame)
{
    free(frame->ic_attribute);
}

void ximattribute_fr_read(ximattribute_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->attribute_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->value_length, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->value, frame->value_length, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* ximattribute_fr_write(ximattribute_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->attribute_ID, data, swap);
    data = uint16_t_write(&frame->value_length, data, swap);
    data = bytearray_write(&frame->value, frame->value_length, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t ximattribute_fr_size(ximattribute_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += frame->value_length;
    size = align_to_4(size, size, NULL);
    return size;
}

void ximattribute_fr_free(ximattribute_fr *frame)
{
    free(frame->value);
}

void xicattribute_fr_read(xicattribute_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->attribute_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->value_length, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->value, frame->value_length, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* xicattribute_fr_write(xicattribute_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->attribute_ID, data, swap);
    data = uint16_t_write(&frame->value_length, data, swap);
    data = bytearray_write(&frame->value, frame->value_length, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t xicattribute_fr_size(xicattribute_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += frame->value_length;
    size = align_to_4(size, size, NULL);
    return size;
}

void xicattribute_fr_free(xicattribute_fr *frame)
{
    free(frame->value);
}

void ximtriggerkey_fr_read(ximtriggerkey_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint32_t_read(&frame->keysym, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->modifier, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->modifier_mask, data, len, swap);
    if (!*data) { return; }
}

uint8_t* ximtriggerkey_fr_write(ximtriggerkey_fr *frame, uint8_t *data, bool swap)
{
    data = uint32_t_write(&frame->keysym, data, swap);
    data = uint32_t_write(&frame->modifier, data, swap);
    data = uint32_t_write(&frame->modifier_mask, data, swap);
    return data;
}

size_t ximtriggerkey_fr_size(ximtriggerkey_fr *frame)
{
    size_t size = 0;
    size += 4;
    size += 4;
    size += 4;
    return size;
}

void ximtriggerkey_fr_free(ximtriggerkey_fr *frame)
{
}

void encodinginfo_fr_read(encodinginfo_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->length_of_encoding_info, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->encoding_info, frame->length_of_encoding_info, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* encodinginfo_fr_write(encodinginfo_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->length_of_encoding_info, data, swap);
    data = bytearray_write(&frame->encoding_info, frame->length_of_encoding_info, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t encodinginfo_fr_size(encodinginfo_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += frame->length_of_encoding_info;
    size = align_to_4(size, size, NULL);
    return size;
}

void encodinginfo_fr_free(encodinginfo_fr *frame)
{
    free(frame->encoding_info);
}

void str_fr_read(str_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t_read(&frame->length_of_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->string, frame->length_of_string, data, len, swap);
    if (!*data) { return; }
}

uint8_t* str_fr_write(str_fr *frame, uint8_t *data, bool swap)
{
    data = uint8_t_write(&frame->length_of_string, data, swap);
    data = bytearray_write(&frame->string, frame->length_of_string, data, swap);
    return data;
}

size_t str_fr_size(str_fr *frame)
{
    size_t size = 0;
    size += 1;
    size += frame->length_of_string;
    return size;
}

void str_fr_free(str_fr *frame)
{
    free(frame->string);
}

void xpcs_fr_read(xpcs_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->length_of_string_in_bytes, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->string, frame->length_of_string_in_bytes, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* xpcs_fr_write(xpcs_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->length_of_string_in_bytes, data, swap);
    data = bytearray_write(&frame->string, frame->length_of_string_in_bytes, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t xpcs_fr_size(xpcs_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += frame->length_of_string_in_bytes;
    size = align_to_4(size, size, NULL);
    return size;
}

void xpcs_fr_free(xpcs_fr *frame)
{
    free(frame->string);
}

void ext_fr_read(ext_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->extension_major_opcode, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->extension_minor_opcode, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_extension_name, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->extension_name, frame->length_of_extension_name, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* ext_fr_write(ext_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->extension_major_opcode, data, swap);
    data = uint16_t_write(&frame->extension_minor_opcode, data, swap);
    data = uint16_t_write(&frame->length_of_extension_name, data, swap);
    data = bytearray_write(&frame->extension_name, frame->length_of_extension_name, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t ext_fr_size(ext_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += frame->length_of_extension_name;
    size = align_to_4(size, size, NULL);
    return size;
}

void ext_fr_free(ext_fr *frame)
{
    free(frame->extension_name);
}

void inputstyle_fr_read(inputstyle_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint32_t_read(&frame->inputstyle, data, len, swap);
    if (!*data) { return; }
}

uint8_t* inputstyle_fr_write(inputstyle_fr *frame, uint8_t *data, bool swap)
{
    data = uint32_t_write(&frame->inputstyle, data, swap);
    return data;
}

size_t inputstyle_fr_size(inputstyle_fr *frame)
{
    size_t size = 0;
    size += 4;
    return size;
}

void inputstyle_fr_free(inputstyle_fr *frame)
{
}

void attr_head_fr_read(attr_head_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->attribute_id, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->attribute_length, data, len, swap);
    if (!*data) { return; }
}

uint8_t* attr_head_fr_write(attr_head_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->attribute_id, data, swap);
    data = uint16_t_write(&frame->attribute_length, data, swap);
    return data;
}

size_t attr_head_fr_size(attr_head_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void attr_head_fr_free(attr_head_fr *frame)
{
}

void short_fr_read(short_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->value, data, len, swap);
    if (!*data) { return; }
}

uint8_t* short_fr_write(short_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->value, data, swap);
    return data;
}

size_t short_fr_size(short_fr *frame)
{
    size_t size = 0;
    size += 2;
    return size;
}

void short_fr_free(short_fr *frame)
{
}

void long_fr_read(long_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint32_t_read(&frame->value, data, len, swap);
    if (!*data) { return; }
}

uint8_t* long_fr_write(long_fr *frame, uint8_t *data, bool swap)
{
    data = uint32_t_write(&frame->value, data, swap);
    return data;
}

size_t long_fr_size(long_fr *frame)
{
    size_t size = 0;
    size += 4;
    return size;
}

void long_fr_free(long_fr *frame)
{
}

void xrectangle_fr_read(xrectangle_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->x, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->y, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->width, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->height, data, len, swap);
    if (!*data) { return; }
}

uint8_t* xrectangle_fr_write(xrectangle_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->x, data, swap);
    data = uint16_t_write(&frame->y, data, swap);
    data = uint16_t_write(&frame->width, data, swap);
    data = uint16_t_write(&frame->height, data, swap);
    return data;
}

size_t xrectangle_fr_size(xrectangle_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    return size;
}

void xrectangle_fr_free(xrectangle_fr *frame)
{
}

void xpoint_fr_read(xpoint_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->x, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->y, data, len, swap);
    if (!*data) { return; }
}

uint8_t* xpoint_fr_write(xpoint_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->x, data, swap);
    data = uint16_t_write(&frame->y, data, swap);
    return data;
}

size_t xpoint_fr_size(xpoint_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void xpoint_fr_free(xpoint_fr *frame)
{
}

void fontset_fr_read(fontset_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->length_of_base_font_name, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->base_font_name_list, frame->length_of_base_font_name, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* fontset_fr_write(fontset_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->length_of_base_font_name, data, swap);
    data = bytearray_write(&frame->base_font_name_list, frame->length_of_base_font_name, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t fontset_fr_size(fontset_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += frame->length_of_base_font_name;
    size = align_to_4(size, size, NULL);
    return size;
}

void fontset_fr_free(fontset_fr *frame)
{
    free(frame->base_font_name_list);
}

void input_styles_fr_read(input_styles_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->XIMStyle_list.items = NULL;
    frame->XIMStyle_list.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->XIMStyle_list.items, (frame->XIMStyle_list.size + 1) * sizeof(inputstyle_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->XIMStyle_list.items = temp;
        inputstyle_fr_read(&frame->XIMStyle_list.items[frame->XIMStyle_list.size], data, &counter, swap);
        if (!*data) { return; }
        frame->XIMStyle_list.size++;
    }
}

uint8_t* input_styles_fr_write(input_styles_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    counter16 = 0;
    for (uint32_t i = 0; i < frame->XIMStyle_list.size; i++) {
        counter16 += inputstyle_fr_size(&frame->XIMStyle_list.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->XIMStyle_list.size; i++) {
        data = inputstyle_fr_write(&frame->XIMStyle_list.items[i], data, swap);
    }
    return data;
}

size_t input_styles_fr_size(input_styles_fr *frame)
{
    size_t size = 0;
    size += 2;
    size = align_to_4(size, size, NULL);
    for (uint32_t i = 0; i < frame->XIMStyle_list.size; i++) {
        size += inputstyle_fr_size(&frame->XIMStyle_list.items[i]);
    }
    return size;
}

void input_styles_fr_free(input_styles_fr *frame)
{
    if (frame->XIMStyle_list.items) {
        for (uint32_t i = 0; i < frame->XIMStyle_list.size; i++) {
            inputstyle_fr_free(&frame->XIMStyle_list.items[i]);
        }
    }
    free(frame->XIMStyle_list.items);
}

void packet_header_fr_read(packet_header_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t_read(&frame->major_opcode, data, len, swap);
    if (!*data) { return; }
    uint8_t_read(&frame->minor_opcode, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length, data, len, swap);
    if (!*data) { return; }
}

uint8_t* packet_header_fr_write(packet_header_fr *frame, uint8_t *data, bool swap)
{
    data = uint8_t_write(&frame->major_opcode, data, swap);
    data = uint8_t_write(&frame->minor_opcode, data, swap);
    data = uint16_t_write(&frame->length, data, swap);
    return data;
}

size_t packet_header_fr_size(packet_header_fr *frame)
{
    size_t size = 0;
    size += 1;
    size += 1;
    size += 2;
    return size;
}

void packet_header_fr_free(packet_header_fr *frame)
{
}

void error_fr_read(error_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->flag, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->Error_Code, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_error_detail, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->type_of_error_detail, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->error_detail, frame->length_of_error_detail, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* error_fr_write(error_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->flag, data, swap);
    data = uint16_t_write(&frame->Error_Code, data, swap);
    data = uint16_t_write(&frame->length_of_error_detail, data, swap);
    data = uint16_t_write(&frame->type_of_error_detail, data, swap);
    data = bytearray_write(&frame->error_detail, frame->length_of_error_detail, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t error_fr_size(error_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    size += frame->length_of_error_detail;
    size = align_to_4(size, size, NULL);
    return size;
}

void error_fr_free(error_fr *frame)
{
    free(frame->error_detail);
}

void connect_fr_read(connect_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint8_t_read(&frame->byte_order, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_2((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint16_t_read(&frame->client_major_protocol_version, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->client_minor_protocol_version, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->client_auth_protocol_names.items = NULL;
    frame->client_auth_protocol_names.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->client_auth_protocol_names.items, (frame->client_auth_protocol_names.size + 1) * sizeof(xpcs_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->client_auth_protocol_names.items = temp;
        xpcs_fr_read(&frame->client_auth_protocol_names.items[frame->client_auth_protocol_names.size], data, &counter, swap);
        if (!*data) { return; }
        frame->client_auth_protocol_names.size++;
    }
}

uint8_t* connect_fr_write(connect_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint8_t_write(&frame->byte_order, data, swap);
    data = (uint8_t*) align_to_2((uintptr_t) data, data - start, NULL);
    data = uint16_t_write(&frame->client_major_protocol_version, data, swap);
    data = uint16_t_write(&frame->client_minor_protocol_version, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->client_auth_protocol_names.size; i++) {
        counter16 += xpcs_fr_size(&frame->client_auth_protocol_names.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->client_auth_protocol_names.size; i++) {
        data = xpcs_fr_write(&frame->client_auth_protocol_names.items[i], data, swap);
    }
    return data;
}

size_t connect_fr_size(connect_fr *frame)
{
    size_t size = 0;
    size += 1;
    size = align_to_2(size, size, NULL);
    size += 2;
    size += 2;
    size += 2;
    for (uint32_t i = 0; i < frame->client_auth_protocol_names.size; i++) {
        size += xpcs_fr_size(&frame->client_auth_protocol_names.items[i]);
    }
    return size;
}

void connect_fr_free(connect_fr *frame)
{
    if (frame->client_auth_protocol_names.items) {
        for (uint32_t i = 0; i < frame->client_auth_protocol_names.size; i++) {
            xpcs_fr_free(&frame->client_auth_protocol_names.items[i]);
        }
    }
    free(frame->client_auth_protocol_names.items);
}

void connect_reply_fr_read(connect_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->server_major_protocol_version, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->server_minor_protocol_version, data, len, swap);
    if (!*data) { return; }
}

uint8_t* connect_reply_fr_write(connect_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->server_major_protocol_version, data, swap);
    data = uint16_t_write(&frame->server_minor_protocol_version, data, swap);
    return data;
}

size_t connect_reply_fr_size(connect_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void connect_reply_fr_free(connect_reply_fr *frame)
{
}

void auth_required_fr_read(auth_required_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint8_t_read(&frame->auth_protocol_index, data, len, swap);
    if (!*data) { return; }
    uint8_t_read(&frame->auth_data1, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->auth_data2, frame->auth_data1, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* auth_required_fr_write(auth_required_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint8_t_write(&frame->auth_protocol_index, data, swap);
    data = uint8_t_write(&frame->auth_data1, data, swap);
    data = bytearray_write(&frame->auth_data2, frame->auth_data1, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t auth_required_fr_size(auth_required_fr *frame)
{
    size_t size = 0;
    size += 1;
    size += 1;
    size += frame->auth_data1;
    size = align_to_4(size, size, NULL);
    return size;
}

void auth_required_fr_free(auth_required_fr *frame)
{
    free(frame->auth_data2);
}

void auth_reply_fr_read(auth_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint8_t_read(&frame->field0, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->field1, frame->field0, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* auth_reply_fr_write(auth_reply_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint8_t_write(&frame->field0, data, swap);
    data = bytearray_write(&frame->field1, frame->field0, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t auth_reply_fr_size(auth_reply_fr *frame)
{
    size_t size = 0;
    size += 1;
    size += frame->field0;
    size = align_to_4(size, size, NULL);
    return size;
}

void auth_reply_fr_free(auth_reply_fr *frame)
{
    free(frame->field1);
}

void auth_next_fr_read(auth_next_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint8_t_read(&frame->auth_data1, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->auth_data2, frame->auth_data1, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* auth_next_fr_write(auth_next_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint8_t_write(&frame->auth_data1, data, swap);
    data = bytearray_write(&frame->auth_data2, frame->auth_data1, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t auth_next_fr_size(auth_next_fr *frame)
{
    size_t size = 0;
    size += 1;
    size += frame->auth_data1;
    size = align_to_4(size, size, NULL);
    return size;
}

void auth_next_fr_free(auth_next_fr *frame)
{
    free(frame->auth_data2);
}

void auth_setup_fr_read(auth_setup_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->server_auth_protocol_names.items = NULL;
    frame->server_auth_protocol_names.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->server_auth_protocol_names.items, (frame->server_auth_protocol_names.size + 1) * sizeof(xpcs_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->server_auth_protocol_names.items = temp;
        xpcs_fr_read(&frame->server_auth_protocol_names.items[frame->server_auth_protocol_names.size], data, &counter, swap);
        if (!*data) { return; }
        frame->server_auth_protocol_names.size++;
    }
}

uint8_t* auth_setup_fr_write(auth_setup_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    counter16 = 0;
    for (uint32_t i = 0; i < frame->server_auth_protocol_names.size; i++) {
        counter16 += xpcs_fr_size(&frame->server_auth_protocol_names.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->server_auth_protocol_names.size; i++) {
        data = xpcs_fr_write(&frame->server_auth_protocol_names.items[i], data, swap);
    }
    return data;
}

size_t auth_setup_fr_size(auth_setup_fr *frame)
{
    size_t size = 0;
    size += 2;
    size = align_to_4(size, size, NULL);
    for (uint32_t i = 0; i < frame->server_auth_protocol_names.size; i++) {
        size += xpcs_fr_size(&frame->server_auth_protocol_names.items[i]);
    }
    return size;
}

void auth_setup_fr_free(auth_setup_fr *frame)
{
    if (frame->server_auth_protocol_names.items) {
        for (uint32_t i = 0; i < frame->server_auth_protocol_names.size; i++) {
            xpcs_fr_free(&frame->server_auth_protocol_names.items[i]);
        }
    }
    free(frame->server_auth_protocol_names.items);
}

void auth_ng_fr_read(auth_ng_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
}

uint8_t* auth_ng_fr_write(auth_ng_fr *frame, uint8_t *data, bool swap)
{
    return data;
}

size_t auth_ng_fr_size(auth_ng_fr *frame)
{
    size_t size = 0;
    return size;
}

void auth_ng_fr_free(auth_ng_fr *frame)
{
}

void disconnect_fr_read(disconnect_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
}

uint8_t* disconnect_fr_write(disconnect_fr *frame, uint8_t *data, bool swap)
{
    return data;
}

size_t disconnect_fr_size(disconnect_fr *frame)
{
    size_t size = 0;
    return size;
}

void disconnect_fr_free(disconnect_fr *frame)
{
}

void disconnect_reply_fr_read(disconnect_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
}

uint8_t* disconnect_reply_fr_write(disconnect_reply_fr *frame, uint8_t *data, bool swap)
{
    return data;
}

size_t disconnect_reply_fr_size(disconnect_reply_fr *frame)
{
    size_t size = 0;
    return size;
}

void disconnect_reply_fr_free(disconnect_reply_fr *frame)
{
}

void open_fr_read(open_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    str_fr_read(&frame->field0, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* open_fr_write(open_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = str_fr_write(&frame->field0, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t open_fr_size(open_fr *frame)
{
    size_t size = 0;
    size = align_to_4(size, size, NULL);
    return size;
}

void open_fr_free(open_fr *frame)
{
    str_fr_free(&frame->field0);
}

void open_reply_fr_read(open_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->IM_attribute_supported.items = NULL;
    frame->IM_attribute_supported.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->IM_attribute_supported.items, (frame->IM_attribute_supported.size + 1) * sizeof(ximattr_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->IM_attribute_supported.items = temp;
        ximattr_fr_read(&frame->IM_attribute_supported.items[frame->IM_attribute_supported.size], data, &counter, swap);
        if (!*data) { return; }
        frame->IM_attribute_supported.size++;
    }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->IC_attribute_supported.items = NULL;
    frame->IC_attribute_supported.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->IC_attribute_supported.items, (frame->IC_attribute_supported.size + 1) * sizeof(xicattr_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->IC_attribute_supported.items = temp;
        xicattr_fr_read(&frame->IC_attribute_supported.items[frame->IC_attribute_supported.size], data, &counter, swap);
        if (!*data) { return; }
        frame->IC_attribute_supported.size++;
    }
}

uint8_t* open_reply_fr_write(open_reply_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->IM_attribute_supported.size; i++) {
        counter16 += ximattr_fr_size(&frame->IM_attribute_supported.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->IM_attribute_supported.size; i++) {
        data = ximattr_fr_write(&frame->IM_attribute_supported.items[i], data, swap);
    }
    counter16 = 0;
    for (uint32_t i = 0; i < frame->IC_attribute_supported.size; i++) {
        counter16 += xicattr_fr_size(&frame->IC_attribute_supported.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->IC_attribute_supported.size; i++) {
        data = xicattr_fr_write(&frame->IC_attribute_supported.items[i], data, swap);
    }
    return data;
}

size_t open_reply_fr_size(open_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    for (uint32_t i = 0; i < frame->IM_attribute_supported.size; i++) {
        size += ximattr_fr_size(&frame->IM_attribute_supported.items[i]);
    }
    size += 2;
    size = align_to_4(size, size, NULL);
    for (uint32_t i = 0; i < frame->IC_attribute_supported.size; i++) {
        size += xicattr_fr_size(&frame->IC_attribute_supported.items[i]);
    }
    return size;
}

void open_reply_fr_free(open_reply_fr *frame)
{
    if (frame->IM_attribute_supported.items) {
        for (uint32_t i = 0; i < frame->IM_attribute_supported.size; i++) {
            ximattr_fr_free(&frame->IM_attribute_supported.items[i]);
        }
    }
    free(frame->IM_attribute_supported.items);
    if (frame->IC_attribute_supported.items) {
        for (uint32_t i = 0; i < frame->IC_attribute_supported.size; i++) {
            xicattr_fr_free(&frame->IC_attribute_supported.items[i]);
        }
    }
    free(frame->IC_attribute_supported.items);
}

void close_fr_read(close_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* close_fr_write(close_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t close_fr_size(close_fr *frame)
{
    size_t size = 0;
    size += 2;
    size = align_to_4(size, size, NULL);
    return size;
}

void close_fr_free(close_fr *frame)
{
}

void close_reply_fr_read(close_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* close_reply_fr_write(close_reply_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t close_reply_fr_size(close_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size = align_to_4(size, size, NULL);
    return size;
}

void close_reply_fr_free(close_reply_fr *frame)
{
}

void register_triggerkeys_fr_read(register_triggerkeys_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint32_t counter32 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint32_t_read(&counter32, data, len, swap);
    if (!*data) { return; }
    counter = counter32;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->on_keys_list.items = NULL;
    frame->on_keys_list.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->on_keys_list.items, (frame->on_keys_list.size + 1) * sizeof(ximtriggerkey_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->on_keys_list.items = temp;
        ximtriggerkey_fr_read(&frame->on_keys_list.items[frame->on_keys_list.size], data, &counter, swap);
        if (!*data) { return; }
        frame->on_keys_list.size++;
    }
    uint32_t_read(&counter32, data, len, swap);
    if (!*data) { return; }
    counter = counter32;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->off_keys_list.items = NULL;
    frame->off_keys_list.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->off_keys_list.items, (frame->off_keys_list.size + 1) * sizeof(ximtriggerkey_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->off_keys_list.items = temp;
        ximtriggerkey_fr_read(&frame->off_keys_list.items[frame->off_keys_list.size], data, &counter, swap);
        if (!*data) { return; }
        frame->off_keys_list.size++;
    }
}

uint8_t* register_triggerkeys_fr_write(register_triggerkeys_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint32_t counter = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    counter = 0;
    for (uint32_t i = 0; i < frame->on_keys_list.size; i++) {
        counter += ximtriggerkey_fr_size(&frame->on_keys_list.items[i]);
    }
    data = uint32_t_write(&counter, data, swap);
    for (uint32_t i = 0; i < frame->on_keys_list.size; i++) {
        data = ximtriggerkey_fr_write(&frame->on_keys_list.items[i], data, swap);
    }
    counter = 0;
    for (uint32_t i = 0; i < frame->off_keys_list.size; i++) {
        counter += ximtriggerkey_fr_size(&frame->off_keys_list.items[i]);
    }
    data = uint32_t_write(&counter, data, swap);
    for (uint32_t i = 0; i < frame->off_keys_list.size; i++) {
        data = ximtriggerkey_fr_write(&frame->off_keys_list.items[i], data, swap);
    }
    return data;
}

size_t register_triggerkeys_fr_size(register_triggerkeys_fr *frame)
{
    size_t size = 0;
    size += 2;
    size = align_to_4(size, size, NULL);
    size += 4;
    for (uint32_t i = 0; i < frame->on_keys_list.size; i++) {
        size += ximtriggerkey_fr_size(&frame->on_keys_list.items[i]);
    }
    size += 4;
    for (uint32_t i = 0; i < frame->off_keys_list.size; i++) {
        size += ximtriggerkey_fr_size(&frame->off_keys_list.items[i]);
    }
    return size;
}

void register_triggerkeys_fr_free(register_triggerkeys_fr *frame)
{
    if (frame->on_keys_list.items) {
        for (uint32_t i = 0; i < frame->on_keys_list.size; i++) {
            ximtriggerkey_fr_free(&frame->on_keys_list.items[i]);
        }
    }
    free(frame->on_keys_list.items);
    if (frame->off_keys_list.items) {
        for (uint32_t i = 0; i < frame->off_keys_list.size; i++) {
            ximtriggerkey_fr_free(&frame->off_keys_list.items[i]);
        }
    }
    free(frame->off_keys_list.items);
}

void trigger_notify_fr_read(trigger_notify_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_mehotd_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->flag, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->index_of_keys_list, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->client_select_event_mask, data, len, swap);
    if (!*data) { return; }
}

uint8_t* trigger_notify_fr_write(trigger_notify_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_mehotd_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->flag, data, swap);
    data = uint32_t_write(&frame->index_of_keys_list, data, swap);
    data = uint32_t_write(&frame->client_select_event_mask, data, swap);
    return data;
}

size_t trigger_notify_fr_size(trigger_notify_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    size += 4;
    return size;
}

void trigger_notify_fr_free(trigger_notify_fr *frame)
{
}

void trigger_notify_reply_fr_read(trigger_notify_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* trigger_notify_reply_fr_write(trigger_notify_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t trigger_notify_reply_fr_size(trigger_notify_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void trigger_notify_reply_fr_free(trigger_notify_reply_fr *frame)
{
}

void set_event_mask_fr_read(set_event_mask_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->forward_event_mask, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->synchronous_event_mask, data, len, swap);
    if (!*data) { return; }
}

uint8_t* set_event_mask_fr_write(set_event_mask_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->forward_event_mask, data, swap);
    data = uint32_t_write(&frame->synchronous_event_mask, data, swap);
    return data;
}

size_t set_event_mask_fr_size(set_event_mask_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    return size;
}

void set_event_mask_fr_free(set_event_mask_fr *frame)
{
}

void encoding_negotiation_fr_read(encoding_negotiation_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->supported_list_of_encoding_in_IM_library.items = NULL;
    frame->supported_list_of_encoding_in_IM_library.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->supported_list_of_encoding_in_IM_library.items, (frame->supported_list_of_encoding_in_IM_library.size + 1) * sizeof(str_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->supported_list_of_encoding_in_IM_library.items = temp;
        str_fr_read(&frame->supported_list_of_encoding_in_IM_library.items[frame->supported_list_of_encoding_in_IM_library.size], data, &counter, swap);
        if (!*data) { return; }
        frame->supported_list_of_encoding_in_IM_library.size++;
    }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->list_of_encodings_supported_in_th.items = NULL;
    frame->list_of_encodings_supported_in_th.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->list_of_encodings_supported_in_th.items, (frame->list_of_encodings_supported_in_th.size + 1) * sizeof(encodinginfo_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->list_of_encodings_supported_in_th.items = temp;
        encodinginfo_fr_read(&frame->list_of_encodings_supported_in_th.items[frame->list_of_encodings_supported_in_th.size], data, &counter, swap);
        if (!*data) { return; }
        frame->list_of_encodings_supported_in_th.size++;
    }
}

uint8_t* encoding_negotiation_fr_write(encoding_negotiation_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->supported_list_of_encoding_in_IM_library.size; i++) {
        counter16 += str_fr_size(&frame->supported_list_of_encoding_in_IM_library.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->supported_list_of_encoding_in_IM_library.size; i++) {
        data = str_fr_write(&frame->supported_list_of_encoding_in_IM_library.items[i], data, swap);
    }
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->list_of_encodings_supported_in_th.size; i++) {
        counter16 += encodinginfo_fr_size(&frame->list_of_encodings_supported_in_th.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->list_of_encodings_supported_in_th.size; i++) {
        data = encodinginfo_fr_write(&frame->list_of_encodings_supported_in_th.items[i], data, swap);
    }
    return data;
}

size_t encoding_negotiation_fr_size(encoding_negotiation_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    for (uint32_t i = 0; i < frame->supported_list_of_encoding_in_IM_library.size; i++) {
        size += str_fr_size(&frame->supported_list_of_encoding_in_IM_library.items[i]);
    }
    size = align_to_4(size, size, NULL);
    size += 2;
    size = align_to_4(size, size, NULL);
    for (uint32_t i = 0; i < frame->list_of_encodings_supported_in_th.size; i++) {
        size += encodinginfo_fr_size(&frame->list_of_encodings_supported_in_th.items[i]);
    }
    return size;
}

void encoding_negotiation_fr_free(encoding_negotiation_fr *frame)
{
    if (frame->supported_list_of_encoding_in_IM_library.items) {
        for (uint32_t i = 0; i < frame->supported_list_of_encoding_in_IM_library.size; i++) {
            str_fr_free(&frame->supported_list_of_encoding_in_IM_library.items[i]);
        }
    }
    free(frame->supported_list_of_encoding_in_IM_library.items);
    if (frame->list_of_encodings_supported_in_th.items) {
        for (uint32_t i = 0; i < frame->list_of_encodings_supported_in_th.size; i++) {
            encodinginfo_fr_free(&frame->list_of_encodings_supported_in_th.items[i]);
        }
    }
    free(frame->list_of_encodings_supported_in_th.items);
}

void encoding_negotiation_reply_fr_read(encoding_negotiation_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->category_of_the_encoding_determined, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->index_of_the_encoding_dterminated, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* encoding_negotiation_reply_fr_write(encoding_negotiation_reply_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->category_of_the_encoding_determined, data, swap);
    data = uint16_t_write(&frame->index_of_the_encoding_dterminated, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t encoding_negotiation_reply_fr_size(encoding_negotiation_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size = align_to_4(size, size, NULL);
    return size;
}

void encoding_negotiation_reply_fr_free(encoding_negotiation_reply_fr *frame)
{
}

void query_extension_fr_read(query_extension_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->extensions_supported_by_the_IM_library.items = NULL;
    frame->extensions_supported_by_the_IM_library.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->extensions_supported_by_the_IM_library.items, (frame->extensions_supported_by_the_IM_library.size + 1) * sizeof(str_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->extensions_supported_by_the_IM_library.items = temp;
        str_fr_read(&frame->extensions_supported_by_the_IM_library.items[frame->extensions_supported_by_the_IM_library.size], data, &counter, swap);
        if (!*data) { return; }
        frame->extensions_supported_by_the_IM_library.size++;
    }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* query_extension_fr_write(query_extension_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->extensions_supported_by_the_IM_library.size; i++) {
        counter16 += str_fr_size(&frame->extensions_supported_by_the_IM_library.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->extensions_supported_by_the_IM_library.size; i++) {
        data = str_fr_write(&frame->extensions_supported_by_the_IM_library.items[i], data, swap);
    }
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t query_extension_fr_size(query_extension_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    for (uint32_t i = 0; i < frame->extensions_supported_by_the_IM_library.size; i++) {
        size += str_fr_size(&frame->extensions_supported_by_the_IM_library.items[i]);
    }
    size = align_to_4(size, size, NULL);
    return size;
}

void query_extension_fr_free(query_extension_fr *frame)
{
    if (frame->extensions_supported_by_the_IM_library.items) {
        for (uint32_t i = 0; i < frame->extensions_supported_by_the_IM_library.size; i++) {
            str_fr_free(&frame->extensions_supported_by_the_IM_library.items[i]);
        }
    }
    free(frame->extensions_supported_by_the_IM_library.items);
}

void query_extension_reply_fr_read(query_extension_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->list_of_extensions_supported_by_th.items = NULL;
    frame->list_of_extensions_supported_by_th.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->list_of_extensions_supported_by_th.items, (frame->list_of_extensions_supported_by_th.size + 1) * sizeof(ext_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->list_of_extensions_supported_by_th.items = temp;
        ext_fr_read(&frame->list_of_extensions_supported_by_th.items[frame->list_of_extensions_supported_by_th.size], data, &counter, swap);
        if (!*data) { return; }
        frame->list_of_extensions_supported_by_th.size++;
    }
}

uint8_t* query_extension_reply_fr_write(query_extension_reply_fr *frame, uint8_t *data, bool swap)
{
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->list_of_extensions_supported_by_th.size; i++) {
        counter16 += ext_fr_size(&frame->list_of_extensions_supported_by_th.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->list_of_extensions_supported_by_th.size; i++) {
        data = ext_fr_write(&frame->list_of_extensions_supported_by_th.items[i], data, swap);
    }
    return data;
}

size_t query_extension_reply_fr_size(query_extension_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    for (uint32_t i = 0; i < frame->list_of_extensions_supported_by_th.size; i++) {
        size += ext_fr_size(&frame->list_of_extensions_supported_by_th.items[i]);
    }
    return size;
}

void query_extension_reply_fr_free(query_extension_reply_fr *frame)
{
    if (frame->list_of_extensions_supported_by_th.items) {
        for (uint32_t i = 0; i < frame->list_of_extensions_supported_by_th.size; i++) {
            ext_fr_free(&frame->list_of_extensions_supported_by_th.items[i]);
        }
    }
    free(frame->list_of_extensions_supported_by_th.items);
}

void get_im_values_fr_read(get_im_values_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->im_attribute_id.items = NULL;
    frame->im_attribute_id.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->im_attribute_id.items, (frame->im_attribute_id.size + 1) * sizeof(uint16_t));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->im_attribute_id.items = temp;
        uint16_t_read(&frame->im_attribute_id.items[frame->im_attribute_id.size], data, &counter, swap);
        if (!*data) { return; }
        frame->im_attribute_id.size++;
    }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* get_im_values_fr_write(get_im_values_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    counter16 = frame->im_attribute_id.size * 2;
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->im_attribute_id.size; i++) {
        data = uint16_t_write(&frame->im_attribute_id.items[i], data, swap);
    }
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t get_im_values_fr_size(get_im_values_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += frame->im_attribute_id.size * 2;
    size = align_to_4(size, size, NULL);
    return size;
}

void get_im_values_fr_free(get_im_values_fr *frame)
{
    free(frame->im_attribute_id.items);
}

void get_im_values_reply_fr_read(get_im_values_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->im_attribute_returned.items = NULL;
    frame->im_attribute_returned.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->im_attribute_returned.items, (frame->im_attribute_returned.size + 1) * sizeof(ximattribute_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->im_attribute_returned.items = temp;
        ximattribute_fr_read(&frame->im_attribute_returned.items[frame->im_attribute_returned.size], data, &counter, swap);
        if (!*data) { return; }
        frame->im_attribute_returned.size++;
    }
}

uint8_t* get_im_values_reply_fr_write(get_im_values_reply_fr *frame, uint8_t *data, bool swap)
{
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->im_attribute_returned.size; i++) {
        counter16 += ximattribute_fr_size(&frame->im_attribute_returned.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->im_attribute_returned.size; i++) {
        data = ximattribute_fr_write(&frame->im_attribute_returned.items[i], data, swap);
    }
    return data;
}

size_t get_im_values_reply_fr_size(get_im_values_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    for (uint32_t i = 0; i < frame->im_attribute_returned.size; i++) {
        size += ximattribute_fr_size(&frame->im_attribute_returned.items[i]);
    }
    return size;
}

void get_im_values_reply_fr_free(get_im_values_reply_fr *frame)
{
    if (frame->im_attribute_returned.items) {
        for (uint32_t i = 0; i < frame->im_attribute_returned.size; i++) {
            ximattribute_fr_free(&frame->im_attribute_returned.items[i]);
        }
    }
    free(frame->im_attribute_returned.items);
}

void create_ic_fr_read(create_ic_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->ic_attributes.items = NULL;
    frame->ic_attributes.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->ic_attributes.items, (frame->ic_attributes.size + 1) * sizeof(xicattribute_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->ic_attributes.items = temp;
        xicattribute_fr_read(&frame->ic_attributes.items[frame->ic_attributes.size], data, &counter, swap);
        if (!*data) { return; }
        frame->ic_attributes.size++;
    }
}

uint8_t* create_ic_fr_write(create_ic_fr *frame, uint8_t *data, bool swap)
{
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->ic_attributes.size; i++) {
        counter16 += xicattribute_fr_size(&frame->ic_attributes.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->ic_attributes.size; i++) {
        data = xicattribute_fr_write(&frame->ic_attributes.items[i], data, swap);
    }
    return data;
}

size_t create_ic_fr_size(create_ic_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    for (uint32_t i = 0; i < frame->ic_attributes.size; i++) {
        size += xicattribute_fr_size(&frame->ic_attributes.items[i]);
    }
    return size;
}

void create_ic_fr_free(create_ic_fr *frame)
{
    if (frame->ic_attributes.items) {
        for (uint32_t i = 0; i < frame->ic_attributes.size; i++) {
            xicattribute_fr_free(&frame->ic_attributes.items[i]);
        }
    }
    free(frame->ic_attributes.items);
}

void create_ic_reply_fr_read(create_ic_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* create_ic_reply_fr_write(create_ic_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t create_ic_reply_fr_size(create_ic_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void create_ic_reply_fr_free(create_ic_reply_fr *frame)
{
}

void destroy_ic_fr_read(destroy_ic_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* destroy_ic_fr_write(destroy_ic_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t destroy_ic_fr_size(destroy_ic_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void destroy_ic_fr_free(destroy_ic_fr *frame)
{
}

void destroy_ic_reply_fr_read(destroy_ic_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* destroy_ic_reply_fr_write(destroy_ic_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t destroy_ic_reply_fr_size(destroy_ic_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void destroy_ic_reply_fr_free(destroy_ic_reply_fr *frame)
{
}

void set_ic_values_fr_read(set_ic_values_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->ic_attribute.items = NULL;
    frame->ic_attribute.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->ic_attribute.items, (frame->ic_attribute.size + 1) * sizeof(xicattribute_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->ic_attribute.items = temp;
        xicattribute_fr_read(&frame->ic_attribute.items[frame->ic_attribute.size], data, &counter, swap);
        if (!*data) { return; }
        frame->ic_attribute.size++;
    }
}

uint8_t* set_ic_values_fr_write(set_ic_values_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
        counter16 += xicattribute_fr_size(&frame->ic_attribute.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
        data = xicattribute_fr_write(&frame->ic_attribute.items[i], data, swap);
    }
    return data;
}

size_t set_ic_values_fr_size(set_ic_values_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size = align_to_4(size, size, NULL);
    for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
        size += xicattribute_fr_size(&frame->ic_attribute.items[i]);
    }
    return size;
}

void set_ic_values_fr_free(set_ic_values_fr *frame)
{
    if (frame->ic_attribute.items) {
        for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
            xicattribute_fr_free(&frame->ic_attribute.items[i]);
        }
    }
    free(frame->ic_attribute.items);
}

void set_ic_values_reply_fr_read(set_ic_values_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* set_ic_values_reply_fr_write(set_ic_values_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t set_ic_values_reply_fr_size(set_ic_values_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void set_ic_values_reply_fr_free(set_ic_values_reply_fr *frame)
{
}

void get_ic_values_fr_read(get_ic_values_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->ic_attribute.items = NULL;
    frame->ic_attribute.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->ic_attribute.items, (frame->ic_attribute.size + 1) * sizeof(uint16_t));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->ic_attribute.items = temp;
        uint16_t_read(&frame->ic_attribute.items[frame->ic_attribute.size], data, &counter, swap);
        if (!*data) { return; }
        frame->ic_attribute.size++;
    }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* get_ic_values_fr_write(get_ic_values_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    counter16 = frame->ic_attribute.size * 2;
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
        data = uint16_t_write(&frame->ic_attribute.items[i], data, swap);
    }
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t get_ic_values_fr_size(get_ic_values_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += frame->ic_attribute.size * 2;
    size = align_to_4(size, size, NULL);
    return size;
}

void get_ic_values_fr_free(get_ic_values_fr *frame)
{
    free(frame->ic_attribute.items);
}

void get_ic_values_reply_fr_read(get_ic_values_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->ic_attribute.items = NULL;
    frame->ic_attribute.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->ic_attribute.items, (frame->ic_attribute.size + 1) * sizeof(xicattribute_fr));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->ic_attribute.items = temp;
        xicattribute_fr_read(&frame->ic_attribute.items[frame->ic_attribute.size], data, &counter, swap);
        if (!*data) { return; }
        frame->ic_attribute.size++;
    }
}

uint8_t* get_ic_values_reply_fr_write(get_ic_values_reply_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    counter16 = 0;
    for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
        counter16 += xicattribute_fr_size(&frame->ic_attribute.items[i]);
    }
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
        data = xicattribute_fr_write(&frame->ic_attribute.items[i], data, swap);
    }
    return data;
}

size_t get_ic_values_reply_fr_size(get_ic_values_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size = align_to_4(size, size, NULL);
    for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
        size += xicattribute_fr_size(&frame->ic_attribute.items[i]);
    }
    return size;
}

void get_ic_values_reply_fr_free(get_ic_values_reply_fr *frame)
{
    if (frame->ic_attribute.items) {
        for (uint32_t i = 0; i < frame->ic_attribute.size; i++) {
            xicattribute_fr_free(&frame->ic_attribute.items[i]);
        }
    }
    free(frame->ic_attribute.items);
}

void set_ic_focus_fr_read(set_ic_focus_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* set_ic_focus_fr_write(set_ic_focus_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t set_ic_focus_fr_size(set_ic_focus_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void set_ic_focus_fr_free(set_ic_focus_fr *frame)
{
}

void unset_ic_focus_fr_read(unset_ic_focus_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* unset_ic_focus_fr_write(unset_ic_focus_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t unset_ic_focus_fr_size(unset_ic_focus_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void unset_ic_focus_fr_free(unset_ic_focus_fr *frame)
{
}

void forward_event_fr_read(forward_event_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->flag, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->sequence_number, data, len, swap);
    if (!*data) { return; }
}

uint8_t* forward_event_fr_write(forward_event_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->flag, data, swap);
    data = uint16_t_write(&frame->sequence_number, data, swap);
    return data;
}

size_t forward_event_fr_size(forward_event_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    return size;
}

void forward_event_fr_free(forward_event_fr *frame)
{
}

void sync_fr_read(sync_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* sync_fr_write(sync_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t sync_fr_size(sync_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void sync_fr_free(sync_fr *frame)
{
}

void sync_reply_fr_read(sync_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* sync_reply_fr_write(sync_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t sync_reply_fr_size(sync_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void sync_reply_fr_free(sync_reply_fr *frame)
{
}

void commit_fr_read(commit_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->flag, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->committed_string, frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->keysym.items = NULL;
    frame->keysym.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->keysym.items, (frame->keysym.size + 1) * sizeof(uint32_t));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->keysym.items = temp;
        uint32_t_read(&frame->keysym.items[frame->keysym.size], data, &counter, swap);
        if (!*data) { return; }
        frame->keysym.size++;
    }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* commit_fr_write(commit_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->flag, data, swap);
    data = uint16_t_write(&frame->byte_length_of_committed_string, data, swap);
    data = bytearray_write(&frame->committed_string, frame->byte_length_of_committed_string, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    counter16 = frame->keysym.size * 4;
    data = uint16_t_write(&counter16, data, swap);
    for (uint32_t i = 0; i < frame->keysym.size; i++) {
        data = uint32_t_write(&frame->keysym.items[i], data, swap);
    }
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t commit_fr_size(commit_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    size += frame->byte_length_of_committed_string;
    size = align_to_4(size, size, NULL);
    size += 2;
    size += frame->keysym.size * 4;
    size = align_to_4(size, size, NULL);
    return size;
}

void commit_fr_free(commit_fr *frame)
{
    free(frame->committed_string);
    free(frame->keysym.items);
}

void commit_chars_fr_read(commit_chars_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->flag, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->committed_string, frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* commit_chars_fr_write(commit_chars_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->flag, data, swap);
    data = uint16_t_write(&frame->byte_length_of_committed_string, data, swap);
    data = bytearray_write(&frame->committed_string, frame->byte_length_of_committed_string, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t commit_chars_fr_size(commit_chars_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    size += frame->byte_length_of_committed_string;
    size = align_to_4(size, size, NULL);
    return size;
}

void commit_chars_fr_free(commit_chars_fr *frame)
{
    free(frame->committed_string);
}

void commit_both_fr_read(commit_both_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->flag, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint32_t_read(&frame->keysym, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->committed_string, frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* commit_both_fr_write(commit_both_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->flag, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    data = uint32_t_write(&frame->keysym, data, swap);
    data = uint16_t_write(&frame->byte_length_of_committed_string, data, swap);
    data = bytearray_write(&frame->committed_string, frame->byte_length_of_committed_string, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t commit_both_fr_size(commit_both_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size = align_to_4(size, size, NULL);
    size += 4;
    size += 2;
    size += frame->byte_length_of_committed_string;
    size = align_to_4(size, size, NULL);
    return size;
}

void commit_both_fr_free(commit_both_fr *frame)
{
    free(frame->committed_string);
}

void reset_ic_fr_read(reset_ic_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* reset_ic_fr_write(reset_ic_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t reset_ic_fr_size(reset_ic_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void reset_ic_fr_free(reset_ic_fr *frame)
{
}

void reset_ic_reply_fr_read(reset_ic_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->committed_string, frame->byte_length_of_committed_string, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* reset_ic_reply_fr_write(reset_ic_reply_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->byte_length_of_committed_string, data, swap);
    data = bytearray_write(&frame->committed_string, frame->byte_length_of_committed_string, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t reset_ic_reply_fr_size(reset_ic_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += frame->byte_length_of_committed_string;
    size = align_to_4(size, size, NULL);
    return size;
}

void reset_ic_reply_fr_free(reset_ic_reply_fr *frame)
{
    free(frame->committed_string);
}

void geometry_fr_read(geometry_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* geometry_fr_write(geometry_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t geometry_fr_size(geometry_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void geometry_fr_free(geometry_fr *frame)
{
}

void str_conversion_fr_read(str_conversion_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->XIMStringConversionPosition, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->XIMStringConversionType, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->XIMStringConversionOperation, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_to_multiply_th, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_the_string_to_b, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->string, frame->length_of_the_string_to_b, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
}

uint8_t* str_conversion_fr_write(str_conversion_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->XIMStringConversionPosition, data, swap);
    data = uint32_t_write(&frame->XIMStringConversionType, data, swap);
    data = uint32_t_write(&frame->XIMStringConversionOperation, data, swap);
    data = uint16_t_write(&frame->length_to_multiply_th, data, swap);
    data = uint16_t_write(&frame->length_of_the_string_to_b, data, swap);
    data = bytearray_write(&frame->string, frame->length_of_the_string_to_b, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    return data;
}

size_t str_conversion_fr_size(str_conversion_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    size += 4;
    size += 2;
    size += 2;
    size += frame->length_of_the_string_to_b;
    size = align_to_4(size, size, NULL);
    return size;
}

void str_conversion_fr_free(str_conversion_fr *frame)
{
    free(frame->string);
}

void str_conversion_reply_fr_read(str_conversion_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->XIMStringConversionFeedback, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_the_retrieved_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->retrieved_string, frame->length_of_the_retrieved_string, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->feedback_array.items = NULL;
    frame->feedback_array.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->feedback_array.items, (frame->feedback_array.size + 1) * sizeof(uint32_t));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->feedback_array.items = temp;
        uint32_t_read(&frame->feedback_array.items[frame->feedback_array.size], data, &counter, swap);
        if (!*data) { return; }
        frame->feedback_array.size++;
    }
}

uint8_t* str_conversion_reply_fr_write(str_conversion_reply_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->XIMStringConversionFeedback, data, swap);
    data = uint16_t_write(&frame->length_of_the_retrieved_string, data, swap);
    data = bytearray_write(&frame->retrieved_string, frame->length_of_the_retrieved_string, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    counter16 = frame->feedback_array.size * 4;
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->feedback_array.size; i++) {
        data = uint32_t_write(&frame->feedback_array.items[i], data, swap);
    }
    return data;
}

size_t str_conversion_reply_fr_size(str_conversion_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 2;
    size += frame->length_of_the_retrieved_string;
    size = align_to_4(size, size, NULL);
    size += 2;
    size = align_to_4(size, size, NULL);
    size += frame->feedback_array.size * 4;
    return size;
}

void str_conversion_reply_fr_free(str_conversion_reply_fr *frame)
{
    free(frame->retrieved_string);
    free(frame->feedback_array.items);
}

void preedit_start_fr_read(preedit_start_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* preedit_start_fr_write(preedit_start_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t preedit_start_fr_size(preedit_start_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void preedit_start_fr_free(preedit_start_fr *frame)
{
}

void preedit_start_reply_fr_read(preedit_start_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->return_value, data, len, swap);
    if (!*data) { return; }
}

uint8_t* preedit_start_reply_fr_write(preedit_start_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->return_value, data, swap);
    return data;
}

size_t preedit_start_reply_fr_size(preedit_start_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    return size;
}

void preedit_start_reply_fr_free(preedit_start_reply_fr *frame)
{
}

void preedit_draw_fr_read(preedit_draw_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->caret, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->chg_first, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->chg_length, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->status, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_preedit_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->preedit_string, frame->length_of_preedit_string, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->feedback_array.items = NULL;
    frame->feedback_array.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->feedback_array.items, (frame->feedback_array.size + 1) * sizeof(uint32_t));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->feedback_array.items = temp;
        uint32_t_read(&frame->feedback_array.items[frame->feedback_array.size], data, &counter, swap);
        if (!*data) { return; }
        frame->feedback_array.size++;
    }
}

uint8_t* preedit_draw_fr_write(preedit_draw_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->caret, data, swap);
    data = uint32_t_write(&frame->chg_first, data, swap);
    data = uint32_t_write(&frame->chg_length, data, swap);
    data = uint32_t_write(&frame->status, data, swap);
    data = uint16_t_write(&frame->length_of_preedit_string, data, swap);
    data = bytearray_write(&frame->preedit_string, frame->length_of_preedit_string, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    counter16 = frame->feedback_array.size * 4;
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->feedback_array.size; i++) {
        data = uint32_t_write(&frame->feedback_array.items[i], data, swap);
    }
    return data;
}

size_t preedit_draw_fr_size(preedit_draw_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    size += 4;
    size += 4;
    size += 2;
    size += frame->length_of_preedit_string;
    size = align_to_4(size, size, NULL);
    size += 2;
    size = align_to_4(size, size, NULL);
    size += frame->feedback_array.size * 4;
    return size;
}

void preedit_draw_fr_free(preedit_draw_fr *frame)
{
    free(frame->preedit_string);
    free(frame->feedback_array.items);
}

void preedit_caret_fr_read(preedit_caret_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->position, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->direction, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->style, data, len, swap);
    if (!*data) { return; }
}

uint8_t* preedit_caret_fr_write(preedit_caret_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->position, data, swap);
    data = uint32_t_write(&frame->direction, data, swap);
    data = uint32_t_write(&frame->style, data, swap);
    return data;
}

size_t preedit_caret_fr_size(preedit_caret_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    size += 4;
    return size;
}

void preedit_caret_fr_free(preedit_caret_fr *frame)
{
}

void preedit_caret_reply_fr_read(preedit_caret_reply_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->position, data, len, swap);
    if (!*data) { return; }
}

uint8_t* preedit_caret_reply_fr_write(preedit_caret_reply_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->position, data, swap);
    return data;
}

size_t preedit_caret_reply_fr_size(preedit_caret_reply_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    return size;
}

void preedit_caret_reply_fr_free(preedit_caret_reply_fr *frame)
{
}

void preedit_done_fr_read(preedit_done_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* preedit_done_fr_write(preedit_done_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t preedit_done_fr_size(preedit_done_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void preedit_done_fr_free(preedit_done_fr *frame)
{
}

void status_start_fr_read(status_start_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* status_start_fr_write(status_start_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t status_start_fr_size(status_start_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void status_start_fr_free(status_start_fr *frame)
{
}

void status_draw_text_fr_read(status_draw_text_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint8_t* start = *data;
    uint16_t counter16 = 0;
    size_t counter = 0;
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->type, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->status, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->length_of_status_string, data, len, swap);
    if (!*data) { return; }
    bytearray_read(&frame->status_string, frame->length_of_status_string, data, len, swap);
    if (!*data) { return; }
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    uint16_t_read(&counter16, data, len, swap);
    if (!*data) { return; }
    counter = counter16;
    *data = (uint8_t*) align_to_4((uintptr_t) *data, *data - start, len);
    if (!*data) { return; }
    if (counter > *len) { *data = NULL; return; } else { *len -= counter; } 
    frame->feedback_array.items = NULL;
    frame->feedback_array.size = 0;
    while (counter != 0) {
        void* temp = realloc(frame->feedback_array.items, (frame->feedback_array.size + 1) * sizeof(uint32_t));
        if (!temp) {
            *data = NULL;
            return;
        }
        frame->feedback_array.items = temp;
        uint32_t_read(&frame->feedback_array.items[frame->feedback_array.size], data, &counter, swap);
        if (!*data) { return; }
        frame->feedback_array.size++;
    }
}

uint8_t* status_draw_text_fr_write(status_draw_text_fr *frame, uint8_t *data, bool swap)
{
    uint8_t* start = data;
    uint16_t counter16 = 0;
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->type, data, swap);
    data = uint32_t_write(&frame->status, data, swap);
    data = uint16_t_write(&frame->length_of_status_string, data, swap);
    data = bytearray_write(&frame->status_string, frame->length_of_status_string, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    counter16 = frame->feedback_array.size * 4;
    data = uint16_t_write(&counter16, data, swap);
    data = (uint8_t*) align_to_4((uintptr_t) data, data - start, NULL);
    for (uint32_t i = 0; i < frame->feedback_array.size; i++) {
        data = uint32_t_write(&frame->feedback_array.items[i], data, swap);
    }
    return data;
}

size_t status_draw_text_fr_size(status_draw_text_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    size += 2;
    size += frame->length_of_status_string;
    size = align_to_4(size, size, NULL);
    size += 2;
    size = align_to_4(size, size, NULL);
    size += frame->feedback_array.size * 4;
    return size;
}

void status_draw_text_fr_free(status_draw_text_fr *frame)
{
    free(frame->status_string);
    free(frame->feedback_array.items);
}

void status_draw_bitmap_fr_read(status_draw_bitmap_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->type, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->pixmap_data, data, len, swap);
    if (!*data) { return; }
}

uint8_t* status_draw_bitmap_fr_write(status_draw_bitmap_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->type, data, swap);
    data = uint32_t_write(&frame->pixmap_data, data, swap);
    return data;
}

size_t status_draw_bitmap_fr_size(status_draw_bitmap_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    return size;
}

void status_draw_bitmap_fr_free(status_draw_bitmap_fr *frame)
{
}

void status_done_fr_read(status_done_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
}

uint8_t* status_done_fr_write(status_done_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    return data;
}

size_t status_done_fr_size(status_done_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    return size;
}

void status_done_fr_free(status_done_fr *frame)
{
}

void ext_set_event_mask_fr_read(ext_set_event_mask_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->filter_event_mask, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->intercept_event_mask, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->select_event_mask, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->forward_event_mask, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->synchronous_event_mask, data, len, swap);
    if (!*data) { return; }
}

uint8_t* ext_set_event_mask_fr_write(ext_set_event_mask_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint32_t_write(&frame->filter_event_mask, data, swap);
    data = uint32_t_write(&frame->intercept_event_mask, data, swap);
    data = uint32_t_write(&frame->select_event_mask, data, swap);
    data = uint32_t_write(&frame->forward_event_mask, data, swap);
    data = uint32_t_write(&frame->synchronous_event_mask, data, swap);
    return data;
}

size_t ext_set_event_mask_fr_size(ext_set_event_mask_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 4;
    size += 4;
    size += 4;
    size += 4;
    size += 4;
    return size;
}

void ext_set_event_mask_fr_free(ext_set_event_mask_fr *frame)
{
}

void ext_forward_keyevent_fr_read(ext_forward_keyevent_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->flag, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->sequence_number, data, len, swap);
    if (!*data) { return; }
    uint8_t_read(&frame->xEvent_u_u_type, data, len, swap);
    if (!*data) { return; }
    uint8_t_read(&frame->keycode, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->state, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->time, data, len, swap);
    if (!*data) { return; }
    uint32_t_read(&frame->window, data, len, swap);
    if (!*data) { return; }
}

uint8_t* ext_forward_keyevent_fr_write(ext_forward_keyevent_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->flag, data, swap);
    data = uint16_t_write(&frame->sequence_number, data, swap);
    data = uint8_t_write(&frame->xEvent_u_u_type, data, swap);
    data = uint8_t_write(&frame->keycode, data, swap);
    data = uint16_t_write(&frame->state, data, swap);
    data = uint32_t_write(&frame->time, data, swap);
    data = uint32_t_write(&frame->window, data, swap);
    return data;
}

size_t ext_forward_keyevent_fr_size(ext_forward_keyevent_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    size += 1;
    size += 1;
    size += 2;
    size += 4;
    size += 4;
    return size;
}

void ext_forward_keyevent_fr_free(ext_forward_keyevent_fr *frame)
{
}

void ext_move_fr_read(ext_move_fr *frame, uint8_t **data, size_t *len, bool swap)
{
    memset(frame, 0, sizeof(*frame));
    uint16_t_read(&frame->input_method_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->input_context_ID, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->X, data, len, swap);
    if (!*data) { return; }
    uint16_t_read(&frame->Y, data, len, swap);
    if (!*data) { return; }
}

uint8_t* ext_move_fr_write(ext_move_fr *frame, uint8_t *data, bool swap)
{
    data = uint16_t_write(&frame->input_method_ID, data, swap);
    data = uint16_t_write(&frame->input_context_ID, data, swap);
    data = uint16_t_write(&frame->X, data, swap);
    data = uint16_t_write(&frame->Y, data, swap);
    return data;
}

size_t ext_move_fr_size(ext_move_fr *frame)
{
    size_t size = 0;
    size += 2;
    size += 2;
    size += 2;
    size += 2;
    return size;
}

void ext_move_fr_free(ext_move_fr *frame)
{
}

