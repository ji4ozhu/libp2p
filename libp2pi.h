#pragma once
#include <stdint.h>

const uint32_t p2p_type_unknown   = 0;

const uint32_t p2p_type_full      = 1;

const uint32_t p2p_type_host      = 2;

const uint32_t p2p_type_fixed     = 3;

const uint32_t p2p_type_symmetric = 4;

const uint32_t p2p_type_multiip   = 5;


const uint32_t p2p_code_connect_error   = 0;

const uint32_t p2p_code_connect_timeout = 1;

const uint32_t p2p_code_close_active    = 2;

const uint32_t p2p_code_close_passive   = 3;

const uint32_t p2p_code_close_timeout   = 4;


typedef void(*p2p_recved)(uint64_t id, uint32_t session, char* data, uint32_t size);

typedef void(*p2p_checked)(uint32_t type, const char* host_ip, const char* napt_ip);

typedef void(*p2p_keepalived)(const char* ip, uint16_t port, uint64_t latency);

typedef void(*p2p_accepted)(uint64_t id, uint32_t session, uint32_t type);

typedef void(*p2p_connected)(uint64_t id, uint32_t session, uint32_t type);

typedef void(*p2p_closed)(uint64_t id, uint32_t session, uint32_t code);


struct p2p_callback
{
    p2p_recved     recved;

    p2p_checked    checked;

    p2p_keepalived keepalived;

    p2p_accepted   accepted;

    p2p_connected  connected;

    p2p_closed     closed;
};

extern "C" void p2p_config(uint64_t id, p2p_callback callback);

extern "C" void p2p_login(const char* ip, uint16_t port);

extern "C" void p2p_logout();

extern "C" void p2p_connect(uint64_t id, const char* ip, uint16_t port);

extern "C" void p2p_close(uint32_t session);

extern "C" void p2p_send(uint32_t session, const void* data, uint32_t size);

extern "C" uint32_t p2p_waitsend(uint32_t session);