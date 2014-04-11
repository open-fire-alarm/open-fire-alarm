/* Mylog.h */

int init_mylog(); /* initialization of the log */

int update_mylog_zones_active(); /* add a line to the log with the time about which zones are active */

int update_mylog_zones_on_fire(); /* add a line to the log with the time about which zones are on fire */

int update_mylog_alarms_on_fire(); /* add a line to the log with the time about which alarms are on fire */

int print_mylog(); /* print the log */
