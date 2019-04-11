#!/usr/bin/env perl

# Print environment variables
#
# Usage:
# $ ./env.pl
# COLORTERM=truecolor
# DISPLAY=:0.0
# EDITOR=vim
# GOPATH=/home/lionell/dev/go
# HOME=/home/lionell
# LANG=en_US.UTF-8
# MAIL=/var/mail/lionell
# PAGER=less -R
# SHELL=/run/current-system/sw/bin/fish
# SSH_AUTH_SOCK=/run/user/1000/ssh-agent
# TERM=screen-256color
# USER=lionell
# ...

use strict;
use warnings;
use feature "say";

say "$_=$ENV{$_}" for (sort keys %ENV)
