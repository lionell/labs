# PARCS-JAVA

Consists of hosts-server (load balancer) and a bunch of daemons (slaves). One can submit task to hosts-server via sending corresponding `.jar` file.

## Setting up Google Compute Engine

We'll create 2 instances for daemons, instance for hosts-server and instance to for an application.

First of set default project in `gcloud` tool. This saves us from constantly specifying project id.
```
$ gcloud config set project "moggio-165703"
```

Now let's create new instances
```
$ gcloud compute instances create daemon-1 daemon-2 hosts-server app --zone us-central1-c

Created [https://www.googleapis.com/compute/v1/projects/moggio-165703/zones/us-central1-c/instances/hosts-server].
Created [https://www.googleapis.com/compute/v1/projects/moggio-165703/zones/us-central1-c/instances/daemon-1].
Created [https://www.googleapis.com/compute/v1/projects/moggio-165703/zones/us-central1-c/instances/daemon-2].
Created [https://www.googleapis.com/compute/v1/projects/moggio-165703/zones/us-central1-c/instances/app].
NAME          ZONE           MACHINE_TYPE   PREEMPTIBLE  INTERNAL_IP  EXTERNAL_IP    STATUS
hosts-server  us-central1-c  n1-standard-1               10.128.0.2   35.192.221.94  RUNNING
daemon-1      us-central1-c  n1-standard-1               10.128.0.5   35.188.57.169  RUNNING
daemon-2      us-central1-c  n1-standard-1               10.128.0.4   35.192.8.28    RUNNING
app           us-central1-c  n1-standard-1               10.128.0.3   35.192.150.94  RUNNING
```

## Cleaning up

Don't forget to remove all created instances as resources are not free. If you don't do it GCP can **charge you**!
```
$ gcloud compute instances delete daemon-1 daemon-2 hosts-server app --zone us-central1-c
```
