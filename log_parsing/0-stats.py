#!/usr/bin/python3
""" 
Module for log parsing.
This script reads stdin line by line and computes metrics.
"""
import sys
import signal

# Initialize variables to store statistics
file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0


# Signal handler to print statistics on interrupt
def signal_handler(sig, frame):
    """Signal handler function that prints statistics when interrupted."""
    print_stats()


# Function to print statistics
def print_stats():
    """Prints statistics including total file size
    and counts of each status code.
    """
    print(f"File size: {file_size}")
    for code, count in sorted(status_codes.items()):
        if count > 0:
            print(f"{code}: {count}")
    sys.stdout.flush()


# Register signal handler
signal.signal(signal.SIGINT, signal_handler)

# Process input line by line
for line in sys.stdin:
    """ Doc """
    try:
        # Parse line
        parts = line.split()
        ip_address = parts[0]
        status_code = int(parts[-2])
        size = int(parts[-1])

        # Update statistics
        file_size += size
        status_codes[status_code] += 1
        line_count += 1

        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print_stats()

    except Exception as e:
        # Skip line if format is incorrect
        pass
