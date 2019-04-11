#!/usr/bin/env perl

# mail util (using sendmail)
#
# Usage:
# ./email.pl -t my_friend@gmail.com -f me@gmail.com -s 'Top secret' -m 'Check this link out'
# Sent successfully!

use strict;
use warnings;
use feature "say";
use Getopt::Long qw(GetOptions);

my $to = "";
my $from = "";
my $subject = "";
my $message = "";
GetOptions(
    "to=s" => \$to,
    "from=s" => \$from,
    "subject=s" => \$subject,
    "message=s" => \$message,
) or die $!;

open my $mail, "|sendmail -t";
print $mail "To: $to\n";
print $mail "From: $from\n";
print $mail "Subject: $subject\n\n";
print $mail $message;
close $mail;

say "Sent successfully!";
