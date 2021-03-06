/*
 * The Clear BSD License
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _EMBEDDED_RPC__CLIENT_SETUP_H_
#define _EMBEDDED_RPC__CLIENT_SETUP_H_

#include "erpc_common.h"
#include "erpc_config_internal.h"
#include "erpc_mbf_setup.h"
#if ERPC_NESTED_CALLS
#include "erpc_server_setup.h"
#endif
#include "erpc_client_manager.h"
#include "erpc_transport_setup.h"

/*!
 * @addtogroup client_setup
 * @{
 * @file
 */

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//! @name Client setup
//@{

/*!
 * @brief This function initializes client.
 *
 * @param[in] transport Initiated transport.
 * @param[in] message_buffer_factory Initiated message buffer factory.
 *
 * This function initializes client with all components necessary for serve client request.
 */
void erpc_client_init(erpc_transport_t transport, erpc_mbf_t message_buffer_factory);

/*!
 * @brief This function sets error handler function.
 *
 * Given error_handler function is called when error occur inside eRPC infrastructure.
 *
 * @param[in] error_handler Pointer to function error handler.
 */
void erpc_client_set_error_handler(client_error_handler_t error_handler);

/*!
 * @brief Can be used to set own crcStart number.
 *
 * For example can be used generated crc from erpcgen
 * which is providing when @crc annotation is used.
 * Accessed can be through 'extern const uint32_t erpc_generated_crc;'
 *
 * @param[in] crcStart Set start number for crc.
 */
void erpc_client_set_crc(uint32_t crcStart);

#if ERPC_NESTED_CALLS
/*!
 * @brief This function sets server object for handling nested eRPC calls.
 *
 * @param[in] server Initiated server.
 */
void erpc_client_set_server(erpc_server_t server);

/*!
 * @brief This function sets server thread id.
 *
 * @param[in] serverThreadId Id of thread where server run function is executed.
 */
void erpc_client_set_server_thread_id(void *serverThreadId);
#endif

#if ERPC_MESSAGE_LOGGING
/*!
 * @brief This function adds transport object for logging send/receive messages.
 *
 * @param[in] transport Initiated transport.
 *
 * @retval True When transport was successfully added.
 * @retval False When transport wasn't added.
 */
bool erpc_client_add_message_logger(erpc_transport_t transport);
#endif

/*!
 * @brief This function de-initializes client.
 *
 * This function de-initializes client and all components which it own.
 */
void erpc_client_deinit(void);

//@}

#ifdef __cplusplus
}
#endif

/*! @} */

#endif // _EMBEDDED_RPC__CLIENT_SETUP_H_
