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
define( 'DB_USER', 'maria' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

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
define('AUTH_KEY',         '-PCGefIXt|Um--+XoKVE.OK2.-mP-F&bnZZo7:fG<6}uLU1tksNzrqTk4%BR2o&c');
define('SECURE_AUTH_KEY',  'i-;XsH?0*5.6;I gR,b?uvs!Pa+kQOtiwiI|Z(*$)vp<E^+%@_1p`rmU]  _Ylu(');
define('LOGGED_IN_KEY',    'Z3hNvW~h-~<,F8OQCVX6]6A8jIB0I}?m&+>}Np EK,y0ub-U?gsz,$k#D$J;07n@');
define('NONCE_KEY',        '4piGZ%!g(6xHxuS.2Hx>&!qO]cjw#E`(=?t#ql!)UmpfG4=t%J#udTj%AVCt`#nB');
define('AUTH_SALT',        'f,(IKpa6&xGw*M~!C7CRx~MJS7 7VFo6z[R33T|+e>#:.fs{N}20)=SiQC2Jf)|@');
define('SECURE_AUTH_SALT', 'cyg5`J`fnSb(+Ij`-(Jp0c6wV:{_ GnE%|<!]QNfjN>0q-i>6s &GCiEo9Z** SH');
define('LOGGED_IN_SALT',   'f2J7wrD%.Pdys}qbgMz)+pM.AA#+{vK_7jO[}N+B*{>$-V~)K(Wd2^&L~-@d:LQ9');
define('NONCE_SALT',       'ALB3Cm0n]Y7D<s!i}+F2c1%&tl>CyX1!r{LK1CY/B+8JPp?0jA|x[5-i32+ut?uR');

/**#@-*/

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
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';