/*
 * Prototypes for public functions only of internal interest,
 * normally not used by modules.
 * What goes here are typically *_init() routines.
 */

/*! \file
 *
 * \brief
 * Prototypes for public functions only of internal interest,
 * 
 */


#ifndef _ASTERISK__PRIVATE_H
#define _ASTERISK__PRIVATE_H

int load_modules(unsigned int);		/*!< Provided by loader.c */
int load_pbx(void);			/*!< Provided by pbx.c */
int init_logger(void);			/*!< Provided by logger.c */
void close_logger(void);		/*!< Provided by logger.c */
void clean_time_zones(void);			/*!< Provided by localtime.c */
int ast_term_init(void);		/*!< Provided by term.c */
int astdb_init(void);			/*!< Provided by db.c */
void ast_channels_init(void);		/*!< Provided by channel.c */
void ast_builtins_init(void);		/*!< Provided by cli.c */
int ast_cli_perms_init(int reload);	/*!< Provided by cli.c */
int dnsmgr_init(void);			/*!< Provided by dnsmgr.c */ 
void dnsmgr_start_refresh(void);	/*!< Provided by dnsmgr.c */
int dnsmgr_reload(void);		/*!< Provided by dnsmgr.c */
void threadstorage_init(void);		/*!< Provided by threadstorage.c */
int ast_event_init(void);		/*!< Provided by event.c */
int ast_device_state_engine_init(void);	/*!< Provided by devicestate.c */
int astobj2_init(void);			/*!< Provided by astobj2.c */
int ast_file_init(void);		/*!< Provided by file.c */
int ast_features_init(void);            /*!< Provided by features.c */
void ast_autoservice_init(void);	/*!< Provided by autoservice.c */
int ast_data_init(void);		/*!< Provided by data.c */
int ast_http_init(void);		/*!< Provided by http.c */
int ast_http_reload(void);		/*!< Provided by http.c */
int ast_tps_init(void); 		/*!< Provided by taskprocessor.c */
int ast_timing_init(void);		/*!< Provided by timing.c */
int ast_indications_init(void); /*!< Provided by indications.c */
int ast_indications_reload(void);/*!< Provided by indications.c */
void ast_stun_init(void);               /*!< Provided by stun.c */
int ast_cel_engine_init(void);		/*!< Provided by cel.c */
int ast_cel_engine_reload(void);	/*!< Provided by cel.c */
int ast_ssl_init(void);                 /*!< Provided by ssl.c */
int ast_test_init(void);            /*!< Provided by test.c */
int ast_msg_init(void);             /*!< Provided by message.c */
void ast_msg_shutdown(void);        /*!< Provided by message.c */

/*!
 * \brief Reload asterisk modules.
 * \param name the name of the module to reload
 *
 * This function reloads the specified module, or if no modules are specified,
 * it will reload all loaded modules.
 *
 * \note Modules are reloaded using their reload() functions, not unloading
 * them and loading them again.
 * 
 * \return 0 if the specified module was not found.
 * \retval 1 if the module was found but cannot be reloaded.
 * \retval -1 if a reload operation is already in progress.
 * \retval 2 if the specfied module was found and reloaded.
 */
int ast_module_reload(const char *name);

/*!
 * \brief Process reload requests received during startup.
 *
 * This function requests that the loader execute the pending reload requests
 * that were queued during server startup.
 *
 * \note This function will do nothing if the server has not completely started
 *       up.  Once called, the reload queue is emptied, and further invocations
 *       will have no affect.
 */
void ast_process_pending_reloads(void);

/*! \brief Load XML documentation. Provided by xmldoc.c 
 *  \retval 1 on error.
 *  \retval 0 on success. 
 */
int ast_xmldoc_load_documentation(void);

/*!
 * \brief Reload genericplc configuration value from codecs.conf
 *
 * Implementation is in main/channel.c
 */
int ast_plc_reload(void);

/*!
 * \brief Init the ast_format attribute interface register container.
 */
int ast_format_attr_init(void);

/*!
 * \brief Init the Asterisk global format list after all format attribute modules have been loaded
 */
int ast_format_list_init(void);

/*! \brief initializes the rtp engine arrays */
int ast_rtp_engine_init(void);
#endif /* _ASTERISK__PRIVATE_H */
