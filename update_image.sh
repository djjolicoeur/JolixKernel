#!/bin/bash

sudo losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 /mnt/os
sudo cp src/kernel /mnt/os/kernel
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
