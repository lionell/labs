#!/usr/bin/env perl

# List all users and their shells
#
# $ ./pwent.pl
# /run/current-system/sw/bin/bash         root
# /run/current-system/sw/bin/nologin      messagebus
# /run/current-system/sw/bin/nologin      polkituser
# /run/current-system/sw/bin/nologin      cups
# /run/current-system/sw/bin/nologin      rtkit
# /run/current-system/sw/bin/nologin      transmission
# /run/current-system/sw/bin/nologin      systemd-journal-gateway
# /run/current-system/sw/bin/nologin      systemd-network
# /run/current-system/sw/bin/nologin      systemd-resolve
# /run/current-system/sw/bin/nologin      systemd-timesync
# /run/current-system/sw/bin/nologin      nscd
# /run/current-system/sw/bin/fish         lionell
# /run/current-system/sw/bin/nologin      nobody

use strict;
use warnings;
use User::pwent;
use feature "say";

while (my $e = getpwent()) {
    say $e->shell . " \t" . $e->name;
}
