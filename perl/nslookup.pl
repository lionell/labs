#!/usr/bin/env perl

# nslookup util
#
# Usage:
# $ ./nslookup.pl www.google.com
# www.google.com => 216.58.215.100

use strict;
use warnings;
use feature "say";
use Socket;
use Net::hostent;

my $host = gethostbyname shift;
my $name = $host->name;
my $addresses = $host->addr_list;
my @lst = map { inet_ntoa($_) } @$addresses;
say "$name => @lst";
