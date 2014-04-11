/* Alarm.h */

int init_alarms(); /* initialization of alarms (all are safe) */
int init_zone(); /* initialization of zone (all are safe) */
int init_zone_active(); /* initialization of which zones are active (all are deactivated) */

int update_zones(); /* values of zones are changed automatically with alarms values */

int get_alarm1(); /* have the value of alarm1 */
int set_alarm1(int new_alarm1); /* change the value of alarm1 */
int get_alarm2(); /* have the value of alarm2 */
int set_alarm2(int new_alarm2); /* change the value of alarm2 */
int get_alarm3(); /* have the value of alarm3 */
int set_alarm3(int new_alarm3); /* change the value of alarm3 */
int get_alarm4(); /* have the value of alarm4 */
int set_alarm4(int new_alarm4); /* change the value of alarm4 */
int get_alarm5(); /* have the value of alarm5 */
int set_alarm5(int new_alarm5); /* change the value of alarm5 */
int get_alarm6(); /* have the value of alarm6 */
int set_alarm6(int new_alarm6); /* change the value of alarm6 */
int get_alarm7(); /* have the value of alarm7 */
int set_alarm7(int new_alarm7); /* change the value of alarm7 */
int get_alarm8(); /* have the value of alarm8 */
int set_alarm8(int new_alarm8); /* change the value of alarm8 */
int get_alarm9(); /* have the value of alarm9 */
int set_alarm9(int new_alarm9); /* change the value of alarm9 */

int get_zone1(); /* have the value of zone1 */
int get_zone2(); /* have the value of zone2 */
int get_zone3(); /* have the value of zone3 */

int get_zones_active1(); /* have the value of zones active1 */
int set_zones_active1(int new_zones_active1); /* change the value of zones active1 */
int get_zones_active2(); /* have the value of zones active2 */
int set_zones_active2(int new_zones_active2); /* change the value of zones active2 */
int get_zones_active3(); /* have the value of zones active3 */
int set_zones_active3(int new_zones_active3); /* change the value of zones active3 */

int everything_is_safe(); /* return 1 if everything is safe (no fire) else 0 */
