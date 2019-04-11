#!/usr/bin/env perl

# TCP server that can handle multiple connections
#
# Usage:
# (SERVER)
# $ ./tcp_server.pl 1234
# [1836] 127.0.0.1:38156 connected.
# [1858] 127.0.0.1:38158 connected.
# [1836] 127.0.0.1:38156 sent 'hello from client 1'
# [1858] 127.0.0.1:38158 sent 'hello from client 2'
# [1858] 127.0.0.1:38158 sent 'bye'
# [1858] 127.0.0.1:38158 disconnected.
# [1836] 127.0.0.1:38156 sent 'bye'
# [1836] 127.0.0.1:38156 disconnected.
# ^C[1832] Shutting down gracefully...
#
# (CLIENT 1)
# $ nc 127.0.0.1 1234
# hello from client 1
# Echo: hello from client 1
# bye
#
# (CLIENT 2)
# $ nc 127.0.0.1 1234
# hello from client 2
# Echo: hello from client 2
# bye

use strict;
use warnings;
use feature "say";
use IO::Socket::INET;

my $sock = IO::Socket::INET->new(LocalPort => shift, Listen => 5, Reuse => 1) or die $!;

sub handle {
    my $client = shift;
    $SIG{INT} = sub {
        $client->close;
        $sock->close;
        exit;
    };
    my $ip = $client->peerhost;
    my $port = $client->peerport;
    my $peer = "$ip:$port";
    say "[$$] $peer connected.";

    my $msg;
    while (1) {
        $client->recv($msg, 1024);
        last unless length $msg;
        chomp $msg;
        say "[$$] $peer sent '$msg'";
        last if $msg eq "bye";
        $client->send("Echo: $msg\n");
    }
    say "[$$] $peer disconnected.";
    $client->close;
    exit;
}

my @children = ();

$SIG{INT} = sub {
    say "[$$] Shutting down gracefully...";
    $sock->close;
    kill "INT", @children;
    exit;
};

while (my $client = $sock->accept) {
   if (my $pid = fork) {
        push @children, $pid;
    } else {
        handle $client;
    }
}
