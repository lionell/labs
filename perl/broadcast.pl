#!/usr/bin/env perl

# UDP broadcasting
#
# Usage:
# (SERVER)
# $ ./broadcast.pl 4321
# Broadcasting 'Hello, world!' message...
#
# (CLIENT)
# $ nc -l -u 4321
# Hello, world!

use strict;
use warnings;
use feature "say";
use IO::Socket::INET;

my $msg = "Hello, world!";
my $sock = IO::Socket::INET->new(
    PeerAddr => "255.255.255.255",
    PeerPort => shift,
    Proto => "udp",
    Broadcast => 1
) or die $!;

$SIG{INT} = sub {
    $sock->close;
    exit;
};

say "Broadcasting '$msg' message...";
while (1) {
    $sock->send($msg);
    sleep(1);
}
