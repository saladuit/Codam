<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'dbuser' );

/** MySQL database password */
define( 'DB_PASSWORD', 'dbpassword' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-svc:3306' );

define('WP_HOME', 'http://192.168.99.129:5050' );
define('WP_SITEURL', 'http://192.168.99.129:5050' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'Y.zgE>gSQCoQ2eU9s3W1U3Ls[l3PfAtB6{dekxpty*IDL&Cq}f ?U(c:d5RgBL^E' );
define( 'SECURE_AUTH_KEY',  'cf?N7j^wieOOrokA$#N_a=uo6Ob!nxgFVvZ|XC6a:_oe[~aBg;vx1>)kmy;PGAE:' );
define( 'LOGGED_IN_KEY',    '68quFNHcjPiW}MN7)D.M%<eJ:cZ^FAGv3p>pT$Z!7nV?$W;f,ESei}b`rfoLKct8' );
define( 'NONCE_KEY',        'tN[xji>Ar~>vY5&TOp{+1#HPsi/z53m=d-kA>A=PMMApmZ[%Ylo$<gmJ&/}+Rnoo' );
define( 'AUTH_SALT',        '$ZxM^+)WvIN]!]hCNC(!l~yH:k b5jsI$,~n:&{|3P9bP]+$h8I8NyaNt(Ta3`:m' );
define( 'SECURE_AUTH_SALT', 'v%Y/{OMQ7;xzc*?[j>~9/lbKa1cp;g$ZG&}{yX~FyLE>dXqD[M8}Un&szxq;uT*t' );
define( 'LOGGED_IN_SALT',   '%;}IkegGZVzqhAwP~qD*so!aVtd&u_f7, &Q !sq:l~YiQN3K2Iig7[i*Szv]g>5' );
define( 'NONCE_SALT',       'CpGM0rAijXmf3f!)mEU6K#qiXbHxTCMm$ttBD;:%(iB)k$6JDhgxcI6L^,`@XBtV' );

/**#@-*/

/** Prevent WordPress CSS & JS from breaking in admin dashboard
* define( 'CONCATENATE_SCRIPTS', false ); 
*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', true );

define( 'WP_DEBUG_LOG', '/tmp/wp-errors.log' );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
