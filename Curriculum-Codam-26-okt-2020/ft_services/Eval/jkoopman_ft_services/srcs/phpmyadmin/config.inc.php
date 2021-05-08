<?php
declare(strict_types=1);

$cfg['blowfish_secret'] = 'f1]eykk/o-Bz,,Q/r,0}mB03Zjw]icA0';

$i = 1;

$cfg['Servers'][$i]['auth_type'] = 'cookie';
$cfg['Servers'][$i]['host'] = 'mysql';
$cfg['Servers'][$i]['compress'] = false;
$cfg['Servers'][$i]['AllowNoPassword'] = false;

$cfg['Servers'][$i]['port'] = '3306';
$cfg['Servers'][$i]['user'] = 'admin';
$cfg['Servers'][$i]['password'] = 'admin';

$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';
$cfg['TempDir'] = '/tmp';
