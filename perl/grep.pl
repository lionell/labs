#!/usr/bin/env perl

# grep util
#
# Usage:
# $ ifconfig | ./grep.pl broadcast
# inet 172.18.0.1  netmask 255.255.0.0  broadcast 172.18.255.255
# inet 172.19.0.1  netmask 255.255.0.0  broadcast 172.19.255.255
# inet 172.17.0.1  netmask 255.255.0.0  broadcast 172.17.255.255
# inet 192.168.0.107  netmask 255.255.255.0  broadcast 192.168.0.255

use strict;
use warnings;

my $word = shift;
for (<STDIN>) {
    print if $_ =~ /$word/;
}
