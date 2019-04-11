#!/usr/bin/env perl

# List files on FTP server
#
# Usage:
# ./ftp.pl speedtest.tele2.net anonymous super_hard_password
# Listing files on server...
# 1000GB.zip
# 100GB.zip
# 100KB.zip
# 100MB.zip
# 10GB.zip
# 10MB.zip
# 1GB.zip
# 1KB.zip
# 1MB.zip
# 200MB.zip
# 20MB.zip
# 2MB.zip
# 3MB.zip
# 500MB.zip
# 50MB.zip
# 512KB.zip
# 5MB.zip
# upload

use strict;
use warnings;
use feature "say";
use Net::FTP;

my ($host, $login, $password) = @ARGV;
my $ftp = Net::FTP->new($host) or die $!;
$ftp->login($login, $password) or die $ftp->message;
say "Listing files on server...";
say join "\n", $ftp->ls or die $ftp->message;
$ftp->quit;
