# Disk-Scheduling-Techniques
The simplest form of disk scheduling is, of course, the (FIFO) algorithm. This algorithm is intrinsically fair, but it generally does not provide the fastest service.
In the SCAN algorithm, the disk arm starts at one end, and moves towards the other end, servicing requests as it reaches each cylinder, until it gets to the other end of the disk. At the other end, the direction of head movement is reversed, and servicing continues. The head continuously scans back and forth across the disk.
C-SCAN is a variant of SCAN designed to provide a more uniform wait time.
Like SCAN, C-SCAN moves the head from one end of the disk to the other, servicing requests along the way. When the head reaches the other end, however, it immediately returns to the beginning of the disk without servicing any requests on the return trip.
