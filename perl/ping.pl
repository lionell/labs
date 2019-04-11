#!/usr/bin/env perl

# ping util
#
# Usage:
# sudo ./ping.pl lun.ua
# ICMP ip=46.101.136.215 time=64.3ms
# ICMP ip=46.101.136.215 time=46.9ms
# ICMP ip=46.101.136.215 time=43.8ms
# ICMP ip=46.101.136.215 time=39.8ms
# ^C

use strict;
use warnings;
use feature "say";
use Net::Ping;

my $p = Net::Ping->new("icmp");
while (1) {
    my ($status, $time, $ip) = $p->ping(shift);
    if ($status) {
        printf "ICMP $ip time=%0.1fms\n", 1000 * $time;
    } else {
        say "Server is not reachable";
    }
    sleep(1);
}
$p->close();
