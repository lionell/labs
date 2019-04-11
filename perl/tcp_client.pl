#!/usr/bin/env perl

# TCP client
#
# Usage:
# (SERVER)
# $ ./tcp_server.pl 1234
# [2463] 127.0.0.1:38288 connected.
# [2463] 127.0.0.1:38288 sent 'here'
# [2463] 127.0.0.1:38288 sent 'we'
# [2463] 127.0.0.1:38288 sent 'go'
# [2463] 127.0.0.1:38288 sent 'bye'
# [2463] 127.0.0.1:38288 disconnected.
# ^C[2459] Shutting down gracefully...
#
# (CLIENT)
# $ ./tcp_client.pl 127.0.0.1 1234
# > here
# < Echo: here
# > we
# < Echo: we
# > go
# < Echo: go
# > bye

use strict;
use warnings;
use IO::Socket::INET;

my $sock = IO::Socket::INET->new(PeerHost => shift, PeerPort => shift) or die $!;
my $msg = "";
do {
    print "> ";
    chomp($msg = <STDIN>);
    $sock->send($msg);
    $sock->recv($msg, 1024);
    print "< $msg" if $msg;
} while (length $msg);
$sock->close;
