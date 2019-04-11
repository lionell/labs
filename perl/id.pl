#!/usr/bin/env perl

# Show pid, uid, gid of the current process
#
# Usage:
# $ ./id.pl
# PID: 17649
# Real UID: 1000
# Effective UID: 1000
# Real GIDs: 100 1 17 70 100 131 499
# Effective GIDs: 100 1 17 70 100 131 499
#
# $ sudo ./id.pl
# [sudo] password for lionell:
# PID: 17600
# Real UID: 0
# Effective UID: 0
# Real GIDs: 0 0
# Effective GIDs: 0 0

use strict;
use warnings;
use feature "say";

say "PID: ", $$;
say "Real UID: ", $<;
say "Effective UID: ", $>;
say "Real GIDs: ", $(;
say "Effective GIDs: ", $);
