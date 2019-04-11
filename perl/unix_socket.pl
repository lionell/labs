#!/usr/bin/env perl

# UNIX domain socket listener
#
# Usage:
# (SERVER)
# $ ./unix_socket.pl unix.socket
# Socket file 'unix.socket' created.
# Client connected.
# Received: 'Hello from there'
# Client disconnected.
# Client connected.
# Received: 'I'm here again'
# Client disconnected.
# ^CSocket file removed.
#
# (CLIENT)
# $ nc -U unix.socket
# Hello from there
# Echo: Hello from there
# ^C
#
# $ nc -U unix.socket
# I'm here again
# Echo: I'm here again
# ^C

use strict;
use warnings;
use feature "say";
use IO::Socket::UNIX;

my $file = shift;
my $server = IO::Socket::UNIX->new(
    Type => SOCK_STREAM(),
    Local => $file,
    Listen => 1,
) or die $!;

$SIG{INT} = sub {
    $server->close;
    unlink $file;
    say "Socket file removed.";
    exit;
};

say "Socket file '$file' created.";
while (my $conn = $server->accept) {
    say "Client connected.";
    while (<$conn>) {
        chomp;
        say "Received: '$_'";
        $conn->print("Echo: $_\n");
    }
    $conn->close;
    say "Client disconnected.";
}
