#!/usr/bin/env perl

# Make HTTP POST request
#
# Usage:
# $ ./post.pl http://jsonplaceholder.typicode.com/posts \
#     '{"title": "my_title", "body": "my_body", "userId": 10}'
# {
#   "body": "my_body",
#   "title": "my_title",
#   "userId": "10",
#   "id": 101
# }

use strict;
use warnings;
use HTTP::Tiny;
use JSON::MaybeXS qw(decode_json);

my $response = HTTP::Tiny->new->post_form(shift, decode_json shift);
if ($response->{success}) {
    print $response->{content};
} else {
    die "Failed with status: $response->{status} and reason: $response->{reason}";
}
