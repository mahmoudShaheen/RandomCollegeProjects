#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M%S")

fswebcam -r 800x600 --no-banner /var/www/html/camProject/images/$DATE.jpg 