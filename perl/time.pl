#!/usr/bin/env perl

# time util
#
# Usage:
# $ ./time.pl sleep 5
# Execution took 5 seconds.
#
# $ ./time.pl ping www.google.com
# PING www.google.com (172.217.20.196) 56(84) bytes of data.
# 64 bytes from waw02s08-in-f4.1e100.net (172.217.20.196): icmp_seq=1 ttl=54 time=29.5 ms
# 64 bytes from waw02s08-in-f4.1e100.net (172.217.20.196): icmp_seq=2 ttl=54 time=27.5 ms
# 64 bytes from waw02s08-in-f4.1e100.net (172.217.20.196): icmp_seq=3 ttl=54 time=29.7 ms
# 64 bytes from waw02s08-in-f4.1e100.net (172.217.20.196): icmp_seq=4 ttl=54 time=26.1 ms
# 64 bytes from waw02s08-in-f4.1e100.net (172.217.20.196): icmp_seq=5 ttl=54 time=38.8 ms
# ^C
# --- www.google.com ping statistics ---
# 5 packets transmitted, 5 received, 0% packet loss, time 10ms
# rtt min/avg/max/mdev = 26.140/30.340/38.824/4.443 ms
# Execution took 5 seconds.

use strict;
use warnings;
use feature "say";

my $start = time;
system join " ", @ARGV;
say "Execution took ", (time - $start), " seconds.";
