<?php
/**
 * Il file base di configurazione di WordPress.
 *
 * Questo file viene utilizzato, durante l’installazione, dallo script
 * di creazione di wp-config.php. Non è necessario utilizzarlo solo via web
 * puoi copiare questo file in «wp-config.php» e riempire i valori corretti.
 *
 * Questo file definisce le seguenti configurazioni:
 *
 * * Impostazioni database
 * * Chiavi Segrete
 * * Prefisso Tabella
 * * ABSPATH
 *
 * * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Impostazioni database - È possibile ottenere queste informazioni dal proprio fornitore di hosting ** //
/** Il nome del database di WordPress */
define('DB_NAME', 'database1');

/** Nome utente del database */
define('DB_USER', 'user');

/** Password del database */
define('DB_PASSWORD', 'password');

/** Hostname del database */
define('DB_HOST', 'mariadb');

/** Charset del Database da utilizzare nella creazione delle tabelle. */
define('DB_CHARSET', 'utf8');

/** Il tipo di Collazione del Database. Da non modificare se non si ha idea di cosa sia. */
define('DB_COLLATE', '');

/**#@+
 * Chiavi Univoche di Autenticazione e di Salatura.
 *
 * Modificarle con frasi univoche differenti!
 * È possibile generare tali chiavi utilizzando {@link https://api.wordpress.org/secret-key/1.1/salt/ servizio di chiavi-segrete di WordPress.org}
 * È possibile cambiare queste chiavi in qualsiasi momento, per invalidare tuttii cookie esistenti. Ciò forzerà tutti gli utenti ad effettuare nuovamente il login.
 *
 * @since 2.6.0
 */

define('AUTH_KEY',         '-Q*-)~RN3&g},(-h6#N_l8F0W.GEld*t(7a9!o7bd[7RB#_<B.Pd=_52K @Jd)oY');
define('SECURE_AUTH_KEY',  'J5[*h^o`1<}~l~Be6Oh|V]!]R[r?%JW7V(}#`ln5ICa[DdvrzfqkF.6IUNEa*ADN');
define('LOGGED_IN_KEY',    '.7kr_-t8?pbn37!.ZL;kirMkKGM_/=rx_xub_Pa<azj9!lhp(PZXN7aT;;bL.Zwl');
define('NONCE_KEY',        ',hh6ff-dOw5<|NDH6-!x*qhxDo.`TQ}a8D&{9)la~~ey},Y.)2l5OV&)]RbY.1NM');
define('AUTH_SALT',        'pi+t!I =KN[$8Bh+9eP|!&1(!;]bK <]m,PZ4yDT{lLI=G?jbRh=$Vx)<54y-Q-n');
define('SECURE_AUTH_SALT', 'S|@~K?UG~b%I3rPgjwTTDLRNH^},,|?}EhZM;R_Y-|+r]y8<t}g(=)o7:>jwSk)$');
define('LOGGED_IN_SALT',   'c1]n4$shhLn$]gh|0g$i=y9CS8vt])pV0<tB;2}X#+<gt*97XflOU5owd0%GNX%l');
define('NONCE_SALT',       '?MeEC3sZcU@sjy7s!a]NUty+|-UZ:Q>-Ss2>DXy2hvmXLzkfsS_8(9eLMOzZ+v%X');

$clear_env = no;
/**#@-*/

/**
 * Prefisso Tabella del Database WordPress.
 *
 * È possibile avere installazioni multiple su di un unico database
 * fornendo a ciascuna installazione un prefisso univoco.
 * Solo numeri, lettere e sottolineatura!
 */
$listen = 9000;
$table_prefix = 'wp_';
//$listen='wordpress:9000';

/**
 * Per gli sviluppatori: modalità di debug di WordPress.
 *
 * Modificare questa voce a TRUE per abilitare la visualizzazione degli avvisi durante lo sviluppo
 * È fortemente raccomandato agli svilupaptori di temi e plugin di utilizare
 * WP_DEBUG all’interno dei loro ambienti di sviluppo.
 *
 * Per informazioni sulle altre costanti che possono essere utilizzate per il debug,
 * leggi la documentazione
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define('WP_DEBUG', false);

/* Finito, interrompere le modifiche! Buon blogging. */

/** Path assoluto alla directory di WordPress. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Imposta le variabili di WordPress ed include i file. */
require_once(ABSPATH . 'wp-settings.php');
