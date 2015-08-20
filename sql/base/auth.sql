/*
SQLyog Ultimate v12.09 (64 bit)
MySQL - 5.5.9 : Database - aut
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `account` */

DROP TABLE IF EXISTS `account`;

CREATE TABLE `account` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `username` varchar(32) NOT NULL DEFAULT '',
  `sha_pass_hash` varchar(40) NOT NULL DEFAULT '',
  `sessionkey` varchar(80) NOT NULL DEFAULT '',
  `v` varchar(64) NOT NULL DEFAULT '',
  `s` varchar(64) NOT NULL DEFAULT '',
  `token_key` varchar(100) NOT NULL DEFAULT '',
  `email` varchar(255) NOT NULL DEFAULT '',
  `reg_mail` varchar(255) NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `lock_country` varchar(2) NOT NULL DEFAULT '00',
  `last_login` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `expansion` tinyint(3) unsigned NOT NULL DEFAULT '4',
  `mutetime` bigint(20) NOT NULL DEFAULT '0',
  `mutereason` varchar(255) NOT NULL DEFAULT '',
  `muteby` varchar(50) NOT NULL DEFAULT '',
  `locale` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `os` varchar(3) NOT NULL DEFAULT '',
  `recruiter` int(10) unsigned NOT NULL DEFAULT '0',
  `hasBoost` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_username` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account System';

/*Data for the table `account` */

/*Table structure for table `account_access` */

DROP TABLE IF EXISTS `account_access`;

CREATE TABLE `account_access` (
  `id` int(10) unsigned NOT NULL,
  `gmlevel` tinyint(3) unsigned NOT NULL,
  `RealmID` int(11) NOT NULL DEFAULT '-1',
  PRIMARY KEY (`id`,`RealmID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_access` */

/*Table structure for table `account_banned` */

DROP TABLE IF EXISTS `account_banned`;

CREATE TABLE `account_banned` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account id',
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  `active` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Ban List';

/*Data for the table `account_banned` */

/*Table structure for table `account_spell` */

DROP TABLE IF EXISTS `account_spell`;

CREATE TABLE `account_spell` (
  `accountId` int(11) NOT NULL,
  `spell` int(10) NOT NULL,
  `active` tinyint(1) DEFAULT NULL,
  `disabled` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`accountId`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `account_spell` */

/*Table structure for table `autobroadcast` */

DROP TABLE IF EXISTS `autobroadcast`;

CREATE TABLE `autobroadcast` (
  `realmid` int(11) NOT NULL DEFAULT '-1',
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `weight` tinyint(3) unsigned DEFAULT '1',
  `text` longtext NOT NULL,
  PRIMARY KEY (`id`,`realmid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `autobroadcast` */

/*Table structure for table `bug_tickets` */

DROP TABLE IF EXISTS `bug_tickets`;

CREATE TABLE `bug_tickets` (
  `ticketId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `realm` int(10) unsigned NOT NULL DEFAULT '0',
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier of ticket creator',
  `message` text NOT NULL,
  `createTime` int(10) unsigned NOT NULL DEFAULT '0',
  `pool` varchar(32) NOT NULL,
  `mapId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `posX` float NOT NULL DEFAULT '0',
  `posY` float NOT NULL DEFAULT '0',
  `posZ` float NOT NULL DEFAULT '0',
  `closedBy` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ticketId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Support System';

/*Data for the table `bug_tickets` */

/*Table structure for table `ip2nation` */

DROP TABLE IF EXISTS `ip2nation`;

CREATE TABLE `ip2nation` (
  `ip` int(11) unsigned NOT NULL DEFAULT '0',
  `country` char(2) NOT NULL DEFAULT '',
  KEY `ip` (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `ip2nation` */

/*Table structure for table `ip2nationcountries` */

DROP TABLE IF EXISTS `ip2nationcountries`;

CREATE TABLE `ip2nationcountries` (
  `code` varchar(4) NOT NULL DEFAULT '',
  `iso_code_2` varchar(2) NOT NULL DEFAULT '',
  `iso_code_3` varchar(3) DEFAULT '',
  `iso_country` varchar(255) NOT NULL DEFAULT '',
  `country` varchar(255) NOT NULL DEFAULT '',
  `lat` float NOT NULL DEFAULT '0',
  `lon` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`code`),
  KEY `code` (`code`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `ip2nationcountries` */

/*Table structure for table `ip_banned` */

DROP TABLE IF EXISTS `ip_banned`;

CREATE TABLE `ip_banned` (
  `ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `bandate` int(10) unsigned NOT NULL,
  `unbandate` int(10) unsigned NOT NULL,
  `bannedby` varchar(50) NOT NULL DEFAULT '[Console]',
  `banreason` varchar(255) NOT NULL DEFAULT 'no reason',
  PRIMARY KEY (`ip`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Banned IPs';

/*Data for the table `ip_banned` */

/*Table structure for table `logs` */

DROP TABLE IF EXISTS `logs`;

CREATE TABLE `logs` (
  `time` int(10) unsigned NOT NULL,
  `realm` int(10) unsigned NOT NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `string` text CHARACTER SET latin1
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `logs` */

/*Table structure for table `quest_completer` */

DROP TABLE IF EXISTS `quest_completer`;

CREATE TABLE `quest_completer` (
  `id` int(5) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

/*Data for the table `quest_completer` */

/*Table structure for table `rbac_account_permissions` */

DROP TABLE IF EXISTS `rbac_account_permissions`;

CREATE TABLE `rbac_account_permissions` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `granted` tinyint(1) NOT NULL DEFAULT '1' COMMENT 'Granted = 1, Denied = 0',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`,`permissionId`,`realmId`),
  KEY `fk__rbac_account_roles__rbac_permissions` (`permissionId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Account-Permission relation';

/*Data for the table `rbac_account_permissions` */

/*Table structure for table `rbac_default_permissions` */

DROP TABLE IF EXISTS `rbac_default_permissions`;

CREATE TABLE `rbac_default_permissions` (
  `secId` int(10) unsigned NOT NULL COMMENT 'Security Level id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'permission id',
  PRIMARY KEY (`secId`,`permissionId`),
  KEY `fk__rbac_default_permissions__rbac_permissions` (`permissionId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Default permission to assign to different account security levels';

/*Data for the table `rbac_default_permissions` */

insert  into `rbac_default_permissions`(`secId`,`permissionId`) values (0,195);
insert  into `rbac_default_permissions`(`secId`,`permissionId`) values (1,194);
insert  into `rbac_default_permissions`(`secId`,`permissionId`) values (2,193);
insert  into `rbac_default_permissions`(`secId`,`permissionId`) values (3,192);

/*Table structure for table `rbac_linked_permissions` */

DROP TABLE IF EXISTS `rbac_linked_permissions`;

CREATE TABLE `rbac_linked_permissions` (
  `id` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `linkedId` int(10) unsigned NOT NULL COMMENT 'Linked Permission id',
  PRIMARY KEY (`id`,`linkedId`),
  KEY `fk__rbac_linked_permissions__rbac_permissions1` (`id`),
  KEY `fk__rbac_linked_permissions__rbac_permissions2` (`linkedId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Permission - Linked Permission relation';

/*Data for the table `rbac_linked_permissions` */

insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (192,21);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (192,42);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (192,43);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (192,193);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (192,196);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (192,776);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (193,48);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (193,194);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (193,197);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (193,1004);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (193,1005);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,1);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,2);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,11);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,13);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,14);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,15);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,16);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,17);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,18);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,19);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,20);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,22);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,23);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,25);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,26);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,27);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,28);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,29);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,30);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,31);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,32);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,33);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,34);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,35);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,36);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,37);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,38);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,39);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,40);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,41);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,44);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,46);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,47);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,195);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (194,198);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,3);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,4);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,5);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,6);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,24);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,49);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,199);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,1002);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,1003);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,1006);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (195,1007);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,200);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,201);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,226);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,227);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,230);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,231);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,233);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,234);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,235);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,238);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,239);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,240);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,241);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,242);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,243);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,244);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,245);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,246);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,247);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,248);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,249);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,250);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,251);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,252);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,253);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,254);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,255);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,256);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,257);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,258);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,259);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,260);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,261);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,262);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,264);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,265);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,266);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,267);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,268);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,269);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,270);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,271);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,272);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,279);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,280);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,283);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,287);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,288);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,289);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,290);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,291);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,292);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,293);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,294);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,295);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,296);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,297);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,298);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,299);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,302);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,303);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,304);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,305);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,306);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,307);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,308);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,309);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,310);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,313);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,314);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,319);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,320);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,321);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,322);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,323);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,324);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,325);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,326);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,327);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,328);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,329);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,330);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,331);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,332);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,333);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,334);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,335);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,336);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,337);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,338);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,339);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,340);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,341);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,342);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,343);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,344);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,345);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,346);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,347);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,348);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,349);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,350);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,351);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,352);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,353);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,354);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,355);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,356);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,357);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,358);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,359);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,360);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,361);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,362);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,363);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,364);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,365);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,366);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,373);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,375);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,400);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,401);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,402);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,403);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,404);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,405);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,406);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,407);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,417);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,418);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,419);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,420);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,421);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,422);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,423);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,424);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,425);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,426);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,427);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,428);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,429);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,434);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,435);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,436);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,437);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,438);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,439);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,440);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,441);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,442);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,443);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,444);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,445);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,446);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,447);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,448);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,449);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,450);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,451);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,452);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,453);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,454);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,455);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,456);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,457);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,458);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,459);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,461);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,463);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,464);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,465);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,472);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,473);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,474);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,475);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,476);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,477);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,478);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,488);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,489);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,491);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,492);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,493);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,495);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,497);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,498);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,499);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,500);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,502);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,503);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,505);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,508);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,511);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,513);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,514);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,516);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,519);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,522);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,523);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,526);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,527);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,529);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,530);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,533);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,535);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,536);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,537);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,538);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,539);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,540);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,541);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,556);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,581);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,582);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,592);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,593);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,596);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,602);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,603);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,604);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,605);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,606);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,607);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,608);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,609);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,610);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,611);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,612);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,613);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,614);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,615);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,616);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,617);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,618);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,619);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,620);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,621);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,622);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,623);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,624);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,625);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,626);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,627);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,628);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,629);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,630);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,631);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,632);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,633);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,634);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,635);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,636);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,637);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,638);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,639);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,640);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,641);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,642);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,643);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,644);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,645);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,646);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,647);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,648);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,649);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,650);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,651);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,652);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,653);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,654);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,655);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,656);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,657);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,658);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,659);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,660);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,661);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,662);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,663);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,664);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,665);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,666);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,667);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,668);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,669);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,670);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,671);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,672);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,673);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,674);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,675);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,676);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,677);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,678);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,679);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,680);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,681);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,682);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,683);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,684);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,685);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,686);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,687);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,688);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,689);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,690);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,691);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,692);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,693);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,694);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,695);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,696);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,697);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,698);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,699);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,700);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,701);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,702);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,703);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,704);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,705);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,706);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,707);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,708);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,709);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,710);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,711);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,712);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,713);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,714);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,715);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,716);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,717);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,718);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,719);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,721);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,722);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,723);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,724);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,725);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,726);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,727);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,728);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,729);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,730);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,733);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,734);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,735);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,736);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,738);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,739);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,748);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,753);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,757);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (196,773);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,232);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,236);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,237);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,273);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,274);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,275);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,276);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,277);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,284);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,285);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,286);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,301);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,311);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,387);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,388);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,389);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,390);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,391);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,392);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,393);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,394);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,395);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,396);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,397);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,398);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,399);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,479);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,480);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,481);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,482);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,485);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,486);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,487);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,494);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,506);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,509);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,510);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,517);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,518);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,521);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,542);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,543);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,550);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,558);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,568);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,571);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,572);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,573);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,574);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,575);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,576);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,577);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,578);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,579);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,580);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,583);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,584);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,585);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,586);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,587);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,588);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,589);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,590);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,591);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,594);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,595);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,601);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,743);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,750);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,758);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,761);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,762);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,763);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,764);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,765);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,766);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,767);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,768);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,769);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,770);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,771);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,772);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (197,774);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,218);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,300);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,312);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,315);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,316);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,317);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,318);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,367);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,368);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,369);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,370);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,371);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,372);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,374);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,376);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,377);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,378);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,379);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,380);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,381);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,382);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,383);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,384);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,385);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,386);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,408);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,409);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,410);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,411);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,412);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,413);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,414);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,415);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,416);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,430);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,431);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,432);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,433);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,462);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,466);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,467);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,468);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,469);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,470);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,471);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,483);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,484);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,490);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,504);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,512);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,515);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,520);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,524);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,528);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,531);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,532);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,544);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,545);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,546);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,547);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,548);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,549);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,551);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,552);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,553);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,554);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,555);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,557);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,559);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,560);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,561);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,562);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,563);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,564);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,565);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,566);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,567);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,569);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,570);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,597);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,598);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,599);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,600);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,737);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,740);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,741);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,742);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,744);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,745);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,746);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,747);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,749);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,751);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,752);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,754);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,755);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,756);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,759);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (198,760);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,217);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,221);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,222);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,223);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,225);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,263);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,496);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,501);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,507);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,525);
insert  into `rbac_linked_permissions`(`id`,`linkedId`) values (199,534);

/*Table structure for table `rbac_permissions` */

DROP TABLE IF EXISTS `rbac_permissions`;

CREATE TABLE `rbac_permissions` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Permission id',
  `name` varchar(100) NOT NULL COMMENT 'Permission name',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Permission List';

/*Data for the table `rbac_permissions` */

insert  into `rbac_permissions`(`id`,`name`) values (1,'Instant logout');
insert  into `rbac_permissions`(`id`,`name`) values (2,'Skip Queue');
insert  into `rbac_permissions`(`id`,`name`) values (3,'Join Normal Battleground');
insert  into `rbac_permissions`(`id`,`name`) values (4,'Join Random Battleground');
insert  into `rbac_permissions`(`id`,`name`) values (5,'Join Arenas');
insert  into `rbac_permissions`(`id`,`name`) values (6,'Join Dungeon Finder');
insert  into `rbac_permissions`(`id`,`name`) values (11,'Log GM trades');
insert  into `rbac_permissions`(`id`,`name`) values (13,'Skip Instance required bosses check');
insert  into `rbac_permissions`(`id`,`name`) values (14,'Skip character creation team mask check');
insert  into `rbac_permissions`(`id`,`name`) values (15,'Skip character creation class mask check');
insert  into `rbac_permissions`(`id`,`name`) values (16,'Skip character creation race mask check');
insert  into `rbac_permissions`(`id`,`name`) values (17,'Skip character creation reserved name check');
insert  into `rbac_permissions`(`id`,`name`) values (18,'Skip character creation heroic min level check');
insert  into `rbac_permissions`(`id`,`name`) values (19,'Skip needed requirements to use channel check');
insert  into `rbac_permissions`(`id`,`name`) values (20,'Skip disable map check');
insert  into `rbac_permissions`(`id`,`name`) values (21,'Skip reset talents when used more than allowed check');
insert  into `rbac_permissions`(`id`,`name`) values (22,'Skip spam chat check');
insert  into `rbac_permissions`(`id`,`name`) values (23,'Skip over-speed ping check');
insert  into `rbac_permissions`(`id`,`name`) values (24,'Two side faction characters on the same account');
insert  into `rbac_permissions`(`id`,`name`) values (25,'Allow say chat between factions');
insert  into `rbac_permissions`(`id`,`name`) values (26,'Allow channel chat between factions');
insert  into `rbac_permissions`(`id`,`name`) values (27,'Two side mail interaction');
insert  into `rbac_permissions`(`id`,`name`) values (28,'See two side who list');
insert  into `rbac_permissions`(`id`,`name`) values (29,'Add friends of other faction');
insert  into `rbac_permissions`(`id`,`name`) values (30,'Save character without delay with .save command');
insert  into `rbac_permissions`(`id`,`name`) values (31,'Use params with .unstuck command');
insert  into `rbac_permissions`(`id`,`name`) values (32,'Can be assigned tickets with .assign ticket command');
insert  into `rbac_permissions`(`id`,`name`) values (33,'Notify if a command was not found');
insert  into `rbac_permissions`(`id`,`name`) values (34,'Check if should appear in list using .gm ingame command');
insert  into `rbac_permissions`(`id`,`name`) values (35,'See all security levels with who command');
insert  into `rbac_permissions`(`id`,`name`) values (36,'Filter whispers');
insert  into `rbac_permissions`(`id`,`name`) values (37,'Use staff badge in chat');
insert  into `rbac_permissions`(`id`,`name`) values (38,'Resurrect with full Health Points');
insert  into `rbac_permissions`(`id`,`name`) values (39,'Restore saved gm setting states');
insert  into `rbac_permissions`(`id`,`name`) values (40,'Allows to add a gm to friend list');
insert  into `rbac_permissions`(`id`,`name`) values (41,'Use Config option START_GM_LEVEL to assign new character level');
insert  into `rbac_permissions`(`id`,`name`) values (42,'Allows to use CMSG_WORLD_TELEPORT opcode');
insert  into `rbac_permissions`(`id`,`name`) values (43,'Allows to use CMSG_WHOIS opcode');
insert  into `rbac_permissions`(`id`,`name`) values (44,'Receive global GM messages/texts');
insert  into `rbac_permissions`(`id`,`name`) values (45,'Join channels without announce');
insert  into `rbac_permissions`(`id`,`name`) values (46,'Change channel settings without being channel moderator');
insert  into `rbac_permissions`(`id`,`name`) values (47,'Enables lower security than target check');
insert  into `rbac_permissions`(`id`,`name`) values (48,'Enable IP, Last Login and EMail output in pinfo');
insert  into `rbac_permissions`(`id`,`name`) values (49,'Forces to enter the email for confirmation on password change');
insert  into `rbac_permissions`(`id`,`name`) values (50,'Allow user to check his own email with .account');
insert  into `rbac_permissions`(`id`,`name`) values (192,'Role: Sec Level Administrator');
insert  into `rbac_permissions`(`id`,`name`) values (193,'Role: Sec Level Gamemaster');
insert  into `rbac_permissions`(`id`,`name`) values (194,'Role: Sec Level Moderator');
insert  into `rbac_permissions`(`id`,`name`) values (195,'Role: Sec Level Player');
insert  into `rbac_permissions`(`id`,`name`) values (196,'Role: Administrator Commands');
insert  into `rbac_permissions`(`id`,`name`) values (197,'Role: Gamemaster Commands');
insert  into `rbac_permissions`(`id`,`name`) values (198,'Role: Moderator Commands');
insert  into `rbac_permissions`(`id`,`name`) values (199,'Role: Player Commands');
insert  into `rbac_permissions`(`id`,`name`) values (200,'Command: rbac');
insert  into `rbac_permissions`(`id`,`name`) values (201,'Command: rbac account');
insert  into `rbac_permissions`(`id`,`name`) values (202,'Command: rbac account list');
insert  into `rbac_permissions`(`id`,`name`) values (203,'Command: rbac account grant');
insert  into `rbac_permissions`(`id`,`name`) values (204,'Command: rbac account deny');
insert  into `rbac_permissions`(`id`,`name`) values (205,'Command: rbac account revoke');
insert  into `rbac_permissions`(`id`,`name`) values (206,'Command: rbac list');
insert  into `rbac_permissions`(`id`,`name`) values (217,'Command: account');
insert  into `rbac_permissions`(`id`,`name`) values (218,'Command: account addon');
insert  into `rbac_permissions`(`id`,`name`) values (219,'Command: account create');
insert  into `rbac_permissions`(`id`,`name`) values (220,'Command: account delete');
insert  into `rbac_permissions`(`id`,`name`) values (221,'Command: account lock');
insert  into `rbac_permissions`(`id`,`name`) values (222,'Command: account lock country');
insert  into `rbac_permissions`(`id`,`name`) values (223,'Command: account lock ip');
insert  into `rbac_permissions`(`id`,`name`) values (224,'Command: account onlinelist');
insert  into `rbac_permissions`(`id`,`name`) values (225,'Command: account password');
insert  into `rbac_permissions`(`id`,`name`) values (226,'Command: account set');
insert  into `rbac_permissions`(`id`,`name`) values (227,'Command: account set addon');
insert  into `rbac_permissions`(`id`,`name`) values (228,'Command: account set gmlevel');
insert  into `rbac_permissions`(`id`,`name`) values (229,'Command: account set password');
insert  into `rbac_permissions`(`id`,`name`) values (230,'Command: achievement');
insert  into `rbac_permissions`(`id`,`name`) values (231,'Command: achievement add');
insert  into `rbac_permissions`(`id`,`name`) values (232,'Command: arena');
insert  into `rbac_permissions`(`id`,`name`) values (233,'Command: arena captain');
insert  into `rbac_permissions`(`id`,`name`) values (234,'Command: arena create');
insert  into `rbac_permissions`(`id`,`name`) values (235,'Command: arena disband');
insert  into `rbac_permissions`(`id`,`name`) values (236,'Command: arena info');
insert  into `rbac_permissions`(`id`,`name`) values (237,'Command: arena lookup');
insert  into `rbac_permissions`(`id`,`name`) values (238,'Command: arena rename');
insert  into `rbac_permissions`(`id`,`name`) values (239,'Command: ban');
insert  into `rbac_permissions`(`id`,`name`) values (240,'Command: ban account');
insert  into `rbac_permissions`(`id`,`name`) values (241,'Command: ban character');
insert  into `rbac_permissions`(`id`,`name`) values (242,'Command: ban ip');
insert  into `rbac_permissions`(`id`,`name`) values (243,'Command: ban playeraccount');
insert  into `rbac_permissions`(`id`,`name`) values (244,'Command: baninfo');
insert  into `rbac_permissions`(`id`,`name`) values (245,'Command: baninfo account');
insert  into `rbac_permissions`(`id`,`name`) values (246,'Command: baninfo character');
insert  into `rbac_permissions`(`id`,`name`) values (247,'Command: baninfo ip');
insert  into `rbac_permissions`(`id`,`name`) values (248,'Command: banlist');
insert  into `rbac_permissions`(`id`,`name`) values (249,'Command: banlist account');
insert  into `rbac_permissions`(`id`,`name`) values (250,'Command: banlist character');
insert  into `rbac_permissions`(`id`,`name`) values (251,'Command: banlist ip');
insert  into `rbac_permissions`(`id`,`name`) values (252,'Command: unban');
insert  into `rbac_permissions`(`id`,`name`) values (253,'Command: unban account');
insert  into `rbac_permissions`(`id`,`name`) values (254,'Command: unban character');
insert  into `rbac_permissions`(`id`,`name`) values (255,'Command: unban ip');
insert  into `rbac_permissions`(`id`,`name`) values (256,'Command: unban playeraccount');
insert  into `rbac_permissions`(`id`,`name`) values (257,'Command: bf');
insert  into `rbac_permissions`(`id`,`name`) values (258,'Command: bf start');
insert  into `rbac_permissions`(`id`,`name`) values (259,'Command: bf stop');
insert  into `rbac_permissions`(`id`,`name`) values (260,'Command: bf switch');
insert  into `rbac_permissions`(`id`,`name`) values (261,'Command: bf timer');
insert  into `rbac_permissions`(`id`,`name`) values (262,'Command: bf enable');
insert  into `rbac_permissions`(`id`,`name`) values (263,'Command: account email');
insert  into `rbac_permissions`(`id`,`name`) values (264,'Command: account set sec');
insert  into `rbac_permissions`(`id`,`name`) values (265,'Command: account set sec email');
insert  into `rbac_permissions`(`id`,`name`) values (266,'Command: account set sec regmail');
insert  into `rbac_permissions`(`id`,`name`) values (267,'Command: cast');
insert  into `rbac_permissions`(`id`,`name`) values (268,'Command: cast back');
insert  into `rbac_permissions`(`id`,`name`) values (269,'Command: cast dist');
insert  into `rbac_permissions`(`id`,`name`) values (270,'Command: cast self');
insert  into `rbac_permissions`(`id`,`name`) values (271,'Command: cast target');
insert  into `rbac_permissions`(`id`,`name`) values (272,'Command: cast dest');
insert  into `rbac_permissions`(`id`,`name`) values (273,'Command: character');
insert  into `rbac_permissions`(`id`,`name`) values (274,'Command: character customize');
insert  into `rbac_permissions`(`id`,`name`) values (275,'Command: character changefaction');
insert  into `rbac_permissions`(`id`,`name`) values (276,'Command: character changerace');
insert  into `rbac_permissions`(`id`,`name`) values (277,'Command: character deleted');
insert  into `rbac_permissions`(`id`,`name`) values (279,'Command: character deleted list');
insert  into `rbac_permissions`(`id`,`name`) values (280,'Command: character deleted restore');
insert  into `rbac_permissions`(`id`,`name`) values (283,'Command: character level');
insert  into `rbac_permissions`(`id`,`name`) values (284,'Command: character rename');
insert  into `rbac_permissions`(`id`,`name`) values (285,'Command: character reputation');
insert  into `rbac_permissions`(`id`,`name`) values (286,'Command: character titles');
insert  into `rbac_permissions`(`id`,`name`) values (287,'Command: levelup');
insert  into `rbac_permissions`(`id`,`name`) values (288,'Command: pdump');
insert  into `rbac_permissions`(`id`,`name`) values (289,'Command: pdump load');
insert  into `rbac_permissions`(`id`,`name`) values (290,'Command: pdump write');
insert  into `rbac_permissions`(`id`,`name`) values (291,'Command: cheat');
insert  into `rbac_permissions`(`id`,`name`) values (292,'Command: cheat casttime');
insert  into `rbac_permissions`(`id`,`name`) values (293,'Command: cheat cooldown');
insert  into `rbac_permissions`(`id`,`name`) values (294,'Command: cheat explore');
insert  into `rbac_permissions`(`id`,`name`) values (295,'Command: cheat god');
insert  into `rbac_permissions`(`id`,`name`) values (296,'Command: cheat power');
insert  into `rbac_permissions`(`id`,`name`) values (297,'Command: cheat status');
insert  into `rbac_permissions`(`id`,`name`) values (298,'Command: cheat taxi');
insert  into `rbac_permissions`(`id`,`name`) values (299,'Command: cheat waterwalk');
insert  into `rbac_permissions`(`id`,`name`) values (300,'Command: debug');
insert  into `rbac_permissions`(`id`,`name`) values (301,'Command: debug anim');
insert  into `rbac_permissions`(`id`,`name`) values (302,'Command: debug areatriggers');
insert  into `rbac_permissions`(`id`,`name`) values (303,'Command: debug arena');
insert  into `rbac_permissions`(`id`,`name`) values (304,'Command: debug bg');
insert  into `rbac_permissions`(`id`,`name`) values (305,'Command: debug entervehicle');
insert  into `rbac_permissions`(`id`,`name`) values (306,'Command: debug getitemstate');
insert  into `rbac_permissions`(`id`,`name`) values (307,'Command: debug getitemvalue');
insert  into `rbac_permissions`(`id`,`name`) values (308,'Command: debug getvalue');
insert  into `rbac_permissions`(`id`,`name`) values (309,'Command: debug hostil');
insert  into `rbac_permissions`(`id`,`name`) values (310,'Command: debug itemexpire');
insert  into `rbac_permissions`(`id`,`name`) values (311,'Command: debug lootrecipient');
insert  into `rbac_permissions`(`id`,`name`) values (312,'Command: debug los');
insert  into `rbac_permissions`(`id`,`name`) values (313,'Command: debug mod32value');
insert  into `rbac_permissions`(`id`,`name`) values (314,'Command: debug moveflags');
insert  into `rbac_permissions`(`id`,`name`) values (315,'Command: debug play');
insert  into `rbac_permissions`(`id`,`name`) values (316,'Command: debug play cinematics');
insert  into `rbac_permissions`(`id`,`name`) values (317,'Command: debug play movie');
insert  into `rbac_permissions`(`id`,`name`) values (318,'Command: debug play sound');
insert  into `rbac_permissions`(`id`,`name`) values (319,'Command: debug send');
insert  into `rbac_permissions`(`id`,`name`) values (320,'Command: debug send buyerror');
insert  into `rbac_permissions`(`id`,`name`) values (321,'Command: debug send channelnotify');
insert  into `rbac_permissions`(`id`,`name`) values (322,'Command: debug send chatmessage');
insert  into `rbac_permissions`(`id`,`name`) values (323,'Command: debug send equiperror');
insert  into `rbac_permissions`(`id`,`name`) values (324,'Command: debug send largepacket');
insert  into `rbac_permissions`(`id`,`name`) values (325,'Command: debug send opcode');
insert  into `rbac_permissions`(`id`,`name`) values (326,'Command: debug send qinvalidmsg');
insert  into `rbac_permissions`(`id`,`name`) values (327,'Command: debug send qpartymsg');
insert  into `rbac_permissions`(`id`,`name`) values (328,'Command: debug send sellerror');
insert  into `rbac_permissions`(`id`,`name`) values (329,'Command: debug send setphaseshift');
insert  into `rbac_permissions`(`id`,`name`) values (330,'Command: debug send spellfail');
insert  into `rbac_permissions`(`id`,`name`) values (331,'Command: debug setaurastate');
insert  into `rbac_permissions`(`id`,`name`) values (332,'Command: debug setbit');
insert  into `rbac_permissions`(`id`,`name`) values (333,'Command: debug setitemvalue');
insert  into `rbac_permissions`(`id`,`name`) values (334,'Command: debug setvalue');
insert  into `rbac_permissions`(`id`,`name`) values (335,'Command: debug setvid');
insert  into `rbac_permissions`(`id`,`name`) values (336,'Command: debug spawnvehicle');
insert  into `rbac_permissions`(`id`,`name`) values (337,'Command: debug threat');
insert  into `rbac_permissions`(`id`,`name`) values (338,'Command: debug update');
insert  into `rbac_permissions`(`id`,`name`) values (339,'Command: debug uws');
insert  into `rbac_permissions`(`id`,`name`) values (340,'Command: wpgps');
insert  into `rbac_permissions`(`id`,`name`) values (341,'Command: deserter');
insert  into `rbac_permissions`(`id`,`name`) values (342,'Command: deserter bg');
insert  into `rbac_permissions`(`id`,`name`) values (343,'Command: deserter bg add');
insert  into `rbac_permissions`(`id`,`name`) values (344,'Command: deserter bg remove');
insert  into `rbac_permissions`(`id`,`name`) values (345,'Command: deserter instance');
insert  into `rbac_permissions`(`id`,`name`) values (346,'Command: deserter instance add');
insert  into `rbac_permissions`(`id`,`name`) values (347,'Command: deserter instance remove');
insert  into `rbac_permissions`(`id`,`name`) values (348,'Command: disable');
insert  into `rbac_permissions`(`id`,`name`) values (349,'Command: disable add');
insert  into `rbac_permissions`(`id`,`name`) values (350,'Command: disable add achievement_criteria');
insert  into `rbac_permissions`(`id`,`name`) values (351,'Command: disable add battleground');
insert  into `rbac_permissions`(`id`,`name`) values (352,'Command: disable add map');
insert  into `rbac_permissions`(`id`,`name`) values (353,'Command: disable add mmap');
insert  into `rbac_permissions`(`id`,`name`) values (354,'Command: disable add outdoorpvp');
insert  into `rbac_permissions`(`id`,`name`) values (355,'Command: disable add quest');
insert  into `rbac_permissions`(`id`,`name`) values (356,'Command: disable add spell');
insert  into `rbac_permissions`(`id`,`name`) values (357,'Command: disable add vmap');
insert  into `rbac_permissions`(`id`,`name`) values (358,'Command: disable remove');
insert  into `rbac_permissions`(`id`,`name`) values (359,'Command: disable remove achievement_criteria');
insert  into `rbac_permissions`(`id`,`name`) values (360,'Command: disable remove battleground');
insert  into `rbac_permissions`(`id`,`name`) values (361,'Command: disable remove map');
insert  into `rbac_permissions`(`id`,`name`) values (362,'Command: disable remove mmap');
insert  into `rbac_permissions`(`id`,`name`) values (363,'Command: disable remove outdoorpvp');
insert  into `rbac_permissions`(`id`,`name`) values (364,'Command: disable remove quest');
insert  into `rbac_permissions`(`id`,`name`) values (365,'Command: disable remove spell');
insert  into `rbac_permissions`(`id`,`name`) values (366,'Command: disable remove vmap');
insert  into `rbac_permissions`(`id`,`name`) values (367,'Command: event');
insert  into `rbac_permissions`(`id`,`name`) values (368,'Command: event activelist');
insert  into `rbac_permissions`(`id`,`name`) values (369,'Command: event start');
insert  into `rbac_permissions`(`id`,`name`) values (370,'Command: event stop');
insert  into `rbac_permissions`(`id`,`name`) values (371,'Command: gm');
insert  into `rbac_permissions`(`id`,`name`) values (372,'Command: gm chat');
insert  into `rbac_permissions`(`id`,`name`) values (373,'Command: gm fly');
insert  into `rbac_permissions`(`id`,`name`) values (374,'Command: gm ingame');
insert  into `rbac_permissions`(`id`,`name`) values (375,'Command: gm list');
insert  into `rbac_permissions`(`id`,`name`) values (376,'Command: gm visible');
insert  into `rbac_permissions`(`id`,`name`) values (377,'Command: go');
insert  into `rbac_permissions`(`id`,`name`) values (378,'Command: go creature');
insert  into `rbac_permissions`(`id`,`name`) values (379,'Command: go graveyard');
insert  into `rbac_permissions`(`id`,`name`) values (380,'Command: go grid');
insert  into `rbac_permissions`(`id`,`name`) values (381,'Command: go object');
insert  into `rbac_permissions`(`id`,`name`) values (382,'Command: go taxinode');
insert  into `rbac_permissions`(`id`,`name`) values (383,'Command: go ticket');
insert  into `rbac_permissions`(`id`,`name`) values (384,'Command: go trigger');
insert  into `rbac_permissions`(`id`,`name`) values (385,'Command: go xyz');
insert  into `rbac_permissions`(`id`,`name`) values (386,'Command: go zonexy');
insert  into `rbac_permissions`(`id`,`name`) values (387,'Command: gobject');
insert  into `rbac_permissions`(`id`,`name`) values (388,'Command: gobject activate');
insert  into `rbac_permissions`(`id`,`name`) values (389,'Command: gobject add');
insert  into `rbac_permissions`(`id`,`name`) values (390,'Command: gobject add temp');
insert  into `rbac_permissions`(`id`,`name`) values (391,'Command: gobject delete');
insert  into `rbac_permissions`(`id`,`name`) values (392,'Command: gobject info');
insert  into `rbac_permissions`(`id`,`name`) values (393,'Command: gobject move');
insert  into `rbac_permissions`(`id`,`name`) values (394,'Command: gobject near');
insert  into `rbac_permissions`(`id`,`name`) values (395,'Command: gobject set');
insert  into `rbac_permissions`(`id`,`name`) values (396,'Command: gobject set phase');
insert  into `rbac_permissions`(`id`,`name`) values (397,'Command: gobject set state');
insert  into `rbac_permissions`(`id`,`name`) values (398,'Command: gobject target');
insert  into `rbac_permissions`(`id`,`name`) values (399,'Command: gobject turn');
insert  into `rbac_permissions`(`id`,`name`) values (400,'debug transport');
insert  into `rbac_permissions`(`id`,`name`) values (401,'Command: guild');
insert  into `rbac_permissions`(`id`,`name`) values (402,'Command: guild create');
insert  into `rbac_permissions`(`id`,`name`) values (403,'Command: guild delete');
insert  into `rbac_permissions`(`id`,`name`) values (404,'Command: guild invite');
insert  into `rbac_permissions`(`id`,`name`) values (405,'Command: guild uninvite');
insert  into `rbac_permissions`(`id`,`name`) values (406,'Command: guild rank');
insert  into `rbac_permissions`(`id`,`name`) values (407,'Command: guild rename');
insert  into `rbac_permissions`(`id`,`name`) values (408,'Command: honor');
insert  into `rbac_permissions`(`id`,`name`) values (409,'Command: honor add');
insert  into `rbac_permissions`(`id`,`name`) values (410,'Command: honor add kill');
insert  into `rbac_permissions`(`id`,`name`) values (411,'Command: honor update');
insert  into `rbac_permissions`(`id`,`name`) values (412,'Command: instance');
insert  into `rbac_permissions`(`id`,`name`) values (413,'Command: instance listbinds');
insert  into `rbac_permissions`(`id`,`name`) values (414,'Command: instance unbind');
insert  into `rbac_permissions`(`id`,`name`) values (415,'Command: instance stats');
insert  into `rbac_permissions`(`id`,`name`) values (416,'Command: instance savedata');
insert  into `rbac_permissions`(`id`,`name`) values (417,'Command: learn');
insert  into `rbac_permissions`(`id`,`name`) values (418,'Command: learn all');
insert  into `rbac_permissions`(`id`,`name`) values (419,'Command: learn all my');
insert  into `rbac_permissions`(`id`,`name`) values (420,'Command: learn all my class');
insert  into `rbac_permissions`(`id`,`name`) values (421,'Command: learn all my pettalents');
insert  into `rbac_permissions`(`id`,`name`) values (422,'Command: learn all my spells');
insert  into `rbac_permissions`(`id`,`name`) values (423,'Command: learn all my talents');
insert  into `rbac_permissions`(`id`,`name`) values (424,'Command: learn all gm');
insert  into `rbac_permissions`(`id`,`name`) values (425,'Command: learn all crafts');
insert  into `rbac_permissions`(`id`,`name`) values (426,'Command: learn all default');
insert  into `rbac_permissions`(`id`,`name`) values (427,'Command: learn all lang');
insert  into `rbac_permissions`(`id`,`name`) values (428,'Command: learn all recipes');
insert  into `rbac_permissions`(`id`,`name`) values (429,'Command: unlearn');
insert  into `rbac_permissions`(`id`,`name`) values (430,'Command: lfg');
insert  into `rbac_permissions`(`id`,`name`) values (431,'Command: lfg player');
insert  into `rbac_permissions`(`id`,`name`) values (432,'Command: lfg group');
insert  into `rbac_permissions`(`id`,`name`) values (433,'Command: lfg queue');
insert  into `rbac_permissions`(`id`,`name`) values (434,'Command: lfg clean');
insert  into `rbac_permissions`(`id`,`name`) values (435,'Command: lfg options');
insert  into `rbac_permissions`(`id`,`name`) values (436,'Command: list');
insert  into `rbac_permissions`(`id`,`name`) values (437,'Command: list creature');
insert  into `rbac_permissions`(`id`,`name`) values (438,'Command: list item');
insert  into `rbac_permissions`(`id`,`name`) values (439,'Command: list object');
insert  into `rbac_permissions`(`id`,`name`) values (440,'Command: list auras');
insert  into `rbac_permissions`(`id`,`name`) values (441,'Command: list mail');
insert  into `rbac_permissions`(`id`,`name`) values (442,'Command: lookup');
insert  into `rbac_permissions`(`id`,`name`) values (443,'Command: lookup area');
insert  into `rbac_permissions`(`id`,`name`) values (444,'Command: lookup creature');
insert  into `rbac_permissions`(`id`,`name`) values (445,'Command: lookup event');
insert  into `rbac_permissions`(`id`,`name`) values (446,'Command: lookup faction');
insert  into `rbac_permissions`(`id`,`name`) values (447,'Command: lookup item');
insert  into `rbac_permissions`(`id`,`name`) values (448,'Command: lookup itemset');
insert  into `rbac_permissions`(`id`,`name`) values (449,'Command: lookup object');
insert  into `rbac_permissions`(`id`,`name`) values (450,'Command: lookup quest');
insert  into `rbac_permissions`(`id`,`name`) values (451,'Command: lookup player');
insert  into `rbac_permissions`(`id`,`name`) values (452,'Command: lookup player ip');
insert  into `rbac_permissions`(`id`,`name`) values (453,'Command: lookup player account');
insert  into `rbac_permissions`(`id`,`name`) values (454,'Command: lookup player email');
insert  into `rbac_permissions`(`id`,`name`) values (455,'Command: lookup skill');
insert  into `rbac_permissions`(`id`,`name`) values (456,'Command: lookup spell');
insert  into `rbac_permissions`(`id`,`name`) values (457,'Command: lookup spell id');
insert  into `rbac_permissions`(`id`,`name`) values (458,'Command: lookup taxinode');
insert  into `rbac_permissions`(`id`,`name`) values (459,'Command: lookup tele');
insert  into `rbac_permissions`(`id`,`name`) values (460,'Command: lookup title');
insert  into `rbac_permissions`(`id`,`name`) values (461,'Command: lookup map');
insert  into `rbac_permissions`(`id`,`name`) values (462,'Command: announce');
insert  into `rbac_permissions`(`id`,`name`) values (463,'Command: channel');
insert  into `rbac_permissions`(`id`,`name`) values (464,'Command: channel set');
insert  into `rbac_permissions`(`id`,`name`) values (465,'Command: channel set ownership');
insert  into `rbac_permissions`(`id`,`name`) values (466,'Command: gmannounce');
insert  into `rbac_permissions`(`id`,`name`) values (467,'Command: gmnameannounce');
insert  into `rbac_permissions`(`id`,`name`) values (468,'Command: gmnotify');
insert  into `rbac_permissions`(`id`,`name`) values (469,'Command: nameannounce');
insert  into `rbac_permissions`(`id`,`name`) values (470,'Command: notify');
insert  into `rbac_permissions`(`id`,`name`) values (471,'Command: whispers');
insert  into `rbac_permissions`(`id`,`name`) values (472,'Command: group');
insert  into `rbac_permissions`(`id`,`name`) values (473,'Command: group leader');
insert  into `rbac_permissions`(`id`,`name`) values (474,'Command: group disband');
insert  into `rbac_permissions`(`id`,`name`) values (475,'Command: group remove');
insert  into `rbac_permissions`(`id`,`name`) values (476,'Command: group join');
insert  into `rbac_permissions`(`id`,`name`) values (477,'Command: group list');
insert  into `rbac_permissions`(`id`,`name`) values (478,'Command: group summon');
insert  into `rbac_permissions`(`id`,`name`) values (479,'Command: pet');
insert  into `rbac_permissions`(`id`,`name`) values (480,'Command: pet create');
insert  into `rbac_permissions`(`id`,`name`) values (481,'Command: pet learn');
insert  into `rbac_permissions`(`id`,`name`) values (482,'Command: pet unlearn');
insert  into `rbac_permissions`(`id`,`name`) values (483,'Command: send');
insert  into `rbac_permissions`(`id`,`name`) values (484,'Command: send items');
insert  into `rbac_permissions`(`id`,`name`) values (485,'Command: send mail');
insert  into `rbac_permissions`(`id`,`name`) values (486,'Command: send message');
insert  into `rbac_permissions`(`id`,`name`) values (487,'Command: send money');
insert  into `rbac_permissions`(`id`,`name`) values (488,'Command: additem');
insert  into `rbac_permissions`(`id`,`name`) values (489,'Command: additemset');
insert  into `rbac_permissions`(`id`,`name`) values (490,'Command: appear');
insert  into `rbac_permissions`(`id`,`name`) values (491,'Command: aura');
insert  into `rbac_permissions`(`id`,`name`) values (492,'Command: bank');
insert  into `rbac_permissions`(`id`,`name`) values (493,'Command: bindsight');
insert  into `rbac_permissions`(`id`,`name`) values (494,'Command: combatstop');
insert  into `rbac_permissions`(`id`,`name`) values (495,'Command: cometome');
insert  into `rbac_permissions`(`id`,`name`) values (496,'Command: commands');
insert  into `rbac_permissions`(`id`,`name`) values (497,'Command: cooldown');
insert  into `rbac_permissions`(`id`,`name`) values (498,'Command: damage');
insert  into `rbac_permissions`(`id`,`name`) values (499,'Command: dev');
insert  into `rbac_permissions`(`id`,`name`) values (500,'Command: die');
insert  into `rbac_permissions`(`id`,`name`) values (501,'Command: dismount');
insert  into `rbac_permissions`(`id`,`name`) values (502,'Command: distance');
insert  into `rbac_permissions`(`id`,`name`) values (503,'Command: flusharenapoints');
insert  into `rbac_permissions`(`id`,`name`) values (504,'Command: freeze');
insert  into `rbac_permissions`(`id`,`name`) values (505,'Command: gps');
insert  into `rbac_permissions`(`id`,`name`) values (506,'Command: guid');
insert  into `rbac_permissions`(`id`,`name`) values (507,'Command: help');
insert  into `rbac_permissions`(`id`,`name`) values (508,'Command: hidearea');
insert  into `rbac_permissions`(`id`,`name`) values (509,'Command: itemmove');
insert  into `rbac_permissions`(`id`,`name`) values (510,'Command: kick');
insert  into `rbac_permissions`(`id`,`name`) values (511,'Command: linkgrave');
insert  into `rbac_permissions`(`id`,`name`) values (512,'Command: listfreeze');
insert  into `rbac_permissions`(`id`,`name`) values (513,'Command: maxskill');
insert  into `rbac_permissions`(`id`,`name`) values (514,'Command: movegens');
insert  into `rbac_permissions`(`id`,`name`) values (515,'Command: mute');
insert  into `rbac_permissions`(`id`,`name`) values (516,'Command: neargrave');
insert  into `rbac_permissions`(`id`,`name`) values (517,'Command: pinfo');
insert  into `rbac_permissions`(`id`,`name`) values (518,'Command: playall');
insert  into `rbac_permissions`(`id`,`name`) values (519,'Command: possess');
insert  into `rbac_permissions`(`id`,`name`) values (520,'Command: recall');
insert  into `rbac_permissions`(`id`,`name`) values (521,'Command: repairitems');
insert  into `rbac_permissions`(`id`,`name`) values (522,'Command: respawn');
insert  into `rbac_permissions`(`id`,`name`) values (523,'Command: revive');
insert  into `rbac_permissions`(`id`,`name`) values (524,'Command: saveall');
insert  into `rbac_permissions`(`id`,`name`) values (525,'Command: save');
insert  into `rbac_permissions`(`id`,`name`) values (526,'Command: setskill');
insert  into `rbac_permissions`(`id`,`name`) values (527,'Command: showarea');
insert  into `rbac_permissions`(`id`,`name`) values (528,'Command: summon');
insert  into `rbac_permissions`(`id`,`name`) values (529,'Command: unaura');
insert  into `rbac_permissions`(`id`,`name`) values (530,'Command: unbindsight');
insert  into `rbac_permissions`(`id`,`name`) values (531,'Command: unfreeze');
insert  into `rbac_permissions`(`id`,`name`) values (532,'Command: unmute');
insert  into `rbac_permissions`(`id`,`name`) values (533,'Command: unpossess');
insert  into `rbac_permissions`(`id`,`name`) values (534,'Command: unstuck');
insert  into `rbac_permissions`(`id`,`name`) values (535,'Command: wchange');
insert  into `rbac_permissions`(`id`,`name`) values (536,'Command: mmap');
insert  into `rbac_permissions`(`id`,`name`) values (537,'Command: mmap loadedtiles');
insert  into `rbac_permissions`(`id`,`name`) values (538,'Command: mmap loc');
insert  into `rbac_permissions`(`id`,`name`) values (539,'Command: mmap path');
insert  into `rbac_permissions`(`id`,`name`) values (540,'Command: mmap stats');
insert  into `rbac_permissions`(`id`,`name`) values (541,'Command: mmap testarea');
insert  into `rbac_permissions`(`id`,`name`) values (542,'Command: morph');
insert  into `rbac_permissions`(`id`,`name`) values (543,'Command: demorph');
insert  into `rbac_permissions`(`id`,`name`) values (544,'Command: modify');
insert  into `rbac_permissions`(`id`,`name`) values (545,'Command: modify arenapoints');
insert  into `rbac_permissions`(`id`,`name`) values (546,'Command: modify bit');
insert  into `rbac_permissions`(`id`,`name`) values (547,'Command: modify drunk');
insert  into `rbac_permissions`(`id`,`name`) values (548,'Command: modify energy');
insert  into `rbac_permissions`(`id`,`name`) values (549,'Command: modify faction');
insert  into `rbac_permissions`(`id`,`name`) values (550,'Command: modify gender');
insert  into `rbac_permissions`(`id`,`name`) values (551,'Command: modify honor');
insert  into `rbac_permissions`(`id`,`name`) values (552,'Command: modify hp');
insert  into `rbac_permissions`(`id`,`name`) values (553,'Command: modify mana');
insert  into `rbac_permissions`(`id`,`name`) values (554,'Command: modify money');
insert  into `rbac_permissions`(`id`,`name`) values (555,'Command: modify mount');
insert  into `rbac_permissions`(`id`,`name`) values (556,'Command: modify phase');
insert  into `rbac_permissions`(`id`,`name`) values (557,'Command: modify rage');
insert  into `rbac_permissions`(`id`,`name`) values (558,'Command: modify reputation');
insert  into `rbac_permissions`(`id`,`name`) values (559,'Command: modify runicpower');
insert  into `rbac_permissions`(`id`,`name`) values (560,'Command: modify scale');
insert  into `rbac_permissions`(`id`,`name`) values (561,'Command: modify speed');
insert  into `rbac_permissions`(`id`,`name`) values (562,'Command: modify speed all');
insert  into `rbac_permissions`(`id`,`name`) values (563,'Command: modify speed backwalk');
insert  into `rbac_permissions`(`id`,`name`) values (564,'Command: modify speed fly');
insert  into `rbac_permissions`(`id`,`name`) values (565,'Command: modify speed walk');
insert  into `rbac_permissions`(`id`,`name`) values (566,'Command: modify speed swim');
insert  into `rbac_permissions`(`id`,`name`) values (567,'Command: modify spell');
insert  into `rbac_permissions`(`id`,`name`) values (568,'Command: modify standstate');
insert  into `rbac_permissions`(`id`,`name`) values (569,'Command: modify talentpoints');
insert  into `rbac_permissions`(`id`,`name`) values (570,'Command: npc');
insert  into `rbac_permissions`(`id`,`name`) values (571,'Command: npc add');
insert  into `rbac_permissions`(`id`,`name`) values (572,'Command: npc add formation');
insert  into `rbac_permissions`(`id`,`name`) values (573,'Command: npc add item');
insert  into `rbac_permissions`(`id`,`name`) values (574,'Command: npc add move');
insert  into `rbac_permissions`(`id`,`name`) values (575,'Command: npc add temp');
insert  into `rbac_permissions`(`id`,`name`) values (576,'Command: npc add delete');
insert  into `rbac_permissions`(`id`,`name`) values (577,'Command: npc add delete item');
insert  into `rbac_permissions`(`id`,`name`) values (578,'Command: npc add follow');
insert  into `rbac_permissions`(`id`,`name`) values (579,'Command: npc add follow stop');
insert  into `rbac_permissions`(`id`,`name`) values (580,'Command: npc set');
insert  into `rbac_permissions`(`id`,`name`) values (581,'Command: npc set allowmove');
insert  into `rbac_permissions`(`id`,`name`) values (582,'Command: npc set entry');
insert  into `rbac_permissions`(`id`,`name`) values (583,'Command: npc set factionid');
insert  into `rbac_permissions`(`id`,`name`) values (584,'Command: npc set flag');
insert  into `rbac_permissions`(`id`,`name`) values (585,'Command: npc set level');
insert  into `rbac_permissions`(`id`,`name`) values (586,'Command: npc set link');
insert  into `rbac_permissions`(`id`,`name`) values (587,'Command: npc set model');
insert  into `rbac_permissions`(`id`,`name`) values (588,'Command: npc set movetype');
insert  into `rbac_permissions`(`id`,`name`) values (589,'Command: npc set phase');
insert  into `rbac_permissions`(`id`,`name`) values (590,'Command: npc set spawndist');
insert  into `rbac_permissions`(`id`,`name`) values (591,'Command: npc set spawntime');
insert  into `rbac_permissions`(`id`,`name`) values (592,'Command: npc set data');
insert  into `rbac_permissions`(`id`,`name`) values (593,'Command: npc info');
insert  into `rbac_permissions`(`id`,`name`) values (594,'Command: npc near');
insert  into `rbac_permissions`(`id`,`name`) values (595,'Command: npc move');
insert  into `rbac_permissions`(`id`,`name`) values (596,'Command: npc playemote');
insert  into `rbac_permissions`(`id`,`name`) values (597,'Command: npc say');
insert  into `rbac_permissions`(`id`,`name`) values (598,'Command: npc textemote');
insert  into `rbac_permissions`(`id`,`name`) values (599,'Command: npc whisper');
insert  into `rbac_permissions`(`id`,`name`) values (600,'Command: npc yell');
insert  into `rbac_permissions`(`id`,`name`) values (601,'Command: npc tame');
insert  into `rbac_permissions`(`id`,`name`) values (602,'Command: quest');
insert  into `rbac_permissions`(`id`,`name`) values (603,'Command: quest add');
insert  into `rbac_permissions`(`id`,`name`) values (604,'Command: quest complete');
insert  into `rbac_permissions`(`id`,`name`) values (605,'Command: quest remove');
insert  into `rbac_permissions`(`id`,`name`) values (606,'Command: quest reward');
insert  into `rbac_permissions`(`id`,`name`) values (607,'Command: reload');
insert  into `rbac_permissions`(`id`,`name`) values (608,'Command: reload access_requirement');
insert  into `rbac_permissions`(`id`,`name`) values (609,'Command: reload achievement_criteria_data');
insert  into `rbac_permissions`(`id`,`name`) values (610,'Command: reload achievement_reward');
insert  into `rbac_permissions`(`id`,`name`) values (611,'Command: reload all');
insert  into `rbac_permissions`(`id`,`name`) values (612,'Command: reload all achievement');
insert  into `rbac_permissions`(`id`,`name`) values (613,'Command: reload all area');
insert  into `rbac_permissions`(`id`,`name`) values (614,'Command: reload all eventai');
insert  into `rbac_permissions`(`id`,`name`) values (615,'Command: reload all gossips');
insert  into `rbac_permissions`(`id`,`name`) values (616,'Command: reload all item');
insert  into `rbac_permissions`(`id`,`name`) values (617,'Command: reload all locales');
insert  into `rbac_permissions`(`id`,`name`) values (618,'Command: reload all loot');
insert  into `rbac_permissions`(`id`,`name`) values (619,'Command: reload all npc');
insert  into `rbac_permissions`(`id`,`name`) values (620,'Command: reload all quest');
insert  into `rbac_permissions`(`id`,`name`) values (621,'Command: reload all scripts');
insert  into `rbac_permissions`(`id`,`name`) values (622,'Command: reload all spell');
insert  into `rbac_permissions`(`id`,`name`) values (623,'Command: reload areatrigger_involvedrelation');
insert  into `rbac_permissions`(`id`,`name`) values (624,'Command: reload areatrigger_tavern');
insert  into `rbac_permissions`(`id`,`name`) values (625,'Command: reload areatrigger_teleport');
insert  into `rbac_permissions`(`id`,`name`) values (626,'Command: reload auctions');
insert  into `rbac_permissions`(`id`,`name`) values (627,'Command: reload autobroadcast');
insert  into `rbac_permissions`(`id`,`name`) values (628,'Command: reload command');
insert  into `rbac_permissions`(`id`,`name`) values (629,'Command: reload conditions');
insert  into `rbac_permissions`(`id`,`name`) values (630,'Command: reload config');
insert  into `rbac_permissions`(`id`,`name`) values (631,'Command: reload creature_text');
insert  into `rbac_permissions`(`id`,`name`) values (632,'Command: reload creature_ai_scripts');
insert  into `rbac_permissions`(`id`,`name`) values (633,'Command: reload creature_ai_texts');
insert  into `rbac_permissions`(`id`,`name`) values (634,'Command: reload creature_questender');
insert  into `rbac_permissions`(`id`,`name`) values (635,'Command: reload creature_linked_respawn');
insert  into `rbac_permissions`(`id`,`name`) values (636,'Command: reload creature_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (637,'Command: reload creature_onkill_reputation');
insert  into `rbac_permissions`(`id`,`name`) values (638,'Command: reload creature_queststarter');
insert  into `rbac_permissions`(`id`,`name`) values (639,'Command: reload creature_summon_groups');
insert  into `rbac_permissions`(`id`,`name`) values (640,'Command: reload creature_template');
insert  into `rbac_permissions`(`id`,`name`) values (641,'Command: reload disables');
insert  into `rbac_permissions`(`id`,`name`) values (642,'Command: reload disenchant_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (643,'Command: reload event_scripts');
insert  into `rbac_permissions`(`id`,`name`) values (644,'Command: reload fishing_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (645,'Command: reload game_graveyard_zone');
insert  into `rbac_permissions`(`id`,`name`) values (646,'Command: reload game_tele');
insert  into `rbac_permissions`(`id`,`name`) values (647,'Command: reload gameobject_questender');
insert  into `rbac_permissions`(`id`,`name`) values (648,'Command: reload gameobject_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (649,'Command: reload gameobject_queststarter');
insert  into `rbac_permissions`(`id`,`name`) values (650,'Command: reload gm_tickets');
insert  into `rbac_permissions`(`id`,`name`) values (651,'Command: reload gossip_menu');
insert  into `rbac_permissions`(`id`,`name`) values (652,'Command: reload gossip_menu_option');
insert  into `rbac_permissions`(`id`,`name`) values (653,'Command: reload item_enchantment_template');
insert  into `rbac_permissions`(`id`,`name`) values (654,'Command: reload item_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (655,'Command: reload item_set_names');
insert  into `rbac_permissions`(`id`,`name`) values (656,'Command: reload lfg_dungeon_rewards');
insert  into `rbac_permissions`(`id`,`name`) values (657,'Command: reload locales_achievement_reward');
insert  into `rbac_permissions`(`id`,`name`) values (658,'Command: reload locales_creature');
insert  into `rbac_permissions`(`id`,`name`) values (659,'Command: reload locales_creature_text');
insert  into `rbac_permissions`(`id`,`name`) values (660,'Command: reload locales_gameobject');
insert  into `rbac_permissions`(`id`,`name`) values (661,'Command: reload locales_gossip_menu_option');
insert  into `rbac_permissions`(`id`,`name`) values (662,'Command: reload locales_item');
insert  into `rbac_permissions`(`id`,`name`) values (663,'Command: reload locales_item_set_name');
insert  into `rbac_permissions`(`id`,`name`) values (664,'Command: reload locales_npc_text');
insert  into `rbac_permissions`(`id`,`name`) values (665,'Command: reload locales_page_text');
insert  into `rbac_permissions`(`id`,`name`) values (666,'Command: reload locales_points_of_interest');
insert  into `rbac_permissions`(`id`,`name`) values (667,'Command: reload locales_quest');
insert  into `rbac_permissions`(`id`,`name`) values (668,'Command: reload mail_level_reward');
insert  into `rbac_permissions`(`id`,`name`) values (669,'Command: reload mail_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (670,'Command: reload milling_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (671,'Command: reload npc_spellclick_spells');
insert  into `rbac_permissions`(`id`,`name`) values (672,'Command: reload npc_trainer');
insert  into `rbac_permissions`(`id`,`name`) values (673,'Command: reload npc_vendor');
insert  into `rbac_permissions`(`id`,`name`) values (674,'Command: reload page_text');
insert  into `rbac_permissions`(`id`,`name`) values (675,'Command: reload pickpocketing_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (676,'Command: reload points_of_interest');
insert  into `rbac_permissions`(`id`,`name`) values (677,'Command: reload prospecting_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (678,'Command: reload quest_poi');
insert  into `rbac_permissions`(`id`,`name`) values (679,'Command: reload quest_template');
insert  into `rbac_permissions`(`id`,`name`) values (680,'Command: reload rbac');
insert  into `rbac_permissions`(`id`,`name`) values (681,'Command: reload reference_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (682,'Command: reload reserved_name');
insert  into `rbac_permissions`(`id`,`name`) values (683,'Command: reload reputation_reward_rate');
insert  into `rbac_permissions`(`id`,`name`) values (684,'Command: reload reputation_spillover_template');
insert  into `rbac_permissions`(`id`,`name`) values (685,'Command: reload skill_discovery_template');
insert  into `rbac_permissions`(`id`,`name`) values (686,'Command: reload skill_extra_item_template');
insert  into `rbac_permissions`(`id`,`name`) values (687,'Command: reload skill_fishing_base_level');
insert  into `rbac_permissions`(`id`,`name`) values (688,'Command: reload skinning_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (689,'Command: reload smart_scripts');
insert  into `rbac_permissions`(`id`,`name`) values (690,'Command: reload spell_required');
insert  into `rbac_permissions`(`id`,`name`) values (691,'Command: reload spell_area');
insert  into `rbac_permissions`(`id`,`name`) values (692,'Command: reload spell_bonus_data');
insert  into `rbac_permissions`(`id`,`name`) values (693,'Command: reload spell_group');
insert  into `rbac_permissions`(`id`,`name`) values (694,'Command: reload spell_learn_spell');
insert  into `rbac_permissions`(`id`,`name`) values (695,'Command: reload spell_loot_template');
insert  into `rbac_permissions`(`id`,`name`) values (696,'Command: reload spell_linked_spell');
insert  into `rbac_permissions`(`id`,`name`) values (697,'Command: reload spell_pet_auras');
insert  into `rbac_permissions`(`id`,`name`) values (698,'Command: reload spell_proc_event');
insert  into `rbac_permissions`(`id`,`name`) values (699,'Command: reload spell_proc');
insert  into `rbac_permissions`(`id`,`name`) values (700,'Command: reload spell_scripts');
insert  into `rbac_permissions`(`id`,`name`) values (701,'Command: reload spell_target_position');
insert  into `rbac_permissions`(`id`,`name`) values (702,'Command: reload spell_threats');
insert  into `rbac_permissions`(`id`,`name`) values (703,'Command: reload spell_group_stack_rules');
insert  into `rbac_permissions`(`id`,`name`) values (704,'Command: reload trinity_string');
insert  into `rbac_permissions`(`id`,`name`) values (705,'Command: reload warden_action');
insert  into `rbac_permissions`(`id`,`name`) values (706,'Command: reload waypoint_scripts');
insert  into `rbac_permissions`(`id`,`name`) values (707,'Command: reload waypoint_data');
insert  into `rbac_permissions`(`id`,`name`) values (708,'Command: reload vehicle_accessory');
insert  into `rbac_permissions`(`id`,`name`) values (709,'Command: reload vehicle_template_accessory');
insert  into `rbac_permissions`(`id`,`name`) values (710,'Command: reset');
insert  into `rbac_permissions`(`id`,`name`) values (711,'Command: reset achievements');
insert  into `rbac_permissions`(`id`,`name`) values (712,'Command: reset honor');
insert  into `rbac_permissions`(`id`,`name`) values (713,'Command: reset level');
insert  into `rbac_permissions`(`id`,`name`) values (714,'Command: reset spells');
insert  into `rbac_permissions`(`id`,`name`) values (715,'Command: reset stats');
insert  into `rbac_permissions`(`id`,`name`) values (716,'Command: reset talents');
insert  into `rbac_permissions`(`id`,`name`) values (717,'Command: reset all');
insert  into `rbac_permissions`(`id`,`name`) values (718,'Command: server');
insert  into `rbac_permissions`(`id`,`name`) values (719,'Command: server corpses');
insert  into `rbac_permissions`(`id`,`name`) values (720,'Command: server exit');
insert  into `rbac_permissions`(`id`,`name`) values (721,'Command: server idlerestart');
insert  into `rbac_permissions`(`id`,`name`) values (722,'Command: server idlerestart cancel');
insert  into `rbac_permissions`(`id`,`name`) values (723,'Command: server idleshutdown');
insert  into `rbac_permissions`(`id`,`name`) values (724,'Command: server idleshutdown cancel');
insert  into `rbac_permissions`(`id`,`name`) values (725,'Command: server info');
insert  into `rbac_permissions`(`id`,`name`) values (726,'Command: server plimit');
insert  into `rbac_permissions`(`id`,`name`) values (727,'Command: server restart');
insert  into `rbac_permissions`(`id`,`name`) values (728,'Command: server restart cancel');
insert  into `rbac_permissions`(`id`,`name`) values (729,'Command: server set');
insert  into `rbac_permissions`(`id`,`name`) values (730,'Command: server set closed');
insert  into `rbac_permissions`(`id`,`name`) values (731,'Command: server set difftime');
insert  into `rbac_permissions`(`id`,`name`) values (732,'Command: server set loglevel');
insert  into `rbac_permissions`(`id`,`name`) values (733,'Command: server set motd');
insert  into `rbac_permissions`(`id`,`name`) values (734,'Command: server shutdown');
insert  into `rbac_permissions`(`id`,`name`) values (735,'Command: server shutdown cancel');
insert  into `rbac_permissions`(`id`,`name`) values (736,'Command: server motd');
insert  into `rbac_permissions`(`id`,`name`) values (737,'Command: tele');
insert  into `rbac_permissions`(`id`,`name`) values (738,'Command: tele add');
insert  into `rbac_permissions`(`id`,`name`) values (739,'Command: tele del');
insert  into `rbac_permissions`(`id`,`name`) values (740,'Command: tele name');
insert  into `rbac_permissions`(`id`,`name`) values (741,'Command: tele group');
insert  into `rbac_permissions`(`id`,`name`) values (742,'Command: ticket');
insert  into `rbac_permissions`(`id`,`name`) values (743,'Command: ticket assign');
insert  into `rbac_permissions`(`id`,`name`) values (744,'Command: ticket close');
insert  into `rbac_permissions`(`id`,`name`) values (745,'Command: ticket closedlist');
insert  into `rbac_permissions`(`id`,`name`) values (746,'Command: ticket comment');
insert  into `rbac_permissions`(`id`,`name`) values (747,'Command: ticket complete');
insert  into `rbac_permissions`(`id`,`name`) values (748,'Command: ticket delete');
insert  into `rbac_permissions`(`id`,`name`) values (749,'Command: ticket escalate');
insert  into `rbac_permissions`(`id`,`name`) values (750,'Command: ticket escalatedlist');
insert  into `rbac_permissions`(`id`,`name`) values (751,'Command: ticket list');
insert  into `rbac_permissions`(`id`,`name`) values (752,'Command: ticket onlinelist');
insert  into `rbac_permissions`(`id`,`name`) values (753,'Command: ticket reset');
insert  into `rbac_permissions`(`id`,`name`) values (754,'Command: ticket response');
insert  into `rbac_permissions`(`id`,`name`) values (755,'Command: ticket response append');
insert  into `rbac_permissions`(`id`,`name`) values (756,'Command: ticket response appendln');
insert  into `rbac_permissions`(`id`,`name`) values (757,'Command: ticket togglesystem');
insert  into `rbac_permissions`(`id`,`name`) values (758,'Command: ticket unassign');
insert  into `rbac_permissions`(`id`,`name`) values (759,'Command: ticket viewid');
insert  into `rbac_permissions`(`id`,`name`) values (760,'Command: ticket viewname');
insert  into `rbac_permissions`(`id`,`name`) values (761,'Command: titles');
insert  into `rbac_permissions`(`id`,`name`) values (762,'Command: titles add');
insert  into `rbac_permissions`(`id`,`name`) values (763,'Command: titles current');
insert  into `rbac_permissions`(`id`,`name`) values (764,'Command: titles remove');
insert  into `rbac_permissions`(`id`,`name`) values (765,'Command: titles set');
insert  into `rbac_permissions`(`id`,`name`) values (766,'Command: titles set mask');
insert  into `rbac_permissions`(`id`,`name`) values (767,'Command: wp');
insert  into `rbac_permissions`(`id`,`name`) values (768,'Command: wp add');
insert  into `rbac_permissions`(`id`,`name`) values (769,'Command: wp event');
insert  into `rbac_permissions`(`id`,`name`) values (770,'Command: wp load');
insert  into `rbac_permissions`(`id`,`name`) values (771,'Command: wp modify');
insert  into `rbac_permissions`(`id`,`name`) values (772,'Command: wp unload');
insert  into `rbac_permissions`(`id`,`name`) values (773,'Command: wp reload');
insert  into `rbac_permissions`(`id`,`name`) values (774,'Command: wp show');
insert  into `rbac_permissions`(`id`,`name`) values (776,'Command: debug phase');
insert  into `rbac_permissions`(`id`,`name`) values (1002,'Command: qc');
insert  into `rbac_permissions`(`id`,`name`) values (1003,'Command: qc status');
insert  into `rbac_permissions`(`id`,`name`) values (1004,'Command: qc add');
insert  into `rbac_permissions`(`id`,`name`) values (1005,'Command: qc del');
insert  into `rbac_permissions`(`id`,`name`) values (1006,'Command: mall');
insert  into `rbac_permissions`(`id`,`name`) values (1007,'Command: chat');

/*Table structure for table `realm_classes` */

DROP TABLE IF EXISTS `realm_classes`;

CREATE TABLE `realm_classes` (
  `realmId` int(11) NOT NULL,
  `class` tinyint(4) NOT NULL COMMENT 'Class Id',
  `expansion` tinyint(4) NOT NULL COMMENT 'Expansion for class activation',
  PRIMARY KEY (`realmId`,`class`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `realm_classes` */

insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,1,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,2,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,3,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,4,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,5,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,6,2);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,7,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,8,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,9,0);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,10,4);
insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,11,0);

/*Table structure for table `realm_races` */

DROP TABLE IF EXISTS `realm_races`;

CREATE TABLE `realm_races` (
  `realmId` int(11) NOT NULL,
  `race` tinyint(4) NOT NULL COMMENT 'Race Id',
  `expansion` tinyint(4) NOT NULL COMMENT 'Expansion for race activation',
  PRIMARY KEY (`realmId`,`race`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `realm_races` */

insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,1,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,2,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,3,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,4,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,5,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,6,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,7,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,8,0);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,9,3);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,10,1);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,11,1);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,22,3);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,24,4);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,25,4);
insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,26,4);

/*Table structure for table `realmcharacters` */

DROP TABLE IF EXISTS `realmcharacters`;

CREATE TABLE `realmcharacters` (
  `realmid` int(10) unsigned NOT NULL DEFAULT '0',
  `acctid` int(10) unsigned NOT NULL,
  `numchars` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`realmid`,`acctid`),
  KEY `acctid` (`acctid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Realm Character Tracker';

/*Data for the table `realmcharacters` */

/*Table structure for table `realmlist` */

DROP TABLE IF EXISTS `realmlist`;

CREATE TABLE `realmlist` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL DEFAULT '',
  `address` varchar(255) NOT NULL DEFAULT '127.0.0.1',
  `localAddress` varchar(255) NOT NULL DEFAULT '127.0.0.1',
  `localSubnetMask` varchar(255) NOT NULL DEFAULT '255.255.255.0',
  `port` smallint(5) unsigned NOT NULL DEFAULT '8085',
  `icon` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `flag` tinyint(3) unsigned NOT NULL DEFAULT '2',
  `timezone` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `allowedSecurityLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `population` float unsigned NOT NULL DEFAULT '0',
  `gamebuild` int(10) unsigned NOT NULL DEFAULT '18414',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='Realm System';

/*Data for the table `realmlist` */

insert  into `realmlist`(`id`,`name`,`address`,`localAddress`,`localSubnetMask`,`port`,`icon`,`flag`,`timezone`,`allowedSecurityLevel`,`population`,`gamebuild`) values (1,'WoWSource548','127.0.0.1','127.0.0.1','255.255.255.0',8085,0,0,1,0,0,18414);

/*Table structure for table `uptime` */

DROP TABLE IF EXISTS `uptime`;

CREATE TABLE `uptime` (
  `realmid` int(10) unsigned NOT NULL,
  `starttime` int(10) unsigned NOT NULL DEFAULT '0',
  `uptime` int(10) unsigned NOT NULL DEFAULT '0',
  `maxplayers` smallint(5) unsigned NOT NULL DEFAULT '0',
  `revision` varchar(255) NOT NULL DEFAULT '5.4.8',
  PRIMARY KEY (`realmid`,`starttime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Uptime system';

/*Data for the table `uptime` */

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
